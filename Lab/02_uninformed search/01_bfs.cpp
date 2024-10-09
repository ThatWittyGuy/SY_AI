#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(const vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    int n = 5;
    vector<vector<int>> graph(n);
    graph[0].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[0].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    cout << "BFS starting from node 0: ";
    bfs(graph, 0);
    cout << endl;
    return 0;
}
