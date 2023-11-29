#include <iostream>
#include "CResOilCapa.h"

using namespace std;


///Defini o metodo de calculo da classe
void CResOilCapa::Calc()
{
            double eg;                                                           //Define as variaveis da Equacao de Balanco de Materiais (EBM):
            double eo;                                                          //eg (expansao do gas), eo (expansao do oleo), f 
            double f;
///atribui os valores dos vetores X e Y para linearizacao da EBM do mecanismo de producao presente
            for ( int i=0; i<n; i++ )
            {
                eg = (boi*(bg[i]/bgi-1));
                eo = (bo[i]-boi+(rsi-rs[i])*bg[i]);
                f = np[i]*(bo[i]+(rp[i]-rs[i])*bg[i]);
                x[i] = eg/eo;
                y[i] = f/eo;
            }    
}

///Define o construtor
CResOilCapa::CResOilCapa()
{
                rp.resize(n);                                                    //Dimensiona como n o numero de valores 
                rs.resize(n);                                                    //para os vetores rs, rp, bg
                bg.resize(n);
                cout << "Bgi (m3/m3 std): ";
                cin >> bgi;
                cin.get();
                cout << "Rsi (m3/m3 std): ";
                cin >> rsi;
                cin.get(); 
                cout << "." << endl;
                cin.get();   
///percorre os vetores rp, rs, bg e we pedindo e pegando seus valores correspondentes   
                for (int i = 0; i<n; i++)
                {
                    cout << "Rp (" << i+1 << ")(m3 std/m3 std): ";
                    cin >> rp[i];
                    cin.get();
                    cout << "Rs (" << i+1 << ")(m3/m3 std): ";
                    cin >> rs[i];
                    cin.get();
                    cout << "Bg (" << i+1 << ")(m3/m3 std): ";
                    cin >> bg[i];
                    cin.get(); 
                }
}
