#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(vector<vector<int>> &edges, int n){
    vector<vector<int>> adjList(n);
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Because it's an undirected graph
    }
    return adjList;
}

void printAdjList(const vector<vector<int>> &adjList) {
    for (int i = 0; i < adjList.size(); i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}
    };
    int n = 6; // Assuming we know the number of vertices (0 to 5)
    vector<vector<int>> adjList = graph(edges, n);
    printAdjList(adjList);
}



//output:
// 0 -> 1 2 
// 1 -> 0
// 2 -> 0
// 3 -> 5 4
// 4 -> 5 3
// 5 -> 3 4 
