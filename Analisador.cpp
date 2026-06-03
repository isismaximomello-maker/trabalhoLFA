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


        Analisador(const std::string& nomeArquivo) {
            if (!leitura.abrirArquivo(nomeArquivo)) {   // agora aceita const&
                throw std::runtime_error("Nao foi possivel abrir o arquivo.");
            }
            leitura.leProxCaractere();
        }

        void erroLexico(char encontrado, const std::string esperado){
            printf("Erro léxico: caractere encontrado: %c \n Era (m) esperado (s): %s\n", encontrado, esperado.c_str());
        }



        Token iniciarMaquinaDeMoore(){
            return s0();
        }

        Token s0(){

            leitura.getCaractereAtual();

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
            return Token::EOF_TOKEN;   // valor qualquer, mas necessário para compilar
        }

        Token s1(){
           // leitura.leProxCaractere(); //le o proximo

            while (leitura.caractereAtualEsta(DIGITOS)){
                leitura.leProxCaractere();
            }
            if (leitura.caractereAtualEsta(VAZIOS)|| leitura.eof()){ //caso de espaço, enter e tab
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
            if (leitura.caractereAtualEsta(VAZIOS)|| leitura.eof()){ //caso de espaço, enter e tab
                return Token::VAR;

            } else {
                erroLexico(leitura.getCaractereAtual(), DIGITOS + LETRAS + UNDERLINE);
            }

            return Token::VAR;
        }

        Token s3(){
            char op = leitura.getCaractereAtual();
            leitura.leProxCaractere();  // consome o operador
            switch (op) {
                case '+': return Token::MAIS;
                case '-': return Token::MENOS;
                case '*': return Token::VEZES;
                case '/': return Token::DIVIDE;
                default: erroLexico(op, OPERADORES);
            }
            return Token::MAIS; // nunca alcançado
        }
        

        Token s4(){
            leitura.leProxCaractere();
            return Token::ABREP;
        }

        Token s5(){
            leitura.leProxCaractere();
            return Token::FECHAP;
        }

        Token s6(){
            leitura.leProxCaractere();
            return Token::ABRECO;
        }

        Token s7(){
            leitura.leProxCaractere();
            return Token::FECHACO;
        }

        Token s8(){
            leitura.leProxCaractere();
            return Token::ABRECH;
        }

        Token s9(){
            leitura.leProxCaractere();
            return Token::FECHACH;
        }
};