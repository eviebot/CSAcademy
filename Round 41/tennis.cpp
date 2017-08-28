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

	int n, k, m, c = 1;
	cin >> n >> k >> m;


	int r = log2(k), t = pow(2, n);
	if( r < m || (k == t && m != r)){
		cout << "-1\n";
		return 0;
	}

	r = pow(2, m);

	int array[40000], i;

	for(i = 1; i < r; ++i){
		array[i] = c;
		c++;
	}

	array[r] = k;
	array[r+1] = t;

	for(i = r+2; c < t; ++i){
		//cout << i << " "<< c << "\n";
		if(c != k){
			array[i] = c;
		}
		else
			--i;
		c++;
	}

	for(i = 1; i <= t; ++i)
		cout << array[i] << " ";
	cout << "\n";
}