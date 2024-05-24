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



class BSTIterator {
    stack<TreeNode*> st;
    // if reverse == true previous
    // if reverse == false next
    bool reverse = true;
    public:
        BSTIterator(TreeNode* root, bool isReverse){
            reverse = isReverse;
            pushAll(root);
        }
        bool hasNext(){
            return !st.empty();
        }

        int next(){
            TreeNode* temp = st.top();
            st.pop();
            if(!reverse) pushAll(temp->right);
            else pushAll(temp->left);
            return temp->val;
        }
    
    private:
        void pushAll(TreeNode* root){
            while(root){
                st.push(root);
                if(reverse){
                    root = root->right;
                } else {
                    root = root->left;
                }
            }
        }

};

class Solution {
    public:
        bool findTarget(TreeNode* root, int key){
            if(!root) return false;
            BSTIterator l(root, false);
            BSTIterator r(root, true);

            int i = l.next();
            int j = r.next();

            while(i<j){
                if(i + j == key) return true;
                else if(i + j < key) i = l.next();
                else j = r.next();
            }
        }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}