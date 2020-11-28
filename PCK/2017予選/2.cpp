#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#define Vsort(a) sort(a.begin(), a.end())
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vvi vector<vector<int>>
using namespace std;

int  main(){
    int m,f,b;
    cin >> m >> f >> b;
    if(m < b){
        b -= m;
        f -= b;
        if(f < 0){
            cout << "NA" << endl;
            return 0;
        }
    }else{
        cout << 0 << endl;
        return 0;
    }
    cout << b << endl;
}