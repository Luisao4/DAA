#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> cap;

    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
        cap.resize(n + 1, vector<int>(n + 1));
    }

    void addLink(int a, int b, int c) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        cap[b][a] = c;
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INT_MAX});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[cur]) {
                if (parent[next] == -1 && cap[cur][next] > 0) {
                    parent[next] = cur;
                    int new_flow = min(flow, cap[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int flow = 0;
        vector<int> parent(n + 1);

        while (true) {
            int new_flow = bfs(s, t, parent);
            if (new_flow == 0)
                break;

            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }
};

int main() {
    int n, e, a, b;
    cin >> n;
    Graph* g = new Graph(n);
    cin >> e;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        g->addLink(a, b, 1);
    }

    int flow = g->maxFlow(1, n);
    cout << flow << endl;

    return 0;
}
