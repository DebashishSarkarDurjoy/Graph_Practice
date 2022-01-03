#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
        this->l[j].push_back(i);
    }

    void dfs_helper(int node, vector<bool> &visited) {
        cout << node << ", ";
        visited[node] = true;

        for (auto nbr: this->l[node]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(int source) {
        vector<bool> visited(this->V, false);
        dfs_helper(source, visited);
        cout << endl;
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto vertex: this->l[i]) {
                cout << vertex << ", ";
            }
            cout << endl;
        }
    }

};

int main(void) {
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(0,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    g.showGraph();
    g.dfs(1);

    return 0;
}
