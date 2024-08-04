#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(i,m,n) for(ll i=m;i<n;i++)
#define fi(i,m,n) for(ll i=m;i>=n;i--)
#define fa(i,j) for(auto i:j)
#define nl cout<<endl;
#define ump(a,b) unordered_map<a,b>
#define omp(a,b) map<a,b>
const int MOD = 1e9+7;
ll power(ll x, ll y){ll res = 1;while(y>0){if(y&1) res = (res*x);y = y>>1;x = (x*x);}return res;}

class TreeNode{
    public:
        int val;
        TreeNode * left;
        TreeNode * right;
        TreeNode():val(0),left(nullptr),right(nullptr){}
        TreeNode(int val):val(val),left(nullptr),right(nullptr){}
        TreeNode(int val, TreeNode * left, TreeNode * right):val(val),left(left), right(right){}
} typedef TN;


/*
    https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
    https://leetcode.com/problems/flower-planting-with-no-adjacent/description/

    TC -> O(N^M)
    SC -> O(N) to store the color record + O(N) auxiliary stack space
*/

// GFG Solution 
class Solution{
private:
    bool isSafeToColor(int color, int node, vector<int> adj[], vector<int> &vis){
        for(auto it:adj[node]){
            if(vis[it] == color) return false;
        }
        return true;
    }
    bool check(int node, vector<int> adj[], int m, int n, vector<int> &vis){
        if(node == n)
            return true;
        
        for(int i = 1;i<=m;i++){
            if(isSafeToColor(i, node, adj, vis)){
                vis[node] = i;
                if(check(node + 1, adj, m, n, vis) == true)
                    return true;
                vis[node] = 0;
            }
        }
        return false;
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> vis(n, 0);
        vector<int> adj[101];
        for(int i = 0;i<101;i++){
            for(int j = 0;j<101;j++){
                if(graph[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(check(0, adj, m, n, vis) == true) return true;
        return false;
        
    }
};

// Leetcode Solution 
class Solution1 {
private:
    bool isSafeToColor(int color, int node, vector<int> adj[],
        vector<int>& vis) {
        for (auto it : adj[node]) {
            if (vis[it] == color)
                return false;
        }
        return true;
    }
    bool check(int node, vector<int> adj[], int m, int n, 
    vector<int>& vis, vector<int> &ans) {
        if (node == n)
            return true;

        for (int i = 1; i <= m; i++) {
            if (isSafeToColor(i, node, adj, vis)) {
                vis[node] = i;
                ans.push_back(i);
                if (check(node + 1, adj, m, n, vis, ans) == true)
                    return true;
                vis[node] = 0;
                ans.pop_back();
            }
        }
        return false;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n];
        for (auto it : paths) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans;
        vector<int> vis(n, 0);
        check(0, adj, 4, n, vis, ans);
        return ans;
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}