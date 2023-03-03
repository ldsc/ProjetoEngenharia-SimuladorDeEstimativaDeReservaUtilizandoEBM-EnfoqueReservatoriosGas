///Classe herdeira de CResGas para Reservatorio de Gas seco anormalmente pressurizado

#ifndef CRESGASSECOPRES_H
#define CRESGASSECOPRES_H

#include <cmath>
#include <iostream>
#include "CResGas.h"

///Heranca Simples
class CResGasSecoPres: public CResGas
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
       double cw, cf, swi;     

///Torna publico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar o valor da saturacao inicial de agua
float Swi() const {return swi;}
///Declara o metodo para pegar o valor da compressibilidade da agua
double Cw() const {return cw;}
///Declara o metodo para pegar o valor da compressibilidade da formacao
double Cf() const {return cf;}

///Construtor default da classe
CResGasSecoPres();   
};
#endif
