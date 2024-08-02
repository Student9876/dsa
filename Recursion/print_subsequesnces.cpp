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



void printSubsequences(int index, vector<int> &arr, vector<int> & temp, int n){
    if(index >= n){
        for(auto it:temp) cout<<it<<" ";
        nl;
        return;
    }

    temp.push_back(arr[index]);
    printSubsequences(index + 1, arr, temp, n);
    temp.pop_back();
    printSubsequences(index + 1, arr, temp, n);
}



int main(){
    vector<int> arr = {3,1,2};
    vector<int> temp;
    printSubsequences(0, arr, temp, arr.size());

    return 0;
}