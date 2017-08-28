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

	lli d, l, n, i, t;
	cin >> d >> l >> n;
	vector <lli> stations;
	stations.pb(0);
	stations.pb(d);
	for(i = 1; i <= n; ++i){
		cin >> t;
		stations.pb(t);
	}
	sort(stations.begin(), stations.end());

	lli sum = 0;
	for(i = 0; i <= n; ++i){
		if( stations[i+1] <= stations[i]+l ){
			continue;
		}else{
			lli val = stations[i+1] - stations[i] - l;
			sum += val*val;
			//cout << stations[i] << " "<< stations[i+1] << " "<<  val << "\n";
		}
	}
	cout <<fixed << setprecision(10)<< (double)(sum)*.25/d << "\n";
}