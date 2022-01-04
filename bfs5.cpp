#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph{
public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int x, int y) {
        this->l[x].push_back(y);
        this->l[y].push_back(x);
    }

    void bfs(int start) {
        queue<int> q;
        vector<bool> visited(this->V, false);

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

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (int vertex: this->l[i]) {
                cout << vertex << ", ";
            }
            cout << endl;
        }
    }
};

int main(void) {

    Graph g(7);
    g.addEdge(0,4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,6);
	g.addEdge(3,4);
    g.showGraph();
	g.bfs(0);
	return 0;

    return 0;
}
