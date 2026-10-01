#include <bits/stdc++.h>
using namespace std;

// --- FUNÇÕES AUXILIARES (Para usar dentro da main) ---

// 1. Busca Padrão (Encontra o valor exato)
int binarySearchPadrao(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        // CÁLCULO SEGURO DO MEIO (Evita Overflow de int)
        // mid = low + (distancia / 2)
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid; // Achou!
        
        if (arr[mid] < target) 
            low = mid + 1; // Está na direita -> descarta esquerda
        else 
            high = mid - 1; // Está na esquerda -> descarta direita
    }
    return -1; // Não achou
}

// 2. Lower Bound (Primeiro Verdadeiro)
// Exemplo: Achar o PRIMEIRO número que é >= target
int buscaPrimeiroTrue(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1; // Guarda a melhor resposta encontrada

    while (low <= high) {
        int mid = low + (high-low) / 2;

        // Condição: É maior ou igual? (Verdadeiro)
        if (arr[mid] >= target) {
            ans = mid;      // Opa, serve! Salva o índice.
            high = mid - 1; // Mas sou ganancioso: tento achar um índice MENOR à esquerda.
        } else {
            low = mid + 1;  // Falso. Preciso aumentar o valor.
        }
    }
    return ans;
}

// 3. Last True (Último Verdadeiro)
// Exemplo: Achar o ÚLTIMO número que é <= target
int buscaUltimoTrue(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Condição: É menor ou igual? (Verdadeiro)
        if (arr[mid] <= target) {
            ans = mid;      // Serve! Salva o índice.
            low = mid + 1;  // Mas sou ganancioso: tento achar um índice MAIOR à direita.
        } else {
            high = mid - 1; // Falso. O valor já passou do limite.
        }
    }
    return ans;
}

// -----------------------------------------------------

int main() {
    // Vetor ordenado para os exemplos (REGRA DE OURO: Tem que estar ordenado)
    // Índices:      0   1   2   3   4   5   6   7   8   9
    vector<int> v = {2,  5,  8,  12, 16, 23, 38, 56, 72, 91};

    cout << "Vetor: {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}" << endl;
    cout << "Tamanho: " << v.size() << endl << endl;

    cout << "=== 1. BUSCA BINARIA PADRAO (Exact Match) ===" << endl;
    cout << "Lógica: Divide ao meio. Se igual, retorna. Se maior, vai pra dir. Se menor, vai pra esq." << endl;
    cout << "Fórmula do Mid: mid = low + (high - low) / 2; (Anti-Overflow)" << endl;

    int alvo = 23;
    int idx = binarySearchPadrao(v, alvo);
    
    if (idx != -1) 
        cout << "Alvo " << alvo << " encontrado no índice: " << idx << endl;
    else 
        cout << "Alvo não encontrado." << endl;

    cout << endl;


    cout << "=== 2. BUSCA NA RESPOSTA: TIPO 'LOWER BOUND' (Primeiro True) ===" << endl;
    cout << "Cenário: [F, F, F, T, T, T]. Quero o PRIMEIRO T." << endl;
    cout << "Lógica: Se check(mid) é True -> Salva 'ans = mid' e tenta ESQUERDA (high = mid - 1)." << endl;

    // Exemplo: Primeiro número >= 20
    // No vetor: 16 (F), 23 (T), 38 (T)... O primeiro T é o 23 (índice 5).
    int limiteMin = 20;
    int idxPrimeiro = buscaPrimeiroTrue(v, limiteMin);

    cout << "Primeiro elemento >= " << limiteMin << " está no índice: " << idxPrimeiro;
    cout << " (Valor: " << v[idxPrimeiro] << ")" << endl;
    cout << endl;


    cout << "=== 3. BUSCA NA RESPOSTA: TIPO 'LAST TRUE' (Último True) ===" << endl;
    cout << "Cenário: [T, T, T, F, F, F]. Quero o ÚLTIMO T." << endl;
    cout << "Lógica: Se check(mid) é True -> Salva 'ans = mid' e tenta DIREITA (low = mid + 1)." << endl;

    // Exemplo: Último número <= 40
    // No vetor: 38 (T), 56 (F)... O último T é o 38 (índice 6).
    int limiteMax = 40;
    int idxUltimo = buscaUltimoTrue(v, limiteMax);

    cout << "Último elemento <= " << limiteMax << " está no índice: " << idxUltimo;
    cout << " (Valor: " << v[idxUltimo] << ")" << endl;
    cout << endl;


    cout << "=== 4. USANDO STL (Bibliotecas do C++) ===" << endl;
    cout << "Dica: Em competições/trabalho, use as funções prontas se for vetor simples." << endl;

    // binary_search -> Retorna bool (só diz se existe ou não)
    bool existe = binary_search(v.begin(), v.end(), 56);
    cout << "binary_search(56): " << (existe ? "True" : "False") << endl;

    // lower_bound -> Retorna ITERADOR para o primeiro elemento >= valor
    auto it = lower_bound(v.begin(), v.end(), 20);
    cout << "lower_bound(20): aponta para " << *it << " (Indice: " << (it - v.begin()) << ")" << endl;

    // upper_bound -> Retorna ITERADOR para o primeiro elemento ESTRITAMENTE MAIOR que valor
    // Útil para saber onde inserir algo sem quebrar a ordem
    auto it2 = upper_bound(v.begin(), v.end(), 23); // Busca > 23
    cout << "upper_bound(23): aponta para " << *it2 << " (Indice: " << (it2 - v.begin()) << ")" << endl;

    return 0;
}