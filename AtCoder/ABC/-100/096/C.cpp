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
  int h,w;
  cin >> h >> w;
  vector<vector<char>> color(h,vector<char>(w));
  rep2nd(h,w) cin >> color[i][j];
  auto up = [color,h,w](int a, int b) -> bool{
    if(a == 0) return false;
    else if(color[a-1][b] == '.') return false;
    else return true;
  };
  auto down = [color,h,w](int a, int b) -> bool{
    if(a == h-1) return false;
    else if(color[a+1][b] == '.') return false;
    else return true;
  };
  auto right = [color,h,w](int a, int b) -> bool{
    if(b == w-1) return false;
    else if(color[a][b+1] == '.') return false;
    else return true;
  };
  auto left = [color,h,w](int a, int b) -> bool{
    if(b == 0) return false;
    else if(color[a][b-1] == '.') return false;
    else return true;
  };
  rep2nd(h,w){
    if(color[i][j] == '#'){
      if((up(i,j)==false)&&(down(i,j)==false)&&(right(i,j)==false)&&(left(i,j)==false)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
