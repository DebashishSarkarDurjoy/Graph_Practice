#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
    int V;
    list<pair<int, int>> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<pair<int, int>> [this->V];
    }

    void addEdge(int i, int j, int wt, bool undir=true) {
        this->l[i].push_back({j, wt});
        if (undir) {
            this->l[j].push_back({i, wt});
        }
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto p: this->l[i]) {
                cout << "(" << p.first << ", " << p.second << "), ";
            }
            cout << endl;
        }
    }
};

int main(void) {

    Graph g(11);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 10, 1);
    g.addEdge(1, 10, 3);
    g.addEdge(1, 5, 7);
    g.addEdge(1, 2, 15);
    g.addEdge(2, 5, 20);
    g.addEdge(2, 4, 2);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 9, 5);
    g.addEdge(3, 4, 13);
    g.addEdge(3, 7, 21);
    g.addEdge(3, 8, 17);
    g.addEdge(3, 9, 8);
    g.addEdge(4, 5, 8);
    g.addEdge(4, 7, 12);
    g.addEdge(5, 10, 6);
    g.addEdge(5, 6, 11);
    g.addEdge(10, 6, 4);
    g.addEdge(6, 7, 2);
    g.addEdge(7, 8, 5);
    g.addEdge(8, 9, 7);

    g.showGraph();


    return 0;
}
