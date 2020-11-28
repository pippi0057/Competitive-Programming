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
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>
#define P pair<int,int>
#define F first
#define S second

using namespace std;

vi heap(INT32_MAX);
int sz = 0;

int push(int x){
    int i = sz++;
    while(i > 0){
        int p = (i - 1) / 2;
        if(heap[p] <= x) break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

int pop(){
    int ret = heap[0];
    int x = heap[--sz];
    int i = 0;
    while(i * 2 + 1 < sz){
        int a = i * 2 + 1, b = i * 2 + 2;
        if((b < sz)&&(heap[b] < heap[a])) a = b;
        if(heap[a] >= x) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int main(){
    int n,input;
    Srep(n){
        cin >> input;
        push(input);
    }
    Srep(n) cout << pop();
}