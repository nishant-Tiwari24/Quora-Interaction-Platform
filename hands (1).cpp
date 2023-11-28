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

    void displayVerticesWithInwardEdges(); 

    void printAllEdges() {
    for (const auto& vertex : vertices) {
        for (const auto& neighbor : adjacencyList[vertex]) {
        cout << "(" << vertex << ", " << neighbor << ")" << endl;
        }
    }
}

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
    cout  << vertex << endl;

    const unordered_set<string>& connectedVertices = adjacencyList[vertex];

    for (const auto& v : vertices) {
        if (v != vertex && connectedVertices.find(v) == connectedVertices.end()) {
            cout << v << endl;
        }
    }

    cout << endl;
}


void Graph::displayVerticesWithInwardEdges() {
    cout << "Display Vertices with Greater Inward Edges" << endl;

    vector<pair<string, int>> inwardEdgesCount;

    for (const auto& vertex : vertices) {
        int count = 0;
        for (const auto& neighbor : vertices) {
            if (neighbor != vertex && adjacencyList[neighbor].count(vertex) > 0) {
                count++;
            }
        }
        inwardEdgesCount.push_back({vertex, count});
    }

    sort(inwardEdgesCount.begin(), inwardEdgesCount.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    for (const auto& pair : inwardEdgesCount) {
        cout << pair.first << endl;
    }

    cout << endl;
}