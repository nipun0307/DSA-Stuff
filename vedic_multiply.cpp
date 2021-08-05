#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#define send freopen("in.txt", "r", stdin)
#define help freopen("out.txt", "w", stdout)

using namespace std;

int arr[11][11];

void compute()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
            arr[i][j] = i * j;
    }
}

string str_cmp(string a, string b)
{
    if (a.length() != b.length())
        return a.length() > b.length() ? a : b;
    else
        return a > b ? a : b;
}

string choose_base(string a, string b)
{
    if (a.length() <= 1 && b.length() <= 1)
        return "10";
    string c = str_cmp(a, b);
    if (c[1] == '0')
        return c;
    c.pop_back();
    c = to_string(stoi(c) + 1) + "0";
    return c;
}

string get_excess(string a, string base)
{
    return to_string(stoi(base) - stoi(a));
}

pair<string, pair<int, int>> pre_process(string a)
{
    // return pairs as:
    // new processed string
    // pair <sign, decimal>
    // sign is -1 if negative and sign is 1 if positive
    // decimal is -1 if no decimal till last else the index from the last
    int sign = 1;
    if (a[0] == '+')
    {
        sign = 1;
        a = a.substr(1, a.length() - 1);
    }
    else if (a[0] == '-')
    {
        sign = 0;
        a = a.substr(1, a.length() - 1);
    }

    int decimal = 0;
    int n = a.length();
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '.')
        {
            decimal = i;
            break;
        }
    }
    if (decimal)
    {
        a = a.substr(0, decimal) + a.substr(decimal + 1, n - decimal - 1);
        decimal = n - decimal - 1;
    }
    return {a, {sign, decimal}};
}

string multiply_single(string a, string b)
{
    // to multiply a big string a with single integer < 10 , b
    int carry = 0;
    string res = "";
    if (a.length() <= 1 && b.length() <= 1)
        return to_string(arr[stoi(a)][stoi(b)]);
    if (b.length() > a.length())
    {
        swap(a, b);
    }
    for (int i = a.length() - 1; i >= 0; i--)
    {
        string s = to_string(carry + arr[a[i] - '0'][stoi(b)]);
        if (s.length() > 1)
        {
            carry = s[0] - '0';
            res = to_string(s[1] - '0') + res;
        }
        else
        {
            carry = 0;
            res = s + res;
        }
    }
    if (carry)
    {
        res = to_string(carry) + res;
    }
    return res;
}

string processing(string p1, string p2)
{
    // this implements the final stage of the vedic multiplier
    // check if the p2 is lengthier than 1

    if (p2.length() == 1)
        return p1 + p2;
    else
    {
        char tem = p2.back();
        p2.pop_back();
        return to_string(stoi(p1) + stoi(p2)) + tem;
    }
}

string multiply_main(string a, string b)
{

    string base = choose_base(a, b);
    string p1 = to_string(stoi(a) + stoi(b) - stoi(base));
    //cout<<"\nThe first part is: "<<p1<<endl;

    string e1 = get_excess(a, base), e2 = get_excess(b, base);
    string p2 = multiply_single(e1, e2);

    //cout<<"\nThe second part is: "<<p2<<endl;

    base.pop_back();
    if (base == "10")
    {
        p1 = p1 + "0";
    }
    else
        p1 = multiply_single(base, p1);

    return processing(p1, p2);
}

string post_process(string a, int final_sign, int final_position)
{
    if (final_position)
    {
        int n = a.length();
        a = a.substr(0, n - final_position) + "." + a.substr(n - final_position, final_position);
    }
    if (final_sign)
        a = "-" + a;
    return a;
}

int main()
{
    send;
    help;

    compute();
    string a, b;
    cin >> a >> b;
    //cout<<"\n*********\n";
    //cout<<choose_base(a,b);

    pair<string, pair<int, int>> pa1, pa2;
    pa1 = pre_process(a);
    pa2 = pre_process(b);

    int final_decimal = pa1.second.second + pa2.second.second;
    int final_sign = pa1.second.first ^ pa2.second.first;

    //cout<<"\nFINAL SIGN"<<pa1.second.first<<"\t" <<pa2.second.first;
    //cout<<"\nFINAL DECIMAL POSITION: "<<final_decimal;
    cout << "String 1 : " << pa1.first;
    cout << "\nString 2 : " << pa2.first;
    string ans = multiply_main(pa1.first, pa2.first);
    //cout<<endl<<multiply_main(a,b);
    cout << "\n\nBEFORE PROCESSING:\t" << ans << endl;
    ans = post_process(ans, final_sign, final_decimal);
    cout << "THE FINAL ANSWER IS:\t" << ans << endl;
    return 0;
}