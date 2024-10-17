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
    https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

    s1 - s2 = d
    total - 2*s2 = d;
    s2 = (total - d)/2;
*/


// Memoization 
// int helper(int i, vector<int> &arr, int target, vector<vector<int>> &dp){
//     if(i == 0){
//         if(target == 0 and arr[i] == 0) return 2;
//         if(target == 0 or target == arr[i]) return 1;
//         else return 0;
//     } 
//     if(dp[i][target] != -1) return dp[i][target];
//     int exclude = helper(i - 1, arr, target, dp);
//     int include = 0;
//     if(target >= arr[i]) include = helper(i - 1, arr, target - arr[i], dp);
//     return dp[i][target] = (include + exclude)%MOD;
// }


// int countPartitions(int n, int d, vector<int>& arr) {
//     int total = 0;
//     for(int i = 0; i < n; i++) total += arr[i];
//     int s2 = (total - d)/2;
//     if(total - d < 0 or (total - d)%2) return 0;
//     vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
//     return helper(n-1, arr, s2, dp);
// }


// Tabulation 
int countPartitions(int n, int d, vector<int>& arr) {
    int total = 0;
    for(int i = 0; i < n; i++) total += arr[i];
    int s2 = (total - d)/2;
    if(total - d < 0 or (total - d)%2) return 0;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 and arr[0] <= s2) dp[0][arr[0]] = 1;

    for(int i = 1;i<n;i++){
        for(int j = 0;j<=s2;j++){
            int exclude = dp[i - 1][j];
            int include = 0;
            if(j >= arr[i]) include = dp[i - 1][j - arr[i]];
            dp[i][j] = (include + exclude)%MOD;
        }
    }
    return dp[n-1][s2];
}


int main(){
    int n, d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<countPartitions(n, d, arr);
    return 0;
}