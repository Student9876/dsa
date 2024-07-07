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
    https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
    https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
    
*/

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        for(int i = 0;i<n;i++) dist[i][i] = 0;
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            dist[u][v] = wt;
            dist[v][u] = wt;
        }
        
        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int mn = -1, mx = n;
        for(int i = 0;i<n;i++){
            int ct = 0;
            for(int j = 0; j<n;j++){
                if(dist[i][j] != 1e9 and dist[i][j] <= distanceThreshold) ct++;
            }
            
            if(ct <= mx){
                mn = i;
                mx = ct;
            }
        }
        return mn;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}