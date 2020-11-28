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

int main(){
    int x;
    cin >> x;
    x %= 7;
    switch (x) {
        case 0:
            cout << "thu" << endl;
            break;
        case 1:
            cout << "fri" << endl;
            break;
        case 2:
            cout << "sat" << endl;
            break;
        case 3:
            cout << "sun" << endl;
            break;
        case 4:
            cout << "mon" << endl;
            break;
        case 5:
            cout << "tue" << endl;
            break;
        default:
            cout << "wed" << endl;
            break;
    }
}