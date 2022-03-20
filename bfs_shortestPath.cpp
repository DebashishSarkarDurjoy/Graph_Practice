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

    void bfs_shortestPath(int source, int dest = -1) {
        bool *visited = new bool[this->V]{false};
        int *parent = new int[this->V]{-1};
        int *dist = new int[this->V]{-1};

        queue<int> q;

        for (int i = 0; i < this->V; i++) {
            parent[i] = -1;
        }

        q.push(source);
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (int nbr: this->l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = f;
                    dist[nbr] = dist[f] + 1;
                }
            }
        }

        cout << "Min distances: " ;
        for (int i = 0; i < this->V; i++) {
            cout << dist[i] << ", ";
        }

        if (dest != -1) {
            cout << "Path to " << dest << endl;
            int temp = dest;
            while (temp != source) {
                cout << temp << " --> ";
                temp = parent[temp];
            }
            cout << temp;
        }

        cout << endl;
    }
};

int main(void) {
    Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
    g.showGraph();

    g.bfs_shortestPath(1, 6);

    return 0;
}
