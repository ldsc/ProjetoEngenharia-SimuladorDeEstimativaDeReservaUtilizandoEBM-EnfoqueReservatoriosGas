#include <iostream>
#include "CResGas.h"

using namespace std;

///Define o metodo de calculo da classe
void CResGas::Calc()
{
///Atribui os valores calculados nos vetores X e Y para este tipo de reservatorio
        for (int i=0; i<n; i++)
        {
            x[i] = gp[i];                           
            y[i] = p[i]/z[i];
        }
        
}

///Define o construtor
CResGas::CResGas()
{
       n=0;         

 	   cout << "\nNumero de medicoes:";                        //Numero de dados(mediçoes) que temos
       cin >> n;
       cin.get();
       x.resize(n);                                            //Dimensiona como n o numero de valores 
       y.resize(n);                                            //para os vetores X, Y, GP, P e Z
       gp.resize(n);
       p.resize(n);
       z.resize(n);
                
		for (int i = 0; i < n; i++)                            //Corre de 0 a n, pegando os valores de P, GP e Z
        {
             cout << "\nPressao (" << i+1 << ") (kgf/cm2):";
             cin >> p[i];
             cin.get();
             cout << "\nGas Produzido (" << i+1 << ")(m3 std):";
             cin >> gp[i];
             cin.get();
             cout << "\nZ(" << i+1 << "):";
             cin >> z[i];
             cin.get(); 
        }
}
