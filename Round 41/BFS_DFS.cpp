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

	int n, t, i, BFS[5000], DFS[5000];
	cin >> n;

	for(i = 1; i <= n; ++i){
		cin >> BFS[i];
	}

	for(i = 1; i <= n; ++i){
		cin >> DFS[i];
	}

	if(BFS[2] != DFS[2] || BFS[1] != DFS[1]){
		cout << "-1\n";
		return 0;
	}
	cout << 2*(n-1) - 1 << "\n";
	for(i = 2; i <= n; ++i){
		cout << "1 "<< BFS[i] << "\n";
	}

	for(i = 2; i < n; ++i){
		cout << DFS[i] << " "<< DFS[i+1] << "\n";
	}
}