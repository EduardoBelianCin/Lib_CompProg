#include <bits/stdc++.h>
using namespace std;

int main() {
    
    // --- 1. stack (Pilha: LIFO) ---
    cout << "--- Demonstração stack (LIFO) ---" << endl;
    stack<int> pilha;
    
    pilha.push(10); // Topo -> [10]
    pilha.push(20); // Topo -> [20, 10]
    pilha.push(30); // Topo -> [30, 20, 10]

    cout << "Elemento no topo (top): " << pilha.top() << endl; // 30
    
    pilha.pop(); // Remove o topo (30)
    cout << "Novo elemento no topo: " << pilha.top() << endl; // 20
    
    cout << "Tamanho da pilha: " << pilha.size() << endl;

    cout << "Esvaziando a pilha: ";
    while (!pilha.empty()) {
        cout << pilha.top() << " "; // 20, depois 10
        pilha.pop();
    }
    cout << endl;

    // --- 2. queue (Fila: FIFO) ---
    cout << "\n--- Demonstração queue (FIFO) ---" << endl;
    queue<int> fila;

    fila.push(10); // Fim -> [10] <- Início
    fila.push(20); // Fim -> [20, 10] <- Início
    fila.push(30); // Fim -> [30, 20, 10] <- Início
    
    cout << "Elemento no início (front): " << fila.front() << endl; // 10
    cout << "Elemento no fim (back): " << fila.back() << endl; // 30

    fila.pop(); // Remove do início (10)
    cout << "Novo elemento no início: " << fila.front() << endl; // 20

    cout << "Esvaziando a fila: ";
    while (!fila.empty()) {
        cout << fila.front() << " "; // 20, depois 30
        fila.pop();
    }
    cout << endl;

    // --- 3. priority_queue (Fila de Prioridade) ---
    cout << "\n--- Demonstração priority_queue ---" << endl;

    // Por padrão, é uma Max-Heap (o MAIOR elemento fica no topo)
    priority_queue<int> pq_max;
    pq_max.push(10);
    pq_max.push(50);
    pq_max.push(5);
    pq_max.push(20);
    
    cout << "Topo da Max-Heap: " << pq_max.top() << endl; // 50

    cout << "Esvaziando a Max-Heap (ordem decrescente): ";
    while (!pq_max.empty()) {
        cout << pq_max.top() << " "; // 50, 20, 10, 5
        pq_max.pop();
    }
    cout << endl;

    // Criando uma Min-Heap (o MENOR elemento fica no topo)
    // Sintaxe: priority_queue<Tipo, Contêiner, Comparador>
    priority_queue<int, vector<int>, greater<int>> pq_min;
    
    pq_min.push(10);
    pq_min.push(50);
    pq_min.push(5);
    pq_min.push(20);

    cout << "Topo da Min-Heap: " << pq_min.top() << endl; // 5

    cout << "Esvaziando a Min-Heap (ordem crescente): ";
    while (!pq_min.empty()) {
        cout << pq_min.top() << " "; // 5, 10, 20, 50
        pq_min.pop();
    }
    cout << endl;

    return 0;
}