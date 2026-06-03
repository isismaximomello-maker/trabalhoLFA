/*
RESPONSÁVEL POR
abrir arquivo
ler próximo caractere
informar caractere atual
detectar EOF
controlar linha
*/

#include <fstream>
#include <stdio.h>
#include <string>
#include "Constantes.h"


class Leitura {
    private:
        std::ifstream arquivo;
        char caractereAtual = EOF_CHAR; //inicializa com EOF_CHAR para indicar que ainda não leu nenhum caractere

    public:
        bool abrirArquivo(const std::string& nomeArquivo){ //& para passar por referência

            arquivo.open(nomeArquivo);

            if(arquivo.is_open()){
                printf("Arquivo aberto com sucesso!\n");
                return true;
            } else {
                printf("Erro ao abrir o arquivo!\n");
                return false;
            }
        }

        void fecharArquivo(){
            arquivo.close();
        }

        //le o proximo caractere. Se fim, retorna EOF
        void leProxCaractere(){

            char caractere;
            if (arquivo.get(caractere)){ // Lê o próximo caractere do arquivo
                this->caractereAtual = caractere; // Armazena o caractere atual
            }
            else
                this->caractereAtual = EOF_CHAR; //não conseguiu ler == fim do arquivo
        }

        //Verifica se o caractere atual está em 's'
        bool caractereAtualEsta(const std::string& s){ //& para passar por referência
            
            for (char c : s){ //percorre elementos de s
                if (caractereAtual == c)
                    return true;
            }

            return false;
        }
        
        //retorna caractere atual
        char getCaractereAtual(){
            return this->caractereAtual;
        }

        bool eof(){
            return this->caractereAtual == EOF_CHAR;
        }
};

