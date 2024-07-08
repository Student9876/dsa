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
    https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
    Minimum Spanning Tree Prim's Algorithm

    O(E log E + E log E) = O(E log E)

*/


class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        
        vector<int> vis(V, 0);
        // {wt, node} 
        pq.push({0, 0});
        int sum = 0;
        // E
        while(!pq.empty()){
            // log E
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            // E log  E
            for(auto iter: adj[node]){
                int u = iter[0];
                int edW = iter[1];
                
                if(!vis[u]){
                    pq.push({edW, u});
                }
            }
            
        }
        return sum;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}