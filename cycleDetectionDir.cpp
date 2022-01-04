#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int x, int y, bool undir = false) {
        this->l[x].push_back(y);
        if (undir) this->l[y].push_back(x);
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (int nbr: this->l[i]) {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    void dfs_helper(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << ", ";

        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(this->V, false);
        dfs_helper(start, visited);
        cout << endl;
    }

    void bfs(int start) {
        vector<bool> visited(this->V, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int f = q.front();
            cout << f << ", ";
            q.pop();

            for (int nbr: this->l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout << endl;
    }

    bool doDFS(int node, vector<bool> &visited, int parent) {
        visited[node] = true;
        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool cycleFound = doDFS(nbr, visited, node);
                if (cycleFound) return true;
            }
            else return true;
        }
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(this->V, false);
        return doDFS(1, visited, -1);
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
    cout << "DFS: " << endl;
    g.dfs(1);
    cout << "BFS: " << endl;
    g.bfs(1);

    cout << "Is cyclic: " << g.isCyclic() << endl;

    return 0;
}
