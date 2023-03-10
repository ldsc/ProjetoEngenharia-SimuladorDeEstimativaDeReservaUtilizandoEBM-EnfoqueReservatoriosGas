///Classe Derivada de CRes
///Possui os dados iniciais de Reservatorio de ?leo
///Classes Derivadas: COilCapa e COilInf

#ifndef CRESOIL_H
#define CRESOIL_H

#include <iostream>
#include <cmath>
#include <vector>
#include "CRes.h"

///Heranca Simples
class CResOil: public CRes
{
///Protected permite as classes derivadas usar os atributos declarados aqui
protected:
///Declara o vetor que armazena o volume de oleo produzido 
          std::vector<double> np;
///Declara o vetor que armazena o volume do fator volume de formacao
          std::vector<double> bo;
///declara os atributos que armazenaram os valores correspondentes a copressibilidade da agua e da formacao, saturacao inicial de agua, pressao inicial e fator volume de formacao inicial do oleo, respectivamente
          double cw, cf, swi, pi, boi;

///Torna puplico os proximos metodos
public:
///Declara o metodo calculo (polimorfismo)
virtual void Calc();
///Declara o metodo para pegar os valores de oleo produzido
double Np(int i) const {return np[i];}
///Declara o metodo para pegar os valores dos fatores de formacao do oleo
double Bo(int i) const {return bo[i];}
///Declara o metodo para pegar o valor da saturacao inicial de agua
double Swi() const {return swi;}
///Declara o metodo para pegar o valor da compressibilidade da agua
double Cw() const {return cw;}
///Declara o metodo para pegar o valor da compressibilidade da formacao
double Cf() const {return cf;}
///Declara o metodo para pegar o valor da pressao incial
double Pi() const {return pi;}
///Declara o metodo para pegar o valor do fator volume de formacao inicial do oleo
double Boi() const {return boi;}

///Construtor default da classe
CResOil();
};

#endif
