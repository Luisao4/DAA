// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <iostream>

#define MAX 100  // Maximo numero de nos
#define FILL '#'

using namespace std;

char m[MAX][MAX];        // Matriz de adjacencias
bool visited[MAX][MAX];  // Que nos ja foram visitados?
int rows, cols;
int c = 0;


void printmatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

void clean() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }
}

void dfs(int y, int x){
    if(x<0 || y<0 || y>=rows || x>=cols) return;
    if(visited[y][x] || m[y][x]!= FILL) return;
    visited[y][x] = true;
    c++;
    dfs(y-1,x);
    dfs(y+1,x);
    dfs(y,x-1);
    dfs(y,x+1);
    dfs(y-1,x-1);
    dfs(y+1,x+1);
    dfs(y-1,x+1);
    dfs(y+1,x-1);
}



int main() {
    int n;
    cin >> n;

    while (n > 0) {
        cin >> rows >> cols;
        for (int i = 0; i < rows; i++) {
            cin >> m[i];
        }
        // printmatrix();
        // clean();
        int newcounter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    dfs(i, j);
                    if(c>=newcounter) newcounter = c;
                    c = 0;
                }
            }
        }
        clean();
        cout << newcounter << endl;
        c=0;
        newcounter = 0;
        n--;
    }
    return 0;
}
