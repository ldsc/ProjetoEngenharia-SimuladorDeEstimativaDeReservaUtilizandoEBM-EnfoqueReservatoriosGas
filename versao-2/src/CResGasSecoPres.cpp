#include <iostream>
#include "CResGasSecoPres.h"

using namespace std;


///Define o metodo de calculo da classe
void CResGasSecoPres::Calc()
{
            double cewf = (cw*swi + cf)/(1 - swi);                               //Define as variaveis da Equacao de Balanco de Materiais (EBM): Cewf 
            double pi = p[0];
///atribui os valores dos vetores X e Y para linearizacao da EBM do mecanismo de producao presente
            for ( int i=0; i<n; i++ )
            {
                x[i] = gp[i];
                y[i] = (p[i]/z[i])*(1.0-cewf*(pi-p[i]));
            }    
}


///Define o construtor
CResGasSecoPres::CResGasSecoPres()
{
///pede e pega os valores de swi, cw e cf
           cout << "Saturacao Inicial de Agua: ";
           cin >> swi;
           cin.get();
           cout << "Compressibilidade da agua ((kgf/cm2)^-1): ";
           cin >> cw;
           cin.get();                  
           cout << "Compressibilidade da formacao ((kgf/cm2)^-1): ";
           cin >> cf;
           cin.get();
}
