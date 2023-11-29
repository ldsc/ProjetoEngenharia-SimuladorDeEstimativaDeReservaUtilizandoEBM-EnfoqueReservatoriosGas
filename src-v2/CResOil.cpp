#include <iostream>
#include "CResOil.h"

using namespace std;

///Define o metodo de calculo da classe
void CResOil::Calc()
{
               double f;
               double eo;
               double ewf;
               for (int i=0; i<n; i++)
               {
               f = np[i] * bo[i];
               eo = bo[i] - boi;
               ewf = boi * (pi - p[i]) * ( (cw*swi + cf) / (1-swi) );
///Atribui os valores calculados nos vetores X e Y para este tipo de reservatorio
               x[i] = eo + ewf;
               y[i] = f;
               }
               
}


///Define o construtor
CResOil::CResOil()
{
                cout << "\nNumero de medicoes:";                                 //Numero de dados(mediçoes) que temos
                cin >> n;
                cin.get();
                x.resize(n);                                                     //Dimensiona como n o numero de valores 
                y.resize(n);                                                     //para os vetores X, Y, NP, P e Bo
                np.resize(n);
                p.resize(n);
                bo.resize(n);
                cout << "Pressao Inicial (kgf/cm2): ";
                cin >> pi;
                cin.get();
                cout << "Boi (m3/m3 std): ";                                     //Pega o valor de B0 inicial
                cin >> boi;
                cin.get();
                cout << "Saturacao Inicial de Agua: ";                           //Pega o valor de Sw inicial
                cin >> swi;
                cin.get();
                cout << "Compressibilidade da agua ((kgf/cm2)^-1): ";            //Pega o valor de cw
                cin >> cw;
                cin.get();                  
                cout << "Compressibilidade da formacao ((kgf/cm2)^-1): ";        //Pega o valor de cf
                cin >> cf;
                cin.get();
                for (int i = 0; i<n; i++)                                        //Corre de 0 a n, pegando os valores de P, NP e Bo
                {
                    cout << "Pressao (" << i+1 << ")(kgf/cm2): ";
                    cin >> p[i];
                    cin.get();
                    cout << "Oleo Produzido (" << i+1 << ")(m3 std): ";
                    cin >> np[i];
                    cin.get();
                    cout << "Bo (" << i+1 << ")(m3/m3 std): ";
                    cin >> bo[i];
                    cin.get();
                }
}
