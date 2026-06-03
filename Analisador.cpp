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
        char c;

    public:

        void erroLexico(char encontrado, const std::string esperado){
            printf("Erro léxico: caractere encontrado: %c \n Era (m) esperado (s): %s\n", encontrado, esperado);
        }

        Token s0(){
            while (leitura.caractereAtualEsta(VAZIOS))
                leitura.leProxCaractere();

            if (leitura.caractereAtualEsta(DIGITOS))
                return s1();
            else if (leitura.caractereAtualEsta(LETRAS))
                return s2();
            else if (leitura.caractereAtualEsta(OPERADORES))
                return s3();
            else if (leitura.caractereAtualEsta(P1))
                return s4();
            else if (leitura.caractereAtualEsta(P2))
                return s5();
            else if (leitura.caractereAtualEsta(Col1))  
                return s6();
            else if (leitura.caractereAtualEsta(Col2))  
                return s7();
            else if (leitura.caractereAtualEsta(Cha1))  
                return s8();
            else if (leitura.caractereAtualEsta(Cha2))  
                return s9();
            
            else if (leitura.eof())
                return Token::EOF_TOKEN;

            erroLexico(leitura.getCaractereAtual(), DIGITOS + LETRAS + OPERADORES + P1 + P2 + Col1 + Col2 + Cha1 + Cha2);
            return;
        }

        Token s1(){
            leitura.leProxCaractere(); //le o proximo

            while (leitura.caractereAtualEsta(DIGITOS)){
                leitura.leProxCaractere();
            }
            if (leitura.caractereAtualEsta(VAZIOS)){ //caso de espaço, enter e tab
                return Token::NUM;

            } else { //caso de erro
                erroLexico(leitura.getCaractereAtual(), DIGITOS);
            }
            
            //ultimo caso == EOF -> só retorna

            return Token::NUM;
        }

        Token s2(){
            leitura.leProxCaractere();

            while (leitura.caractereAtualEsta(DIGITOS + LETRAS + UNDERLINE)){ //concatena todas os conjuntos de caracteres válidos para variável
                leitura.leProxCaractere();
            }
            if (leitura.caractereAtualEsta(VAZIOS)){ //caso de espaço, enter e tab
                return Token::VAR;

            } else {
                erroLexico(leitura.getCaractereAtual(), DIGITOS + LETRAS + UNDERLINE);
            }

            return Token::VAR;
        }

        Token s3(){
            return Token::OPB;
        }

        Token s4(){
            return Token::ABREP;
        }

        Token s5(){
            return Token::FECHAP;
        }

        Token s6(){
            return Token::ABRECO;
        }

        Token s7(){
            return Token::FECHACO;
        }

        Token s8(){
            return Token::ABRECH;
        }

        Token s9(){
            return Token::FECHACH;
        }
};