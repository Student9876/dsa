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

int countSetBits(int u){unsigned int uCount;uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);return ((uCount + (uCount >> 3)) & 030707070707) % 63;}

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
    https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

*/


// Memoization Approach 
bool helper(int i, int target, vector<int> &arr, vector<vector<int>>&dp){
    if(target == 0) return true;
    if(i == 0) return (arr[i] == target);
    if(dp[i][target] != -1) return dp[i][target];
    bool notTake = helper(i - 1, target, arr, dp);
    bool take = false;
    if(arr[i] <= target) take = helper(i-1, target - arr[i], arr, dp);

    return dp[i][target] = take or notTake;
}

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     int sz = 1e3 + 1;
//     vector<vector<int>> dp(sz, vector<int>(sz, -1));
//     return helper(n-1, k, arr, dp);
// }


// Tabulation Approach
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }   
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
              take = dp[i - 1][j - arr[i]];
            dp[i][j] = notTake or take;
        }
    }
    return dp[n-1][k];
}

// Space Optimized Tabulation Approach 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false), cur(k+1, false);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
              take = prev[j - arr[i]];
            cur[j] = notTake or take;
        }
        prev = cur;
    }
    return prev[k];
}




int main(){
    int T;cin>>T;
    while(T--){
        
    }
    return 0;
}