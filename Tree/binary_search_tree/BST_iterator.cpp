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

class BSTIterator{
    stack<TN*> st;
    public:
        BSTIterator(TN* root){
            pushAll(root);
        }

        bool hasNext(){
            return !st.empty();
        }

        int next(){
            TN* node = st.top();
            st.pop();
            pushAll(node->right);
            return node->val;
        }
    private:
        void pushAll(TN* root){
            while(root){
                st.push(root);
                root = root->left;
            }
        }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}