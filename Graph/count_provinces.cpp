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


// Extension of DFS 
void dfs(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    fa(it,adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
}

int countNumberOfProvinces(int V, vector<vector<int>> adj){
    // adjacency matrix is given 
    // convert is to adjacency list 
    vector<int> adj_list[V+1];
    f(i,1,V+1){
        f(j,1,V+1){
            if(adj[i][j] == 1 and i!=j){
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }
    int t=0;
    fa(i,adj_list){
        cout<<t<<": ";
        fa(j,i) cout<<j<<" ";
        nl;
        t++;
    }

    int vis[V+1] = {0};
    vis[0] = 1;
    int ct=0;
    f(i,1,V+1){
        if(!vis[i]){
            ct++;
            dfs(i, adj_list, vis);
        }
    }
    return ct;

}


int main(){
    vector<vector<int>> adj = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0 },
        {0, 0, 1, 0, 0, 0, 0, 0, 0 },
        {0, 1, 0, 1, 0, 0, 0, 0, 0 },
        {0, 0, 1, 0, 0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0, 1, 0, 0, 0 },
        {0, 0, 0, 0, 1, 0, 1, 0, 0 },
        {0, 0, 0, 0, 0, 1, 0, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 0, 1 },
        {0, 0, 0, 0, 0, 0, 0, 1, 0 }
    };

    int ct = countNumberOfProvinces(8, adj);
    cout<<"Number of provinces: "<<ct;
    return 0;
}