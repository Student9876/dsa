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



int widthOFBinaryTree(TreeNode* root){
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        int mn = q.front().second;
        int first, last;
        f(i,0,size){
            int cur_id = q.front().second - mn;
            TreeNode* node = q.front().first;
            q.pop();
            if(i==0) first = cur_id;
            if(i==size-1) last = cur_id;
            if(node->left) q.push({node->left, cur_id*2+1});
            if(node->right) q.push({node->right, cur_id*2+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}



int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // root->left->right->left = new TreeNode(8);
    // root->left->right->right = new TreeNode(9);


    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int x = widthOFBinaryTree(root);;
    cout<<"Width of the binary tree is:"<<x;

    return 0;
}