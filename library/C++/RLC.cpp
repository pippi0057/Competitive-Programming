namespace RLC{
    vector<pair<char, int>> encode(const string& s){
        int n = (int)s.size();
        vector<pair<char, int>> ret;
        for(int l = 0; l < n;){
            int r = l + 1;
            for (; r < n && s[l] == s[r]; r++) {};
            ret.push_back({s[l], r - l});
            l = r;
        }
        return ret;
    }
    string decode(const vector<pair<char, int>>& c){
        string ret = "";
        for(auto [x, p] : c){
            for(int i = 0; i < p; i++){
                ret.push_back(x);
            }
        }
        return ret;
    }
}