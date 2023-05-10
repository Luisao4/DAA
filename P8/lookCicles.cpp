#include <iostream>

#define MAX 25

#define WHITE 0
#define GREY 1
#define BLACK 2

int n;
bool adj[MAX][MAX];
int color[MAX]; //visited

using namespace std;

void dfs(int v){
    color[v] = GREY;
    for(int i=1; i<=n ; i++)
    if(adj[v][i]){
        if(color[i] == GREY)
            cout << "cicle in (" << v << "," << i << ")" << endl;
        else if(color[i] == WHITE)
        dfs(i);
    }
    color[v] = BLACK;
}

int main(){
    int edges, a,b;
    cin >> n >> edges;
    for(int i=0; i<edges; i++){
        cin >> a >> b;
        adj[a][b] = true;
    }
    for(int i=1; i<=n; i++)
    color[i] = WHITE;
    
    for (int i = 1; i<=n; i++)
    {
        if(color[i]==WHITE) dfs(i);
    }
    return 0;
}