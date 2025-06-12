#ifndef STOCK_H
#define STOCK_H

#ifdef __cplusplus
extern "C" {
#endif

double fetch_stock_price(const char *symbol);
double parse_stock_price(const char *json);

#ifdef __cplusplus
}
#endif

#endif // STOCK_H
