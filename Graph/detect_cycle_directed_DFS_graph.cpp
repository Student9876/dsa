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



// We need to visit a already visited node in the same path 
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        
        for(auto adjacent:adj[node]){
            if(!vis[adjacent]){
                // if the node not visited
                if(dfs(adjacent, adj, vis, pathVis) == true) return true;
            } else if(pathVis[adjacent]){
                // if the node visited, it has to be visited in the same path 
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true) return true;
            }
        }
        return false;
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}