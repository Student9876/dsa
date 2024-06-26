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
    https://leetcode.com/problems/balance-a-binary-search-tree/description/
    Given a binary search tree, return a balanced binary search tree with the same node values.

    We create a vector of elements by inorder traversal of the tree.
    Then we build a balanced BST from the elements.
*/


class Solution {
private:
void inorderTraversal(TreeNode * root, vector<int> &elements){
    if(root == NULL) return;
    inorderTraversal(root->left, elements);
    elements.push_back(root->val);
    inorderTraversal(root->right, elements);
}
TreeNode *buildBalancedBST(vector<int> & elements, int start, int end){
    if(start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode * node = new TreeNode(elements[mid]);
    node->left = buildBalancedBST(elements, start, mid - 1);
    node->right = buildBalancedBST(elements, mid + 1, end);
    return node;
}
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> elements;
        inorderTraversal(root, elements);
        
        return buildBalancedBST(elements, 0, elements.size() - 1);
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}