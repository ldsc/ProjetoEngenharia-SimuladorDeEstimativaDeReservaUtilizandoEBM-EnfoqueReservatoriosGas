#include <iostream>
#include "CResGasSecoInfPotAquifer.h"

using namespace std;

///Define o metodo de calculo da classe
void CResGasSecoInfPotAquifer::Calc()
{
///atribui os valores dos vetores X e Y para linearizacao da EBM do mecanismo de producao presente
            

 	deltap.resize(n);                        //Dimensiona como n o numero de valores para os vetores deltap e we
        we.resize(n);
        
        double wi = 3.14159*(re*re - ro*ro)*h*fi;         //Calcula o valor do influxo de água inicial
     
     for (int i=0; i<n; i++)
	 {
	 	deltap[i] = p[0] - p[i];                          //Calcula variação de pressão
	 	we[i] = (cw+cf)*wi*deltap[i];                     //Calcula o influxo de água acumulado
	 	
 	 }

	for (int i=0; i<n; i++)
            {
                x[i] = we[i]/(bg[i] - bgi);
                y[i] = gp[i]*bg[i]/(bg[i] - bgi);
            }

}


///Define o construtor
CResGasSecoInfPotAquifer::CResGasSecoInfPotAquifer()
{
  
  cout << "Porosidade : ";
           cin >> fi;
           cin.get();

 cout << "bgi (m3/m3 std) : ";
           cin >> bgi;
           cin.get();

  
  cout << "Espessura do aquifero - h (m) : ";
           cin >> h;
           cin.get();
		            
  cout << "Raio do aquifero - re (m): ";
           cin >> re;
           cin.get();  
           
 cout << "Raio do reservatorio - ro (m): ";
           cin >> ro;
           cin.get(); 

 cout << "Compressibilidade da agua - Cw ((kgf/cm2)^-1): ";
           cin >> cw;
           cin.get(); 
           
 cout << "Compressibilidade da formacao - Cf ((kgf/cm2)^-1): ";
           cin >> cf;
           cin.get(); 

bg.resize(n);
           
for (int i=0; i<n; i++)
	 {
  	   cout << "\nbg (" << i+1 << ") (m3/m3 std) : ";
           cin >> bg[i];
           cin.get();         
	
 	 }
 
	  
	   
}
           
           
           
                                     
     
