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
    https://www.geeksforgeeks.org/problems/eventual-safe-states/1
    Eventual Safe States

    Intuition
    Using topological sort algorithm 
    We have to reverse the adj list first
    Then we've applied the topo sort algorithm
    so basically in the reversed graph, if we can ommit all the incoming edges, then we 
    are actually the outgoing edges. So it becomes a safe node.
    
*/




class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> indeg(V, 0);
        vector<int> adjReverse[V];
        vector<int> res;
        queue<int> q;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjReverse[it].push_back(i);
                indeg[i]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it:adjReverse[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};


int main(){
    int T;cin>>T;
    
    return 0;
}