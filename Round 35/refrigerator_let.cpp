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

	int n, n_letters[26];
	string s;
	char c;
	cin >> n;
	for(int i = 0; i < 26; ++i)
		n_letters[i] = 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> c;
		n_letters[c-'a']++;
	}

	cin >> s;
	int sum = 0;
	for( int i = 0; i < s.size(); ++i)
	{
		c = s[i];
		if( n_letters[c-'a'])
			n_letters[c-'a']--;
		else
			++sum;
	}
	cout << sum;
}
