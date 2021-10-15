#ifndef HASHTABLE
#define HASHTABLE

#include <string>

typedef struct {
    int no;
    std::string name;
} Data;

typedef struct __node {
    Data data;
    struct __node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} Hash;

bool init_hash(Hash *, int);
int hash(int, int);
void set_node(Node *, Data, Node *);
bool insert_node(Hash *, Data);
void free_hash(Hash *);

#endif
