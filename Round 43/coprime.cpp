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

	int n, k, i, t, j;
	cin >> n >> k;

	vector <int> primes;
	int primecounter = 0;

	int arr[20000];
	for(i = 1; i <= n; ++i)
		arr[i] = 2*i;

	int sieve[1000010];
	for(i = 1; i <= 1000000; ++i)
		sieve[i] = 0;
	
	for(i = 2; i <= 1000000; ++i){
		if(!sieve[i]){
			j = i;
			while(j <= 1000000){
				sieve[j] = i;
				j += i;
			}
		}
	}

	for(i = 1000000; i > 10; --i){
		if(sieve[i] == i){
			primes.pb(i);
		}
	}

	i = 1;
	while(i < n){
		if(k - (n-i) >= 0){
			//cout << k << " "<< n << " "<< i << " " <<  "OKAY!\n";
			k = k - (n-i);
			arr[i] = primes[primecounter++];
		}
		++i;
	}

	for(i = 1; i <= n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}