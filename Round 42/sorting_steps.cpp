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

	int n, t, i;
	vector <pair <int, int>> arr;

	cin >> n;
	arr.pb({0, 0});

	for(i = 1; i <= n; ++i){
		cin >> t;
		arr.pb(MP(t, i));
	}


	sort(arr.begin(), arr.end());


	int maxi = 0;

	for(i = 1; i <= n; ++i){
		//cout << arr[i].fi << " "<< arr[i].se << "\n";
		maxi = max(maxi, arr[i].se-i);
	}
	cout << maxi+1 << "\n";
}