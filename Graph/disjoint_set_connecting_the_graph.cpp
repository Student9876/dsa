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
    https://leetcode.com/problems/number-of-operations-to-make-network-connected/
    https://www.geeksforgeeks.org/problems/connecting-the-graph/1

    Time Complexity: 
        for union by size or rank O(4 (alpha)) == O(1) almost
        same for the whole code
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
public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        int m = edge.size();
        int requiredEdges = 0;
        DisjointSet s1(n);
        
        for(auto &it:edge){
            int u = it[0];
            int v = it[1];
             if(s1.findUPar(u) == s1.findUPar(v)){
                requiredEdges++;
            } else {
                s1.unionByRank(u,v);
            }
        }
        int ct = 0;
        for(int i = 0;i<n;i++){
            if(s1.parent[i] == i) ct++;
        }
        ct--;
        
        if(requiredEdges >= ct) return ct;
        else return -1;
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}