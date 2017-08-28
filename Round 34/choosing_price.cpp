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
    long long maxi = 0, i, n;
    cin >> n;
    long long int arr[n];
    for(i =0 ; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    for(i = n-1; i >= 0; --i)
    {
        if( arr[i] * (n-i) > maxi)
            maxi = arr[i] * (n-i);
    }
    cout << maxi;
}
