#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

#define addr(i,j,m) i*m+j

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);
    #endif

    int t; cin>>t;
    while (t--){

        // map <int, int> turn; // maps the window win(i,j) to its turn number;
        // // turn(win(i,j)) = A[n-1-i][j]
        int n, m;
        cin>>n>>m;
        
        int A[n][m];
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++) cin>>A[i][j];
        }

        bool isClean[n][m]; // isClean[i][j]=1 iff win(i,j) remains clean forever, else 0

        // for(int i=0; i<n; i++)
        //     for(int j=0; j<m; j++){
        //         turn[addr(i,j,m)]=A[n-1-i][j];
        //     }

        // for win(i,j) check if all the windows that could have got win(i,j) dirty 
        // have been cleaned before, if yes, good to go
        // if no, isClean[i][j]=0;
        for(int i=0; i<m; i++) isClean[n-1][i]=1;

        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                // int cell=addr(i,j,m);
                int curr_win=A[i][j];

                if (j==0){
                    if (A[i+1][j]<curr_win && A[i+1][j+1]<curr_win) isClean[i][j]=1;
                    else isClean[i][j]=0;
                } 
                else if (j==m-1){
                    if (A[i+1][j]<curr_win && A[i+1][j-1]<curr_win) isClean[i][j]=1;
                    else isClean[i][j]=0;
                }
                else{
                    if (A[i+1][j]<curr_win && A[i+1][j+1]<curr_win && A[i+1][j-1]<curr_win) isClean[i][j]=1;
                    else isClean[i][j]=0;
                }
            }
        }

        // loops end

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++)
            cout<<isClean[i][j];
            cout<<endl;
        }

    }

    return 0;
}