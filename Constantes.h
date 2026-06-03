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
    EOF_TOKEN
};

const std::string DIGITOS = "0123456789";
const std::string LETRAS = "abcdefghijklmnopqrstuvwxyz";
const std::string UNDERLINE = "_";
const std::string OPERADORES = "+-*/";
const std::string P1 = "(";
const std::string P2 = ")";
const std::string Col1 = "[";
const std::string Col2 = "]";
const std::string Cha1 = "{";
const std::string Cha2 = "}";
const std::string VAZIOS = " \r\n\t";
const char EOF_CHAR = '\0';