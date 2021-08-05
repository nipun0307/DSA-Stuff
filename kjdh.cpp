#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define infile freopen("in.txt","r", stdin)
#define outfile freopen("out.txt","w", stdout)

#define cell(i,j,m) i*m+j
// (n-1)*(n)+(n-1)=n^2-1

class Account{
    private:
    string acc_name="NO NAME";
    int balance=1000000;

    public:
    void deposit(int amt){
        balance+=amt;
    }
    void statement(){
        cout<<"AVAILABLE BALANCE AT "<<acc_name<<" IS: "<<balance;
    }
    void withdraw(int amt){
        if (amt<=balance) balance-=amt;
        else cout<<"Insufficient Balance";
    }
    void update_name(string name){
        cout<<"ARE YOU SURE?\nEnter 0 if no, else 1\n";
        bool tem;
        cin>>tem;
        if (tem) acc_name=name;
        else cout<<"NO CHANGE\n";
    }

};

int main(){
    
    Account my_acc;

    //cout<<my_acc.acc_name;
    my_acc.update_name("NIPUN");
    

    my_acc.deposit(150000);
    my_acc.statement();
    return 0;
}