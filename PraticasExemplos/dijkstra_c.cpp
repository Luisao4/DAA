// Exemplo de aplicacao do algoritmo de Dijkstra
// (assumindo um grafo pesado e dirigido, sem pesos negativos)
// (codigo adaptado do codigo em C++ mostrado na teorica)
// (compilar com g++)

#include <cstdio>
#include <climits>
#include <list>
#include <set>

using namespace std;

#define MAX 1000 // Maxima quantidade de nos
 
typedef struct {
  list<pair<int, int>> adj;  // Lista de adjacencias
  bool visited;              // No ja foi visitado?
  int distance;              // Distancia ao no origem da pesquisa
} Node;

// Classe que representa um grafo
typedef struct {
  int n;           // Numero de nos do grafo
  Node nodes[MAX]; // Array para conter os nos
} Graph;

void addLink(Graph *g, int a, int b, int c) {
  g->nodes[a].adj.push_back({b,c});
}

// Algoritmo de Dijkstra
void dijkstra(Graph *g, int s) {
    
  //Inicializar nos como nao visitados e com distancia infinita
  for (int i=1; i<=g->n; i++) {
    g->nodes[i].distance = INT_MAX;
    g->nodes[i].visited  = false;
  }
    
  // Inicializar "fila" com no origem
  g->nodes[s].distance = 0;
  set<pair<int, int>> q; // By "default" um par e comparado pelo primeiro elemento 
  q.insert({0, s});      // Criar um par (dist=0, no=s)

  // Ciclo principal do Dijkstra
  while (!q.empty()) {
      
    // Retirar no com menor distancia (o "primeiro" do set, que e uma BST)
    int u = q.begin()->second;
    q.erase(q.begin());
    g->nodes[u].visited = true;
    printf("%d [dist=%d]\n", u, g->nodes[u].distance);

    // Relaxar arestas do no retirado
    for (auto edge : g->nodes[u].adj) {
      int v = edge.first;
      int cost = edge.second;
      if (!g->nodes[v].visited && g->nodes[u].distance + cost < g->nodes[v].distance) {
        q.erase({g->nodes[v].distance, v});  // Apagar do set
        g->nodes[v].distance = g->nodes[u].distance + cost;
        q.insert({g->nodes[v].distance, v}); // Inserir com nova (e menor) distancia
      }
    }
  }
}

int main() {
  int e, a, b, c;

  Graph g;
  scanf("%d", &g.n);
  scanf("%d", &e);
  for (int i=0; i<e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    addLink(&g, a, b, c);
  }

  // Execucao exemplo a partir do no 1
  dijkstra(&g, 1);

  return 0;
}

