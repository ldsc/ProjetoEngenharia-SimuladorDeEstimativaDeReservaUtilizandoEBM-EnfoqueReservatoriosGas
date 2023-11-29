#include <iostream>
#include "CResGasSecoInf.h"

using namespace std;


///Define o metodo de calculo da classe
void CResGasSecoInf::Calc()
{
///atribui os valores dos vetores X e Y para linearizacao da EBM do mecanismo de producao presente
            for (int i=0; i<n; i++)
            {
                x[i] = we[i]/(bg[i] - bgi);
                y[i] = gp[i]*bg[i]/(bg[i] - bgi);
            }
}


CResGasSecoInf::CResGasSecoInf()
{
     bg.resize(n);                                                         //Dimensiona como n o numero de valores 
     we.resize(n);                                                         //para os vetores bg e we
     cout << "Bgi (m3/m3std): ";
     cin >> bgi;
     cin.get();
       for (int i=0; i<n; i++)                                               //Corre de 0 a n, pegando os valores de  bg e we
       {
        cout << "Bg (" << i+1 << ")(m3/m3 std): ";
        cin >> bg[i];
        cin.get();
        cout << "Influxo Acumulado We (" << i+1 << ")(m3): ";
        cin >> we[i];
        cin.get(); 
       }                 
}

