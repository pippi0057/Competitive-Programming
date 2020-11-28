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
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
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
#define printvecs(name)\
    Srep(name.size()-1) cout << name[i] << ' ';\
    cout << name[name.size()-1] << endl;
#define printvece(name)\
    Srep(name.size()) cout << name[i] << endl;
#define printvvec(name)\
    Srep(name.size()){\
        Lrep(j,0,name[i].size()-1) cout << name[i][j] << ' ';\
        cout << name[i][name[i].size()-1] << endl;\
    }

int main(){
    vecscan(int,dish,5);
    vecc(int,v,5);
    Srep(5) v[i] = i;
    int ans = INT_MAX;
    do{
        int temp = 0;
        Srep(4){
            if(dish[v[i]] % 10 == 0) temp += dish[v[i]];
            else temp += dish[v[i]] + (10 - (dish[v[i]] % 10));
        }
        temp += dish[v[4]];
        ans = min(ans, temp);
    }while(next_permutation(all(v)));
    cout << ans << endl;
}