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

*/

// Tabulation 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int s = 0;
    for(auto i:arr) s+=i;
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
    int mn = INT_MAX;
    for(int j = 0;j<=s;j++){
        if(dp[n-1][j]) mn = min(mn, abs(j - (s - j)));
    }
    return mn;
}




int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}