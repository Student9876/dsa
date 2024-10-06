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
    https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
    https://leetcode.com/problems/partition-equal-subset-sum/
*/



// Recursion 
// bool helper(int i, int sum, vector<int> &arr){
// 	if(sum == 0) return true;
// 	if(i == 0) return arr[0] == sum;
//     bool notTake = helper(i-1,sum,arr);
//     bool take = false;
//     if(arr[i] <= sum) {
//         take = helper(i-1,sum-arr[i],arr);
//     }
//     return notTake or take;
// }

// bool canPartition(vector<int> &arr, int n){
//     int s = 0;
//     for(auto i:arr) s+=i;
//     if(s%2) return false;
//     s = s/2;
//     return helper(0,s,arr);
// }


// Memoization 
// bool helper(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
// 	if(sum == 0) return true;
// 	if(i == 0) return sum == arr[0];
//     if(dp[i][sum] != -1) return dp[i][sum];
//     bool notTake = helper(i-1,sum,arr, dp);
//     bool take = false;
//     if(arr[i] <= sum) {
//         take = helper(i-1,sum-arr[i],arr, dp);
//     }
//     return dp[i][sum] = notTake or take;
// }

// bool canPartition(vector<int> &arr, int n){
//     int s = 0;
//     for(auto i:arr) s+=i;
//     if(s%2) return false;
//     s = s/2;
//     vector<vector<int>> dp(n,vector<int>(s+1,-1));
//     return helper(n-1,s,arr, dp);
//     return dp[n-1][s] == 1;
// }


// Tabulation 
bool canPartition(vector<int> &arr, int n){
    int s = 0;
    for(auto i:arr) s+=i;
    if(s%2) return false;
    s = s/2;
    vector<vector<bool>> dp(n,vector<bool>(s+1,false));
    for(int i = 0;i < n;i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=s;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j) {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = notTake or take;
        }
    }
    return dp[n-1][s];
}



int main(){
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        vector<int> arr(n);
        f(i,0,n) cin>>arr[i];
        cout<<canPartition(arr,n);nl;
    }
    return 0;
}