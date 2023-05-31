#include <iostream>
#include <algorithm>
using namespace std;

typedef struct 
{
    int li=0;
    int ri=0;
    int t;
} SR;

struct compari{
    bool operator()(const SR um, const SR dois){
        if(um.li < dois.li ) return true;
        if(um.li > dois.li) return false;
        if(um.ri > dois.ri) return true;
        return false;
    }
};


int analisa(SR seg[], int M, int N){
    int c=0;
    int middle=0;
    int middleENd=0;
    int end=0; //o fim donde esta
    while(end<M){
        for (int i = middle; i < N; i++) {
            if (seg[i].li <= end) {
                if (seg[i].ri > middleENd) {
                    middle = i;
                    middleENd = seg[i].ri;
                }
            }
        }
        end = seg[middle].ri;
        c++;
    }
    return c;
    }


int main(){

int m; cin >> m; //tamanho pretendido
int n; cin >> n;
SR seg[n];
for(int i=0; i<n ; i++){
    cin >> seg[i].li ;
    cin >> seg[i].ri ;
    seg[i].t = seg[i].ri - seg[i].li ;
}

    sort(seg, seg+n, compari());

    cout << analisa(seg, m, n) << endl;
    return 0;
}