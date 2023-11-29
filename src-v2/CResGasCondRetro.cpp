#include <iostream>
#include "CResGasCondRetro.h"

using namespace std;

///Define o metodo de calculo da classe
void CResGasCondRetro::Calc()
{
    	// Redefine os tamanhos dos vetores para o numero de medicoes escolhida pelo usuario
		z2f.resize(n);
    
	//percorre o vetor atribuido em cada posicao da medicao os valores calculados
	 for (int i=0; i<n; i++)
	 {
	 n1[i] = (p[i]*(1-sl[i]))/(z[i]*0.08478*temp);
	 
	 n2[i] = (1000* dl * sl[i])/ml;
     
     z2f[i] = p[i]/(0.08478 * temp *(n1[i]+n2[i]));
	 
	 
	 // assume os novos valores de z2f para ser plotado no grafico 
	 x[i] = gp[i];                           
     y[i] = p[i]/z2f[i];
	 }
}
     

///Define o construtor
CResGasCondRetro::CResGasCondRetro()
{
  
 cout << "\nBgi (m3/m3std): ";
           cin >> bgi;
           cin.get(); 

cout << "\nTemperatura (K): ";
           cin >> temp;
           cin.get(); 
           
cout << "\nDl: ";
           cin >> dl;
           cin.get();
           
cout << "\nMl: ";
           cin >> ml;
           cin.get();           
           
	 sl.resize(n);
     n1.resize(n);
     n2.resize(n);         

  for (int i=0; i<n; i++)
	 {
  cout << "\nSl (" << i+1 << "): ";
           cin >> sl[i];
           cin.get(); 
                  
	
 	 }
}
