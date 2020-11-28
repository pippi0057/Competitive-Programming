#include<stdio.h>
#include<stdlib.h>
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
    string s;
    cin >> s;
    int n = s.size();
    int64_t sum = 0;
    vector<int> a(n);
    Srep(n){
        a[i] = (s[i] - '0');
        sum += a[i];
    }
    sum % 9 == 0 ? cout << "Yes" << endl : cout << "No" << endl;
}