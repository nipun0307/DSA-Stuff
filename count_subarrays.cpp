#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen ("in.txt","r", stdin);
        freopen ("out.txt","w",stdout);
    #endif

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> inp(n,0);

        for (int i=0; i<n; i++){
            cin>>inp[i];
        }

        // DP[i] stores the number of non dec arrays from 0 to i that ends at i
        int dp[n];
        // Either you take the ith element in non dec array then you inc the size of ans +1 or 
        dp[0]=1;
        for (int i=1; i<n; i++){
            if (inp[i]>=inp[i-1]) // then take this element
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        // ans is sum(dp)
        int ans=accumulate(dp, dp+n, 0);
        cout<<ans<<"\n";

    }

    return 0;
}

