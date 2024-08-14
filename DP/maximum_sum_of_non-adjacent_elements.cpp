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



// Recursion (TLE)
// int helper(vector<int> &nums, int idx){
//     if(idx >= nums.size()){
//         return 0;
//     }
//     int c1 = nums[idx] + helper(nums, idx + 2);
//     int c2 = 0 + helper(nums, idx + 1);
//     return max(c1, c2);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int ans = helper(nums, 0);
//     return ans;
// }

// // Memoization 
// int helper(vector<int> &nums, int idx, vector<int> &dp){
//     if(idx >= nums.size()){
//         return 0;
//     }
//     if(dp[idx] != -1) return dp[idx];
//     int c1 = nums[idx] + helper(nums, idx + 2, dp);
//     int c2 = 0 + helper(nums, idx + 1, dp);
//     return dp[idx] = max(c1, c2);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     vector<int> dp(nums.size(), -1);
//     int ans = helper(nums, 0, dp);
//     return ans;
// }

// Tabulation 
// void helper(vector<int> &nums, vector<int> &dp){
//     dp[0] = nums[0];
//     f(i,1,nums.size()){
//         int c1 = nums[i];
//         if(i>1)
//             c1 += dp[i-2];
//         int c2 = dp[i-1];
//         dp[i] = max(c1, c2);
//     }
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     vector<int> dp(nums.size(), 0);
//     helper(nums, dp);
//     return dp[dp.size()-1];
// }

// Space optimized 
int maximumNonAdjacentSum(vector<int> &nums){
    int prev2, prev, curr;
    prev = nums[0];
    prev2 = 0;
    f(i,1,nums.size()){
        int pick = nums[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}



int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<int> nums(n);
        f(i,0,n) cin>>nums[i];
        cout<<maximumNonAdjacentSum(nums);
        nl;
    }
    return 0;
}