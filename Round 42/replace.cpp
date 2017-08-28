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

string s, a, b;
int sn, an, bn, indexa = 0;

bool matcher(int val){

	string temp;int size;
	if(val == 1){
		temp = a;
		size = an;
	}
	else{
		temp = b;
		size = bn;
	}

	if(indexa+size > sn)
		return false;

	for(int j = indexa; j < indexa+size; ++j){
		if(s[j] != temp[j-indexa]){
			return false;
		}
	}
	return true;

}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	cin >> s >> a >> b;

	string fin = "";
	an = a.size();
	bn = b.size();
	sn = s.size();

	//cout << an << " "<< bn << " "<< sn << "\n";
	while(indexa < sn){
		//cout << indexa << " "<< fin << '\n';
		bool flag = false;
		if(matcher(1)){
			//cout << indexa << " a found\n";
			flag = true;
			fin += b;
			indexa += (an);
		}
		if(matcher(2)){
			//cout << indexa << " b found\n";
			flag = true;
			fin += a;
			indexa += (bn);
		}
		if(!flag){
			//cout << indexa << " not found!\n";
			fin += s[indexa];
			++indexa;
		}
	}
	cout << fin << "\n";
}