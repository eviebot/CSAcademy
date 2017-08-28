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

	fastIO;
	long long int n, t, maxi = 0;
	cin >> n;
	int i, j;

	long long int rowsum[n+1], colsum[n+1], matrix[n+1][n+1];
	for(i = 1; i<= n; ++i)
    {
        rowsum[i] = 0;
        colsum[i] = 0;
    }
	for(i =1; i <= n; ++i)
    {
        for(j = 1; j <= n; ++j)
        {
            cin >> t;
            matrix[i][j] = t;
            rowsum[i] += t;
            colsum[j] += t;
        }
    }

    for(i= 1; i <= n; ++i)
    {
        maxi = max(maxi, max(rowsum[i], colsum[i]));
    }
    vector <pair <long long int, long long int>> rowadd, coladd;
    for(i = 1; i <= n; ++i)
    {
        if( rowsum[i] < maxi)
        {
            rowadd.pb(MP(i, maxi-rowsum[i]));
        }
        if( colsum[i] < maxi)
        {
            coladd.pb( MP(i, maxi-colsum[i]));
        }
    }

    for(i = 0; i < rowadd.size();++i)
    {
        while(rowadd[i].se)
        {
            for(j = 0; j < coladd.size() && rowadd[i].se; ++j)
            {
                if( coladd[j].se)
                {
                    t = min(rowadd[i].se, coladd[j].se);
                    matrix[rowadd[i].fi][coladd[j].fi] += t;
                    rowadd[i].se -= t;
                    coladd[j].se -= t;
                }
            }
        }
    }

    for(i = 1; i <= n; ++i)
    {
        for(j= 1; j <= n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
