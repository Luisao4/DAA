#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int pos;
    double duration;
    double fine;
    double ratio;
} SAPATO;

struct compare {
    bool operator()(const SAPATO s1, const SAPATO s2) {
        if (s1.ratio < s2.ratio) return true;  // o que tem menor ratio é feito primeiro
        if (s1.ratio > s2.ratio) return false;
        return s1.pos < s2.pos;  // caso de empate o que tem menor duracao
    }
};

int main() {
    int n;
    cin >> n;     // n sapatos
    SAPATO v[n];  // criacao da estrutura sapato
    for (int i = 0; i < n; i++) {
        v[i].pos = i + 1;
        cin >> v[i].duration >> v[i].fine;
        v[i].ratio = v[i].duration / v[i].fine;
    }
    // for (int i = 0; i < n; i++) cout <<  v[i].duration << " " << v[i].fine << endl;
    sort(v, v + n, compare());
    // for (int i = 0; i < n; i++) cout << v[i].duration << " " << v[i].ratio << endl;
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            cout << v[i].pos << " ";
        else
            cout << v[i].pos << endl;
    }
    return 0;
}