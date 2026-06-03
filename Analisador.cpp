#include <iostream>
#include <fstream>
#include <string>
#include "Constantes.h"
#include "Leitura.cpp"

/*
Analisador
├── recebe uma Leitura
├── executa a máquina de estados
├── monta lexemas
├── identifica tokens
├── detecta erros léxicos
└── retorna o próximo token
*/

class Analisador {
    protected:
        Leitura leitura;
        std::string lexema;

    public:
        void limpaString(){
            lexema = ""; //limpa lexema para montar o próximo
        }

        std::string getLexema(){
            return this->lexema;
        }

        Token s0(){
            while (leitura.caractereAtualEsta(VAZIOS)){

                leitura.leProxCaractere();
            }
            if (leitura.caractereAtualEsta(DIGITOS))
                    s1();
                else if (leitura.caractereAtualEsta(LETRAS))
                    s2();
                else if (leitura.caractereAtualEsta(OPERADORES))
                    s3();
                else if (leitura.caractereAtualEsta(P1))
                    s4();
                else if (leitura.caractereAtualEsta(P2))
                    s5();
                else if (leitura.caractereAtualEsta(Col1))  
                    s6();
                else if (leitura.caractereAtualEsta(Col2))  
                    s7();
                else if (leitura.caractereAtualEsta(Cha1))  
                    s8();
                else if (leitura.caractereAtualEsta(Cha2))  
                    s9();
                else if (leitura.eof())
                    return Token::EOF_TOKEN;
                else {
                    printf("Erro léxico: caractere '%c' não reconhecido na linha %d\n", leitura.getCaractereAtual(), leitura.getLinha());
                    limpaString();
                    leitura.leProxCaractere();
                }
        }

        Token s1(){

            while (leitura.caractereAtualEsta(DIGITOS)){
                lexema = lexema + leitura.getCaractereAtual(); //adiciona caractere atual ao lexema
                leitura.leProxCaractere();
            }
            limpaString();
            return Token::NUM;
        }

        Token s2(){

            while (leitura.caractereAtualEsta(DIGITOS + LETRAS + UNDERLINE)){ //concatena todas os conjuntos de caracteres válidos para variável
                lexema = lexema + leitura.getCaractereAtual(); //adiciona caractere atual ao lexema
                leitura.leProxCaractere();
            }
            limpaString();
            return Token::VAR;
        }

        Token s3(){
            limpaString();
            return Token::OPB;
        }

        Token s4(){
            limpaString();
            return Token::ABREP;
        }

        Token s5(){
            limpaString();
            return Token::FECHAP;
        }

        Token s6(){
            limpaString();
            return Token::ABRECO;
        }

        Token s7(){
            limpaString();
            return Token::FECHACO;
        }

        Token s8(){
            limpaString();
            return Token::ABRECH;
        }

        Token s9(){
            limpaString();
            return Token::FECHACH;
        }
};