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
    https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

*/

// Meemoization 
// int helper(int i, int target, int arr[], vector<vector<int>> &dp){
//     if(i == 0){
//         if(target == 0 and arr[i] == 0) return 2;
//         if(target == 0 or target == arr[i]) return 1;
//         else return 0;
//     } 
   
//     if(dp[i][target] != -1) return dp[i][target];
   
//     int exclude = helper(i - 1, target, arr, dp);
//     int include = 0;
//     if(target >= arr[i]) include = helper(i - 1, target - arr[i], arr, dp);
//     return dp[i][target] = (include + exclude)%MOD;
// }

// int perfectSum(int arr[], int n, int sum){
// 	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
//     int count = helper(n-1, sum, arr, dp);
//     return count%MOD;
// }


// Tabulation 
int perfectSum(int arr[], int n, int sum){
	vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
     if (arr[0] == 0) {
        dp[0][0] = 2; // Two ways to form 0 when arr[0] is 0: include or exclude
    } else {
        dp[0][0] = 1; // One way to form 0 by excluding arr[0]
    }
    
    if (arr[0] != 0 && arr[0] <= sum) {
        dp[0][arr[0]] = 1; // One way to form arr[0] by including it
    }
    
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= sum; target++) {
            int exclude = dp[i - 1][target];
            int include = 0;
            if (target >= arr[i]) {
                include = dp[i - 1][target - arr[i]];
            }
            
            dp[i][target] = (include + exclude) % MOD;
        }
    }
    return dp[n - 1][sum];
}



int main(){
    int n, sum;cin>>n>>sum;
    vector<int> arr(n);
    f(i,0,n) cin>>arr[i];
    cout<<perfectSum(arr.data(), n, sum);
    return 0;
}