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
    https://cses.fi/problemset/task/1131/
    Tree Diameter
    
    Intuition

    One easy to implement solution is using 2 Breadth First Searches (BFS). 
    Start a BFS with a random node and store the last node encountered before search ends. 
    This last node will definitely be one of the ends of the diameter. 
    Now run a second BFS from this node and you will end on the other end of the diameter.
*/




const int sz = 200005;
vector<int> adj[sz];

pair<int, int> bfs(int node){
    queue<pair<int, int>> q;
    q.push({node, 0});
    pair<int, int> p;
    vector<int> vis(sz, 0);

    while(!q.empty()){
        p = q.front();
        q.pop();
        vis[p.first] = 1;
        fa(i, adj[p.first]){
            if(vis[i] == 0){
                q.push({i, p.second+1});
            }
        }
    }
    return p;
}


int main(){
    int n;cin>>n;
    f(i,0,n-1){
        int x, y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pair<int,int>  end1 = bfs(1);
	pair<int,int>  end2 = bfs(end1.first);
    cout<<end2.second;nl;
    return 0;
}