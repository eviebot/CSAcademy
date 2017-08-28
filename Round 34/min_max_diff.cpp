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

int n, k;
vector <long long int> storage;
long long int temp, temp1;
map <long long int, int> mymap;
map <long long int, int>::iterator iter;

void findmax_twist(int start, int end)
{
    for(int i = start+1; i < end; ++i)
    {
        mymap[storage[i]-storage[i-1]]++;
    }
}
long long int findmax(int start, int end)
{
    long long int maxi = 0;
    for(int i = start+1; i < end; ++i)
    {
        if( storage[i]-storage[i-1] > maxi)
            maxi = storage[i]-storage[i-1];
    }
    return (maxi?maxi:inf);
}
int main()
{
    infile.open("input.txt");
    outfile.open("output.txt");
    fastIO;
    int i, j;
    cin >> n >> k >> temp;
    storage.pb(temp);

    for(i = 1; i < n; ++i)
    {
        cin >> temp;
        storage.pb(temp);
    }
    long long int maxi, mini = inf;
    temp = storage.size() -k;
    findmax_twist(0, temp);
    iter = mymap.end();--iter;
    maxi = iter->fi;mini = maxi;


    for(i = temp; i < storage.size(); ++i)
    {
        temp1 = storage[i] - storage[i-1];
        iter = mymap.find( temp1);
        if( iter == mymap.end())
        {
            mymap[temp1] = 1;
        }
        else
        {
            ++iter->se;
        }

        iter = mymap.find(storage[i-temp+1]-storage[i-temp] );
        --iter->se;
        //cout << i << ' '<<iter->fi << ' '<< iter->se << '\n';
        if(!iter->se)
            mymap.erase(iter);

        iter = mymap.end();--iter;

        mini = min(mini, iter->fi);
    }
    cout << mini ;
}

