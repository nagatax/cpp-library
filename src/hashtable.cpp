#include "../src/hashtable.hpp"

/**
 * ハッシュテーブルの初期化
 *
 * @param Hash* h ハッシュテーブル
 * @param int size ハッシュテーブルのサイズ
 * @return bool
 */
bool init_hash(Hash *h, int size)
{
    int i;

    h->size = 0;
    if ((h->table = (Node **)calloc(size, sizeof(Node *))) == NULL) {
        return false;
    }

    h->size = size;
    for (i = 0; i < size; i++) {
        h->table[i] = NULL;
    }

    return true;
}

/**
 * ハッシュ値の算出
 *
 * @param int key キー値
 * @param int size ハッシュテーブルサイズ
 * @return
 */
int hash(int key, int size)
{
    return (key % size);
}

/**
 * ノードの設定
 *
 * @param Node* n ノードポインタ
 * @param Data x データ
 * @param Node* next 次のノードポインタ
 */
void set_node(Node *n, Data x, Node *next)
{
    n->data = x;
    n->next = next;
}

/**
 * ノードの挿入
 *
 * @param Hash* h ハッシュテーブル
 * @param Data x データ
 * @return
 */
bool insert_node(Hash *h, Data x)
{
    int key = hash(h->size, x.no);
    Node *p = h->table[key];
    Node *temp;

    while (p != NULL) {
        if (p->data.no == x.no) {
            return false;
        }
        p = p->next;
    }

    if ((temp = (Node *)calloc(1, sizeof(Node))) == NULL) {
        return false;
    }

    set_node(temp, x, h->table[key]);
    h->table[key] = temp;

    return true;
}

/**
 * ハッシュテーブルの解放
 *
 * @param Hash* h ハッシュテーブル
 */
void free_hash(Hash *h)
{
    for (int i = 0; i < h->size; i++) {
        Node *p = h->table[i];
        while (p != NULL) {
            Node *next = p->next;
            free(p);
            p = next;
        }
    }
    free(h->table);
}