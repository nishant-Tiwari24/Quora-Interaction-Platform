#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Graph {
public:
    vector<string> vertices;
    unordered_map<string, unordered_set<string>> adjacencyList;

    Graph(const vector<string>& vertices);

    void addEdge(const string& v, const string& w);

    void displayDisconnectedVertices(const string& vertex);


};

Graph::Graph(const vector<string>& vertices) : vertices(vertices) {
    for (const auto& vertex : vertices) {
        adjacencyList[vertex] = unordered_set<string>();
    }
}

void Graph::addEdge(const string& v, const string& w) {
    adjacencyList[v].insert(w);
    // adjacencyList[w].insert(v);
}

void Graph::displayDisconnectedVertices(const string& vertex) 
{
    cout << "Vertices not connected to vertex " << vertex << " are: ";

    const unordered_set<string>& connectedVertices = adjacencyList[vertex];

    for (const auto& v : vertices) {
        if (v != vertex && connectedVertices.find(v) == connectedVertices.end()) {
            cout << v << " ";
        }
    }

    cout << endl;
}