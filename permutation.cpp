#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#define mod 1000000009
#define max 1e6

vector<int> dp(max+1);

void precompute(){
    dp[0]=0;
    dp[1]=0;
    dp[2]=dp[3]=1;

    for(int i=4; i<=max;i++){
        dp[i]=(dp[i-2]+dp[i-3])%mod;
    }

}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen ("in.txt","r", stdin);
        freopen ("out.txt","w",stdout);
    #endif
    precompute();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        // vector<int> dp(n+1,0);
        // // dp stores the number if ways to arrange x 2s and y 3s such that 2x+3y=i
        
        // // Base cases
        // dp[1]=0; dp[2]=dp[3]=1;

        // // the answer is dp[n]
        cout<<dp[n]<<"\n";



    }

    return 0;
}

