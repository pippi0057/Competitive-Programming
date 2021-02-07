/*
 * 単機能RSQ
 * sum、addのみ
**/

struct RSQ{
    using ll = long long;
    const ll seg_len = 1 << 20;
    vector<int> seg;
    RSQ() : seg(2 * seg_len) {}
    void add(int ind, int x){
        ind += seg_len;
        seg[ind] += x;
        while(true){
            ind /= 2;
            if(ind == 0) return;
            seg[ind] = seg[ind*2] + seg[ind*2+1];
        }
        return;
    }
    int sum(int l, int r){
        l += seg_len;
        r += seg_len;
        int res = 0;
        while(l < r){
            if(l % 2 == 1){
                res += seg[l];
                l++;
            }
            l /= 2;
            if(r % 2 == 1){
                res += seg[r-1];
                r--;
            }
            r /= 2;
        }
        return res;
    }
};
