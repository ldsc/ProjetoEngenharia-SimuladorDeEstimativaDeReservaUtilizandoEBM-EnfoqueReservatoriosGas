///Classe herdeira de CResGas para Reservatorio de Gas Condensado nao Retrogrado

#ifndef CRESGASCONDNAORETRO_H
#define CRESGASCONDNAORETRO_H

#include <cmath>
#include <iostream>
#include <vector>
#include "CResGas.h"

///Heranca Simples
class CResGasCondNaoRetro: public CResGas
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara os vetores que armazenaram os valores de volume de gas produzido parcial, volume de gas equivalente, volume de vapor de agua equivalente
//a agua produzida, volume total de gas produzido, volume de agua produzida, volume de gas condensado produzido
       std::vector<double> gpp, gec, gew, gpt, vw, vc;
///Declara a variável que representa o fator volume de formacao inicial do gas, densidade do condensado produzido, massa molecular do condensado produzido
       double bgi, dc, mc;
       
///Torna publico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
void Calc();
///Declara o metodo para pegar os valores do volume de gas produzido parcial
double Gpp(int i) const {return gpp[i];}
///Declara o metodo para pegar os valores do volume de gas equivalente
double Gec(int i) const {return gec[i];}
///Declara o metodo para pegar os valores do volume de vapor de agua equivalente a agua produzida
double Gew(int i) const {return gew[i];}
///Declara o metodo para pegar os valores do volume total de gas produzido
double Gpt(int i) const {return gpt[i];}
///Declara o metodo para pegar os valores de agua produzida
double Vw(int i) const {return vw[i];}
///Declara o metodo para pegar os valores de gas condensado produzido
double Vc(int i) const {return vc[i];}
///Declara o metodo para pegar o valor inicial do fator volume de formacao
double Bgi() const {return bgi;}
///Declara o metodo para pegar a densidade do condensado produzido
double Dc() const {return dc;}
///Declara o metodo para pegar a massa molecular do condensado produzido
double Mc() const {return mc;}

///Construtor default da classe
CResGasCondNaoRetro();
      
};
#endif
