#include <bits/stdc++.h>
using namespace std;

int main(){
    srand((unsigned)time(NULL));
    FILE *in = freopen("input.txt", "w", stdout);
    
    int n = rand() % 200000 + 1;
    int w = rand() % 200000 + 1;
    vector<int> a(n);
    cout << n << endl << w << endl << "[";
    for(int i = 0; i < n; i++){
        a[i] = rand() % 1000000000 + 1;
        cout << a[i];
        if(i == n - 1) cout << "]" << endl;
        else cout << ", ";
    }
    sort(a.begin(), a.end());
    long long ans = 0, sum = 0;
    for(auto x : a){
        sum += x;
        if(x > w) break;
        ans++;
    }
    cout << ans << endl;
}