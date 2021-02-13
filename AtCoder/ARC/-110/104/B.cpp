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
#define vc vector<char>
 
using namespace std;

int main(){
    int n;
    cin >> n;
    vi Asum(n+1), Bsum(n+1), Csum(n+1), Dsum(n+1);
    Asum[0] = 1;
    Bsum[0] = 1;
    Csum[0] = 1;
    Dsum[0] = 1;
    Lrep(i,1,n+1){
        char input;
        cin >> input;
        if(input == 'A') Asum[i] = Asum[i-1] + 1;
        if(input == 'T') Bsum[i] = Bsum[i-1] + 1;
        if(input == 'C') Csum[i] = Csum[i-1] + 1;
        if(input == 'G') Dsum[i] = Dsum[i-1] + 1;
    }
    
}