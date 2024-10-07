#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Graph edge
class Edge {
public:
    int src, dest, weight;
};

// Disjoint set
class DisjointSet {
    vector<int> parent, rank;

public:

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v])
                parent[u] = v;
            else if (rank[u] > rank[v])
                parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};

// Kruskal's algorithm
void kruskalMST(vector<Edge> &edges, int V) {
    // Sort all edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(V);
    vector<Edge> mst;

    for (Edge &edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        // Check formation of cycle by this edge
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            ds.unionSets(u, v);
        }

        // Early exit: Stop if we have V-1 edges of the MST
        if (mst.size() == V - 1)
            break;
    }

    // Output: Edges in the MST
    int mstWeight = 0;
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (Edge &edge : mst) {
    	cout << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
    	mstWeight += edge.weight;
    }

    cout << "Total MST weight: " << mstWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);

    cout << "Enter each edge in the format: source destination weight\n";
    for (int i = 0; i < E; ++i) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, V);

    return 0;
}
