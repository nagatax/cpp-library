/**
 * 配列を逆順にする
 *
 * @param int[] a 配列
 * @param int len
 */
void ary_reverse(int a[], int len)
{
    for (int i = 0, t = 0, cnt = len / 2; i < cnt; i++) {
        t = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = t;
    }
}

