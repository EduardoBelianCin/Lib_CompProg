#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Demonstração vector ---" << endl;

    // --- 1. Formas de Inicialização ---
    vector<int> v1; // Vazio
    vector<int> v2(5); // 5 elementos, inicializados com 0
    vector<int> v3(5, 10); // 5 elementos, todos com valor 10
    vector<int> v4 = {1, 2, 3, 4, 5}; // C++11 list initialization
    vector<int> v5(v4); // Cópia de outro vetor

    // --- 2. Funções Essenciais (Modificadores) ---
    cout << "\n--- Modificadores ---" << endl;
    v1.push_back(10); // Adiciona ao final [10]
    v1.push_back(20); // [10, 20]
    v1.push_back(30); // [10, 20, 30]
    
    cout << "v1 após push_back: ";
    for (int x : v1) { cout << x << " "; }
    cout << endl;

    v1.pop_back(); // Remove o último elemento [10, 20]
    cout << "v1 após pop_back: ";
    for (int x : v1) { cout << x << " "; }
    cout << endl;

    // insert(iterador_posicao, valor)
    v1.insert(v1.begin() + 1, 15); // Insere 15 na posição 1: [10, 15, 20]
    cout << "v1 após insert: ";
    for (int x : v1) { cout << x << " "; }
    cout << endl;

    // erase(iterador_posicao)
    v1.erase(v1.begin() + 1); // Remove o elemento na posição 1: [10, 20]
    cout << "v1 após erase: ";
    for (int x : v1) { cout << x << " "; }
    cout << endl;

    // --- 3. Acesso a Elementos ---
    cout << "\n--- Acesso ---" << endl;
    cout << "v4[0]: " << v4[0] << endl; // Acesso direto (rápido, mas não verifica limites)
    cout << "v4.at(1): " << v4.at(1) << endl; // Acesso com verificação (lança exceção se fora dos limites)
    cout << "Primeiro elemento (front): " << v4.front() << endl;
    cout << "Último elemento (back): " << v4.back() << endl;

    // --- 4. Tamanho e Capacidade ---
    cout << "\n--- Tamanho ---" << endl;
    cout << "Tamanho (size): " << v4.size() << endl;
    cout << "Está vazio? (empty): " << (v1.empty() ? "Sim" : "Não") << endl;
    
    v1.clear(); // Remove todos os elementos
    cout << "Tamanho de v1 após clear: " << v1.size() << endl;

    return 0;
}