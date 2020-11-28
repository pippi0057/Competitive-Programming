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
    int a, b, x, sum = 0, count = 0;
    cin >> a >> b >> x;
    vi ans;
    Lrep(i,0,21){
        Lrep(j,0,41){
            if((1000 * i) + (500 * j) >= x){
                ans.push_back((a * i) + (b * j));
            }
        }
    }
    Vsort(ans);
    cout << ans[0] << endl;
}