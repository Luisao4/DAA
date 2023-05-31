#include <iostream>

#define MAX 25  // Maximo numero de nos
#define RED 0
#define GREEN 1

using namespace std;

int n;               // Numero de nos do grafo
bool adj[MAX][MAX];  // Matriz de adjacencias
bool visited[MAX];   // Que nos ja foram visitados?
bool color[MAX];

void dfs(int v, int c) {
    if (visited[v] == true) {
        if (color[v] == c) return true;
        return false;
    } else {
        visited[v] = true;
        color[v] = c;
        (c == RED) ? c = GREEN : c = RED;
        for (int i = 1; i <= n; i++) {
            if (m[v][i] && !dfs(i, c)) return false;
            return true;
        }
    }
}

int main() {
    int edges, a, b;
    int N;
    cin >> N;  // casos
    while (N > 0) {
        cin >> n;      // nos
        cin >> edges;  // arestas
        for (int i = 0; i < edges; i++) {
            cin >> a >> b;
            adj[a][b] = adj[b][a] = true;
        }

        if (dfs(1, RED))  // Pesquisa em profundidade a partir do no 1
            cout << "sim";
        else
            cout << "nao";

        n--;
    }
    return 0;
}
