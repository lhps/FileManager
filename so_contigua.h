//
// Created by Lucas Henrique on 01/09/2018.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>

#define MAX_BLOCO_DIR 100 // Quantidade de blocos reservados para diretório
#define MAX_BLOCO_ARQ 900 // Quantidade de blocos reservados para arquivos
#define MAX_TAMANHO_BLOCO 32 // tamanho do bloco


using namespace std;

#ifndef SISTEMAS_OPERACIONAIS_SO_CONTIGUA_H
#define SISTEMAS_OPERACIONAIS_SO_CONTIGUA_H

class HDCore{
private:
    char blocoDiretorio[MAX_BLOCO_DIR][MAX_TAMANHO_BLOCO];
    char blocoArquivo[MAX_BLOCO_ARQ][MAX_TAMANHO_BLOCO];
    char nomeHD[30];
    string PATH;
public:
    HDCore();
    //funções para manipular o HD
    void ListHd();
    void DelHd(char nome[]);
    bool inicializarHd(char nome[]);
    bool CriarHd(char nome[]);
    bool FormatarHd(char nome[]);
    bool TypeHd(char nome[], int flag);
    void Salvar(char nome[]);

    //funções para manipular arquivos
    bool CriarArquivo(char nome[],char conteudo[], int flag);
    bool RemoveArquivo(char nome[]);
    bool TypeArquivo(char nome[]);

    //funções para manipulação de blocos

    int FindBlocoDirVazio();
    int FindBlocoArqVazio(int QtBloco);
    int FindArquivoPorNome(char nome[]);

    bool Dir();
};



#endif //SISTEMAS_OPERACIONAIS_SO_CONTIGUA_H
