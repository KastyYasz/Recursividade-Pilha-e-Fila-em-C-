/*
Pilha com recursividade

Explicação dos Conceitos

•	Recursividade:
    A função imprimirPilhaRecursivamente se chama repetidamente para processar cada elemento da pilha.
        o	Caso Base: Se a pilha estiver vazia, a função retorna sem fazer nada.
        o	Passo Recursivo: Remove o elemento do topo, imprime-o, chama a si mesma para processar os elementos restantes e, em seguida, reempilha o elemento removido para restaurar a pilha à sua ordem original.
•	Uso da Pilha e Alocação Dinâmica:
        o	A classe PilhaDinamica utiliza alocação dinâmica (por meio de new e delete[]) para criar um array cujo tamanho é definido em tempo de execução.
        o	As operações de empilhar e desempilhar trabalham com o índice topo, e os elementos são armazenados no array alocado na heap.

*/

#include <iostream>

using namespace std;

struct PilhaDinamica {

    int* dados; // ponteiro para o array dinâmico que armazenará os elementos da pilha
    int capacidade; // capacidade max
    int topo;       // indice do elemento topo, -1 indica pilha vazia

    bool vazia(){ return topo == -1; }

    bool cheia(){ return topo == capacidade - 1; }

    void empilhar(int valor){
        if(cheia()){
            cout << "Pilha cheia: não é possivel empilhar " << valor << endl;
        } else {
            topo++;
            dados[topo] = valor;
        }
    }

    int desempilhar(){
        if(vazia()){
            cout << "Pilha vazia: não há elementos para desempilhar" << endl;
            return -1;
        } else {
            int valorRetirado = dados[topo];
            topo--;
            return valorRetirado;
        }
    }

    int verTopo() {
        if(vazia()){
            cout << "Pilha vazia" << endl;
            return -1;
        } else {
            return dados[topo];
        }
    }

    PilhaDinamica(int cap){
        capacidade = cap;
        dados = new int[capacidade];
        topo = -1;
    }

    ~PilhaDinamica() {
        delete[] dados;
        dados = nullptr;
    }
};

void imprimirPilhaRecursivamente(PilhaDinamica &pilha){
    // se a pilha estiver vazia, termina a recursão
    if(pilha.vazia()){
        return;
    }
    // Remove o elemento do topo e armazena-o temporariamente
    int temp = pilha.desempilhar();

    cout << temp << " "; 

    imprimirPilhaRecursivamente(pilha);

    pilha.empilhar(temp);
}

int main(){
    int capacidade;

    cout << "Informe a capacidade da pilha: ";
    cin >> capacidade;

    PilhaDinamica pilha(capacidade);

    pilha.empilhar(10);
    pilha.empilhar(20);
    pilha.empilhar(30);
    pilha.empilhar(40);
    pilha.empilhar(50);

    cout << "Elementos da pilha: ";
    imprimirPilhaRecursivamente(pilha);
    cout << endl;
    
    cout << "Elemento no topo após impressão: " << pilha.verTopo() << endl;

    return 0;
}
