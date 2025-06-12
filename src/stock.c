#include "stock.h"
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct string_buffer {
    char *data;
    size_t length;
};

static void init_buffer(struct string_buffer *sb) {
    sb->length = 0;
    sb->data = malloc(1);
    if (sb->data)
        sb->data[0] = '\0';
}

static size_t write_cb(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total = size * nmemb;
    struct string_buffer *sb = userdata;
    char *new_data = realloc(sb->data, sb->length + total + 1);
    if (!new_data)
        return 0;
    sb->data = new_data;
    memcpy(sb->data + sb->length, ptr, total);
    sb->length += total;
    sb->data[sb->length] = '\0';
    return total;
}

double parse_stock_price(const char *json) {
    const char *key = "\"regularMarketPrice\":";
    const char *pos = strstr(json, key);
    if (!pos)
        return -1.0;
    pos += strlen(key);
    return strtod(pos, NULL);
}

double fetch_stock_price(const char *symbol) {
    CURL *curl = curl_easy_init();
    if (!curl)
        return -1.0;

    char url[256];
    snprintf(url, sizeof(url),
             "https://query1.finance.yahoo.com/v7/finance/quote?symbols=%s", symbol);

    struct string_buffer sb;
    init_buffer(&sb);

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sb);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    double price = -1.0;
    if (res == CURLE_OK)
        price = parse_stock_price(sb.data);

    free(sb.data);
    return price;
}
