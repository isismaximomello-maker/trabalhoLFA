#include <iostream>
#include <string>
#include "Analisador.cpp"

std::string tokenToString(Token t) {
    switch (t) {
        case Token::NUM: return "\nNUM";
        case Token::VAR: return "\nVAR";
        case Token::MAIS: return "\nMAIS";
        case Token::MENOS: return "\nMENOS";
        case Token::VEZES: return "\nVEZES";
        case Token::DIVIDE: return "\nDIVIDE";
        case Token::ABREP: return "\nABREP";
        case Token::FECHAP: return "\nFECHAP";
        case Token::ABRECO: return "\nABRECO";
        case Token::FECHACO: return "\nFECHACO";
        case Token::ABRECH: return "\nABRECH";
        case Token::FECHACH: return "\nFECHACH";
        case Token::EOF_TOKEN: return "\nEOF";
        default: return "\nDESCONHECIDO";
    }
}

int main() {
    std::string nomeArquivo;
    std::cout << "Digite o nome do arquivo de entrada (com o .txt): ";
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