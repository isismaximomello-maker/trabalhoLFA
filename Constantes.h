
#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>

enum class Token {
    NUM,
    VAR,
    MAIS,
    MENOS,
    VEZES,
    DIVIDE,
    ABREP,
    FECHAP,
    ABRECO,
    FECHACO,
    ABRECH,
    FECHACH,
    EOF_TOKEN
};


static const std::string DIGITOS = "0123456789";
static const std::string LETRAS="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const std::string UNDERLINE = "_";
static const std::string OPERADORES = "+-*/";
static const std::string P1 = "(";
static const std::string P2 = ")";
static const std::string Col1 = "[";
static const std::string Col2 = "]";
static const std::string Cha1 = "{";
static const std::string Cha2 = "}";
static const std::string VAZIOS = " \r\n\t";
static const char EOF_CHAR = '\0';

#endif