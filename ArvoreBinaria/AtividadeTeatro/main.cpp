//Guilherme Augusto Deitos Alves
//Gabriel Yudi Leite Higuchi
//Notamos que por algum motivo o compilador do codeblocks dá erro com nosso codigo, porém no g++(o que eu uso pra programar no vscode) funciona bonitinho
#include "Classes.h"

void showMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Inserir reserva" << endl;
    cout << "2. Remover reserva" << endl;
    cout << "3. Atualizar nome da reserva" << endl;
    cout << "4. Buscar reservas por nome" << endl;
    cout << "5. Balancear poltronas" << endl;
    cout << "6. Mostrar todas as reservas" << endl;
    cout << "0. Sair" << endl;
    cout << "================" << endl;
}

int main() {
    Arvore arvore;

    int opcao;
    do {
        showMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                system("clear");
                
                int valor;
                string nome;
                cout << "Digite o numero da poltrona: ";
                cin >> valor;
                cout << "Digite o nome da reserva: ";
                cin >> nome;
                arvore.inserir(valor, nome);
               
                break;
            }
            case 2: {
                system("clear");
                int op;
                cout << "[1] Remover por nome\n[2] Remover por poltrona" << endl;
                cin >> op;
                if(op == 1){
                    string nome;
                    cout << "Digite o nome da reserva a ser removida: ";
                    cin >> nome;
                    arvore.removeNoByName(nome);
                } else if(op == 2){
                    int valor;
                    cout << "Digite o numero da poltrona a ser removida: ";
                    cin >> valor;
                    arvore.removeNo(valor);
                } else {
                    cout << "Opcao invalida. Tente novamente." << endl;
                }
                break;
            }
            case 3: {
                system("clear");
                int op;
                cout << "[1] Atualizar a poltrona\n[2] Atualizar o nome da reserva\n " << endl;
                cin >> op;

                if(op == 1){
                    int valor, novoValor;
                    cout << "Digite o numero da poltrona a ser atualizada: ";
                    cin >> valor;
                    cout << "Digite o novo numero da poltrona: ";
                    cin >> novoValor;
                    arvore.atualizarPoltrona(arvore.getRaiz(), valor, novoValor);
                } else if(op == 2){
                    int valor;
                    string nome, novoNome;
                    cout << "Digite o nome da reserva a ser atualizada: ";
                    cin >> nome;
                    cout << "Digite o novo nome: ";
                    cin >> novoNome;


                    cout << "Deseja atualizar o nome de todas as poltronas com o nome " << nome << "? [1] Sim [2] Nao" << endl;
                    cin >> op;

                    if(op == 2){
                        cout << "Digite o numero da poltrona a ser atualizada: ";
                        cin >> valor;
                    } 

                    arvore.atualizarNome(arvore.getRaiz(), nome, novoNome, op, valor);
                } else {
                    cout << "Opcao invalida. Tente novamente." << endl;
                }
                break;
            }
            case 4: {
                system("clear");
                string nome;
                cout << "Digite o nome a ser buscado: ";
                cin >> nome;
                IntList* reservas = arvore.buscaNome(nome);
                if (reservas->isEmpty()) {
                    cout << "Nenhuma reserva encontrada com esse nome." << endl;
                } else {
                    cout << "Reservas encontradas:" << endl;

                    for (IntNode* reserva = reservas->getHead(); reserva != nullptr; reserva = reserva->next){
                        cout << "Poltrona: " << reserva->nome << endl;
                        cout << "Nome vinculado: " << reserva->data << endl;
                    }
                }
                break;
            }
            case 5: {
                arvore.balanceamento(arvore.getRaiz());
                break;
            }
            case 6: {
                system("clear");
                arvore.emOrdem(arvore.getRaiz(), 1);
                break;
            }
            case 0: {
                cout << "Encerrando o programa..." << endl;
                break;
            }
            default: {
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
