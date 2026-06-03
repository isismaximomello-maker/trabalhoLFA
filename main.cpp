#include <iostream>
#include <string>
#include "Analisador.cpp"   // inclui toda a implementação

// Função auxiliar para converter Token para string
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << std::endl;
        return 1;
    }

    try {
        Analisador analisador(argv[1]);

        Token tok;
        do {
            tok = analisador.iniciarMaquinaDeMoore();
            std::cout << tokenToString(tok) << " ";
        } while (tok != Token::EOF_TOKEN);

        std::cout << std::endl << "Analise lexica realizada com sucesso." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}
