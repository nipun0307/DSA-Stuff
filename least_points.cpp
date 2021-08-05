#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;

int least_initial_points (vector<vector<int>> &vec, vector<vector<int>> &dp){
    
    dp[0][0]= -1*vec[0][0];
    for(int i=1; i<m; i++) dp[i][0]=dp[i-1][0]-vec[i][0];
    for(int i=1; i<n; i++) dp[0][i]=dp[0][i-1]-vec[0][i];

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if (i>0 && j>0)dp[i][j]=min(dp[i-1][j], dp[i][j-1])-vec[i][j];
        }
    }
    return dp[m-1][n-1];
}
 

 
    bool compare_ (const vector<int> &p1, const vector<int> &p2){
        return p1[1]<p2[1];
    }

int main(){

    vector<vector<int>> vec={ {-2, -3,   3}, {-5, -10,  1}, {10,  30, -5} };
    
    sort(vec.begin(), vec.end(), compare_);
    int m=vec.size(), n= vec[0].size();

for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<vector<int>> dp(m, vector<int>(n));
    
    //int ans=least_initial_points(vec, dp);
    dp[0][0]= -1*vec[0][0];
    for(int i=1; i<m; i++) dp[i][0]=dp[i-1][0]-vec[i][0];
    for(int i=1; i<n; i++) dp[0][i]=dp[0][i-1]-vec[0][i];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if (i>0 && j>0)dp[i][j]=max(dp[i-1][j], dp[i][j-1])-vec[i][j];
        }
    }
    int ans= dp[m-1][n-1];
    cout<<ans;
                    

    return 0;
}