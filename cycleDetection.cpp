//cycle detection for undirected graph using adjacency list
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

    bool isCyclic(int node, vector<bool> &visited, int parent) {
        visited[node] = true;

        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool containsCycle = isCyclic(nbr, visited, node);
                if (containsCycle) return true;
            }
            else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }

    void dfs(int start) {
        vector<bool> visited(this->V, false);
        cout << isCyclic(start, visited, -1) << endl;;
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
