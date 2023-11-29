#include <iostream>
#include "CResGasSecoInfSchilthuis.h"

using namespace std;

///Define o metodo de calculo da classe
void CResGasSecoInfSchilthuis::Calc()
{
    	deltap.resize(n);                             //Dimensiona como n o numero de valores para os vetores deltap e we
        we.resize(n);
        
	 for (int i=0; i<n; i++)
	 {
	 	deltap[i] = p[0] - p[i];
	 	we[i] = j*deltap[i]*(t2-t1);
  	 }
       
	     for (int i=0; i<n; i++)
            {
                x[i] = we[i]/(bg[i] - bgi);
                y[i] = gp[i]*bg[i]/(bg[i] - bgi);
            }
}
     

///Define o construtor
CResGasSecoInfSchilthuis::CResGasSecoInfSchilthuis()
{
 	 
	cout << "t1 (d): ";
	           cin>>t1;
		   cin.get();
		  
	cout << "t2 (d): ";
	           cin>>t2;
		   cin.get();
		   
	cout << "Constante de influxo - J (m3/(d*kgf/cm2) : ";
	          cin>>j;
		  cin.get();
 
        cout << "bgi (m3/m3 std) : ";
        	  cin >> bgi;
        	  cin.get();

bg.resize(n);
           
for (int i=0; i<n; i++)
	 {
  	   cout << "\nbg (" << i+1 << ") (m3/m3 std) : ";
           cin >> bg[i];
           cin.get();         
	
 	 }
		  
		   
}
           
           
           
                                     
     
