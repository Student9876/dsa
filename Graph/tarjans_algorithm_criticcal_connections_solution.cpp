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
    https://leetcode.com/problems/critical-connections-in-a-network/description/

    Space complexity 
    O( V + 2E ) + O(3N)
    Time Complexity
    O(V+2E)
*/


class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[],
    int tin[], int low[], vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]);

                if(low[it] >  tin[node]){
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}