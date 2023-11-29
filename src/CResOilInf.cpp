#include <iostream>
#include "CResOilInf.h"

using namespace std;

///Defini o metodo de calculo da classe
void CResOilInf::Calc()
{
            double eg;                                                          //Define as variaveis da Equacao de Balanco de Materiais (EBM):
            double eo;                                                          //eg (expansao do gas), eo (expansao do oleo), f 
            double f;
///atribui os valores dos vetores X e Y para linearizacao da EBM do mecanismo de producao presente
            for (int i=0; i<n; i++) 
            {
                eg = (boi*(bg[i]/bgi-1));
                eo = (bo[i]-boi+(rsi-rs[i])*bg[i]);
                f = np[i]*(bo[i]+(rp[i]-rs[i])*bg[i]);
                x[i] = we[i] / (eo + m*eg);
                y[i] = f/ (eo + m*eg);
            }
}

///Define o construtor
CResOilInf::CResOilInf()
{
           rp.resize(n);                                                         //Dimensiona como n o numero de valores 
           rs.resize(n);                                                         //para os vetores rs, rp, bg, we
           bg.resize(n);
           we.resize(n);
           cout << "Bgi (m3/m3 std): ";
           cin >> bgi;                                                          //Pega o valor de Bg inicial          
           cin.get();                                                          
           cout << "Rsi (m3 stf/m3 std): ";
           cin >> rsi;                                                           //Pega o valor de rs inicial      
           cin.get(); 
           cout << "m (m3/m3): ";
           cin >> m;                                                             //Pega o valor de m inicial
           cin.get();
           cout << "." << endl;
           cin.get(); 
///percorre os vetores rp, rs, bg e we pedindo e pegando seus valores correspondentes 
           for (int i=0; i<n; i++)
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
               cout << "Influxo Acumulado We (" << i+1 << ")(m3): ";
               cin >> we[i];
               cin.get();
           }
};
