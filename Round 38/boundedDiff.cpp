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

int data[100005], n, k;

bool checker(int a, int b)
{
	if( a == 1)
	{
		if( abs(data[2]-data[1]) > k)
			return 0;
	}
	else if( a == n)
	{
		if((abs(data[n-1]-data[n])) > k)
			return 0;
	}
	else
	{
		if( abs(data[a]-data[a+1]) > k || abs(data[a]-data[a-1]) > k )
			return 0;
	}

	if( b == 1)
	{
		if( abs(data[2]-data[1]) > k)
			return 0;
	}
	else if( b == n)
	{
		if((abs(data[n-1]-data[n])) > k)
			return 0;
	}
	else
	{
		if( abs(data[b]-data[b+1]) > k || abs(data[b]-data[b-1]) > k )
			return 0;
	}
	return 1;
}
void printans(int a,int b)
{
	if(a> b)
		cout << b << ' ' << a << "\n";
	else
		cout << a << " "<< b << "\n";
}
bool checkergen()
{
	for(int i = 1; i < n; ++i)
	{
		if( abs(data[i]-data[i+1]) > k )
			return 0;
	}
	return 1;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	int sum = 0, temp, val;
	int i, j;
	vector <int> candi;

	cin >> n >> k;

	for(i = 1; i <= n; ++i)
	{
		cin >> data[i];
	}

	for(i = 1; i < n; ++i)
	{
		if( abs(data[i] - data[i+1]) > k)
		{
			++sum;
			candi.pb(i);
			candi.pb(++i);
		}
	}
	if(sum > 3)
	{
		cout << "-1\n";
		return 0;
	}
	else if( !sum)
	{
		cout << "0\n";
		return 0;
	}

	if( sum == 1)
	{
		for(i = 0; i < 2; ++i)
		{
			val = candi[i];
		
			for(j = 1; j <= n; ++j)
			{
				temp = data[j];
				data[j] = data[val];
				data[val] = temp;

				if( checkergen())
				{
					printans(j, val);
					return 0;
				}
				else
				{
					temp = data[j];
					data[j] = data[val];
					data[val] = temp;
				}
			}
		}
	}
	else
	{
		for(i = 0; i < candi.size(); ++i)
		{
			for(j = i+1; j < candi.size(); ++j)
			{
				temp = data[candi[j]];
				data[candi[j]] = data[candi[i]];
				data[candi[i]] = temp;

				if( checkergen())
				{
					printans(candi[i], candi[j]);
					return 0;
				}
				else
				{
					temp = data[candi[j]];
					data[candi[j]] = data[candi[i]];
					data[candi[i]] = temp;
				}
			}
		}
	}
	cout << "-1\n";
}