#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 114514810;
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
    intscan(n,m);
    intscan(sx,sy,gx,gy);
    sx--; sy--; gx--; gy--;
    vvecscan(char,maze,n,m);
    vvec(int,d,n,m,inf);
    vec(int,dx) = {1, 0, -1, 0};
    vec(int,dy) = {0, 1, 0, -1};
    queue<pair<int,int>> que;
    rep2d(n,m) d[i][j] = inf;
    que.push(pair<int,int>(sx,sy));
    d[sx][sy] = 0;
    while(que.size()){ 
        pair<int,int> p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy) break;
        Srep(4){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == inf){
                que.push(pair<int,int>(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    cout << d[gx][gy] << endl;
}