#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define send freopen("in.txt", "r", stdin);
#define help freopen("out.txt","w", stdout);

bool isPalin (string s){
        for(int i=0; i<s.length()/2; i++){
            if (s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }
    
    int longestPalindromeSubseq(string s) {
        // dp[i] is the highest palindrome ending at ith index included;
        vector<string> dp (s.length(),"");
        dp[0]=s.substr(0,1);
        
        for(int i=1; i<s.length(); i++){
            for(int j=i-1; j>=0; j--){
                if (dp[j][0]==s[i]){
                    if (dp[i].length()<dp[j].length()+1 && isPalin(dp[j]+s.substr(i,1))){
                        dp[i]=dp[j]+s.substr(i,1);
                    }
                }
            }
            
        }
        
        return dp[dp.size()-1].length();
        
    }

int main(){
    send help
    
    string s;
    cin>>s;

    int ans=longestPalindromeSubseq(s);

    cout<<ans;


    return 0;
}