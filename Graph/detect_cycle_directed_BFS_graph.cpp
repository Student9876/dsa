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




 // Using Kahn's Algorithm (Topological sort)
//  BFS Algorithm
/*
    Intuition:
        If we try to make a topological sort of a directed graph, and there contains a cycle
        then the topological sort will not contain all the nodes.

        So we have to check just the number of elements in the topological sort result.
*/

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indeg(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]) indeg[it]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i] == 0) q.push(i);
        }
        
        int ct=0;
        
        while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        ct++;
	        
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it] == 0) q.push(it);
	        }
	        
	   }
        
        if(ct == V) return false;
        else return true;
    }
};

int main(){
    int T;cin>>T;
    while(T--){
        
    }
    return 0;
}