#include "CRegLin.h"

#include <iostream>
///Metodo que fara a regressao linear e recebe um ponteiro que aponta para um atributo do tipo CRes 
void CRegLin::Reg(CRes* parametro)
{
///declara o atributo que armazena o somatorio de x e defini-o igual a zero
        double sx = 0.0;
///declara o atributo que armazena o somatorio de y e defini-o igual a zero
        double sy = 0.0;
///declara o atributo que armazena o somatorio do produto de x*x e defini-o igual a zero
        double sxx = 0.0;
///declara o atributo que armazena o somatorio do produto de y*y e defini-o igual a zero
        double sxy = 0.0;
///define n iguaal ao tamanho do atributo parametro
        int n = parametro->N();
        
        //media=0.0;
///For utilizado para fazer o somatorio
        for (int i=0; i<n; i++)                                 
        {
///faz o somatório de x sobrecarregando-o
            sx += parametro->X(i);
///faz o somatório de y sobrecarregando-o
            sy += parametro->Y(i);
///faz o somatório do produto x*x sobrecarregando-o
            sxx += parametro->X(i)*parametro->X(i);
///faz o somatório do produto y*y sobrecarregando-o
            sxy += parametro->X(i)*parametro->Y(i);
            
            //media+=parametro->P(i)/parametro->N();
        }
///Coeficiente Linear
    a = (sy-(n*sx*sxy-sx*sx*sy)/(n*sxx-sx*sx))/n;  
///Coeficiente Angular
    b = (n*sxy-sx*sy)/(n*sxx-sx*sx);                
}

/*
void CRegLin::Est(CRes* parametro2)
{
     double soma=0.0;
     media=0.0;
     minimo=0.0;
     maximo=0.0;
     for (int i=0; i<paramentro2->N(); i++)
     {
         soma+=paramentro2->P(i);
     }
     media=soma/parametro2->N();
     
     for (int i=0; i<parametro2->N(); i++)
     {
         if (maximo<parametro2->P(i))
         {  maximo=parametro2->p(i);}
     }
     
     minimo=maximo;
     for (int i=0; i<parametro2->N(); i++)
     {
         if (minimo>parametro2->P(i))
         {  minimo=parametro2->p(i);}
     }
}
*/         
