#include<bits/stdc++.h>
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

bool contains_cycle(int V,vector<pair<int,int> > edges){
    //Complete this method
    Graph g(V);
    for (auto edge: edges) {
        g.addEdge(edge.first, edge.second);
    }

    return g.isCyclic();

}
