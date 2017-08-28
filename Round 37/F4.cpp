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

	lli a, b, c, d;

	cin >> a >> b >> c >> d;

	vector <lli> storage = {a, b, c, d};
	sort(storage.begin(), storage.end());

	lli maxi = storage[3], last = storage[0], s_last = storage[1];
	lli diff = s_last-last;

	if( diff % 3 == 0 )
	{
		diff /= 3;
		last += (diff*2);

		maxi -= diff;
		maxi += (last*2);
	}
	else if( diff % 3 ==1)
	{
		if( maxi == s_last)
		{
			maxi = last + (maxi*2);
		}
		else
		{
			diff /= 3;
			last += (diff*2);

			maxi -= diff;
			maxi += (last*2);
		}
	}
	else
	{
		if( maxi == s_last)
		{
			maxi = last + (maxi*2);
		}
		else
		{
			diff /= 3;
			++diff;
			last += (diff*2);
			--last;

			maxi -= diff;
			maxi += (last*2);
		}
	}


	cout << maxi << "\n";
}
