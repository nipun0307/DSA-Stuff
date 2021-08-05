#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int isSubstr(string &s, string &t){
    int l1=s.length(), l2=t.length();
    if (l2>l1) return -1;
    int ind=0, i=0;

    while(true){
        if (ind>=l2) return i-l2;
        if (i>=l1) return -1;
        if (s[i]==t[ind]){
            ind++; i++;
        }
        else if (s[i]!=t[ind] && ind!=0){
            ind=0;
        }
        else if (s[i]!=t[ind] && ind==0) i++;
        
    }
    return -1;

}

int main(){
    string s, t;
    //s="ktsearlteysufdofrgchejmkhswtrate", t="salesforce";
    s="california", t="cat";
    string even="", odd="";

    for(int i=0; i<s.length(); i++){
        if (i%2) odd+=s[i];
        else even+=s[i];
    }

    cout<<even<<" "<<odd<<endl;

    int ans= isSubstr(s,t);

    if (ans==-1){
        int even_num=isSubstr(even,t);
        int odd_num=isSubstr(odd, t);

        if (even_num ==-1 && odd_num==-1){
            cout<<"no secret"; return 0;
        }

        if (even_num!=-1){
            cout<<2*even_num+1<<","<<2*(even_num+t.length()-1)+1;
            return 0;
        }
        if (odd_num!=-1){
            cout<<2*odd_num+2<<","<<2*(odd_num+t.length()-1)+2;
            return 0;
        }

    }

    cout<<ans+1<<","<<ans+t.length();
    return 0;

}