#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
 
#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>
 
using namespace std;

int main(){
  int x,n;
  cin >> x >> n;
  vi p(n);
  if(n == 0){
    cout << x << endl;
    return 0;
  }
  Srep(n) cin >> p[i];
  Vsort(p);
  int j = 0,Min=100,ans;
  Lrep(i,0,102){
    if(i == p[j]) j++;
    else{
      if(Min > abs(x-i)) ans = i;
      Min = min(Min,abs(x-i));
    }
  }
  cout << ans << endl;
}
