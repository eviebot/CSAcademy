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

	int n, t;
	vector <int> array;

	cin >> n;
	int i;
	for(i = 1; i <= n; ++i){
		cin >> t;
		array.pb(t);
	}

	sort(array.begin(), array.end());

	int sum = 0;
	for(i = 0; i < n; ){
		sum += array[i+1]-array[i];
		i += 2;
	}

	cout << sum << "\n";
}	