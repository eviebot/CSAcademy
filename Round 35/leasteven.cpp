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

bool checker(long long x)
{
    bool flag = true;
    int t;
    while(x)
    {
        t = x%10;
        if( t % 2 == 0)
            flag = false;
        x /= 10;
    }
    return flag;
}
void printans(long long int builder)
{
    long long int multi = builder+1, t = builder;
    int n_d= 0, i;
    while(t)
    {
        t /= 10;
        n_d ++;
    }
    t = 1;
    for(i =0; i < n_d; ++i)
    {
        t *= 10;
    }
    multi *= (t-builder+1);
    cout << multi ;
}
void printstuff(long long int builder)
{
    int n_d = 0, i;
    long long int multi = 1, t = builder;
    while(t)
    {
        t/=10;
        ++n_d;
    }

    for(i = 0; i <= n_d; ++i)
    {
        multi *= 10;
    }
    multi += builder+1;

    t = 1;
    for(i =0; i < n_d; ++i)
    {
        t *= 10;
    }
    multi *= (t-builder+1);
    cout << multi;

}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");

    long long int x, t;
    cin >> x;

    if( x && checker(x))
    {
        cout << "-1";
        return 0;
    }
    t = x%10;
    if( !t && x != 10 && ((x/10)%10)%2 == 1)
    {
        cout << 11;
        return 0;
    }
    if( t%2 == 0)
    {
        cout << 1;
        return 0;
    }
    long long int builder = 0;
    while(x)
    {
        t = x%10;

        if( !t && ((x/10)%10)%2 == 1 )
        {
            printstuff(builder);
            break;
        }
        if( t %2 == 0)
        {
            x/=10;
            t = x%10;

            printans(builder);
            break;
        }
        x /= 10;
        builder = builder*10+t;
    }

}
