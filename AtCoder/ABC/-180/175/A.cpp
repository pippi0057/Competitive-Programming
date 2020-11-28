#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>

using namespace std;

int main(){
    char a,b,c;
    cin >> a >> b >> c;
    if((a == 'S')&&(b == 'S')&&(c == 'S')){
        cout << "0" << endl;
    }else if(((a == 'R')&&(b == 'S')&&(c == 'S'))||((a == 'S')&&(b == 'R')&&(c == 'S'))||((a == 'S')&&(b == 'S')&&(c == 'R'))||((a == 'R')&&(b == 'S')&&(c == 'R'))){
        cout << "1" << endl;
    }else if((a == 'R')&&(b == 'R')&&(c =='R')){
        cout << "3" << endl;
    }else if(((a == 'S')&&(b == 'R')&&(c == 'R'))||((a == 'R')&&(b == 'R')&&(c == 'S'))){
        cout << "2" << endl;
    }else{
        cout << "0" << endl;
    }
}