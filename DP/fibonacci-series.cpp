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




// Memoization Approach 
// Uses O(N) Stack space and O(N) additional memory to store the computed Data 
ll findFibonacci(ll n, ll dp[]){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = findFibonacci(n-1, dp) + findFibonacci(n - 2, dp);
}




int main(){
    ll n;cin>>n;
    // ll dp[n+1];
    // memset(dp, -1, sizeof(dp));
    // cout<< findFibonacci(n, dp);



    // Tabulation Method 
    // Just uses O(N) TC and O(N) Space 
    // ll n;cin>>n;
    // ll dp[n+1];
    // dp[0] = 0;
    // dp[1] = 1;

    // f(i,2,n+1){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout<<dp[n];

    // in SC O(1)
    int prev2 = 0, prev1 = 1;
    f(i,2,n+1){
        int curri = prev1 + prev2;
        prev2 = prev1;
        prev1 = curri;
    }
    cout<<prev1;

    return 0;
}