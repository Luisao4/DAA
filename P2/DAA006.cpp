//Dadas as coordenadas de um quadrado e um círculo 
//a tua tarefa é descobrir qual a área da zona da interseção entre ambas as duas figuras geométricas. 

#include <iostream>
#include <cmath>
using namespace std;

double intersecao(double qx, double qy, double ql, double cx, double cy, double cr){
        double area = 0;
    
        if (qx + ql <= cx - cr || cx + cr <= qx || cy - cr >= qy + ql || qy >= cy + cr) // Nao se tocam
            return 0;
        
        if (cx + cr <= qx + ql && cx - cr >= qx && cy + cr <= qy + ql && cy - cr >= qy)  // circulo dentro do quadrado
            return M_PI * (cr*cr); 

        if ((qx-cx) * (qx-cx) + (qy+ql-cy) * (qy+ql-cy) <= cr*cr && (qx+ql-cx) * (qx+ql-cx) + (qy+ql-cy) * (qy+ql-cy) <= cr*cr
          && (qx-cx) * (qx-cx) + (qy-cy) * (qy-cy) <= cr*cr && (qx+ql-cx) * (qx+ql-cx) + (qy-cy) * (qy-cy) <= cr*cr) 
            return ql * ql;  // quadrado dentro do circulo

        if (ql > 0.0007) {
            area += intersecao(qx, qy+(ql/2), ql/2, cx, cy, cr);        // quadrado superior esquerdo
            area += intersecao(qx+(ql/2), qy+(ql/2), ql/2, cx, cy, cr); // quadrado superior direito
            area += intersecao(qx, qy, ql/2, cx, cy, cr);               // quadrado inferior esquerdo
            area += intersecao(qx+(ql/2), qy, ql/2, cx, cy, cr);        // quadrado inferior direito
        }
        return area;
}

int main(){
    double qx,qy,ql;
    double cx,cy,cr;
    int n; // numero de casos a considerar
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> qx >> qy >> ql ;
        cin >> cx >> cy >> cr;
        cout << intersecao(qx, qy, ql, cx, cy, cr) << endl;
        }
    return 0;
}