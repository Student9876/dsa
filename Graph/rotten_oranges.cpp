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


// https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;
        int delRow[] = {0,0,1,-1};
        int delCol[] = {1,-1,0,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);
            for(int i=0;i<4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >=0 and nrow <n and ncol >=0 and ncol < m and 
                grid[nrow][ncol] == 1 and vis[nrow][ncol] != 2){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 and grid[i][j] == 1) return -1;
            }
        }
        return tm;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}