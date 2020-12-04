/**
 *  素数判定 O(sqrt(n))
 *  is_prime(n)
 *  
 *  素数列挙 O(nloglogn)
 *  prime_list(n)
 *  nまでの整数が素数か判定してbool型の配列で返す
 *  (エラトステネスの篩)
**/

bool is_prime(int n){
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    for(int i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
    return 1;
}

vector<bool> prime_list(int n){
    vector<bool> prime(n+1, 1);
    if(n >= 0) prime[0] = 0;
    if(n >= 1) prime[1] = 0;
    for(int i = 2; i * i <= n; i++){
        if(!prime[i]) continue;
        for(int j = i * i; j <= n; j += i){
            prime[j] = 0;
        }
    }
    return prime;
}
