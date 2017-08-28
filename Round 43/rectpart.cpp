#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int h, w, n, m, i, t1, t2;

	cin >>h >> w >> n >> m;
	int diff[200000], arr1[200000], arr2[200000];

	for(i = 0; i < 200000; ++i)
		diff[i] = 0;

	for(i = 1; i <= n; ++i){
		cin >> arr1[i];
	}

	for(i = 1; i <= m; ++i){
		cin >> arr2[i];
	}

	arr1[0] = 0;
	arr2[0] = 0;
	arr1[n+1] = h;
	arr2[m+1] = w;

	sort(arr1, arr1+n+1);
	sort(arr2, arr2+m+1);

	for(i = 1; i <= n+1; ++i){
		diff[arr1[i]-arr1[i-1]]++;
	}
	lli sum = 0;
	for(i = 1; i <= m+1; ++i){
		sum += (lli)(diff[arr2[i]-arr2[i-1]]);
	}

	cout << sum << "\n";
}