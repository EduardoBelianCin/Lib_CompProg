#include <bits/stdc++.h>
using namespace std;

// --- 1. Soma de Prefixo (Prefix Sum) ---
// Técnica O(N) para pré-calcular, permitindo consultas
// de soma de intervalo (i, j) em O(1).
void demoPrefixSum() {
    cout << "--- 1. Demonstração Soma de Prefixo (Prefix Sum) ---" << endl;
    vector<int> v = {2, 8, 3, 5, 7, 4, 1, 9};
    int n = v.size();

    // Cria um vetor prefix_sum de tamanho n
    // prefix_sum[i] = soma de v[0]...v[i]
    vector<long long> prefix_sum(n);
    
    // Método 1: Usando partial_sum (do <numeric>)
    partial_sum(v.begin(), v.end(), prefix_sum.begin());

    /* // Método 2: Manual (mais comum em competições)
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
    }
    */

    cout << "Vetor original: ";
    for(int x : v) cout << x << " ";
    cout << "\nVetor Prefix Sum: ";
    for(long long x : prefix_sum) cout << x << " ";
    cout << endl;

    // --- Consulta de Intervalo O(1) ---
    // Queremos a soma do intervalo [i, j] (inclusivo)
    int i = 2; // (valor 3)
    int j = 5; // (valor 4)
    // Soma(i, j) = Soma(0, j) - Soma(0, i-1)
    
    long long soma_intervalo = prefix_sum[j];
    if (i > 0) {
        soma_intervalo -= prefix_sum[i-1];
    }
    
    // Soma = 3 + 5 + 7 + 4 = 19
    cout << "Soma do intervalo [" << i << ", " << j << "] = " << soma_intervalo << endl;

    // Suffix Sum (Soma de Sufixo) é a mesma lógica, mas do final para o começo.
}


// --- 2. Mediana Móvel (Running Median) ---
// Técnica para encontrar a mediana de um fluxo de números
// de forma eficiente (O(log N) por inserção).
// Usa duas PQs:
// 1. lowers (Max-Heap): Armazena a metade INFERIOR dos números
// 2. highers (Min-Heap): Armazena a metade SUPERIOR dos números
class RunningMedian {
private:
    priority_queue<int> lowers; // Max-Heap
    priority_queue<int, vector<int>, greater<int>> highers; // Min-Heap

    // Garante que as heaps estejam balanceadas (tamanhos diferem em no máximo 1)
    void rebalance() {
        if (lowers.size() > highers.size() + 1) {
            highers.push(lowers.top());
            lowers.pop();
        } else if (highers.size() > lowers.size() + 1) {
            lowers.push(highers.top());
            highers.pop();
        }
    }

public:
    void addNumber(int num) {
        // Adiciona o novo número
        if (lowers.empty() || num < lowers.top()) {
            lowers.push(num);
        } else {
            highers.push(num);
        }
        
        // Rebalanceia as heaps
        rebalance();
    }

    double getMedian() {
        if (lowers.empty() && highers.empty()) {
            return 0.0;
        }

        // Se tamanhos iguais (nº par de elementos), mediana é a média dos topos
        if (lowers.size() == highers.size()) {
            return (lowers.top() + highers.top()) / 2.0;
        } 
        // Se tamanhos diferentes (nº ímpar), mediana é o topo da heap maior
        else if (lowers.size() > highers.size()) {
            return lowers.top();
        } else {
            return highers.top();
        }
    }
};

void demoRunningMedian() {
    cout << "\n--- 2. Demonstração Mediana Móvel (Running Median) ---" << endl;
    RunningMedian medianFinder;
    vector<int> fluxo = {5, 2, 10, 8, 1, 12};
    
    cout << "Adicionando números e calculando a mediana:" << endl;
    for (int num : fluxo) {
        medianFinder.addNumber(num);
        cout << "Adicionado: " << setw(2) << num 
             << " | Mediana atual: " << medianFinder.getMedian() << endl;
    }
}

int main() {
    // Chama a primeira demo
    demoPrefixSum();

    // Chama a segunda demo
    demoRunningMedian();
    
    return 0;
}