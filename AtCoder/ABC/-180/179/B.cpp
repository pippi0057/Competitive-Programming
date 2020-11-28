#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int n;
    bool ans = false;
    cin >> n;
    vi judge(n);
    Srep(n){
        int a,b;
        cin >> a >> b;
        if(a == b) judge[i] = 1;
        else judge[i] = 0;
    }
    Lrep(i,2,n) if((judge[i-2] == 1)&&(judge[i-1] == 1)&&(judge[i] == 1)) ans = true;
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}