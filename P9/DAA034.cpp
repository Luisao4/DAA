#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

// Class representing a node
class Node {
public:
    vector<pair<int, int>> adj;  // List of adjacent nodes
    bool visited;                // Has the node been visited?
    int distance;                // Distance from the source node

    Node() {
        visited = false;
        distance = INT_MAX;
    }
};

// Class representing a graph
class Graph {
public:
    int n;                // Number of nodes in the graph
    vector<Node> nodes;   // Vector to store the nodes

    Graph(int n) {
        this->n = n;
        nodes.resize(n);
    }

    void addEdge(int a, int b, int c) {
        nodes[a].adj.push_back({b, c});
    }

    // Dijkstra's algorithm
    bool dijkstra(int source) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        nodes[source].distance = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (nodes[u].visited)
                continue;

            nodes[u].visited = true;

            for (auto& edge : nodes[u].adj) {
                int v = edge.first;
                int weight = edge.second;

                if (nodes[u].distance + weight < nodes[v].distance) {
                    nodes[v].distance = nodes[u].distance + weight;
                    pq.push({nodes[v].distance, v});
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < n; i++) {
            for (auto& edge : nodes[i].adj) {
                int v = edge.first;
                int weight = edge.second;
                if (nodes[i].distance + weight < nodes[v].distance)
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c < cases; c++) {
        int n, m;
        cin >> n >> m;

        Graph g(n);

        for (int i = 0; i < m; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            g.addEdge(a, b, t);
        }

        if (g.dijkstra(0))
            cout << "possivel" << endl;
        else
            cout << "impossivel" << endl;
    }

    return 0;
}

