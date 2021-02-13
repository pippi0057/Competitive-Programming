#include <bits/stdc++.h>
using namespace std;
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
#define all(a) a.begin(),a.end()
#define Srep(n) for(int64_t i = 0; i < int64_t(n); i++)
#define Lrep(i,a,n) for(int64_t i = int64_t(a); i < int64_t(n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vec(type,name) vector<type> name
#define vecc(type,name,...) vector<type> name(__VA_ARGS__)
#define vvec(type,name,size,...) vector<vector<type>> name(size, vector<type>(__VA_ARGS__))
#define scan(...) IN(__VA_ARGS__)
#define intscan(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define i64scan(...)\
    int64_t __VA_ARGS__;\
    IN(__VA_ARGS__)
#define charscan(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define strscan(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define vecscan(type,name,size)\
    vector<type> name(size);\
    IN(name)
#define vvecscan(type,name,size1,size2)\
    vector<vector<type>> name(size1, vector<type>(size2));\
    IN(name)

struct uf{
	vector<int> parent,siz;
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
    intscan(n,m);
    vecscan(int,a,n);
    vecscan(int,b,n);
    uf g(n);
    Srep(m){
        intscan(c,d);
        c--; d--;
        g.unite(c,d);
    }
    vecc(int64_t,sa,n,0);
    vecc(int64_t,sb,n,0);
    Srep(n){
        sa[g.root(i)] += a[i];
        sb[g.root(i)] += b[i];
    }
    Srep(n){
        if(sa[i] != sb[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}