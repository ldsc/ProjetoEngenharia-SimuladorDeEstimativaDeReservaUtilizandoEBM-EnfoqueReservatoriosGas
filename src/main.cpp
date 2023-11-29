#include <iostream>
#include "CRes.h"
#include "CResGas.h"
#include "CResGasSecoPres.h"
#include "CResGasSecoInf.h"
#include "CResGasSecoInfPotAquifer.h"
#include "CResGasSecoInfSchilthuis.h"
#include "CResGasCondNaoRetro.h"
#include "CResGasCondRetro.h"
#include "CResOil.h"
#include "CResOilCapa.h"
#include "CResOilInf.h"
#include "CRegLin.h"
#include "CGnuplot.h"


using namespace std;

int main()
{
///booleano para escolher tipo de fluido
int escolha1;                                                       
///inicia-se o booleano como falso
bool valido = false;
///loop para pegar resposta valida
while (!valido)
    {
        
        cout << "Tipo de Fluido:\n(1)Gas\n(2)Oleo" << endl;
        cin >> escolha1;
        cin.get();
///escolha valida
        if (escolha1 == 1 || escolha1 == 2)                             
           valido = true;              
        else
///escolha invalida
            cout << "Escolha invalida." << endl;
    }

///booleano para escolher tipo de mecanismo    
int escolha2;
///inicia-se o booleano como falso
valido = false;
///loop para pegar resposta valida
while (!valido)
    {
        cout << (escolha1 == 1 ? "\nTipo de mecanismo:\n(1)Volumetrico de Gas Seco\n(2)Anormalmente Pressurizado\n(3)Sob Influxo de Agua\n(4)Sob Influxo de agua Modelo Pot Aquifer\n(5)Sob Influxo de agua Modelo Schilthuis\n(6)Gas Condensado Nao Retrogrado\n(7)Gas Condensado Retrogrado" : "\nTipo de mecanismo:\n(1)Gas em solucao\n(2)Capa de Gas\n(3)Sob Influxo de Agua") << endl;
        cin >> escolha2;
        cin.get();
///escolha valida
        if (escolha2 == 1 || escolha2 == 2 || escolha2 == 3 || escolha2 == 4 || escolha2 == 5 || escolha2 == 6 || escolha2 == 7)            
           valido = true;
        else
///escolha invalida
            cout << "\nEscolha invalida." << endl;
    }

///cirar ponteiro res do tipo CRes    
CRes* res;
std::string eixo_x;

std::string eixo_y;
    
if ( escolha1 == 1 )
    {
        
         if (escolha2 == 1)                                                                         
        {
///reservatorio volumetrico de gas seco
	    eixo_x = "Gp(m3 std)";
	    eixo_y = "P/Z(kgf/cm2)";
           res = new CResGas();
        }
        
		
		else if ( escolha2 == 2)                                                                    
        {
///reservatorio de gas anormalmente pressurizado
	    eixo_x = "Gp(m3 std)";
	    eixo_y = "(P/Z)*(1-Cewf*dP)(kgf/cm2)";
            res = new CResGasSecoPres();
        }
        
		
		
		else if ( escolha2 == 3)                                                                    
        {
///reservatorio de gas sob influxo de agua
	    eixo_x = "We/(Bg-Bgi)";
	    eixo_y = "GpBg/(Bg-Bgi)";
             res = new CResGasSecoInf();
        }
    }
    
    
    if ( escolha1 == 1)
    {
      if ( escolha2 == 4)
      {
//reservatorio de gas sob influxo de agua modelo Pot Aquifer
     eixo_x = "We/(Bg-Bgi)";
     eixo_y = "GpBg/(Bg-Bgi)";
     		res = new CResGasSecoInfPotAquifer();
    
  
     }
}

if ( escolha1 ==1)
{
            if ( escolha2 == 5)
            {
                 //reservatorio de gas sob influxo de agua modelo Schilthuis
     eixo_x = "We/(Bg-Bgi)";
     eixo_y = "GpBg/(Bg-Bgi)";
     res = new CResGasSecoInfSchilthuis();
			
                        }
                  }
if ( escolha1 ==1)
{
            if ( escolha2 == 6)
            {
    //reservatorio de gas condensado nao retrogrado
     eixo_x = "Gpt(m3 std)";
	 eixo_y = "(P/Z)(kgf/cm2)";
     res = new CResGasCondNaoRetro();
			
            }
}     
   
   if ( escolha1 ==1)
{
            if ( escolha2 == 7)
            {
    //reservatorio de gas condensado retrogrado
     eixo_x = "Gp(m3 std)";
	 eixo_y = "(P/Z2f)(kgf/cm2)";
     res = new CResGasCondRetro();
			
            }
}      
     
     
    if ( escolha1 == 2 )
    {
         if (escolha2 == 1)                                                                         
        {
///reservatorio de oleo com gas em solucao
	    eixo_x = "Eo+Ef,w (m3/m3 std)";
	    eixo_y = "F(m3)";
           res = new CResOil;
        }
        else if ( escolha2 == 2)                                                                    
        {
///reservatorio de oleo com capa de gas
	    eixo_x = "Eg/Eo(adm)";
	    eixo_y = "F/Eo(m3 std)";
            res = new CResOilCapa;
        }
        else if ( escolha2 == 3)                                                                    
        {
///reservatorio de oleo sob influxo de agua
	    eixo_x = "We/Eo (m3 std)";
	    eixo_y = "F/Eo(m3 std)";
             res = new CResOilInf;
        }
    }
    
cout << "\n" << eixo_x << "\t\t\t\t" << eixo_y << endl;

///utilizar ponteiro res para chamar metodo Calc()    
res->Calc(); 
   
///loop variando de 0 a n (numero de termos)                                                                                    
for (int i=0; i<res->N(); i++)                                                         
    {
///mostrar valores dos vetores calculados
        cout << res->X(i) << "\t\t\t\t" << res->Y(i) << endl;
    }
    
//-----------------------------------------------------------------------------

///criar vetor coef do tipo CRegLin e obrigar iniciar o construtor da classe
CRegLin* coef = new CRegLin();
///usar ponteiro coef para chamar metodo Reg(res) 
coef->Reg(res);                                                                        
                                                  
///calcular estimativa de reserva                                     
if ( escolha1 == 1 )
{
     if (escolha2 == 1)
///Calculo de estimativa de reserva para reservatorio de gas volumetricamente seco
     {
        cout << "\n\nRegressao Linear" << endl;
        cout << "G (m3 std) = -a/b = " << -coef->A()/coef->B() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 2)
     {
///Calculo de estimativa de reserva para reservatorio de gas anormalmente pressurizado
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = -a/b = " << -coef->A()/coef->B() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 3)
     {
///Calculo de estimativa de reserva para reservatorio de gas sob influxo de agua
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = a = " << coef->A() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 4)
     {
///Calculo de estimativa de reserva para reservatorio de gas sob influxo de agua modelo Pot AQuifer
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = a = " << coef->A() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 5)
     {
///Calculo de estimativa de reserva para reservatorio de gas sob influxo de agua modelo Schilthuis
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = a = " << coef->A() << "\n\n\n" << endl;
     }
      else if ( escolha2 == 6)
     {
///Calculo de estimativa de reserva para reservatorio de gas condensado nao retrogrado
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = -a/b = " << -coef->A()/coef->B() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 7)
     {
///Calculo de estimativa de reserva para reservatorio de gas condensado retrogrado
         cout << "\n\nRegressao Linear" << endl;
         cout << "G (m3 std) = -a/b = " << -coef->A()/coef->B() << "\n\n\n" << endl;
     }
     
}
if ( escolha1 == 2 )
{
     if (escolha2 == 1)
     {
///Calculo de estimativa de reserva para reservatorio de oleo com gas em solucao
         cout << "\n\nRegressao Linear" << endl;
         cout << "N (m3 std) = b = " << coef->B() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 2)
     {
///Calculo de estimativa de reserva para reservatorio de oleo com capa de gas
         cout << "\n\nRegressao Linear" << endl;
         cout << "N (m3 std) = a = " << coef->A() << "\n\n\n" << endl;
     }
     else if ( escolha2 == 3)
     {
///Calculo de estimativa de reserva para reservatorio de oleo sob influxo de agua
         cout << "\n\nRegressao Linear" << endl;
         cout << "N (m3 std) = a = " << coef->A() << "\n\n\n" << endl;
     }
}


///criar um objeto gnu do tipo Gnuplot    
CGnuplot gnu;
///reta formatada em linhas (lines, steps, points)
gnu.set_style("lines"); 

///nomenclatura do eixo x recebe o nome dado acima
gnu.set_xlabel(eixo_x);
///nomenclatura do eixo y recebe o nome dado acima
gnu.set_ylabel(eixo_y);
///range do eixo x
gnu.set_xrange(res->X().front(), res->X().back());
///plota grafico a partir dos coeficientes linear e angular
gnu.plot_slope(coef->B(), coef->A());

gnu.plot_x(res->P());
         
cin.get();
return 0;           

system ("pause");  
}
