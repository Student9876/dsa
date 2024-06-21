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
    https://www.geeksforgeeks.org/problems/course-schedule/1
    https://leetcode.com/problems/course-schedule-ii/description/

    This solution is based on Topological Sort Algorithm
*/

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
         vector<int> adj[N];
	    
	    for(auto it:prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    vector<int> indeg(N,0);
	    
	    for(int i=0;i<N;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<N;i++){
	        if(indeg[i] == 0) q.push(i);
	    }
	    vector<int> res;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        res.push_back(node);
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it] == 0) q.push(it);
	        }
	    }
	    
	    if(res.size() == N) return res;
	    else return {};
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}