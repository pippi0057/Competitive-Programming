#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // a b(整数)を入力する
    int a, b;
    cin >> a >> b;
    
    // s(文字列)を入力する
    string s;
    cin >> s;
    
    // a b(整数)、s(文字列)を入力する
    cin >> a >> b >> s;
    // (繋げられるよ)
    
    // 変数aを出力する
    cout << a << endl;
    
    // スペースを空けて出力するとき
    cout << a << " " << b << endl;
    // 間に文字列のスペースを挟む
    
    // endlは改行の意味なので改行の必要がない時は書かなくてもOK
    // (基本書いた方がいいけど)
    cout << "こんなかんじ";
    
    // if文はこんな感じ
    if(a > b){
        // a > bだった時の処理
    }
    
    if(a > b){
        // a > bだった時の処理
    }else{
        // a > bでなかった時の処理
    }
    
    if(a > b){
        // a > bだった時の処理
    }else if(a == b){
        // a > bでなかった場合で、 a == bだった時の処理
    }else{
        // 上のどれでもない時(a > bでなくて、a == bでもないとき)の処理
    }
}
