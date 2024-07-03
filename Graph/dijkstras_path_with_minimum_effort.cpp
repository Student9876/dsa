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
    https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1
    https://leetcode.com/problems/path-with-minimum-effort/description/

    Time complexity: (E log V)
    E = number of edges = n*m*4
    V = number of vertices = n*m
*/



class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        // Creating a min heap
        // {diff, {row, col}} 
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        
        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 and col == m-1) return diff;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
        
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}