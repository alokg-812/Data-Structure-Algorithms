#include <bits/stdc++.h>
using namespace std;

bool bfs(int nodes, int edges, vector<int> graph[], int source, int destination) {
    queue<int> q;
    vector<bool> visited(nodes + 1, false);
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        if(curr == destination){
            return true; // Path exists
        }
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false; // No path found
}

int main() {
    int nodes = 6, edges = 7;
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

    bool result = bfs(nodes, edges, graph, source, destination);
    cout << (result ? "Path exists" : "No path") << endl;

    return 0;
}
