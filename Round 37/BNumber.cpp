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

	int n, i, index;
	double mean = 0, t, mini = (double)(1e9);

	cin >> n ;
	double array[n+1];

	for(i = 1; i <= n; ++i)
	{
		cin >> t;
		mean += t;
		array[i] = t;
	}

	mean = (mean)/(double)(n);

	for(i =1 ; i <= n; ++i)
	{
		if( abs(array[i]- mean) < mini)
		{
			mini = abs(array[i]-mean);
			index = i;
		}
	}
	cout << index << '\n';

}