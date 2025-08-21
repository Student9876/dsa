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
    https://leetcode.com/problems/same-tree/description/
    
    TC = O(n)
    SC = O(n)
*/

bool isSameTree(TreeNode * root1, TreeNode * root2){
    if(root1 == NULL || root2 == NULL) return root1 == root2;
    return (root1->val == root2->val) && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}



int main(){
    TreeNode * root1 = new TreeNode(-10);
    root1->left= new TreeNode(9);
    root1->right= new TreeNode(20);


    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    TreeNode * root2 = new TreeNode(-10);
    root2->left= new TreeNode(9);
    root2->right= new TreeNode(20);


    root2->right->left = new TreeNode(15);
    root2->right->right = new TreeNode(7);



    cout<<isSameTree(root1, root2);

    return 0;
}