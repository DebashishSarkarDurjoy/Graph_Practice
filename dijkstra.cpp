#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std;

class Graph{

	int V;
	list<pair<int,int> > *l;

public:
	Graph(int v){
		V = v;
		l = new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool undir = true){

		l[u].push_back({wt,v});
		if(undir){
			l[v].push_back({wt,u});
		}
	}

	int dijkstra(int src,int dest){

		vector<int> dist(this->V, INT_MAX);
        set<pair<int, int>> s;

        s.insert({0, src});
        dist[src] = 0;

        while (!s.empty()) {
            auto it = s.begin();
            int distTillNow = it->first;
            int node = it->second;
            s.erase(it);

            for (auto nbrPair: this->l[node]) {
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if (currentEdge + distTillNow < dist[nbr]) {
                    auto entry = s.find({dist[nbr], nbr});
                    if (entry != s.end()) {
                        s.erase(entry);
                    }
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({dist[nbr], nbr});
                }
            }
        }

        for (int i = 0; i < this->V; i++) {
            cout << "dist to " << i << " is " << dist[i] << endl;
        }

        return dist[dest];

	}

};

int main(){

	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}
