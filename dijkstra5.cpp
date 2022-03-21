#include <iostream>
#include <list>
#include <vector>
#include <set>

using namespace std;

class Graph {
    int V;
    list<pair<int,int>> *l;

public:
    Graph (int V) {
        this->V = V;
        this->l = new list<pair<int,int>> [this->V];
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (auto p: this->l[i]) {
                cout << "(" << p.first << ", " << p.second << ")  ";
            }
            cout << endl;
        }
    }

    void addEdge(int i, int j, int wt) {
        this->l[i].push_back({wt, j});
        this->l[j].push_back({wt, i});
    }


    void dijkstra(int src, int dest) {
        vector<int> dist(this->V, INT_MAX);
        set<pair<int,int>> s;

        s.insert({0, src});
        dist[src] = 0;

        while (!s.empty()) {
            auto it = s.begin();
            s.erase(it);
            int node = it->second;
            int distTillNow = it->first;

            for (auto nbrPair: this->l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (currentEdge + distTillNow < dist[nbr]) {
                    auto f = s.find({dist[nbr], nbr});
                    if (f != s.end()) s.erase(f);

                    dist[nbr] = currentEdge + distTillNow;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < this->V; i++) {
            cout << "Dist of " << i << " is " << dist[i] << endl;
        }

        cout << dist[dest] << endl;
    }

};

int main(void) {

    Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

    g.showGraph();

    g.dijkstra(0, 4);

    return 0;
}
