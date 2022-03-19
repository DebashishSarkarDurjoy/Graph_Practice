#include <iostream>

using namespace std;

#include <list>
#include <unordered_map>
#include <vector>

class Node {
public:
    string name;
    list<string> nbrs;
    Node(string name) {
        this->name = name;
    }
};

class Graph {
private:
    unordered_map<string, Node*> m;

public:
    Graph(vector<string> cities) {
        for (auto city : cities) {
            m[city] = new Node(city);
        }
    }

    void addEdge(string city1, string city2, bool undir=false) {
        m[city1]->nbrs.push_back(city2);
        if (undir) {
            m[city2]->nbrs.push_back(city1);
        }
    }

    void showGraph() {
        for (auto p : this->m) {
            cout << p.first << "--> ";
            for (auto city: p.second->nbrs) {
                cout << city << ", ";
            }
            cout << endl;
        }
    }
};

int main(void) {
    vector<string> cities = {"Delhi","London","Paris","New York"};
	Graph g(cities);
	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.showGraph();

    return 0;
}
