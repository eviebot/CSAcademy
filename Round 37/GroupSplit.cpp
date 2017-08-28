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

	int n, i, t, sum = 1;
	cin >> n;
	t = sqrt(n);

	if( t * t == n)
	{
		sum ++;
		--t;
	}

	for(i = 2; i <= t; ++i)
	{
		if( n%i == 0 )
			sum += 2;
	}
	cout << sum << "\n";
}
