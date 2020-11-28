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

bool prime_judge(int n){
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    double sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) if (n % i == 0) return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    prime_judge(n) ? cout << n << ":Yes" << endl : cout << n << ":No" << endl;
}