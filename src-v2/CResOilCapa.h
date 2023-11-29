///Classe herdeira de CResOil para Mecanismo de Capa de Gas

#ifndef CRESOILCAPA_H
#define CRESOILCAPA_H

#include <cmath>
#include <iostream>
#include "CResOil.h"

///Heranca Simples
class CResOilCapa: public CResOil
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara os vetores que armazenaram os valores de rp, rs, bg
       std::vector<double> rp, rs, bg;
///declara os atributos que armazenaram os valores correspondentes a rsi e bgi
       double rsi, bgi;     

///Torna puplico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar os valores de rp
double Rp(int i) const {return rp[i];}
///Declara o metodo para pegar os valores de rs
double Rs(int i)  const {return rs[i];}
///Declara o metodo para pegar os valores de fator volume de formacao do gas
double Bg(int i)  const {return bg[i];}
///Declara o metodo para pegar os valores de rasao de solubilidade do gas no oleo
double Rsi() const {return rsi;}
///Declara o metodo para pegar os valores de fotor de formacao do gas
double Bgi() const {return bgi;}

///Construtor default da classe
CResOilCapa();   
};
#endif
