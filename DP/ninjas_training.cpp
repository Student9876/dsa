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




// Recursion 
// int helper(int day, int last, vector<vector<int>> &points){
//     if(day == 0){
//         int mx = 0;
//         for(int task = 0;task<3;task++){
//           if (task != last) {
//             mx = max(mx, points[0][task]);
//           }
//         }
//         return mx;
//     }

//     int mx = 0;
//     for(int task = 0;task<3;task++){
//       if (task != last) {
//         int point = points[day][task] + helper(day - 1, task, points);
//         mx = max(mx, point);
//       }
//     }
//     return mx;

// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     return helper(n-1, 3, points);
// }

// Memoization 
// int helper(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
//     if(day == 0){
//         int mx = 0;
//         for(int task = 0;task<3;task++){
//           if (task != last) {
//             mx = max(mx, points[0][task]);
//           }
//         }
//         return mx;
//     }
//     if(dp[day][last] != -1) return dp[day][last];
//     int mx = 0;
//     for(int task = 0;task<3;task++){
//       if (task != last) {
//         int point = points[day][task] + helper(day - 1, task, points, dp);
//         mx = max(mx, point);
//       }
//     }
//     return dp[day][last] = mx;

// }

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n, vector<int>(4, -1));
//     return helper(n-1, 3, points, dp);
// }


// Tabulation 

// int ninjaTraining(int n, vector<vector<int>> &points){
//     vector<vector<int>> dp(n, vector<int>(4, -1));

//     dp[0][0] = max(points[0][1], points[0][2]);
//     dp[0][1] = max(points[0][0], points[0][2]);
//     dp[0][2] = max(points[0][1], points[0][0]);
//     dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

//     for(int day = 1;day<n;day++){
//       for(int last = 0;last < 4;last++){
//         dp[day][last] = 0;

//         for(int task = 0; task < 3; task++){
//           if(task != last){
//             int point = points[day][task] + dp[day - 1][task];
            
//             dp[day][last] = max(dp[day][last], point);

//           }
//         }
//       }
//     }

//     return dp[n-1][3];
// }

// Space optimised 
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> dp(4,0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][1], points[0][0]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day = 1;day<n;day++){
        vector<int> temp(4,0);
      for(int last = 0;last < 4;last++){
        temp[last] = 0;
        for(int task = 0; task < 3; task++){
          if(task != last){
            temp[last] = max(temp[last], points[day][task] + dp[task]);
          }
        }
      }
        dp = temp;
    }


    return dp[3];
}

int main(){
    int T;cin>>T;
    while(T--){
    
    }
    return 0;
}