// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <iostream>

#define MAX 25  // Maximo numero de nos

using namespace std;

int n;               // Numero de nos do grafo
bool adj[MAX][MAX];  // Matriz de adjacencias
bool visited[MAX];   // Que nos ja foram visitados?

void dfs(int v) {
    // cout << v << " ";
    visited[v] = true;
    for (int i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    int edges, a, b;

    cin >> n;
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true;
    }
    int c = 0;
    for (int i = 1; i <= n; i++)
        if (!visited[i]) {
            c++;
            dfs(i);
        }
    if (edges == 0)
        cout << n << endl;
    else
        cout << c << endl;
    // cout << endl;

    return 0;
}
