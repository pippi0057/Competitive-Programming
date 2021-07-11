namespace RLC{
    string encode(const string& s){
        string res = "";
        for(int l = 0; l < s.size();){
            int r = l + 1;
            for(; r < s.size() && s[l] == s[r]; r++);
            res += s[l] + to_string(r - l);
            l = r;
        }
        return res;
    }
    string decode(const string& s){
        string res = "";
        for(int l = 0; l < s.size();){
            int r = l + 1;
            for(; r < s.size() && 48 <= s[r] && s[r] <= 57; r++);
            for(int i = 0; i < stoi(s.substr(l + 1, r - l)); i++) res += s[l];
            l = r;
        }
        return res;
    }
}