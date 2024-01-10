#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    srand(time(0));

    cout << "Bem-Vindo ao Bingoh! Diverte-te!" << endl;

    int maxNumber;
    cout << "Tenta a sorte e escolhe um número até 75!" << endl;
    cin >> maxNumber;

    if (maxNumber <= 1 || maxNumber >= 75) {
        cout << "Assim n dá bro, ATÉ 75!" << endl;
        return 1;
    }

    char choice;
    vector<int> sortedNumbers;

    cout << "Queres fazer um sorteio? (s/n): ";
    cin >> choice;

    while (choice == 's' || choice == 'S') {
        int newNumber = rand() % maxNumber + 1;
        sortedNumbers.push_back(newNumber);

        for (int i = 0; i < sortedNumbers.size(); i++) {
            cout << "Número sorteado: " << sortedNumbers[i] << endl;

            if (i > 0) {
                cout << "Número anterior: " << sortedNumbers[i - 1] << endl;
            }
        }

        cout << "Queres continuar o sorteio? (s/n): ";
        cin >> choice;
    }

    int cardCount;
    cout << "Escreve a quantidade de cartões a serem gerados: ";
    cin >> cardCount;

    for (int i = 1; i <= cardCount; i++) {
        string filename = "card_" + to_string(i) + ".txt";
        ofstream file(filename);

        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                file << "x  ";
            }
            file << endl;
        }

        file.close();
        cout << "O cartão foi gerado!: " << filename << endl;
    }

    return 0;
}
