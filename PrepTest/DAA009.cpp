#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    char d;
    int freq=0;
    int pos=0;
} AND;

struct alinha{
    bool operator()(const AND um, const AND dois){
        if(um.freq > dois.freq) return true;
        if(um.freq < dois.freq) return false;
        if(um.pos < dois.pos) return true;
        return false;
    }
};

int main(){
    string a;
    cin >> a;
    AND nad[26];
    for(int i=0; i<26; i++){
        nad[i].d = 'A' + i;
    }
    for(int i=0; i<int(a.length());i++){
        int pos= abs('A'-a[i]);
        nad[pos].freq+=1;
        if(nad[pos].freq>1) continue;
        else
            nad[pos].pos=i;
            
        
        
        
    }
    sort(nad, nad+26, alinha());

    for(int i=0; i<26; i++){
        if(nad[i].freq == 0) break;
        cout << nad[i].d << " " << nad[i].freq << endl;
    }

return 0;
}