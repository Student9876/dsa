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




// TC -> O(N) + (2E) 
// N for visiting N nodes and 2E explains the summation of total degree of the nodes 
// SC -> O(N) + O(N) + O(N) = O(N) 

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);
    // Traverse all its neighbours 
    fa(it,adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
    // Taking 1 based graph 
    int vis[V+1] = {0};
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}


int main(){
    vector<int> adj[] = {
        {},
        {2,3},
        {1,5,6},
        {1,4,7},
        {3,8},
        {2},
        {2},
        {3,8},
        {4,7}
    };

    vector<int> ls = dfsOfGraph(8,adj);
    fa(it,ls) cout<<it<<" ";
    return 0;
}