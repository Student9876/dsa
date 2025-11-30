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
	// https://www.geeksforgeeks.org/problems/bipartite-graph/1
	TC - O(V + E)
	SC - O(V)
	Where V is the number of vertices and E is the number of edges in the graph.
	We can use BFS to color the graph in two colors and check if any adjacent nodes have the same color.
*/

class Solution {
    private:
        bool check(int start, vector<int> adj[],  vector<int> &vis){
            queue<int> q;
	        q.push(start);
	        vis[start] = 0;
	    
	        while(!q.empty()){
	            int node = q.front();
	            q.pop();
	        
	            for(auto adjacent:adj[node]){
	                if(vis[adjacent] == -1){
	                    vis[adjacent] = !vis[node];
	                    q.push(adjacent);
	                } else if(vis[adjacent] == vis[node]){
	                    // checking if the adjacent one has the same color as this node 
	                    return false;
	                }
	            }
	        }
	        return true;
        }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis (V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(vis[i] == -1){
	            if(check(i, adj, vis) == false) return false;
	        }
	    }
	    return true;
	}
};



// https://leetcode.com/problems/is-graph-bipartite/description/

class Solution1 {
    private:
        bool check(int start, vector<vector<int>>& graph, vector<int>& vis){
            queue<int> q;
	        q.push(start);
	        vis[start] = 0;
	    
	        while(!q.empty()){
	            int node = q.front();
	            q.pop();
	        
	            for(int i=0;i<graph[node].size();i++){
	                if(vis[graph[node][i]] == -1){
	                    vis[graph[node][i]] = !vis[node];
	                    q.push(graph[node][i]);
	                } else if(vis[graph[node][i]] == vis[node]){
	                    // checking if the adjacent one has the same color as this node 
	                    return false;
	                }
	            }
	        }
	        return true;
        }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int n = graph.size();
        vector<int> vis(n,-1);        
        for(int i = 0;i<n;i++){
            if(vis[i] == -1){
                if(check(i, graph, vis) == false) return false;
            }
        }
        return true;
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}