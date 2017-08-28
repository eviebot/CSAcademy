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
	int n, t, curindex = 1;
	cin >> n;
	int arr[200002];

	int i, j, temp;
	for(i = 1; i <= 200000; ++i)
		arr[i] = 0;

	for(i = 1; i < n; ++i){
		cin >> t;
		curindex = max(curindex, i);
		temp = t-(curindex-i);

		//cout << i << " "<< curindex << " "<< temp << "\n";
		if(temp > 0){
			for(j = curindex-i+1; j <= t; ++j, ++curindex){
				arr[curindex] = j;
			}
		}
		
	}

	for(i = 1; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}