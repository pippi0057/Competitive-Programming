#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define burst\
    cin.tie(0);\
   	ios::sync_with_stdio(false);
#define int long long int
#define db double
#define ldb long double
#define P pair<int,int>
#define F first
#define S second
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>

int32_t main(){
    burst;
    int n, ans = 0;
    string s;
    cin >> n >> s;
    int i = 0;
    bool loop = 1;
    Srep(n) s += 'A';
    while(loop){
        if(s[i] == 'f'){
            if(s[i+1] == 'o'){
                if(s[i+2] == 'x'){
                    ans++;
                    i += 3;
                }
                else{
                    bool ok = 1;
                    int j = i + 2, c1 = 1, c2 = 0;
                    while(ok){
                        if(s[j] == 'f'){
                            if(s[j+1] == 'o') c1++;
                            else ok = 0;
                            j += 2;
                        }else{
                            ok = 0;
                            j++;
                        }
                    }
                    j--;
                    ok = 1;
                    while(ok){
                        if(s[j] == 'x') c2++;
                        else ok = 0;
                        j++;
                    }
                    j--;
                    ans += min(c1,c2);
                    i = j;
                }
            }else if(s[i+1] == 'f'){
                bool ok = 1;
                int j = i + 2, c1 = 2, c2 = 0;
                while(ok){
                    if(s[j] == 'f') c1++;
                    else ok = 0;
                    j++;
                }
                j--;
                ok = 1;
                while(ok){
                    if(s[j] == 'o'){
                        if(s[j+1] == 'x') c2++;
                        else ok = 0;
                        j += 2;
                    }else{
                        ok = 0;
                        j++;
                    }
                }
                j--;
                ans += min(c1,c2);
                i = j;
            }else i++;
        }else if(s[i] == 'A') loop = 0;
        else i++;
        cout << i << endl;
    }
    cout << n - ans * 3 << endl;
}