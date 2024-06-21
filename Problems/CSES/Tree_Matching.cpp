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



// https://cses.fi/problemset/task/1130



const int MAX = 2* 1e5+1;




int main(){

    int n;
    cin>>n;
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        int x, y;cin>>x>>y;
        if(mp.find(x) == mp.end() and mp.find(y) == mp.end()){
            mp[x] = y;
            mp[y] = x;
        }
    }
    cout<<mp.size()/2;

    return 0;
}