#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vvi vector<vector<int>>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    int z = __gcd(x, y);
    int ans = x + y - z + 1;
    cout << ans << endl;
}