// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (compilar com g++)

#include <cstdio>
#include <list>

using namespace std; // Para incluir o namespace std

#define MAX 100

typedef struct {
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia do no origem da pesquisa
} Node;

typedef struct {
  int n;
  Node nodes[MAX];
} Graph;

void addLink(Graph *g, int a, int b) {
  g->nodes[a].adj.push_back(b);
  g->nodes[b].adj.push_back(a);
}

void bfs(Graph *g, int v) {
  list<int> q;
  for (int i=1; i<=g->n; i++) g->nodes[i].visited = false;
  
  q.push_back(v);
  g->nodes[v].visited  = 1;
  g->nodes[v].distance = 0;

  while (q.size() > 0) {
    int u = q.front(); q.pop_front();
    printf("%d [dist=%d]\n", u, g->nodes[u].distance);
    for (auto w : g->nodes[u].adj)
      if (!g->nodes[w].visited) {
        q.push_back(w);
        g->nodes[w].visited  = true;
        g->nodes[w].distance = g->nodes[u].distance + 1; 	  
      }      
  }
}

int main() {
  int e, a, b;

  Graph g;
  scanf("%d", &g.n);
  scanf("%d", &e);
  for (int i=0; i<e; i++) {
    scanf("%d %d", &a, &b);
    addLink(&g, a, b);
  }
  
  // Pesquisa em largura a partir do no 1
  bfs(&g, 1);

  return 0;
}

