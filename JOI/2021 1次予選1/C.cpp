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
    int n,m;
    cin >> n >> m;
    vi a(n),b(m);
    Srep(n) cin >> a[i];
    Srep(m) cin >> b[i];
    Vsort(a);
    Vsort(b);
    vi c;
    if(n > m){
        Srep(n){
            if(binary_search(b,a[i]) != -1){
                if(binary_search(c,a[i]) == -1){
                c.push_back(a[i]);
                }
            }
        }
    }else{
        Srep(m){
            if(binary_search(a,b[i]) != -1){
                if(binary_search(c,b[i]) == -1){
                c.push_back(b[i]);
                }
            }
        }
    }
    Vsort(c);
    Srep(c.size()) cout << c[i] << endl;
}