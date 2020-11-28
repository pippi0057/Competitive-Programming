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

int64_t binary_search64(vi64 a,int64_t key){
    int64_t n = a.size();
    int64_t left = 0, right = n;
    while(left < right){
        int64_t mid = (left + right) / 2;
        if(a[mid] == key) return mid;
        else if(a[mid] > key) right = mid;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    int n, key;
    cin >> n;
    vi a(n);
    Srep(n) cin >> a[i];
    cin >> key;
    cout << binary_search(a, key) << endl;
}