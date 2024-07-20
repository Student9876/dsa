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
    https://www.geeksforgeeks.org/problems/maximum-connected-group/1
    https://leetcode.com/problems/making-a-large-island/description/

*/



class DisjointSet {
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1, 1);
            for(int i = 0;i<=n;i++) parent[i] = i;
        }
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            } else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};


class Solution {
    private:
        bool isValid(int r, int c, int n){
            return (r >= 0 and r < n and c >= 0 and c < n);
        }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
       
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0) continue;
                for(int k = 0;k<4;k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    
                    if(isValid(nrow, ncol, n) and grid[nrow][ncol] == 1){
                        int nodeNo = i*n + j;
                        int newNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, newNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int k = 0;k<4;k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
                    
                    if(isValid(nrow, ncol, n)){
                        if(grid[nrow][ncol] == 1){
                        components.insert(ds.findUPar(nrow * n + ncol));
                        } 
                    }
                }
                int sz = 0;
                for(auto it:components){
                    sz += ds.size[it];
                }
                mx = max(mx, sz + 1);
            }
        }
        for(int i = 0;i<n*n;i++){
            mx = max(mx, ds.size[ds.findUPar(i)]);
        }
        return mx;
       
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}