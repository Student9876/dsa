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



// https://www.geeksforgeeks.org/problems/topological-sort/1
/*
This only works for DAG
Directed Acyclic Graph.

DFS algorithm
*/
class Solution
{
    private:
        void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
            vis[node] = 1;
            
            for(auto adjacent:adj[node]){
                if(!vis[adjacent]){
                    dfs(adjacent, adj, vis, st);
                }
            }
            st.push(node);
        }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i, adj, vis, st);
	    }
	    
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
	    
	}
};




// Topological sort Algorithm using BFS 
// Kahn's Algorithm 
class Solution1
{
    
public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indeg(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]) indeg[it]++;
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i] == 0) q.push(i);
	    }
	    
	    vector<int> topo;
	   // Someone will always be in the queue because its a directed acyclic graph
	   
	   while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it] == 0) q.push(it);
	        }
	        
	   }
	   return topo;
	    
	}
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}