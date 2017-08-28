#include <bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

ofstream outfile;
ifstream infile;

int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    bool flag ;
    int n, sum = 0, dec, i, time, temp;

    flag = true;
    cin >> n;
    for(i = 0; i < n; ++i)
    {
        cin >> dec >> time;
        if( dec == 1 && flag)
        {
            temp = time;
            flag = false;
        }
        else if( dec == 2 && flag == false)
        {
            flag = true;
            sum += time-temp;
        }
    }
    cout << sum ;
}
