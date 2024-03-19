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



// Function to return right side view of a binary tree (Iterative)
vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int val;
        f(i,0,n){
            TreeNode * temp = q.front();
            q.pop();
            val = temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        res.push_back(val);
    }
    return res;
}

// Function to return right side view of a binary tree (Recursive)
void rightSideView(TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return;    
    if(res.size() == level) res.push_back(root->val);
    rightSideView(root->right, level+1, res);
    rightSideView(root->left, level+1, res);
}

// Function to return left side view of a binary tree (Recursive)
void leftSideView(TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return;    
    if(res.size() == level) res.push_back(root->val);
    leftSideView(root->left, level+1, res);
    leftSideView(root->right, level+1, res);
}


int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);


    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // vector<int> res = rightSideView(root);

    vector<int> res;
    rightSideView(root, 0, res);
    cout<<"Right side view of the tree is: ";
    nl;
    fa(i,res) cout<<i<<" ";

    nl;
    vector<int> res1;
    cout<<"Left side view of the tree is: ";
    nl;
    leftSideView(root, 0, res1);
    fa(i,res1) cout<<i<<" ";


    return 0;
}