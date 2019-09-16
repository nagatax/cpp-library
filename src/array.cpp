/**
 * reverse the array.
 */
void ary_reverse(int a[], int len) {
    for (int i = 0, t = 0, cnt = len / 2; i < cnt; i++) {
        t = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = t;
    }
}

