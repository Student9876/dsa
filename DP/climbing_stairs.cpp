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
    https://leetcode.com/problems/climbing-stairs/description/
    
*/

// Recursion (TLE)
class Solution1 {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int c1 = climbStairs(n-1);
        int c2 = climbStairs(n-2);
        return c1 + c2;
    }
};



// Memoization 
class Solution2 {
    int helper(int n, vector<int> & dp){
        if(n == 0) return dp[0] = 1;
        if(n == 1) return dp[1] = 1;
        if(dp[n-1] == -1)
            dp[n-1] = helper(n-1, dp);
        if(dp[n-2] == -1)
            dp[n-2] = helper(n-2, dp);
        return dp[n-1] + dp[n-2];
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[n] = helper(n, dp);
        return dp[n];
    }
};

// Tabulation 
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}