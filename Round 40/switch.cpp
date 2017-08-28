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

int n, cost[100002], rangeu[100002], lazy[300005];
lli sum = 0;
bool init_state[100002], segtree[300005];
string s;

bool checker(int node, int start, int end, int index)
{
	int c1 = node*2, c2 = node*2+1, mid = (start+end)/2;

	if(lazy[node])
	{
		if(lazy[node]%2)
			segtree[node] = !segtree[node];
		if(start != end)
		{
			lazy[c1] += lazy[node];
			lazy[c2] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start == end)
		return segtree[node];

	if(start <= index && index <= mid)
		return checker(c1, start, mid, index);

	return checker(c2, mid+1, end, index);
}

void update(int node, int start, int end, int l, int r)
{
	int c1 = node*2, c2 = node*2+1, mid = (start+end)/2;
	if(lazy[node])
	{
		if(lazy[node]%2)
			segtree[node] = !segtree[node];
		if(start != end)
		{
			lazy[c1] += lazy[node];
			lazy[c2] += lazy[node];
		}
		lazy[node] = 0;
	}

	if( start > r || end < l)
		return;

	if(start >= l && end <= r)
	{
		segtree[node] = !segtree[node];
		if(start != end)
		{
			lazy[c1]++;
			lazy[c2]++;
		}
		return;
	}

	update(c1, start, mid, l, r);
	update(c2, mid+1, end, l, r);

	segtree[node] = segtree[c1]&&segtree[c2];
}

void buildTree(int node, int start, int end)
{
	if(start == end)
	{
		segtree[node] = init_state[start];
		return;
	}

	int c1 = node*2, c2 = node*2+1, mid = (start+end)/2;

	buildTree(c1, start, mid);
	buildTree(c2, mid+1, end);

	segtree[node] = segtree[c1] && segtree[c2];
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	cin >> n >> s;

	int i;
	lli sum = 0;
	for(i = 1; i < 300005; ++i)
		lazy[i] = 0;

	for(i = 1; i <= n; ++i)
	{
		cin >> rangeu[i];
	}
	for(i = 1; i <= n; ++i)
	{
		cin >> cost[i];
	}

	for(i = 0; i < n; ++i)
	{
		if(s[i] == '1')
			init_state[i+1]= 1;
		else
			init_state[i+1] = 0;
	}
	buildTree(1, 1, n);

	for(i = 1; i <= n; ++i)
	{
		if(checker(1, 1, n, i))
		{
			update(1, 1, n, i, rangeu[i]);
			sum += cost[i];
		}
	}
	cout << sum << "\n";
}