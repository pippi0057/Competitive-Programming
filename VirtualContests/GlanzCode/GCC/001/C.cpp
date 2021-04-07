#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long int
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

namespace geometry2d{
    const double EPS = 1e-10;
    const double PI = 3.14159265358979;
    double dtor(double d){ return d * PI / 180.0; }
    double rtod(double r){ return r * 180.0 / PI; }
    int sgn(const double a){ return a < -EPS ? -1 : (a > EPS ? 1 : 0); }
    struct Point{
        double x, y;
        constexpr Point() : x(0.0), y(0.0) {}
        constexpr Point(double x, double y) : x(x), y(y) {}
        constexpr Point operator +() const{ return *this; }
        constexpr Point operator -() const{ return{ -x, -y }; }
        constexpr Point operator +(const Point& other) const{ return{ x + other.x, y + other.y }; }
        constexpr Point operator -(const Point& other) const{ return{ x - other.x, y - other.y }; }
        constexpr Point operator *(double s) const{ return{ x * s, y * s }; }
        constexpr Point operator /(double s) const{ return{ x / s, y / s }; }
        Point& operator +=(const Point& other){ x += other.x; y += other.y; return *this; }
        Point& operator -=(const Point& other){ x -= other.x; y -= other.y; return *this; }
        Point& operator *=(double s){ x *= s; y *= s; return *this; }
        Point& operator /=(double s){ x /= s; y /= s; return *this; }
        inline bool operator ==(Point other){ return x == other.x && y == other.y; }
        inline bool operator <(Point other){ if(sgn(x - other.x) == 0) return sgn(y - other.y) < 0; return sgn(x - other.x) < 0; }
        inline bool operator <=(Point other){ return *this == other || *this < other; }
        inline bool operator >(Point other){ return !(*this <= other); }
        inline bool operator >=(Point other){ return !(*this < other); }
        inline bool operator !=(Point other){ return !(*this == other); }
        double length() const{ return sqrt(max(0.0, length2())); }
        constexpr double dot(const Point& other) const{ return x * other.x + y * other.y; }
        constexpr double cross(const Point& other) const{ return x * other.y - y * other.x; }
        constexpr double length2() const{ return dot(*this); }
        double dist(const Point& other) const{ return (other - *this).length(); }
        Point normalized() const{ return *this / length(); }
        constexpr bool isZero() const{ return x == 0.0 && y == 0.0; }
        Point normalUnitVector() const{ return{ -normalized().y, normalized().x }; }
        Point rotation(double arg) const{ double cs = cos(arg), sn = sin(arg); return Point(x * cs - y * sn, x * sn + y * cs); }
        double angle() const{ return atan2(y, x); }
    };
    int iSP(Point a, Point b, Point c){
        int flg = sgn((b - a).cross(c - a));
        if(flg == 1 || flg == -1) return flg;
        if(sgn((b - a).dot(c - b)) > 0) return 2;
        if(sgn((a - b).dot(c - a)) > 0) return -2;
        return 0;
    }
    int angleType(Point a, Point b, Point c){ double v = (a - b).dot(c - b); return sgn(v) > 0 ? 0 : (sgn(v) == 0 ? 1 : 2); }
}
using namespace geometry2d;

void Main(){
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    string _1 = to_string((b + (a - b).rotation(dtor(270))).x),
        _2 = to_string((b + (a - b).rotation(dtor(270))).y),
        _3 = to_string((a + (b - a).rotation(dtor(90))).x),
        _4 = to_string((a + (b - a).rotation(dtor(90))).y);
    string a1, a2, a3, a4;
    for(auto x : _1){
        if(x == '.') break;
        a1 += x;
    }
    for(auto x : _2){
        if(x == '.') break;
        a2 += x;
    }
    for(auto x : _3){
        if(x == '.') break;
        a3 += x;
    }
    for(auto x : _4){
        if(x == '.') break;
        a4 += x;
    }
    cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}