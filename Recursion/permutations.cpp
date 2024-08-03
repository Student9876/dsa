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
    https://leetcode.com/problems/permutations/description/

    Solution with extra space
    TC -> O(n! * n)
    SC -> O(n) to store visited numbers + O(n) to store the generated permutations


    Optimal Solution (Using swap method)
    TC -> O(n! * n)
    SC -> No extra space is begin used apart from the recursion stack space 


*/


class Solution {
private:
    void makePermutations(vector<int> &nums, int idx, 
    vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i<nums.size();i++){
            swap(nums[idx], nums[i]);
            makePermutations(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        makePermutations(nums, 0, ans);
        return ans;
    }
};

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}