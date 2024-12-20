#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

class Graph {
private:
    // Adjacency list representation
    unordered_map<string, list<string>> adjacencyList;

public:
    // Add a vertex to the graph
    void addVertex(const string& vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = list<string>(); // Initialize an empty list for the vertex
        }
    }

    // Add an edge between two vertices (undirected graph)
    void addEdge(const string& vertex1, const string& vertex2) {
        if (adjacencyList.find(vertex1) != adjacencyList.end() && adjacencyList.find(vertex2) != adjacencyList.end()) {
            adjacencyList[vertex1].push_back(vertex2); // Add vertex2 to vertex1's list
            adjacencyList[vertex2].push_back(vertex1); // Add vertex1 to vertex2's list
        } else {
            cout << "One or both vertices not found in the graph." << endl;
        }
    }

    // Remove an edge between two vertices
    void removeEdge(const string& vertex1, const string& vertex2) {
        if (adjacencyList.find(vertex1) != adjacencyList.end() && adjacencyList.find(vertex2) != adjacencyList.end()) {
            adjacencyList[vertex1].remove(vertex2); // Remove vertex2 from vertex1's list
            adjacencyList[vertex2].remove(vertex1); // Remove vertex1 from vertex2's list
        } else {
            cout << "One or both vertices not found in the graph." << endl;
        }
    }

    // Remove a vertex and all its edges
    void removeVertex(const string& vertex) {
        if (adjacencyList.find(vertex) != adjacencyList.end()) {
            // Remove the vertex from the adjacency lists of its neighbors
            for (const auto& neighbor : adjacencyList[vertex]) {
                adjacencyList[neighbor].remove(vertex);
            }
            // Remove the vertex from the graph
            adjacencyList.erase(vertex);
        } else {
            cout << "Vertex not found in the graph." << endl;
        }
    }

    // Display the adjacency list
    void display() const {
        for (const auto& pair : adjacencyList) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

// Main function to demonstrate the graph
int main() {
    Graph graph;

    // Add vertices
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    // Add edges
    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "C");
    graph.addEdge("C", "D");

    // Display the graph
    cout << "Graph adjacency list:" << endl;
    graph.display();

    // Remove an edge
    cout << "\nRemoving edge between A and B..." << endl;
    graph.removeEdge("A", "B");
    graph.display();

    // Remove a vertex
    cout << "\nRemoving vertex C..." << endl;
    graph.removeVertex("C");
    graph.display();

    return 0;
}