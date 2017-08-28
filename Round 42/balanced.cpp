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

	string s;
	int checker[10];


	cin >> s;

	for(int i = 0; i < 10; ++i)
		checker[i] = 0;


	for(int i = 0; i < s.length(); ++i){
		checker[s[i]-'0']++;
	}

	int t = checker[0];
	for(int i = 0; i < 10; ++i){
		if(checker[i] != t)
		{
			cout << "0\n";
			return 0;
		}
	}
	cout << "1\n";
}