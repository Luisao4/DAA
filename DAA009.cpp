/*Dado um fragmento de ADN alienígena, a tua tarefa é produzir uma listagem das letras que aparecem em pelo menos uma vez,
ordenada por ordem decrescente da sua frequência (número de occorrências)
e em caso de empate pela ordem em que aparecem primeiro no fragmento (ou seja, tendo em conta a primeira ocorrência de cada letra).*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int frequencia;
    int posicao;  // position when first appeared
    char letra;
    int found;  // first found
} ADN;

struct compareFreq {
    bool operator()(const ADN l1, const ADN l2) {
        if (l1.frequencia > l2.frequencia) return true;  // return highest frequency first
        if (l1.frequencia < l2.frequencia) return false;
        if (l1.found < l2.found) return true;
        return false;
    }
};

int main() {
    string dna;
    cin >> dna;
    ADN v[26];

    for (int i = 0; i < 26; i++) {
        v[i].letra = 'A' + i;
        v[i].posicao = i;
        v[i].frequencia = 0;
        // cout<< v[i].letra << " " << v[i].posicao  << " " << endl;
    }

    for (string::size_type i = 0; i < dna.length(); i++) {  // avoid warning of int i =0
        int pos = abs('A' - dna[i]);
        // cout << 'A'- dna[i] << endl; test position on array
        // cout << dna[i] << endl;
        v[pos].frequencia += 1;
        if (v[pos].frequencia > 1) {
            continue;
        } else {
            v[pos].found = i;
            //cout << "entrou" << endl;
        }
        // cout<< v[pos].letra << " " << v[pos].frequencia << " " << v[pos].found << endl; //test if it passes correctly
    }
    sort(v, v + 26, compareFreq());

    for (int i = 0; i < 26; i++) {
        if (v[i].frequencia == 0)
            continue;  // dont output frequency = 0
        else
        cout << v[i].letra << " " << v[i].frequencia << endl;
    }

    return 0;
}