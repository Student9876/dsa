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



int findFloorValueBST(TN* root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }

        if(key > root->val){
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}


int main(){
    TN* root = new TN(10);

    root->left = new TN(5);
    root->left->left = new TN(2);
    root->left->right = new TN(8);
    root->left->right->left = new TN(6);


    root->right = new TN(15);
    root->right->left = new TN(13);
    root->right->right = new TN(17);

    cout<<"Floor value of 9 in this tree is: "<<findFloorValueBST(root, 9);

    return 0;
}