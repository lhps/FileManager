//
// Created by Lucas Henrique on 01/09/2018.
//
#include "so_contigua.h"


HDCore::HDCore(){
    nomeHD[0] = '*';
    PATH = "HDVirtual\\";//{"C:\\HDVirtual\\"};
}

void HDCore::ListHd() {
    char buffer[30];
    int i;

    strcpy(buffer,"dir /B ");
    for(i=0;i<PATH.length();i++){
        buffer[(i+7)] = PATH[i];
    }
    buffer[(i+7)] = 0;

    printf("\n");
    system(buffer);
    printf("\n");
}


bool HDCore::inicializarHd(char nome[]) {
    FILE *f;
    char caminho[100];
    int i;

    for (i = 0;i < PATH.length(); i++) {
        caminho[i] = PATH[i];
    }
    caminho[i]=0;

    try{
        // extensão do HD é adicionada
        strcpy(nomeHD,nome);
        strcat(nomeHD,".flp");
        strcat(caminho,nomeHD);

        //abertura do HD

        if((f = fopen(caminho,"rt"))==nullptr){
            printf("\tErro na leitura do HD: %s\n",nome);
            nomeHD[0] = 0;
            return false;
        }

        printf("\n\tInicializando HD...\n");

        //buffer que armazena o HD  em memoria
        char buffer[MAX_BLOCO_DIR+MAX_BLOCO_ARQ][MAX_TAMANHO_BLOCO+1];

        // O cursor é posicionado no inicio do arquivo
        fseek(f,0,SEEK_SET);

        //O HD é lido e armazenado no buffer

        fread(buffer,MAX_TAMANHO_BLOCO+1,MAX_BLOCO_DIR+MAX_BLOCO_ARQ,f);

        //Carrega o bloco de diretorios

        for(int i=0;i<MAX_BLOCO_DIR;i++){
            for (int j = 0; j < MAX_TAMANHO_BLOCO; ++j) {
                blocoDiretorio[i][j] = buffer[i][j];
            }
        }

        // Carrega bloco de arquivos
        for(int i=0; i<MAX_BLOCO_ARQ; i++){
            for(int j=0; j<MAX_TAMANHO_BLOCO; j++){
                blocoArquivo[i][j] = buffer[(MAX_BLOCO_DIR + i)][j];
            }
        }
        fclose(f);

        printf("\tInicializacao concluida com sucesso.\n\n");
        return true;
    }
    catch (exception &e){
        cout<<"Exception: "<<e.what()<<endl;

        return false;
    }
}

bool HDCore::CriarHd(char *nome) {
    FILE *f;
    char caminho[30];
    int i;

    //monta o caminho do HD
    for(i=0;i<PATH.length();i++){
        caminho[i] = PATH[i];
    }
    caminho[i] = 0;

    //adiciona a extensao
    strcat(caminho, nome);
    strcat(caminho,".flp");

    printf("\n\tCriado HD %s...\n",nome);

    // Abre o HD em questão
    if((f = fopen(caminho,"wt"))==nullptr){
        cout<<"\tErro ao criar o HD"<<endl;
    }

    printf("\tFormatando o HD..\n\n");

    //Formatação do HD criado

    for(int i=0;i<(MAX_BLOCO_DIR + MAX_BLOCO_ARQ);i++){
        for (int j = 0; j < MAX_TAMANHO_BLOCO; ++j) {
            fprintf(f,"f");
        }
        fprintf(f,"\n");
    }

    fclose(f);

    printf("\tHD criado com sucesso.\n\n");

    // Depois de concluida a criacao ,o HD sera iniciado
    inicializarHd(nome);
}
