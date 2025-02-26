#include <bits/stdc++.h>
using namespace std;

int bfs_shortest_path(int nodes, vector<int> graph[], int source, int destination) {
    queue<pair<int, int>> q;  // (current node, current distance)
    vector<bool> visited(nodes + 1, false);

    q.push({source, 0});
    visited[source] = true;

    while (!q.empty()) {
        auto [curr, dist] = q.front();
        q.pop();

        if (curr == destination) {
            return dist; // Found the shortest path
        }

        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }

    return -1; // No path found
}

int main() {
    int nodes = 6;
    int source = 1, destination = 6;
    vector<int> graph[nodes + 1];

    graph[1].push_back(2);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[2].push_back(4);
    graph[3].push_back(2);
    graph[3].push_back(5);
    graph[4].push_back(1);
    graph[4].push_back(2);
    graph[4].push_back(5);
    graph[5].push_back(3);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[6].push_back(5);

    int shortest_distance = bfs_shortest_path(nodes, graph, source, destination);
    
    if (shortest_distance != -1) {
        cout << "Shortest Path Length: " << shortest_distance << endl;
    } else {
        cout << "No path exists" << endl;
    }

    return 0;
}
