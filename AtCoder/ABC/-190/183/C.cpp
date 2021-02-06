#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0, n, k;
    cin >> n >> k;
    vector<vector<int>> time(n, vector<int>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> time[i][j];
    vector<int> v(n-1);
    for(int i = 0; i < n - 1; i++) v[i] = i + 1;
    do{
        long long int temp = 0;
        temp += time[0][v[0]];
        for(int i = 0; i < n - 2; i++) temp += time[v[i]][v[i+1]];
        temp += time[v[n-2]][0];
        if(temp == k) ans++;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}