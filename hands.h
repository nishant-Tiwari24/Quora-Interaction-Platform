#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

#define RESET "\033[0m"
#define BLUE "\033[1;34m"

class Graph
{
public:
    vector<string> vertices;
    unordered_map<string, unordered_set<string>> adjacencyList;

    Graph(const vector<string> &vertices);

    void addEdge(const string &v, const string &w);

    void displayDisconnectedVertices(const string &vertex);

    void displayVerticesWithInwardEdges();

    void displayCommonVertices(const string &vertex1, const string &vertex2);

    void printAllEdges()
    {
        for (const auto &vertex : vertices)
        {
            for (const auto &neighbor : adjacencyList[vertex])
            {
                cout << "(" << vertex << ", " << neighbor << ")" << endl;
            }
        }
    }
};

Graph::Graph(const vector<string> &vertices) : vertices(vertices)
{
    for (const auto &vertex : vertices)
    {
        adjacencyList[vertex] = unordered_set<string>();
    }
}

void Graph::addEdge(const string &v, const string &w)
{
    adjacencyList[v].insert(w);
    // adjacencyList[w].insert(v);
}

void Graph::displayDisconnectedVertices(const string &vertex)
{
    cout << vertex << endl;

    const unordered_set<string> &connectedVertices = adjacencyList[vertex];

    for (const auto &v : vertices)
    {
        if (v != vertex && connectedVertices.find(v) == connectedVertices.end())
        {
            cout << BLUE << ": " << RESET << v << endl;
        }
    }

    cout << endl;
}

void Graph::displayVerticesWithInwardEdges()
{

    vector<pair<string, int>> inwardEdgesCount;

    for (const auto &vertex : vertices)
    {
        int count = 0;
        for (const auto &neighbor : vertices)
        {
            if (neighbor != vertex && adjacencyList[neighbor].count(vertex) > 0)
            {
                count++;
            }
        }
        inwardEdgesCount.push_back({vertex, count});
    }

    sort(inwardEdgesCount.begin(), inwardEdgesCount.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    for (const auto &pair : inwardEdgesCount)
    {
        cout << BLUE << ": " << RESET << pair.first << endl;
    }

    cout << endl;
}

// display the common vertex
void Graph::displayCommonVertices(const string &vertex1, const string &vertex2)
{
    const int columnWidth = 15;
    cout << "Common vertices connected to " << BLUE << vertex1 << RESET << " and " << BLUE << vertex2 << RESET << ": ";
    cout << "\t\t\t\t\t\t\t|" << left << setw(columnWidth) << "Mutual friend"<< "|" << left << setw(columnWidth);

    const unordered_set<string> &connectedVertices1 = adjacencyList[vertex1];
    const unordered_set<string> &connectedVertices2 = adjacencyList[vertex2];

    vector<string> commonVertices;

    for (const auto &v : connectedVertices1)
    {
        if (connectedVertices2.count(v) > 0)
        {
            commonVertices.push_back(v);
        }
    }

    if (commonVertices.empty())
    {
        cout << "None" << endl;
    }
    else
    {
        for (const auto &v : commonVertices)
        {
            cout << BLUE << v << RESET << " ";
        }
        cout << endl;
    }
    cout << "\t|" << endl;
}
