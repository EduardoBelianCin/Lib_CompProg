#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // --- 1. pair (Agrupa 2 valores) ---
    cout << "--- Demonstração pair ---" << endl;

    // Criação
    pair<int, string> p1(1, "Alice");
    pair<int, string> p2 = make_pair(2, "Bob");
    pair<int, string> p3 = {3, "Charlie"}; // C++11

    // Acesso
    cout << "P1: ID=" << p1.first << ", Nome=" << p1.second << endl;
    
    p1.first = 10; // Modificando
    cout << "P1 modificado: ID=" << p1.first << ", Nome=" << p1.second << endl;

    // Desempacotamento (C++17 - Structured Bindings)
    // Este é o jeito moderno de acessar os valores!
    auto [id_p3, nome_p3] = p3;
    cout << "P3 (desempacotado): ID=" << id_p3 << ", Nome=" << nome_p3 << endl;


    // --- 2. tuple (Agrupa N valores) ---
    cout << "\n--- Demonstração tuple ---" << endl;

    // Criação (Nome, ID, Média)
    tuple<string, int, double> t1("David", 4, 9.5);
    auto t2 = make_tuple("Eve", 5, 8.2); // Tipo inferido

    // Acesso (clássico, usando get<index>)
    cout << "T1: Nome=" << get<0>(t1) 
              << ", ID=" << get<1>(t1) 
              << ", Média=" << get<2>(t1) << endl;

    get<2>(t1) = 9.8; // Modificando
    cout << "T1 modificado: Média=" << get<2>(t1) << endl;

    // Desempacotamento (C++17 - Structured Bindings)
    // Muito mais limpo que get!
    auto [nome_t2, id_t2, media_t2] = t2;
    cout << "T2 (desempacotado): Nome=" << nome_t2 
              << ", ID=" << id_t2 
              << ", Média=" << media_t2 << endl;
    
    // UNIQUE
    vector<int> v = {1,2,2,3,3,3,2,4,4};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    return 0;
}