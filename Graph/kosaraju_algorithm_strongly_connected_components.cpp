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
    https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
    Segmentation fault 
*/



class Solution
{
    private:
        void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis){
            vis[node] = 1;
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, st, vis);
                }
            }
            st.push(node);
        }
        void dfs_(int node, vector<int> adj[], vector<int> &vis){
            vis[node] = 1;
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    dfs_(it, adj, vis);
                }
            }
        }
 
	public:
        int kosaraju(int V, vector<vector<int>>& adj)
        {
           vector<int> adjL[V];
           stack<int> st;
           vector<int> vis(V,0);
           for(auto it:adj){
               adjL[it[0]].push_back(it[1]);
           }
           
           for(int i = 0;i<V;i++){
               if(!vis[i]){
                   dfs(i, adjL, st, vis);
               }
           }
           
           vector<int> adjT[V];
           for(int i = 0;i<V;i++){
               vis[i] = 0;
               for(auto it:adjL[i]){
                   adjT[it].push_back(i);
               }
           }
           int ans = 0;
           while(!st.empty()){
               int node = st.top();
               st.pop();
               
               if(!vis[node]){
                   dfs_(node, adjT, vis);
               }
           }
           
           return ans;
           
        }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}