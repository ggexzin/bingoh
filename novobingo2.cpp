#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAX_NUMEROS = 100;

void mostrarPainelBingo(const int todosNumeros[], int tamanho, const int numerosSorteados[], int tamanhoSorteados) {
    cout << "BINGOH!" << endl;

    for (int i = 1; i <= MAX_NUMEROS; ++i) {
        auto it = find(todosNumeros, todosNumeros + tamanho, i);
        if (it != todosNumeros + tamanho) {
            int indice = distance(todosNumeros, it);
            if (find(numerosSorteados, numerosSorteados + tamanhoSorteados, i) != numerosSorteados + tamanhoSorteados) {
                cout << "\033[1;31m| " << setw(2) << i << " |\033[0m ";
            } else {
                cout << "| " << setw(2) << i << " | ";
            }

            if ((indice + 1) % 15 == 0) {
                cout << endl;
            }
        }
    }

    cout << endl;
}

void modoAutomatico(int maxNumero, int todosNumeros[], int numerosSorteados[], int &contadorSorteados) {
    char escolha = 's';
    
    while (escolha == 's' || escolha == 'S') {
        int novoNumero = rand() % maxNumero + 1;
        numerosSorteados[contadorSorteados++] = novoNumero;

        cout << "\033[1;33m[★] Número sorteado: " << novoNumero << " [★]\033[0m" << endl;

        mostrarPainelBingo(todosNumeros, MAX_NUMEROS, numerosSorteados, contadorSorteados);

        cout << "Queres continuar o sorteio? (s/n): ";
        cin >> escolha;
    }
}

void modoManual(int maxNumero, int todosNumeros[], int numerosSorteados[], int &contadorSorteados) {
    char escolha = 's';
    
    while (escolha == 's' || escolha == 'S') {
        int novoNumero;
        cout << "Digite o número sorteado manualmente: ";
        cin >> novoNumero;

        if (novoNumero < 1 || novoNumero > maxNumero) {
            cout << "Número inválido. Deve ser entre 1 e " << maxNumero << "." << endl;
            continue;
        }

        numerosSorteados[contadorSorteados++] = novoNumero;

        mostrarPainelBingo(todosNumeros, MAX_NUMEROS, numerosSorteados, contadorSorteados);

        cout << "Queres continuar o sorteio manual? (s/n): ";
        cin >> escolha;
    }
}

int main() {
    srand(time(0));

    cout << "Bem-Vindo ao Bingoh! Diverte-te!" << endl;

    int maxNumero;
    cout << "Escolhe a quantidade máxima de números para o sorteio (75, 90 ou 100): ";
    cin >> maxNumero;

    if (maxNumero != 75 && maxNumero != 90 && maxNumero != 100) {
        cout << "Opção inválida. Escolhe 75, 90 ou 100." << endl;
        return 1;
    }

    char escolha;
    int todosNumeros[MAX_NUMEROS];
    for (int i = 1; i <= maxNumero; ++i) {
        todosNumeros[i - 1] = i;
    }

    int numerosSorteados[MAX_NUMEROS];
    int contadorSorteados = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1. Modo Automático\n";
        cout << "2. Modo Manual (padrão)\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case '1':
                modoAutomatico(maxNumero, todosNumeros, numerosSorteados, contadorSorteados);
                break;
            case '2':
                modoManual(maxNumero, todosNumeros, numerosSorteados, contadorSorteados);
                break;
            case '3':
                cout << "Adeus! Até a próxima." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }

    } while (escolha != '3');

    int quantidadeCartoes;
    cout << "Escreve a quantidade de cartões a serem gerados: ";
    cin >> quantidadeCartoes;

    for (int i = 1; i <= quantidadeCartoes; i++) {
        string nomeArquivo = "cartao_" + to_string(i) + ".txt";
        ofstream arquivo(nomeArquivo);

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                arquivo << "x  ";
            }
            arquivo << endl;
        }

        arquivo.close();
        cout << "O cartão foi gerado!: " << nomeArquivo << endl;
    }

    return 0;
}
