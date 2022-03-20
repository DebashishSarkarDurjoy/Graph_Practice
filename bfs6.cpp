#include <iostream>
#include <list>
#include <queue>
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
        this->l[j].push_back(i);
    }

    void bfs(int start) {
        queue<int> q;
        vector<bool> visited(this->V, false);

        q.push(start);
        visited[start] = true;
        cout << start << ", ";

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto nbr: this->l[front]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                    cout << nbr << ", ";
                }
            }
        }
        cout << endl;
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
    g.bfs(0);

    return 0;
}
