#include <string.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> s; //multiset porque pode haver repetiçoes senao usar set
    int add, rem;
    cin >> add >> rem;
    int opp = add + rem;
    char command[3]; // só ler as primeiras 3 letras de modo a distinguir entre min/max/bak

    while (opp > 0) {
        cin >> command;
        if (strcmp(command, "BAK") == 0) {  // para adicionar
            int en;
            cin >> en;
            s.insert(en);
        } else {
            if (strcmp(command, "MIN") == 0) {  // begin é o apontador para o primeiro/mais pequeno elemento
                // cout << "entrou" << endl;
                cout << *(s.begin()) << endl;
                s.erase(s.begin());
            } else if (strcmp(command, "MAX") == 0) {
                cout << *(--s.end()) << endl;
                s.erase(--s.end());  // s.end() aponta para o "pos final" --s.end() aponta para o final
                //  cout << "entrou" << endl;
            }
        }
        opp--;
    }
    return 0;
}