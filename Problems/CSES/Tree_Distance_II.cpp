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


const int sz = 200005;
vector<ll> adj[sz];
vector<ll> S(sz);
vector<ll> in(sz), out(sz);
int n;

void dfs_in(int node, int par){
    S[node] = 1;
    for(auto child: adj[node]){
        if(child!=par){
            dfs_in(child, node);
            S[node] += S[child];
            in[node] += in[child] + S[child];
        }
    }
}

void dfs_out(int node, int par){
    int store = 0;
    for(auto child: adj[node]){
        if(child!=par){
            store += in[child] + S[child]*2;
        }
    }

    for(auto child: adj[node]){
        if(child!=par){
            out[child] = (out[node] + 1* (n - S[node] + 1)) + (store  - (in[child] + S[child]*2));
            dfs_out(child, node);
        }
    }
}



int main(){
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_in(1, 0);
    dfs_out(1, 0);

    for(int i = 1;i<=n;i++){
        cout<<in[i] + out[i]<<" ";
    }nl;

    return 0;
}