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
    https://www.geeksforgeeks.org/problems/subset-sums2234/1
    Brute Force O(2^n * n) (Using Power set generation)
    Optimal O(2^n) (Using recursion)
*/


class Solution {
    private:
        void helper(vector<int> & arr, int idx, int sum, vector<int> & ans, int n){
            if(idx == n){
                ans.push_back(sum);
                return;
            }
            sum += arr[idx];
            helper(arr, idx + 1, sum, ans, n);
            sum -= arr[idx];
            helper(arr, idx + 1, sum, ans, n);
        }
    public:
        vector<int> subsetSums(vector<int> arr, int n) {
            vector<int> ans;
            helper(arr, 0, 0, ans, n);
            return ans;
        }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}