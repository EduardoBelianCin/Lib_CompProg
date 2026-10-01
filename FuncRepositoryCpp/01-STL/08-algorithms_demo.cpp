#include <bits/stdc++.h>
using namespace std;

// --- ESTRUTURA PARA O EXEMPLO ---
struct Aluno {
    string nome;
    int nota;
};

// --- COMPARADOR CLÁSSICO (Função) ---
bool compararPorNota(const Aluno& a, const Aluno& b) {
    return a.nota < b.nota; 
}

// Helper para imprimir
void printAlunos(const string& titulo, const vector<Aluno>& v) {
    cout << titulo << endl;
    for (const auto& a : v) {
        cout << "  { " << a.nome << ", " << a.nota << " }" << endl;
    }
}

int main() {
    cout << "=== 1. SORT vs STABLE_SORT ===" << endl;
    
    vector<Aluno> turma = {
        {"Ana", 10}, {"Zeca", 5}, {"Bia", 10}, {"Carlos", 8}, {"Xuxa", 5}
    };

    // STABLE SORT: Garante que se as notas forem iguais (Ana e Bia),
    // a ordem original entre elas é mantida.
    vector<Aluno> v_stable = turma;
    stable_sort(v_stable.begin(), v_stable.end(), compararPorNota);
    printAlunos("Estabilidade garantida (stable_sort):", v_stable);


    cout << "\n=== 2. COMPARADORES CUSTOMIZADOS (Básico) ===" << endl;
    vector<int> nums = {1, 5, 2, 8, 3};

    // Lambda Simples (int explícito)
    sort(nums.begin(), nums.end(), [](int a, int b) {
        // Pares primeiro
        if (a % 2 == 0 && b % 2 != 0) return true;
        if (a % 2 != 0 && b % 2 == 0) return false;
        return a < b;
    });
    
    cout << "Pares primeiro: ";
    for(int n : nums) cout << n << " ";
    cout << endl;


    cout << "\n=== 3. COMPARADORES COM AUTO (C++14) - SUA ESCOLHA ===" << endl;
    // Esta é a forma mais moderna e flexível!
    
    vector<pair<int, int>> arr = { {10, 5}, {5, 8}, {10, 2}, {2, 9} };

    // FORMA A: Criando a lambda e guardando em variável
    // 'const auto &' é eficiente e genérico (funciona pra qualquer tipo com .first)
    auto f = [] (const auto &a, const auto &b) {
        return a.first < b.first;
    };
    
    stable_sort(arr.begin(), arr.end(), f);

    cout << "Ordenado pelo First (usando auto f): ";
    for(auto p : arr) cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;


    // FORMA B: Lambda Inline (Direto na função)
    // Muito comum em competições para economizar linhas
    // Exemplo: Ordenar pelo SECOND decrescente
    sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    cout << "Ordenado pelo Second Decrescente (inline): ";
    for(auto p : arr) cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;


    cout << "\n=== 4. OUTROS ALGORITMOS ÚTEIS ===" << endl;
    vector<int> v = {2, 4, 6, 8, 10};
    
    // Binary Search, Lower Bound, Upper Bound
    // Nota: Todos exigem vetor ordenado
    cout << "Tem 6? " << (binary_search(v.begin(), v.end(), 6) ? "Sim" : "Nao") << endl;
    cout << "Lower bound 5 (>=): " << *lower_bound(v.begin(), v.end(), 5) << endl; // 6
    cout << "Upper bound 6 (>):  " << *upper_bound(v.begin(), v.end(), 6) << endl; // 8
    
    // Min e Max
    cout << "Max: " << *max_element(v.begin(), v.end()) << endl;

    return 0;
}