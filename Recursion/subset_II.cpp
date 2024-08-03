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
    https://leetcode.com/problems/subsets-ii/description/
    Brute force
    Using set DS to store the lists.
    O(2^n + 2^n log n (to store in set and make it a list))


    Optimal 
    O(2^n)
*/

// Brute force 
class Solution {
private:
    void helper(vector<int> &nums, int idx, set<vector<int>> &st, 
    vector<int> &ds){
        if(idx == nums.size()){
            st.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        st.insert(ds);
        helper(nums, idx + 1, st, ds);
        ds.pop_back();
        st.insert(ds);
        helper(nums, idx + 1, st, ds);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, 0, st, temp);
        for(auto &it:st){
            ans.push_back(it);
        }
        return ans;
    }
};


// Optimal 
class Solution1 {
private:
    void helper(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i = idx; i < nums.size(); i++){
            if(i!=idx and nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(nums, i + 1, ds, ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, 0, temp, ans);
        return ans;
    }
};

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}