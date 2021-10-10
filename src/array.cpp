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

/**
 * 線形探索(番兵法)
 * @param int[] x 検索対象
 * @param int n 検索対象の要素数
 * @param int key 検索値
 * @return 検索値のインデックス番号(検索値が存在しない場合、-1)
 */
int search(int x[], int n, int key)
{
    int i = 0;

    // 番兵を追加する
    x[n] = key;

    while (1) {
        if (x[i] == key) {
            break;
        } else {
            i++;
        }
    }

    return (i == n ? -1 : i);
}