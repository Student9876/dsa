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


// TC -> O(V + E) = O(V) + O(2E)
// SC -> O(3N)
vector<int> bfsOfGraph(int V, vector<int> adj[]){
    int vis[V+1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        fa(it,adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}


int main(){
    // adjacency list used to store graph 
    // adjacency matrix used to store weighted graph
    vector<int> adj[] = {
        {1},
        {2,6},
        {1,3,4},
        {2},
        {2,5},
        {4,8},
        {1,7,9},
        {6,8},
        {5,7},
        {6}
    };

    vector<int> bfs = bfsOfGraph(9,adj);
    fa(i,bfs){
        cout<<i<<" ";
    }

    // ans 1 2 6 3 4 7 9 5 8
    return 0;
}