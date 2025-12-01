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


// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/0


class Solution {
    private:
        bool detect(int src, vector<int> adj[], int vis[]){
            vis[src] = 1;
            queue<pair<int, int>> q;
            q.push({src, -1});
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto adjacentNode:adj[node]){
                    if(!vis[adjacentNode]){
                        vis[adjacentNode] = 1;
                        q.push({adjacentNode, node});
                    } else if(parent != adjacentNode){
                        return true;
                    }
                }
            }
        }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};



class Solution1 {
  public:
    bool detect(int src, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i = 0;i<V;i++){
            if(!vis[i])
                if(detect(i, adj, vis)) return true;
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