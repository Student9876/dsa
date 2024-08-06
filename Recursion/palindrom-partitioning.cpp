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
    https://leetcode.com/problems/palindrome-partitioning/description/
    TC -> O(2^N * K * N / 2)
*/

class Solution {
private:
    bool isPalindrom(string s, int start, int end){
        while(start<=end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int idx, string s, vector<string> &path, 
    vector<vector<string>> & ans){
        if(idx == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i = idx;i<s.size();i++){
            if(isPalindrom(s, idx, i)){
                path.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
 
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};



int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}