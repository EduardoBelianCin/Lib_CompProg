#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()

int main() {
    cout << "--- Demonstração de Laços 'for' ---" << endl;
    vector<int> v = {10, 20, 30, 40, 50};

    // --- 1. Laço 'for' Clássico (baseado em índice) ---
    // Bom para quando você precisa do ÍNDICE (i)
    cout << "\n--- 1. Laço por Índice ---" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    // --- 2. Laço 'for' baseado em Iteradores (STL clássico) ---
    // Funciona com TODOS os contêineres STL (incluindo map, set)
    cout << "\n--- 2. Laço por Iterador ---" << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        // 'it' é um iterador (um "ponteiro" para o elemento)
        // Use *it para acessar o valor
        cout << "Valor: " << *it << endl;
    }

    // --- 3. Laço 'for' baseado em Intervalo (Range-based) - C++11 ---
    // O mais moderno, limpo e seguro. Prefira este!
    cout << "\n--- 3. Laço por Intervalo (Range-based C++11) ---" << endl;
    
    // 3a. Lendo os valores (cópia ou const referência)
    cout << "Lendo valores: ";
    // 'const auto&' é o mais eficiente: 'const' (não vou mudar)
    // '&' (referência, evita copiar o objeto)
    for (const auto& elemento : v) {
        cout << elemento << " ";
        // elemento = 100; // Erro! É constante
    }
    cout << endl;

    // 3b. Modificando os valores (usando referência não-const)
    cout << "Modificando valores (dobrando)..." << endl;
    // 'auto&' (referência): 'elemento' é um *apelido* para o item original no vetor
    for (auto& elemento : v) {
        elemento = elemento * 2;
    }

    cout << "Vetor após modificação: ";
    for (const auto& elemento : v) {
        cout << elemento << " ";
    }
    cout << endl;

    // Exemplo com map (onde o índice não existe)
    map<string, int> idades = {{"Alice", 30}, {"Bob", 25}};
    cout << "\n--- Range-based com Map ---" << endl;
    // 'par' será um pair
    for (const auto& par : idades) {
        cout << "Chave: " << par.first << ", Valor: " << par.second << endl;
    }


    // NEXT_PERMUTATION (Lembrar da ordem inicial ser o menor valor possivel)

    vector<int> Seq = {1,2,3,4,5,6,7,8};
    do {
        for(int x : Seq) {
            cout << x << "\n";
        }
    } while(next_permutation(all(Seq)));

    return 0;
}