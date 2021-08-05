#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    string s;
    cin>>s;

    int n=s.length();
    
    vector<vector<bool>> dp(n, vector<bool>(n,0)); // dp table

    // filling the diagonal
    for(int i=0; i<n; i++) dp[i][i]=1;

    // 2 length palindromes
    // i<=j
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]) dp[i][i+1]=dp[i+1][i]=1;
    }


    // i goes from n to 0
    // j goes from i to n
    int max_len=1 , start=0;
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if (dp[i+1][j-1] && s[i]==s[j]) {
                dp[i][j]=dp[j][i]=1;
                if (max_len<j-i+1){
                    max_len=j-i+1;
                    start=i;
                }
            }
        }
    }
    string sub= s.substr(start, max_len);
    cout<<sub;

    return 0;
}