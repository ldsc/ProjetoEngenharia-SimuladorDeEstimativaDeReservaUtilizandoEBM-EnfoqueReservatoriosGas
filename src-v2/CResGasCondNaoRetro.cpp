#include <iostream>
#include "CResGasCondNaoRetro.h"

using namespace std;

///Define o metodo de calculo da classe
void CResGasCondNaoRetro::Calc()
{
    	// Redefine os tamanhos dos vetores para o numero de medicoes escolhida pelo usuario
		gpp.resize(n);
        gec.resize(n);
        gew.resize(n);
        gpt.resize(n);
    
	//percorre o vetor atribuido em cada posicao da medicao os valores calculados
	 for (int i=0; i<n; i++)
	 {
	 gpp[i] = gp[i];
	 
	 gec[i] = ((23686 * dc)/mc)*vc[i];
     
     gew[i] = 1316 * vw[i];
     
     gpt[i] = gpp[i] + gec[i] + gew[i]; 
	 
	 
	 // recalcula gp assumindo os novos valores de gpt para ser plotado no grafico 
	 x[i] = gpt[i];                           
     y[i] = p[i]/z[i];
	 }
}
     

///Define o construtor
CResGasCondNaoRetro::CResGasCondNaoRetro()
{
  
  cout << "\nDc: ";
           cin >> dc;
           cin.get();
           
  cout << "\nMc: ";
           cin >> mc;
           cin.get();  
           
 cout << "\nBgi (m3/m3std): ";
           cin >> bgi;
           cin.get(); 
           
 vc.resize(n);
 vw.resize(n);          

  for (int i=0; i<n; i++)
	 {
  cout << "\nVc (m3) (" << i+1 << "): ";
           cin >> vc[i];
           cin.get(); 
           
  cout << "\nVw (m3) (" << i+1 << "): ";
           cin >> vw[i];
           cin.get();
	
 	 }
}
