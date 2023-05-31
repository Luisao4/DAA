#include <iostream>

#define MAX 25  // Maximo numero de nos

using namespace std;

int n;               // Numero de nos do grafo
bool adj[MAX][MAX];  // Matriz de adjacencias
bool visited[MAX];   // Que nos ja foram visitados?
int count = 0;
void dfs(int v) {
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
  
    for (int i = 1; i < edges; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    cout  <<count << endl;
    return 0;
}
