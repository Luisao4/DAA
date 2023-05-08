// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

// Estrutura para representar um no da arvore
typedef struct node {
    bool isBlack;               // No preto?
    bool isNull;                // No nulo?
    int value;                  // Valor
    struct node *left, *right;  // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
    Node aux = (Node)malloc(sizeof(struct node));
    aux->isNull = (v == 0);
    aux->isBlack = (v >= 0);
    aux->value = abs(v);
    return aux;
}

// Ler input em preorder
Node readPreOrder() {
    int v;
    cin >> v;
    Node aux = mkNode(v);
    if (v != 0) {
        aux->left = readPreOrder();
        aux->right = readPreOrder();
    }
    return aux;
}

// Menor valor da arvore
int minimum(Node t) {
    if (t->isNull) return INT_MAX;
    int minLeft = minimum(t->left);
    int minRight = minimum(t->right);
    return min(t->value, min(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
    if (t->isNull) return INT_MIN;
    int maxLeft = maximum(t->left);
    int maxRight = maximum(t->right);
    return max(t->value, max(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
    if (t->isNull) return 0;
    return 1 + size(t->left) + size(t->right);
}

// ------------------Comeca aqui ---------------------

bool BSTree(Node a, int min, int max) {
    if (a->isNull) return true;
    if (a->value < min || a->value > max) return false;
    return BSTree(a->left, min, a->value) && BSTree(a->right, a->value, max);
    // passar a subarvore a esquerda e a subarvore a direita
}

bool rootProp(Node a) {
    if (a->isBlack) return true;
    return false;
}

bool leafProp(Node a) {
    if (a->isNull && !(a->isBlack)) return false;
    if (a->isNull && a->isBlack) return true;
    return leafProp(a->left) && leafProp(a->right);
}

bool redProp(Node a) {
    if (a->isNull) return true;
    if (!(a->isBlack) && (!(a->right->isBlack) || !(a->left->isBlack))) return false;

    return redProp(a->left) && redProp(a->right);
}

bool blackProp(Node a, int bh, int count) {
    if (a->isNull) return count == bh;
    if (a->isBlack) count++;

    return blackProp(a->left, bh, count) && blackProp(a->right, bh, count);
}

int blackHeight(Node a) {
    int c = 0;
    do {
        a = a->left;
        if (a->isBlack) c++;
    } while (!(a->isNull));
    return c;
}

// ---------------------------------------------------

int main() {
    int i, n;
    Node root;

    cin >> n;
    for (i = 0; i < n; i++) {
        root = readPreOrder();
        int h = blackHeight(root);
        // printf("Tree with %d nodes (min=%d, max=%d)\n", size(root), minimum(root), maximum(root));
        if (BSTree(root, minimum(root), maximum(root)) && rootProp(root) && leafProp(root) && redProp(root) && blackProp(root, h, 0))
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;
    }

    return 0;
}
