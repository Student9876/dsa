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
    https://atcoder.jp/contests/dp/tasks/dp_b

*/


// Recursion (TLE)
int frogJump2(vector<int> &heights, int n, int k){
    if(n==0) return 0;
    int mn = INT_MAX;
    f(i,1,k+1){
        if(n-i < 0) break;
        mn = min(mn, frogJump2(heights, n-i, k) + abs(heights[n] - heights[n-i]));
    }
    return mn;
}

// Memoization 
// TC -> O(N*K) 
// SC -> O(N)
int frogJump2Memo(vector<int>& heights, int n, int k, vector<int> &dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int mn = INT_MAX;
    f(i,1,k+1){
        if(n-i < 0) break;
        mn = min(mn,  (frogJump2Memo(heights, n-i, k, dp) + abs(heights[n] - heights[n-i])));
    }
    return dp[n] = mn;
}

// Tabulation 
// TC -> O(N*K) 
// SC -> O(N)
int frogJump2Tab(vector<int> &heights, int n, int k, vector<int> &dp){
    dp[0] = 0;
    f(i,1,n){
        int jump = INT_MAX;
        f(j,1,k+1){
            if(i - j < 0) break;
            jump = min(jump, dp[i-j] + abs(heights[i] - heights[i-j]));
        }
        dp[i] = jump;
    }
    return dp[n-1];
}


int main(){
    int n, k;cin>>n>>k;
    vector<int> heights(n);
    f(i,0,n) cin>>heights[i];
    // cout<<frogJump2(heights, n-1, k);

    vector<int> dp(n, -1);
    // dp[n-1] = frogJump2Memo(heights, n-1, k, dp);
    cout<<frogJump2Tab(heights, n, k, dp);

    return 0;
}