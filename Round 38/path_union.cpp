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

	lli n, t, i, cur, sum, temp;
	cin >> n;

	cur = 2;
	for(i = 1; i <= n;++i)
	{
		cin >> t;
		sum = pow(2, i+1);
		temp = pow(2, i);
		while(t--)
		{
			cout << cur++ << "\n";
			if( cur == sum)
				cur -= temp;
		}
		cur *= 2;
	}
}