// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public: 
    vector<string>v;
    void maze(vector<vector<int>>m, int n, string s, int i, int j, string d){
        if(i < 0 || i>=n ||  j < 0 || j >= n || m[i][j] == 0 || m[i][j]==-1)
        return;
        s+=d;
        if(i== n-1 && j== n-1){
            v.push_back(s);
            return;
        }
        m[i][j] = -1;
        maze(m, n, s, i-1, j, "U");
        maze(m, n, s, i, j+1, "R");
        maze(m, n, s, i+1, j, "D");
        maze(m, n, s, i, j-1, "L");
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        maze(m ,n, s, 0, 0, "");
        sort(v.begin(), v.end());
        return v;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends

Time Complexity - O(3^N^2)
Space Complexity - O(Length of Path * Number of Paths)