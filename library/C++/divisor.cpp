/**
 *  約数全列挙 O(sqrt(n))
 *  
 *  約数の個数計算 O(sqrt(n))
 *  (素因数分解)
**/

vector<int> divisor(int n){
    vector<int> res;
    for(int i = 1; i * i <= n; i++){
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(all(res));
    return res;
}

int divisor_count(int n){
    int res = 1;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        res *= (cnt + 1);
        if(n == 1) break;
    }
    if(n != 1) res *= 2;
    return res;
}
