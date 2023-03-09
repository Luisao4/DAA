// Cobertura minima (greedy)
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct {
    int li;
    int ri;
} SEG;

struct compare {
    bool operator()(const SEG s1, const SEG s2) {
        if (s1.li < s2.li) return true;
        if (s1.li > s2.li) return false;
        return s1.ri < s2.ri;
    }
};

int analyse(SEG seg[], int m, int n) {
    int c = 0;        // Contador
    int end = 0;      // Posição final do segmento
    int mid = 0;      // posição do segmeto do meio
    int midEnd = 0;  // posição final de um segmeto do meio
    while (end < m) {
        for (int i = mid; i < n; i++) {
            if (seg[i].li <= end) {
                if (seg[i].ri > midEnd) {
                    mid = i;
                    midEnd = seg[i].ri;
                }
            }
        }
        end = seg[mid].ri;
        c++;
    }
    return c;
}

int main() {
    int M, N;
    cin >> M >> N;  // M tamanho a considerar, N numero de segmentos
    SEG seg[N];

    for (int i = 0; i < N; i++) cin >> seg[i].li >> seg[i].ri;
    // cout << "Antes" << endl;
    // for(int i=0; i<N; i++) cout << seg[i].li << " " << seg[i].ri << endl ;

    sort(seg, seg + N, compare());
    // cout << "Depois" << endl;
    // for(int i=0; i<N; i++) cout << seg[i].li << " " << seg[i].ri << endl ;
    cout << analyse(seg, M, N) << endl;
    return 0;
}