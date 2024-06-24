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
    https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
    Shortest path in undirected graph having unit distance

    Intuition:
    We can use BFS algorithm to find the shortest path in the undirected graph.
    We will start from the source node and keep on updating the distance of the nodes from the source node.
    We will use a queue to keep track of the nodes to be visited.
    TC -> O(V + 2E) -> O(V + E) where V is the number of vertices and E is the number of edges. As any other BFS algorithm.
*/


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> dist(N, 1e9);
        
        vector<int> adj[N];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // BFS algorithm 
        // O(V + 2E)
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};


int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
    return 0;
}


 /* 
Example Testcase:

9 10
0 1
0 3 
3 4 
4 5 
5 6 
1 2 
2 6 
6 7 
7 8 
6 8 
0

Output:
0 1 2 1 2 3 3 4 4

 */
