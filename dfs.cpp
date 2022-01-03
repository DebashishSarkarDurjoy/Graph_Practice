#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int v) {
        this->V = v;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j, bool undir = true) {
        this->l[i].push_back(j);
        if (undir) {
            this->l[j].push_back(i);
        }
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

    void dfsHelper(int node, bool *visited) {
        visited[node] = true;
        cout << node << endl;

        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source) {
        bool *visited = new bool[this->V]{false};
        dfsHelper(source, visited);
    }
};


int main(){
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
	g.dfs(0);
	return 0;
}
