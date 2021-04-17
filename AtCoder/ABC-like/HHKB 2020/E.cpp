#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
#include<queue>
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

struct unionfind {
	vector<int> par, siz;
	unionfind(int N) : par(N), siz(N,1) {
		for (int i=0;i<N;i++) par[i]=i;
	}
	int root(int x) {
		while(par[x]!=x) x=par[x]=par[par[x]];
		return x;
	}
	void unite(int x, int y) {
		x=root(x); y=root(y);
		if (x==y) return;
		if (siz[x]<siz[y]) swap(x,y);
		siz[x]+=siz[y];
		par[y]=x;
	}
	bool same(int x, int y) {
		return root(x)==root(y);
	}
	int size(int x) {
		return siz[root(x)];
	}
};

int main(){
    int h,w;
    cin >> h >> w;
    vvc s(h,vc(w));
    rep2d(h,w) cin >> s[i][j];
     
}