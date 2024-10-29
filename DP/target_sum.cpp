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




// Memoization 
// int total;
// int helper(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
//     if(i < 0) {
//         return (target == 0) ? 1 : 0;
//     }
//     if (target + total < 0 || target + total >= dp[0].size()) {
//         return 0;
//     }
//     if(dp[i][total + target] != INT_MIN) return dp[i][total + target];
//     int sub = helper(i - 1, target + nums[i], nums, dp);
//     int add = helper(i - 1, target - nums[i], nums, dp);
//     return dp[i][total + target] = sub + add;
// }
// int findTargetSumWays(vector<int>& nums, int target) {
//     int n = nums.size();
//     total = accumulate(nums.begin(),nums.end(), 0);
//     cout << total <<endl;
//     vector<vector<int>> dp(n, vector<int>(2*total + 1, INT_MIN));
//     int ans = helper(n-1, target, nums, dp);
//     return ans;
// }

// Tabulation 
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > total) return 0;
    vector<vector<int>> dp(n, vector<int>(2 * total + 1, 0));
    dp[0][total + nums[0]] += 1;
    dp[0][total - nums[0]] += 1;
    for (int i = 1; i < n; ++i) {
        for (int sum = -total; sum <= total; ++sum) {
            int current = total + sum;
            if (dp[i - 1][current] > 0) {
                dp[i][current + nums[i]] += dp[i - 1][current];
                dp[i][current - nums[i]] += dp[i - 1][current];
            }
        }
    }
    return dp[n - 1][total + target];
}

// Space optimized 
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > total) return 0;
    vector<int> prev(2 * total + 1, 0), cur(2 * total + 1, 0);
    prev[total + nums[0]] = 1;
    prev[total - nums[0]] = 1;
    for (int i = 1; i < n; ++i) {
        for (int sum = -total; sum <= total; ++sum) {
            int current = total + sum;
            if (prev[current] > 0) {
                cur[current + nums[i]] += prev[current];
                cur[current - nums[i]] += prev[current];
            }
        }
        prev = cur;
    }
    return prev[total + target];
}




int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}