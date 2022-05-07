#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int i) {
        this->V = i;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j, bool undir = true) {
        this->l[i].push_back(j);
        if (undir) {
            this->l[j].push_back(i);
        }
    }

    void showGraph(int i) {
        if (i > this->V) {
            cout << "Only " << this->V << " nodes present.\n";
            return ;
        }
        for (int j = 0; j < i; j++) {
            cout << j << ": ";
            for (auto node: this->l[j]) {
                cout << node << ", ";
            }
            cout << endl;
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
	g.showGraph(6);

    return 0;
}
