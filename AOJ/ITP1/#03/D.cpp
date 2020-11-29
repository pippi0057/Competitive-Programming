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

int binary_search(vi a,int key){
    int n = a.size();
    int left = 0, right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(a[mid] == key) return mid;
        else if(a[mid] > key) right = mid;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    int a,b,c,count=0;
    cin >> a >> b >> c;
    vi divisor;
    Lrep(i,1,c+1) if(c % i == 0) divisor.push_back(i);
    Vsort(divisor);
    Lrep(i,a,b+1){
        if(binary_search(divisor,i) != -1) count++;
    }
    cout << count << endl;
}