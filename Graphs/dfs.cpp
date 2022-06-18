#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int i, vector<int>adj[], int V, vector<int>&ans, vector<int>&vis){
        vis[i]=1;
        ans.push_back(i);
        for(int k = 0;k<adj[i].size();k++){
            if(!vis[adj[i][k]]){
                dfs(adj[i][k], adj, V, ans, vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<int>vis(V,0);
        dfs(0, adj, V, ans, vis);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

Time Complexity - O(V+E)
Space Complexity - O(V)