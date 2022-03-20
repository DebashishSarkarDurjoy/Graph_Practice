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
            for (auto node: this->l[i]) {
                cout << node << ", ";
            }
            cout << endl;
        }
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
    }

    bool isCyclic() {
        vector<bool> visited(this->V, false);
        vector<bool> currentPath(this->V, false);

        for (int i = 0; i < this->V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, currentPath)) return true;
            }
        }
        return false;
    }

    bool dfs(int node, vector<bool> &visited, vector<bool> &currentPath) {
        visited[node] = true;
        currentPath[node] = true;

        for (auto nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool isCyclePresent = dfs(nbr, visited, currentPath);
                if (isCyclePresent) return true;
            }
            else if (currentPath[nbr]) {
                return true;
            }
        }
        currentPath[node] = false;
        return false;
    }

};

int main(void) {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,2);

    g.showGraph();

    if (g.isCyclic()) cout << "Backedge detected" << endl;
    else cout << "Backedge not detected" << endl;

    return 0;
}
