#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
        this->l[j].push_back(i);
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto num: this->l[i]) {
                cout << num << ", ";
            }
            cout << endl;
        }
    }

    bool isCyclic(int start) {
        vector<bool> visited(this->V, false);
        return dfs(start, visited, -1);
    }

    bool dfs(int node, vector<bool> &visited, int parent) {
        visited[node] = true;
        for (auto nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool isCyclePresent = dfs(nbr, visited, node);
                if (isCyclePresent) return true;
            }
            else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }
};

int main(void) {

    Graph g(6);
      g.addEdge(0,1);
      g.addEdge(0,4);
      g.addEdge(2,1);
      g.addEdge(3,4);
      g.addEdge(4,5);
      // g.addEdge(2,3);
      // g.addEdge(3,5);
    g.showGraph();

    if (g.isCyclic(0)) cout << "Cycle Present" << endl;
    else cout << "Cycle not present" << endl;
    return 0;
}