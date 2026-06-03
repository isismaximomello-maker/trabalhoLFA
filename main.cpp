#include <iostream>
#include <string>
#include "Analisador.cpp"

std::string tokenToString(Token t) {
    switch (t) {
        case Token::NUM: return "NUM";
        case Token::VAR: return "VAR";
        case Token::MAIS: return "MAIS";
        case Token::MENOS: return "MENOS";
        case Token::VEZES: return "VEZES";
        case Token::DIVIDE: return "DIVIDE";
        case Token::ABREP: return "ABREP";
        case Token::FECHAP: return "FECHAP";
        case Token::ABRECO: return "ABRECO";
        case Token::FECHACO: return "FECHACO";
        case Token::ABRECH: return "ABRECH";
        case Token::FECHACH: return "FECHACH";
        case Token::EOF_TOKEN: return "EOF";
        default: return "DESCONHECIDO";
    }
}

int main() {
    std::string nomeArquivo;
    std::cout << "Digite o nome do arquivo de entrada: (com o .txt)";
    std::cin >> nomeArquivo;

    try {
        Analisador analisador(nomeArquivo);

        Token tok;
        do {
            tok = analisador.iniciarMaquinaDeMoore();
            std::cout << tokenToString(tok) << " ";
        } while (tok != Token::EOF_TOKEN);

        std::cout << std::endl << "Analise lexica realizada com sucesso." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}