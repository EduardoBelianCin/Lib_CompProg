#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Demonstração set ---" << endl;
    cout << "(Valores ÚNICOS, ordenados)" << endl;

    set<int> numeros;
    numeros.insert(10);
    numeros.insert(5);
    numeros.insert(20);
    numeros.insert(10); // Duplicado: será IGNORADO

    // --- 1. Iteração ---
    // Os elementos são iterados em ORDEM (crescente por padrão)
    cout << "\n--- Iteração (Ordenada) ---" << endl;
    for (int n : numeros) {
        cout << n << " ";
    }
    cout << endl; // Saída: 5 10 20

    // --- 2. Busca (find e count) ---
    cout << "\n--- Busca ---" << endl;
    
    // find(): retorna um iterador para o elemento ou .end()
    auto it = numeros.find(10);
    if (it != numeros.end()) {
        cout << "O número 10 foi encontrado." << endl;
    } else {
        cout << "O número 10 NÃO foi encontrado." << endl;
    }
    
    // count(): retorna 1 se o elemento existe, 0 caso contrário (em set)
    if (numeros.count(5)) {
        cout << "O número 5 existe (via count)." << endl;
    }

    // --- 3. Remoção ---
    numeros.erase(10); // Remove o valor 10
    cout << "Após remover 10: ";
    for (int n : numeros) { cout << n << " "; }
    cout << endl;

    // -----------------------------------------------------------------

    cout << "\n\n--- Demonstração multiset ---" << endl;
    cout << "(Permite valores DUPLICADOS, ordenados)" << endl;

    multiset<int> multi_numeros;
    multi_numeros.insert(10);
    multi_numeros.insert(5);
    multi_numeros.insert(10); // Duplicado: PERMITIDO
    multi_numeros.insert(10); // Duplicado: PERMITIDO
    multi_numeros.insert(20);

    cout << "\n--- Iteração (Ordenada) ---" << endl;
    for (int n : multi_numeros) {
        cout << n << " ";
    }
    cout << endl; // Saída: 5 10 10 10 20

    // count() agora é muito útil!
    cout << "Quantidade de '10' no multiset: " << multi_numeros.count(10) << endl;

    // CUIDADO: erase(valor) remove TODAS as ocorrências do valor
    multi_numeros.erase(10); 
    cout << "Após erase(10): ";
    for (int n : multi_numeros) { cout << n << " "; }
    cout << endl; // Saída: 5 20


    // DA PRA FAZER UPPER_BOUND e LOWER_BOUND no set e no multiset
    auto Ub = multi_numeros.upper_bound(4);
    auto Lb = multi_numeros.lower_bound(8);

    auto Proximo = next(Ub);
    auto Anterior = prev(Ub);

    // 1. Pegando o MENOR (Primeiro elemento)
    int menor = *multi_numeros.begin();
    // 2. Pegando o MAIOR (Último elemento)
    int maior = *multi_numeros.rbegin();

    return 0;
}