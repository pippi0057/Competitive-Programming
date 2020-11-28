#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<stack>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int l;
    cin >> l;
    vi c(l);
    Srep(l) cin >> c[i];
    vi d;
    Srep(l){
        if(c[i] > 0){
            Lrep(j,0,d.size()){
                if(d[j] == c[i]){
                    cout << i + 1 << endl;
                    return 0;
                }
            }
            d.push_back(c[i]);
        }
        if(c[i] < 0){
            if(d.size() == 0){
                cout << i + 1 << endl;
                return 0;
            }else if(d[d.size() - 1] != abs(c[i])){
                cout << i + 1 << endl;
                return 0;
            }
            d.pop_back();
        }
    }
    cout << "OK" << endl;
}