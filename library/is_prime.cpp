bool is_prime(int n){
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    for(int i = 3; i <= (double)sqrt(n); i += 2) if(n % i == 0) return 0;
    return 1;
}
