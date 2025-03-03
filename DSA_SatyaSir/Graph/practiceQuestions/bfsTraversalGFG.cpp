https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &graph) {
        // Code here
        int n = graph.size();
        vector<int> bfsarray;
        queue<int>q;
        vector<bool>visited(n+1,false);
        q.push(0);
        bfsarray.push_back(0);
        visited[0] = true;
        while(q.size()>0){
            int curr = q.front();
            q.pop();
            for(int i = 0;i<graph[curr].size();i++){
                int adj = graph[curr][i];
                if(visited[adj] == false){
                    visited[adj] = true;
                    q.push(adj);
                    bfsarray.push_back(adj);
                }
            }
        }
        return bfsarray;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
