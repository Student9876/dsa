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



class NodeValue {
    public:
        int maxNode, minNode,maxSize;

        NodeValue(int minNode, int maxNode, int maxSize){
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
        }
};

class Solution{
    private:
        NodeValue largestBSTSubtreeHelper(TreeNode* root){
            // An empty tree is a BST of size 0
            if(!root){
                return NodeValue(INT_MAX, INT_MIN, 0);
            }

            // Get values from left and right subtree of current tree 
            auto left = largestBSTSubtreeHelper(root->left);
            auto right = largestBSTSubtreeHelper(root->right);

            // current node is greater than max and smaller than min in right, 
            if(left.maxNode < root->val and root->val < right.minNode){
                // It is a BST 
                return NodeValue(min(root->val, left.minNode), max(right.maxNode, root->val), left.maxSize + right.maxSize + 1);
            }

            // Otherwise, return [-inf, inf] so that the parent can't be a valid BST 
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));

        }
    public:
        int largestBSTSubtree(TreeNode* root){
            return largestBSTSubtreeHelper(root).maxSize;
        }
};


int main(){
    TN* root = new TN(20);

    root->left = new TN(15);
    root->left->left = new TN(14);
    root->left->left->right = new TN(17);
    root->left->right = new TN(18);
    root->left->right->left = new TN(16);
    root->left->right->right = new TN(19);

    root->right = new TN(40);
    root->right->left = new TN(30);
    root->right->right = new TN(60);
    root->right->right->left = new TN(50);

    Solution s1;
    int maxSize = s1.largestBSTSubtree(root);
    cout<<"Size of largest BST: "<<maxSize;
    return 0;
}