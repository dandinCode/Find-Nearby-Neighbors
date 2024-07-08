#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// conjunto de dados
vector <int> Bart = {8, 10, 3, 7, 1};
vector <int> Liza = {6, 5, 8, 1, 10};
vector <int> Homer = {10, 8, 6, 3, 2};
vector <int> Moe = {2, 3, 9, 5, 8};
vector <int> Marge = {5, 3, 7, 1, 10};
vector <vector<int>> Clientes = {Bart, Liza, Homer, Moe, Marge};

//declaração de função e variáveis
string nomeDoVetor(int index);
string clienteMaisProximo;
string clienteAtual;



double calculaDistancia(vector <int> vetor1, vector <int> vetor2){
    double distancia = 0;
    for(int i = 0; i<vetor1.size(); i++){
        distancia += pow((vetor1[i] - vetor2[i]), 2);
    }
    return sqrt(distancia);
}


void vizinhosProximos(vector <int> Cliente, vector <vector<int>> todosClientes) {
    double menorDistancia = 10;
    for(int i = 0; i < todosClientes.size(); i++){
            if(Cliente != todosClientes[i]){
                double distancia = calculaDistancia(Cliente, todosClientes[i]);
                if(distancia < menorDistancia){
                    menorDistancia = distancia;
                    clienteMaisProximo = nomeDoVetor(i);
               }
            } else {
                clienteAtual = nomeDoVetor(i);
            }
    }
    cout << "Cliente mais proximo de " << clienteAtual << ": " << clienteMaisProximo << endl;
    cout << "Distancia entre eles: " << menorDistancia << endl;
    cout << "--------" << endl;
}


int main() {
    for(int i = 0; i < Clientes.size(); i++){
        vizinhosProximos(Clientes[i], Clientes);
    }
    return 0;
}












string nomeDoVetor(int index){
    switch (index) {
        case 0:
            return "Bart";
        case 1:
            return "Liza";
        case 2:
            return "Homer";
        case 3:
            return "Moe";
        case 4:
            return "Marge";
    }
}