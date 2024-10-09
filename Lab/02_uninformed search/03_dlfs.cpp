#include <iostream>
#include <vector>
using namespace std;
void DFLS(int node, const vector<vector<int>>& adjacencyList, vector<bool>& visited, int depth, int limit) {
    // If the depth limit is reached, stop exploring
    if (depth > limit) {
        return;
    }
    visited[node] = true;
    cout << "Visited Node: " << node << " at Depth: " << depth << endl;
    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            DFLS(neighbor, adjacencyList, visited, depth + 1, limit);
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
    int limit = 2; // Depth limit for DFLS
    vector<bool> visited(numNodes, false); 
    DFLS(0, adjacencyList, visited, 0, limit);  // Starting from node 0 with initial depth 0
    return 0;
}
