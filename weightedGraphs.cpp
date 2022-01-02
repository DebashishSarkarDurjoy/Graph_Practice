#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
    int V;
    list<pair<int, int>> *l;

    Graph(int v) {
        this->V = v;
        l = new list<pair<int, int>> [this->V];
    }

    void addEdge(int i, int j, int wt, bool undir = true) {
        this->l[i].push_back({j, wt});
        if (undir) {
            this->l[j].push_back({i, wt});
        }
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto vertex: this->l[i]) {
                cout << "(" << vertex.first << ", " << vertex.second << ")";
            }
            cout << endl;
        }
    }
};

int main(void) {

    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,2);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);
    g.showGraph();

    return 0;
}
