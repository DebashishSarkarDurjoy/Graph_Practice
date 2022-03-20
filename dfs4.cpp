#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int V) {
        this->V = V;
        this->l = new list<int> [this->V];
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto nbr: this->l[i]) {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
        this->l[j].push_back(i);
    }

    void dfs(int start) {
        vector<bool> visited(this->V, false);
        dfs_recurse(start, visited);
        cout << endl;
    }

    void dfs_recurse(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << ", ";
        for (auto nbr: this->l[node]) {
            if (!visited[nbr]) {
                dfs_recurse(nbr, visited);
            }
        }
    }

};


int main(void) {
    Graph g(6);
      g.addEdge(0,1);
      g.addEdge(0,4);
      g.addEdge(2,1);
      g.addEdge(3,4);
      g.addEdge(4,5);
      g.addEdge(2,3);
      g.addEdge(3,5);
    g.showGraph();
    g.dfs(0);

    return 0;
}
