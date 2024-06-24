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
    https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
    Shortest path in directed acyclic graph

    First we find a topological sort of the graph nodes.
    Then we take nodes from the first (i.e. here stack top)  and relax the edges.
    Extra check if distane for a node is not updated then we set it to -1.
*/

class Solution {
    private:
        void dfs(vector<pair<int, int>> adj[], vector<int> &vis, int node, stack<int> &st){
            vis[node] = 1;
            
            for(auto &it:adj[node]){
                if(!vis[it.first]){
                    dfs(adj, vis, it.first, st);
                }
            }
            
            st.push(node);
        }
    public:
        vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
            vector<pair<int, int>> adj[N];
            for(int i=0;i<M;i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
            
                adj[u].push_back({v, wt});
            } 
            // Step 1 Finding the topo sort via DFS method 
            // O(N + E) Dfs algorithm 
            stack<int> st;
            vector<int> vis(N, 0);
            
            for(int i=0;i<N;i++){
                if(!vis[i]) dfs(adj, vis, i, st);
            }
            
            // Step 2 Find the distance 
            vector<int> dist(N, 1e9);
            // Initializing the first node from where all the distances will be measured
            dist[0] = 0;
            // O(N + E) Relaxing the edges
            while(!st.empty()){
                int node = st.top();
                st.pop();
            
                for(auto it: adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    
                    
                    // Relaxing the edges 
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
                
            }
            for(int i = 0;i<N;i++){
                if(dist[i] == 1e9) dist[i] = -1;
            }
                
            return dist;
        }
};


int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}