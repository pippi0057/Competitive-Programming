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

int main(){
    intscan(n);
    vector<int64_t> a(n);
    vector<int> aj;
    vector<int> aplus(n);
    Srep(n){
        cin >> a[i];
        if(a[i] > 0) aj.push_back(i);
        if(i > 0){
            if(a[i] > 0) aplus[i] = aplus[i-1] + 1;
            else aplus[i] = aplus[i-1];
        }else{
            if(a[i] > 0) aplus[0] = 1;
            else aplus[0] = 0;
        }
    }
    vector<vector<int64_t>> move(n);
    vector<int64_t> moveeee(n);
    moveeee[0] = a[0];
    Lrep(i,1,n) moveeee[i] = moveeee[i-1] + a[i];
    Srep(n){
        if(i > 0){
            Lrep(j,0,aplus[i]){
                move[i].push_back(moveeee[aj[j]]);
            }
        }
        move[i].push_back(moveeee[i]);
    }
    int64_t ans = 0;
    vector<int64_t> now(n);
    now[0] = 0;
    Srep(n){
        if(i > 0) now[i] += now[i-1] + move[i-1][move[i-1].size()-1];
        ans = max(ans, now[i]);
        Lrep(j,0,move[i].size()) ans = max(ans, now[i] + move[i][j]);
    }
    cout << ans << endl;
}