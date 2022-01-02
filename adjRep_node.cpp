#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name) {
        this->name = name;
    }
};

class Graph {
public:
    unordered_map<string, Node*> m;

    Graph(vector<string> cities) {
        for (string city: cities) {
            m[city] = new Node(city);
        }
    }

    void addEdge(string city_1, string city_2, bool undir = false) {
        this->m[city_1]->nbrs.push_back(city_2);
        if (undir) {
            this->m[city_2]->nbrs.push_back(city_1);
        }
    }

    void printAdjList() {
        for (auto cityPair: this->m) {
            cout << cityPair.first << ": ";
            for (auto nbrs: cityPair.second->nbrs) {
                cout << nbrs << ", ";
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

	g.printAdjList();


    return 0;
}
