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
 *
 * @param int[] x 検索対象
 * @param int n 検索対象の要素数
 * @param int key 検索値
 * @return 検索値のインデックス番号(検索値が存在しない場合、-1)
 */
int search(int x[], int n, int key)
{
    int i;

    // 番兵を追加する
    x[n] = key;

    for(i = 0; i < n; i++) {
        if (x[i] == key) {
            break;
        }
    }

    return (i == n ? -1 : i);
}

/**
 * 2分探索
 *
 * @param int[] x 検索対象(昇順にソート済みである配列であること)
 * @param int n 検索対象の要素数
 * @param int key 検索値
 * @return 検索値のインデックス番号(検索値が存在しない場合、-1)
 */
int bsearch(const int x[], int n, int key)
{
    int pl = 0;     // 探索範囲の左端インデックス番号
    int pr = n-1;   // 探索範囲の右端インデックス番号
    int pc;         // 探索範囲の中央インデックス番号

    do {
        pc = (pl + pr) / 2;
        if (x[pc] == key) {
            return pc;
        } else if (x[pc] < key) {
            pl = pc + 1;
        } else {
            pr = pc - 1;
        }
    } while (pl <= pr);

    return -1;
}