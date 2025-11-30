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

int countSetBits(int u){unsigned int uCount;uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);return ((uCount + (uCount >> 3)) & 030707070707) % 63;}

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
    https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1
    TC: O(n)
    SC: O(n)
*/


class Solution {
  public:
    vector<string> generateBinary(int n) {
        queue<string> q;
        vector<string> res;
        
        q.push("1");
        
        while(n--){
            string s1 = q.front();
            q.pop();
            
            res.push_back(s1);
            
            string s2 = s1;
            if(q.size() < n){
                q.push(s1.append("0"));
                q.push(s2.append("1"));
            }
        }
        return res;
        
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}