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

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	if( abs(r1-r2) % 2 != abs(c1-c2)%2 )
		cout << "-1\n";
	else
	{
		if(r1 == r2 && c1 == c2)
			cout << "0\n";
		else if(abs(r1-r2) == abs(c1-c2))
			cout << "1\n";
		else
			cout << "2\n";
	}
}