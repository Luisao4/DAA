// Codigo inicial para o problema [DAA 022] Arvores Red-Black
// Pedro Ribeiro (DCC/FCUP)

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Macros para devolver minimo e maximo entre dois valores
#define MIN(A,B) ((A)<(B)?(A):(B))
#define MAX(A,B) ((A)>(B)?(A):(B))

// Estrutura para representar um no da arvore
typedef struct node {
  bool isBlack; // No preto?
  bool isNull;  // No nulo?
  int value;    // Valor
  struct node *left, *right; // Filhos
} *Node;

// Criar um no a partir de um numero
Node mkNode(int v) {
  Node aux = (Node)malloc(sizeof(struct node));
  aux->isNull  = (v==0);
  aux->isBlack = (v>=0);
  aux->value   = abs(v);
  return aux;
}

// Ler input em preorder
Node readPreOrder() {
  Node aux;
  int v;
  scanf("%d", &v);
  aux = mkNode(v);
  if (v!=0) {
    aux->left  = readPreOrder();
    aux->right = readPreOrder();
  }
  return aux;
}

// Menor valor da arvore
int minimum(Node t) {
  int minLeft, minRight;
  if (t->isNull) return INT_MAX;
  minLeft  = minimum(t->left);
  minRight = minimum(t->right);
  return MIN(t->value, MIN(minLeft, minRight));
}

// Maior valor da arvore
int maximum(Node t) {
  int maxLeft, maxRight;
  if (t->isNull) return INT_MIN;
  maxLeft  = maximum(t->left);
  maxRight = maximum(t->right);
  return MAX(t->value, MAX(maxLeft, maxRight));
}

// Quantidade de nos (internos)
int size(Node t) {
  if (t->isNull) return 0;
  return 1 + size(t->left) + size(t->right);
}

// ---------------------------------------------------

int main() {
  int i, n;
  Node root;

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    root = readPreOrder();
    printf("Tree with %d nodes (min=%d, max=%d)\n", size(root), minimum(root), maximum(root));
  }

  return 0;
}
