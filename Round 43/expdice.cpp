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

	int arr1[7],arr2[7], i, t;
	for(i = 1; i <= 6; ++i)
		cin >>arr1[i];

	for(i = 1; i <= 6; ++i)
		cin >> arr2[i];

	int result[102];
	for(i = 1; i <= 100; ++i)
		result[i] = 0;

	for(i = 1; i <= 6; ++i){
		for(int j= 1; j <= 6; ++j){
			
			result[arr1[i]+arr2[j]]++;
		}
	}

	int maxi = 0, index;

	for(i = 1; i <= 100; ++i){
		if(result[i] > maxi){
			maxi = result[i];
			index = i;
		}
	}

	cout << index << "\n";
}