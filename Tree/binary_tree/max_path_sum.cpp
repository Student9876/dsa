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
};


/*
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

*/

// Leetcode solution 
class Solution {
private:
    int helper(TreeNode* root, int &mx){
        if(root == NULL) return 0;
        int leftSum = max(0, helper(root->left,mx));
        int rightSum = max(0, helper(root->right,mx));

        mx = max(mx, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {    
        int mx = INT_MIN;
        helper(root, mx);
        return mx;
    }
};



int maxPathSum(TreeNode *root, int &max_sum){
    if(root == NULL) return 0;

    int leftSum = max(0,maxPathSum(root->left, max_sum));
    int rightSum = max(0,maxPathSum(root->right, max_sum));

    max_sum = max(max_sum, leftSum+rightSum+root->val);

    return root->val + max(leftSum,rightSum);
}


int main(){
    TreeNode * root = new TreeNode(-10);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);


    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    int max_sum = 0;
    maxPathSum(root, max_sum);
    cout<<max_sum;


    return 0;
}