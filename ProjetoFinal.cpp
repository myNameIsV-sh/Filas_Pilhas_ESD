#include <iostream>
using namespace std;

typedef struct Pessoa {
    char CPF[12];
    char nome[50];
    int idade;
} Pessoa;

typedef struct celula {
    Pessoa pessoa;
    struct celula *prox;
} celula;

typedef struct Frasco {
    int quantidadeDoses = 5;
} Frasco;

void imprimeLista(celula *primeiro) {
    if (primeiro == NULL) {
        cout << "Lista Vazia" << endl;
    } else {
        while (primeiro != NULL) {
            cout << "Nome: " << primeiro->pessoa.nome << endl;
            primeiro = primeiro->prox;
        }
    }
    cout << endl;
}

void novoFilaAdd(celula *&primeiro, celula *&ultimoDaFila) {
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) {
        cout << "Erro ao alocar memória!" << endl;
        return;
    }

    cout << "Digite o CPF: ";
    cin >> novo->pessoa.CPF;
    cout << "Digite o nome: ";
    cin.ignore();
    cin.getline(novo->pessoa.nome, 50);
    cout << "Digite a idade: ";
    cin >> novo->pessoa.idade;

    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimoDaFila = novo;
    } else {
        ultimoDaFila->prox = novo;
        ultimoDaFila = novo;
    }
}

celula *removeFila(celula **primeiroDaFila) {
    if (*primeiroDaFila == NULL) {
        cout << "Fila Vazia" << endl;
        return NULL;
    } else {
        celula *temp = *primeiroDaFila;
        *primeiroDaFila = temp->prox;
        return temp;
    }
}

void empilharFrasco(celula **topo, Frasco *frasco) {
    celula *temp = (celula *)malloc(sizeof(celula));
    if (temp == NULL) {
        cout << "Erro ao alocar memória!" << endl;
        return;
    }
    temp->pessoa.idade = frasco->quantidadeDoses;
    temp->prox = *topo;
    *topo = temp;
}

celula *desempilharFrasco(celula **topo) {
    if (*topo == NULL) {
        cout << "Pilha Vazia" << endl;
        return NULL;
    } else {
        celula *temp = *topo;
        *topo = temp->prox;
        return temp;
    }
}

void vacinar(celula **fila, celula **topoFrascos, int &totalVacinados) {
    if (*fila == NULL) {
        cout << "Fila Vazia, não há pessoas para vacinar." << endl;
        return;
    }

    if (*topoFrascos == NULL) {
        cout << "Não há frascos disponíveis para vacinar." << endl;
        return;
    }

    celula *pessoa = removeFila(fila);
    if (pessoa != NULL) {
        int dosesRestantes = (*topoFrascos)->pessoa.idade;
        if (dosesRestantes > 0) {
            cout << "Vacinado: " << pessoa->pessoa.nome << endl;
            (*topoFrascos)->pessoa.idade--;
            totalVacinados++;
            if ((*topoFrascos)->pessoa.idade == 0) {
                cout << "Frasco desempilhado com 0 doses restantes." << endl;
                free(desempilharFrasco(topoFrascos));
            }
            free(pessoa);
        }
    }
}

int main() {
    celula *fila = NULL;
    celula *ultimoDaFila = NULL;
    celula *topoFrascos = NULL;

    for (int i = 0; i < 3; i++) {
        Frasco *frasco = (Frasco *)malloc(sizeof(Frasco));
        if (frasco == NULL) {
            cout << "Erro ao alocar memória para frasco!" << endl;
            return 1;
        }
        empilharFrasco(&topoFrascos, frasco);
    }

    int totalVacinados = 0;
    int opcao;

    do {
        cout << "Menu:\n";
        cout << "1. Adicionar pessoa na fila\n";
        cout << "2. Tirar pessoa da fila\n";
        cout << "3. Imprimir nomes de todo mundo da fila\n";
        cout << "4. Vacinar\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                novoFilaAdd(fila, ultimoDaFila);
                break;
            }
            case 2: {
                celula *removido = removeFila(&fila);
                if (removido != NULL) {
                    cout << "Pessoa removida da fila: " << removido->pessoa.nome << endl;
                    free(removido);
                }
                break;
            }
            case 3: {
                cout << "Nomes na fila:\n";
                imprimeLista(fila);
                break;
            }
            case 4: {
                vacinar(&fila, &topoFrascos, totalVacinados);
                break;
            }
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    while (topoFrascos != NULL) {
        free(desempilharFrasco(&topoFrascos));
    }

    return 0;
}
