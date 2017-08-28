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

	int n, t1, t2;, i, j, maxi, start, end;
	cin >> n >> t1;
	vector <int> array;
	array.pb(INT_MAX);
	array.pb(t);

	start = 0;
	maxi = 1;
	for(end = 1; end < n; ++end)
	{
		cin >> t2;
		if( t2 < t1)
		{
			++maxi;
		}
		else
		{
			while(start < end)
			{
				cout << maxi << " ";
			}
			maxi = 1;
		}
		t1 = t2;
	}
}