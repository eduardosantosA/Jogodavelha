#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> jv() {
    int a = 1;
    vector<vector<string>> v(5, vector<string>(11, " "));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            if (i % 2 != 0) {
                v[i][j] = "-";
            } else if (j == 1 || j == 5 || j == 9) {
                v[i][j] = to_string(a);
                a++;
            } else if (j == 3 || j == 7) {
                v[i][j] = "|";
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 11; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    return v;
}

int main() {
    do {
        vector<vector<string>> v = jv();
        int aux = 0, b;
        bool c = false;

        for (int n = 0; n < 9; n++) {
            bool jr = false;
            if (aux % 2 == 0) {
                while (jr == false) {
                    bool e = false;
                    cout << "Jogador 1 (X), escolha uma posição: ";
                    cin >> b;
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 11; j++) {
                            if (v[i][j] == to_string(b)) {
                                v[i][j] = "X";
                                e = true;
                                jr = true;
                                break;
                            }
                        }
                        if (e == true) break;
                    }
                    if (!e) cout << "Posicao invalida ou ja ocupada! Tente novamente." << endl;
                }
                aux++;
            } else if (aux % 2 != 0) {
                while (jr == false) {
                    bool e = false;
                    cout << "Jogador 2 (O), escolha uma posição: ";
                    cin >> b;
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 11; j++) {
                            if (v[i][j] == to_string(b)) {
                                v[i][j] = "O";
                                e = true;
                                jr = true;
                                break;
                            }
                        }
                        if (e == true) break;
                    }
                    if (!e) cout << "Posicao invalida ou ja ocupada! Tente novamente." << endl;
                }
                aux++;
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 11; j++) {
                    cout << v[i][j];
                }
                cout << endl;
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 11; j++) {
                    if (i % 2 == 0 && v[i][1] == "X" && v[i][1] == v[i][5] && v[i][1] == v[i][9]) {
                        cout << "Parabéns! Jogador 1 venceu!" << endl;
                        c = true; break;
                    } else if (i % 2 == 0 && v[i][1] == "O" && v[i][1] == v[i][5] && v[i][1] == v[i][9]) {
                        cout << "Parabéns! Jogador 2 venceu!" << endl;
                        c = true; break;
                    } else if ((j == 1 || j == 5 || j == 9) && v[0][j] == "X" && v[0][j] == v[2][j] && v[0][j] == v[4][j]) {
                        cout << "Parabéns! Jogador 1 venceu!" << endl;
                        c = true; break;
                    } else if ((j == 1 || j == 5 || j == 9) && v[0][j] == "O" && v[0][j] == v[2][j] && v[0][j] == v[4][j]) {
                        cout << "Parabéns! Jogador 2 venceu!" << endl;
                        c = true; break;
                    } else if (v[2][5] == "X" && (v[0][1] == "X" && v[4][9] == "X" || v[0][9] == "X" && v[4][1] == "X")) {
                        c = true; cout << "Parabéns! Jogador 1 venceu!" << endl;
                        break;
                    } else if (v[2][5] == "O" && (v[0][1] == "O" && v[4][9] == "O" || v[0][9] == "O" && v[4][1] == "O")) {
                        cout << "Parabéns! Jogador 2 venceu!" << endl;
                        c = true; break;
                    }
                }
                if (c) break;
            }
            if (c) break;
        }

        if (c == false) {
            cout << "Empate! Nenhum jogador venceu." << endl;
        }

        char r;
        cout << "Deseja reiniciar o jogo? (S/N)" << endl;
        cin >> r;
        if (r != 'S' && r != 's') {
            return 0;
        }
    } while (true);

    return 0;
}