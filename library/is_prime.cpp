bool is_prime(int n){
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    double sqrtN = sqrt(n);
    for (int i = 3; i <= sqrtN; i += 2) if (n % i == 0) return 0;
    return 1;
}