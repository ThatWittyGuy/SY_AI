#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    int g, h;
    Node* parent;
    bool operator>(const Node& other) const {
        return (g + h) > (other.g + other.h);
    }
};

vector<pair<int, int>> getNeighbors(int x, int y) {
    return {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, int rows, int cols, const vector<vector<int>>& grid) {
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
}

void printPath(Node* node) {
    if (node) {
        printPath(node->parent);
        cout << "(" << node->x << ", " << node->y << ") ";
    }
}

void aoStar(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<int, unordered_map<int, int>> gCost;
    unordered_map<int, unordered_map<int, bool>> closedSet;
    Node* startNode = new Node{start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second), nullptr};
    openSet.push(*startNode);
    gCost[start.first][start.second] = 0;

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goal.first && current.y == goal.second) {
            cout << "Path: ";
            printPath(&current);
            cout << endl;
            return;
        }

        closedSet[current.x][current.y] = true;

        for (auto& neighbor : getNeighbors(current.x, current.y)) {
            int nx = neighbor.first;
            int ny = neighbor.second;

            if (!isValid(nx, ny, rows, cols, grid) || closedSet[nx][ny]) {
                continue;
            }

            int tentativeG = current.g + 1;

            if (tentativeG < gCost[nx][ny] || gCost[nx][ny] == 0) {
                Node* neighborNode = new Node{nx, ny, tentativeG, heuristic(nx, ny, goal.first, goal.second), new Node(current)};
                gCost[nx][ny] = tentativeG;
                openSet.push(*neighborNode);
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {5, 5};
    aoStar(grid, start, goal);
    return 0;
}
