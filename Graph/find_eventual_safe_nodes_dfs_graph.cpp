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
Intuition 
in any node is a part of cycle or it leads to a cycle,
    then it cannot be a a safenode / part of the safenode/
    Safenode is a node which leads to a termnal no with all its available paths
*/

// https://www.geeksforgeeks.org/problems/eventual-safe-states/1


class Solution {
    private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto adjacent:adj[node]){
            if(!vis[adjacent]){
                // if the node not visited
                if(dfs(adjacent, adj, vis, pathVis, check) == true) {
                    // if this call has a cycle, this cannot be a part of safe node 
                    check[node] = 0;
                    return true;
                }
            } else if(pathVis[adjacent]){
                // if the node visited, it has to be visited in the same path 
                    // if this call has a cycle, this cannot be a part of safe node 
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
         int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathVis, check);
            }
        }
        for(int i = 0;i<V;i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};



// https://leetcode.com/problems/find-eventual-safe-states/description/

class Solution1 {
    private:
        bool dfs(int node, vector<vector<int>> &graph, int vis[], int pathVis[], int check[]){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto adjacent:graph[node]){
            if(!vis[adjacent]){
                // if the node not visited
                if(dfs(adjacent, graph, vis, pathVis, check) == true) {
                    // if this call has a cycle, this cannot be a part of safe node 
                    check[node] = 0;
                    return true;
                }
            } else if(pathVis[adjacent]){
                // if the node visited, it has to be visited in the same path 
                    // if this call has a cycle, this cannot be a part of safe node 
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int V = graph.size();
        int vis[V];
        int pathVis[V];
        int check[V];
        for(int i = 0;i<V;i++){
            vis[i] = 0;
            pathVis[i] = 0;
            check[i] = 0;
        }
        vector<int> safeNodes;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, check);
            }
        }
        for(int i = 0;i<V;i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}