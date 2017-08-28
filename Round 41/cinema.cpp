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

	fastIO;
	string s;
	cin >> s;
	int n = s.size(), t =0;
	int i, j, maxi = 0, sum;
	for(i = 0; i < n; ++i){
		sum = 0;
		if(s[i] == '1'){
			j = i-1;
			while(j && s[j] == '0'){
				++sum;--j;
			}
			j = i+1;
			while(j < n && s[j] == '0'){
				++sum;++j;
			}

			maxi = max(maxi, sum);
		}
	}
	for(i =0; i < n; ++i){
		if(s[i] == '0')
			++t;
	}
	cout << min(maxi+1, t) << "\n";
}