#include <iostream>
#include <vector>
using namespace std;
void DFS(int node, const vector<vector<int>>& adjacencyList, vector<bool>& visited) {
    visited[node] = true;
    cout << "Visited Node: " << node << endl;
    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adjacencyList, visited);
        }
    }
}

int main() {
    int numNodes = 6;
    vector<vector<int>> adjacencyList(numNodes);
    adjacencyList[0] = {1, 2};
    adjacencyList[1] = {0, 3, 4};
    adjacencyList[2] = {0, 4};
    adjacencyList[3] = {1, 5};
    adjacencyList[4] = {1, 2, 5};
    adjacencyList[5] = {3, 4};
    vector<bool> visited(numNodes, false); 
    DFS(0, adjacencyList, visited);
    return 0;
}
