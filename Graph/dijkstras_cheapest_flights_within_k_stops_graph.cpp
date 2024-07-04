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
    https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
    https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

    
*/



class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int, int>> adj[n];
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        // {stops, {source, distance}} 
        q.push({0, {src, 0}});
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second; 
            
            if(stops > K) continue;
            for(auto iter: adj[node]){
                int adjNode = iter.first;
                int edgeWeight = iter.second;
                
                if(cost + edgeWeight < dist[adjNode] and stops <= K){
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
            
        }
        
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}