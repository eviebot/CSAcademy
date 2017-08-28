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

	int L[101], R[101], size, i, n, sum = 0;
	char c;
	cin >> n;
	for(i = 1; i <= 100; ++i)
	{
		L[i] = 0;
		R[i] = 0;
	}

	for(i = 0; i < n; ++i)
	{
		cin >> size >> c;
		if( c == 'L')
			L[size]++;
		else
			R[size]++;
	}

	for(i = 1; i <= 100; ++i)
		sum += min(L[i], R[i]);

	cout << sum << "\n";
}