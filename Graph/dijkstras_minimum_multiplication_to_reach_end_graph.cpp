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



/*
    https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
    Minimum multiplications to reach end  
*/


class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node == end) return steps;
            for(auto it:arr){
                int num = (it * node) % 100000;
                if(steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    q.push({num, dist[num]});
                }
            }
        }
        return -1;
    }
};


int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}