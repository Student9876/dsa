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
    https://www.naukri.com/code360/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
*/


// Space optimized
long long int maximumNonAdjacentSum(vector<int> &nums){
    long long int prev2, prev, curr;
    prev = nums[0];
    prev2 = 0;
    for(int i = 1;i<nums.size(); i++){
        long long int pick = nums[i];
        if(i>1)
            pick += prev2;
        long long int nonPick = 0 + prev;
        long long int curr = max(pick, nonPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


long long int houseRobber(vector<int>& valueInHouse){
    if(valueInHouse.size() == 1) return valueInHouse[0];
    vector<int> nums1(valueInHouse.begin(), valueInHouse.end() - 1);
    vector<int> nums2(valueInHouse.begin() + 1, valueInHouse.end());
    long long int ans1 = maximumNonAdjacentSum(nums1);
    long long int ans2 = maximumNonAdjacentSum(nums2);
    return max(ans1, ans2);
}



int main(){
    int T;cin>>T;
    while(T--){
        int n;;cin>>n;
        vector<int> valueInHouse(n);
        f(i,0,n) cin>>valueInHouse[i];
        cout<<houseRobber(valueInHouse);nl
    }
    return 0;
}