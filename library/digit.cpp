int sum_digit(int n){
    int sum = 0;
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++) sum += (int)(s[i] - '0');
    return sum;
}