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
template <std::uint_fast64_t Modulus> struct modint {
    using u64 = std::uint_fast64_t;
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
        a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
        a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
        if (exp % 2) {
            *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }
};
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

using mint = modint<1000000007>;

int main(){
    intscan(n);
    mint sum = 0, ans = 0;
    vecscan(int,a,n);
    Srep(n) sum += a[i];
    Srep(n-1){
        sum -= a[i];
        ans += sum * a[i];
    }
    cout << ans << endl;
}