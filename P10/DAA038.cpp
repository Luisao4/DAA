#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

class Node {
public:
    vector<pair<int, int>> adj;
    bool visited;
    int distance;
};

class Graph {
public:
    int n;
    vector<Node> nodes;

    Graph(int n) {
        this->n = n;
        nodes.resize(n + 1);
    }

    void addLink(int a, int b, int c) {
        nodes[a].adj.push_back({b, c});
        nodes[b].adj.push_back({a, c});
    }

    void prim(int r) {
        for (int i = 1; i <= n; i++) {
            nodes[i].distance = INT_MAX;
            nodes[i].visited = false;
        }

        nodes[r].distance = 0;
        set<pair<int, int>> q;
        q.insert({0, r});

        int total = 0;
        set<int> path;

        while (!q.empty()) {
            int u = q.begin()->second;
            q.erase(q.begin());
            nodes[u].visited = true;

            total += nodes[u].distance;
            if (nodes[u].distance != 0)
                path.insert(nodes[u].distance);

            for (auto edge : nodes[u].adj) {
                int v = edge.first;
                int cost = edge.second;
                if (!nodes[v].visited && cost < nodes[v].distance) {
                    q.erase({nodes[v].distance, v});
                    nodes[v].distance = cost;
                    q.insert({nodes[v].distance, v});
                }
            }
        }

        printf("%d\n", total);

        int space = 0;
        for (auto k : path) {
            if (space == 0)
                printf("%d", k);
            else
                printf(" %d", k);
            space = 1;
        }
        printf("\n");
    }
};

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    Graph* g = new Graph(a + b);

    for (int i = 1; i < a; i++) {
        g->addLink(i, i + 1, 0);
    }

    int x, y, p;
    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &x, &y, &p);
        g->addLink(x, y, p);
    }

    g->prim(1);
    return 0;
}
