// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <stdbool.h>

#include <iostream>
using namespace std;

#define FILL '#'
#define MAX 25  // Maximo numero de nos

int rows, cols;
char m[MAX][MAX];
bool visited[MAX][MAX];
int c = 0;

void printmatrix(int rows, int cols, char m[][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

void dfs(int y, int x) {
    if (y < 0 || y >= rows || x < 0 || x >= cols) return;  // aceder a pos que nao existem
    if (visited[y][x] || m[y][x] != FILL) return;
    // cout<< "dfs(" << y << "," << x << ")"<<endl;
    visited[y][x] = true;
    c++;
    dfs(y - 1, x);
    dfs(y + 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
    dfs(y + 1, x + 1);
    dfs(y - 1, x - 1);
    dfs(y - 1, x + 1);
    dfs(y + 1, x - 1);
}

void cleanseVisited() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            visited[i][j] = false;
}

int main() {
    int n;
    cin >> n;

    while (n > 0) {
        
        cin >> rows >> cols;
        cleanseVisited();  // reset do visited
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> m[i][j];
            }
        }
        int flag = 0;  // comparaçao para ver qual o maior microbio
        // printmatrix(rows,cols,m);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (m[i][j] == FILL && !visited[i][j]) {
                    c = 0;

                    dfs(i, j);
                    if (c > flag) flag = c;
                    c=0;
                    //           puts(" --------------------- ");
                }
        cout << flag << endl;
        n--;
    }
    return 0;
}
