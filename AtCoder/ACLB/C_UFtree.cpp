#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define Srep(n) for(int64_t i = 0; i < int64_t(n); i++)
#define Lrep(i,a,n) for(int64_t i = int64_t(a); i < int64_t(n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>
#define vc vector<char>
#define vvc vector<vc>
using namespace std;

struct uf{
	vi parent,siz;
	uf(int n) : parent(n), siz(n,1){
		Srep(n) parent[i] = i;
	}
	int root(int x){
		while(parent[x] != x){
			x = parent[x] = parent[parent[x]];
		}
		return x;
	}
	bool unite(int x, int y){
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if(siz[x] < siz[y]) swap(x,y);
		siz[x] += siz[y];
		parent[y] = x;
		return true;
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	int size(int x){
		return siz[root(x)];
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	uf city(n);
	Srep(m){
		vi input(2);
		cin >> input[0] >> input[1];
		input[0]--;
		input[1]--;
		city.unite(input[0],input[1]);
	}
	set<int> ans;
	Srep(n) ans.insert(city.root(i));
	cout << ans.size() - 1 << endl;
}