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


// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
// https://leetcode.com/problems/flood-fill/

class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor, int delRow[], int delCol[], int initColor){
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if(nrow < n and nrow >= 0 and ncol < m and ncol >=0 and image[nrow][ncol] == initColor and ans[nrow][ncol] != newColor)
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, initColor);
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,1,0,0};
        int delCol[] = {0,0,-1,1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, initColor);
        return ans;
    }
};




int main(){
    
    return 0;
}