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
    https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
    Bellman Ford Algorithm to find shortest path from source to all vertices
    
    O(V x E) time complexity
*/

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 0;i < V - 1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int edgeWeight = it[2];
                if(dist[u] != 1e8 and dist[u] + edgeWeight < dist[v]){
                    dist[v] = dist[u] + edgeWeight;
                }
            }
        }
        
        for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int edgeWeight = it[2];
                if(dist[u] != 1e8 and dist[u] + edgeWeight < dist[v]){
                    return {-1};
                }
            }
        return dist;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}