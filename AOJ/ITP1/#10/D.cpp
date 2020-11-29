#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
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
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define ll long long int
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
#define linescan(s)\
    string s;\
    getline(cin,s)
#define vecscan(type,name,size)\
    vector<type> name(size);\
    IN(name)
#define vvecscan(type,name,size1,size2)\
    vector<vector<type>> name(size1, vector<type>(size2));\
    IN(name)

int main(){
    intscan(n);
    vecscan(double,x,n);
    vecscan(double,y,n);
    double m = 0, c = 0, a = 0, t = 0;
    Srep(n){
        m += abs(x[i]-y[i]);
        a += pow(abs(x[i]-y[i]),2);
        t += pow(abs(x[i]-y[i]),3);
        c = max(c, abs(x[i]-y[i]));
    }
    a = sqrt(a);
    t = pow(t,0.33333333333333);
    printf("%.20f\n%.20f\n%.20f\n%.20f\n", m, a, t, c);
}
