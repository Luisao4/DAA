// Exemplo de implementacao de algoritmo de Edmonds-Karp
// usando lista de adjacencias + matriz de capacidades
// (implementacao com vector)
// (codigo adaptado do codigo em C++ | compilar com g++)

#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAX 105 // Maxima quantidade de nos

// "Classe" que representa um grafo
typedef struct {
  int n;                // Numero de nos do grafo
  vector<int> adj[MAX]; // Lista de adjacencias
  int cap[MAX][MAX];    // Matriz de capacidades
} Graph;
  
void addLink(Graph *g, int a, int b, int c) {
  // adjacencias do grafo nao dirigido, porque podemos ter de andar no sentido
  // contrario ao procurarmos caminhos de aumento
  g->adj[a].push_back(b);
  g->adj[b].push_back(a);
  g->cap[a][b] = c;
}

// BFS para encontrar caminho de aumento
// devolve valor do fluxo nesse caminho
int bfs(Graph *g, int s, int t, int parent[]) {
  for (int i=1; i<=g->n; i++) parent[i] = -1;

  parent[s] = -2;         
  queue<pair<int, int>> q; // fila do BFS com pares (no, capacidade)
  q.push({s, INT_MAX});    // inicializar com no origem e capacidade infinita

  while (!q.empty()) {
    // returar primeiro no da fila
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    // percorrer nos adjacentes ao no atual (cur)
    for (int next : g->adj[cur]) {
      // se o vizinho ainda nao foi visitado (parent==-1)
      // e a aresta respetiva ainda tem capacidade para passar fluxo
      if (parent[next] == -1 && g->cap[cur][next]>0) {
        parent[next] = cur;                          // atualizar pai
        int new_flow = min(flow, g->cap[cur][next]); // atualizar fluxo
        if (next == t) return new_flow;              // chegamos ao final?
        q.push({next, new_flow});                    // adicionar a fila
      }
    }
  }
    
  return 0;
}
  
// Algoritmo de Edmonds-Karp para fluxo maximo entre s e t
// devolve valor do fluxo maximo (cap[][] fica com grafo residual)
int maxFlow(Graph *g, int s, int t) {
  int flow = 0;     // fluxo a calcular
  int parent[g->n]; // vetor de pais (permite reconstruir caminho)
    
  while (true) {
    int new_flow = bfs(g, s, t, parent); // fluxo de um caminho de aumento
    if (new_flow == 0) break;            // se nao existir, terminar

    // imprimir fluxo e caminho de aumento
    printf("Caminho de aumento: fluxo %d | %d", new_flow, t);
      
    flow += new_flow;  // aumentar fluxo total com fluxo deste caminho
    int cur = t;
    while (cur != s) { // percorrer caminho de aumento e alterar arestas
      int prev = parent[cur];	
      g->cap[prev][cur] -= new_flow;
      g->cap[cur][prev] += new_flow;
      cur = prev;
      printf(" <- %d", cur); // imprimir proximo no do caminho
    }
    putchar('\n');
  }
    
  return flow;
}


int main() {
  int e, a, b, c;
  
  Graph g;
  scanf("%d", &g.n);
  memset(g.cap, 0, sizeof(g.cap));
  scanf("%d", &e);
  for (int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    addLink(&g, a, b, c);
  }

  // Execucao exemplo usando 1 como no origem a 4 como o destino
  int flow = maxFlow(&g, 1, 4);
  printf("Fluxo maximo: %d\n", flow);

  return 0;
}
