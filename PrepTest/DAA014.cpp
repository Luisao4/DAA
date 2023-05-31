#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int dia;
    int pos;
    double multa;
    double ratio;
} SAPATO;

struct compari{
    bool operator()(const SAPATO s1, const SAPATO s2){
        if(s1.ratio>s2.ratio) return true;
        if(s1.ratio<s2.ratio) return false;
        else return s1.dia<s2.dia;
    }
};

int main(){
    int n; cin >> n;
    SAPATO s[n];
    for(int i=0; i<n; i++){
        cin >> s[i].dia >> s[i].multa;
        s[i].ratio = s[i].multa/s[i].dia;
        s[i].pos = i+1;
    }

    sort(s, s+n, compari());
    for(int i=0; i<n;i++){
        if(i==n-1){
            cout << s[i].pos << endl;
            break;
        }
        cout << s[i].pos << " ";
    }
    return 0;
}