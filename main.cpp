#include <fstream> 

int main() {
    std::ifstream arquivo("entrada.txt");

    if (arquivo.fail()){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
}