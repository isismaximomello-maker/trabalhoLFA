#include <string>

enum class Token {
    NUM,
    VAR,
    OPB,
    ABREP,
    FECHAP,
    ABRECO,
    FECHACO,
    ABRECH,
    FECHACH,
    EOF_token
};

const std::string DIGITOS = "0123456789";
const std::string LETRAS = "abcdefghijklmnopqrstuvwxyz";
const std::string OPERADORES = "+-*/";
const std::string SEPARADORES = "()[]{}";

const std::string VAZIOS = " \r\n\t";