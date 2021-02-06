#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define Srep(n) for(int i = 0; i < (n); i++)

struct XOR{
    int a;
    XOR() : a(0){}
    XOR(int a) : a(a){}
    void operator+=(XOR b){ a ^= b.a; }
    XOR operator-(XOR b) const { return {a ^ b.a}; }
    operator int() const { return a; }
};

int main(){
    int n, q;
    cin >> n >> q;
    fenwick_tree<XOR> seg(n);
    Srep(n){
        int input;
        cin >> input;
        seg.add(i, input);
    }
    Srep(q){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) seg.add(x - 1, y);
        else cout << seg.sum(x - 1, y) << endl;
    }
}