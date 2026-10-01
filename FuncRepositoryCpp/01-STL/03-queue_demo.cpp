#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "=== 1. QUEUE (Fila Simples) ===" << endl;
    cout << "Lógica: FIFO (First-In, First-Out) - Primeiro a entrar, primeiro a sair." << endl;
    
    // DECLARAÇÃO: queue<tipo> nome;
    queue<int> q;

    // INSERÇÃO: push(valor) -> insere no FINAL
    q.push(10); 
    q.push(20);
    q.push(30); // Fila: [10, 20, 30]

    // ACESSO: front() (primeiro) e back() (último)
    cout << "Primeiro da fila (front): " << q.front() << endl; // 10
    cout << "Último da fila (back): " << q.back() << endl;   // 30

    // REMOÇÃO: pop() -> remove do INÍCIO (o front)
    q.pop(); // Remove o 10
    cout << "Novo front após pop: " << q.front() << endl; // 20

    // TAMANHO
    cout << "Tamanho: " << q.size() << endl;
    
    // Nota: queue NÃO tem acesso por índice (q[0] dá erro).
    cout << endl;


    cout << "=== 2. DEQUE (Double-Ended Queue) ===" << endl;
    cout << "Lógica: Híbrido. Insere e remove nas duas pontas. Permite acesso por índice." << endl;

    // DECLARAÇÃO: deque<tipo> nome;
    deque<int> dq;

    // INSERÇÃO: push_back() e push_front()
    dq.push_back(10);  // [10]
    dq.push_back(20);  // [10, 20]
    dq.push_front(5);  // [5, 10, 20]
    dq.push_front(1);  // [1, 5, 10, 20]

    // ACESSO: front(), back() e POR ÍNDICE []
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Elemento no índice 1 (dq[1]): " << dq[1] << endl; // O deque permite isso!

    // REMOÇÃO: pop_back() e pop_front()
    dq.pop_front(); // Remove o 1. Fica [5, 10, 20]
    dq.pop_back();  // Remove o 20. Fica [5, 10]

    cout << "Tamanho final: " << dq.size() << endl;
    cout << endl;


    cout << "=== 3. PRIORITY_QUEUE (Fila de Prioridade) ===" << endl;
    cout << "Lógica: O elemento de 'maior prioridade' está sempre no topo." << endl;

    // --- TIPO A: MAX-HEAP (Padrão) ---
    // O maior número sai primeiro.
    // DECLARAÇÃO: priority_queue<tipo> nome;
    priority_queue<int> pq_max;

    pq_max.push(10);
    pq_max.push(50);
    pq_max.push(5);
    
    // ACESSO: top() (ATENÇÃO: não é front, é top!)
    cout << "Maior elemento (top): " << pq_max.top() << endl; // 50

    // REMOÇÃO: pop() -> remove o topo (o maior)
    pq_max.pop(); 
    cout << "Novo maior (top): " << pq_max.top() << endl; // 10

    
    // --- TIPO B: MIN-HEAP (Invertida) ---
    // O menor número sai primeiro.
    // DECLARAÇÃO: priority_queue<tipo, vector<tipo>, greater<tipo>> nome;
    cout << "\n--- Min-Heap (Menor sai primeiro) ---" << endl;
    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_min.push(10);
    pq_min.push(50);
    pq_min.push(5);

    cout << "Menor elemento (top): " << pq_min.top() << endl; // 5
    
    pq_min.pop(); // Remove o 5
    cout << "Novo menor (top): " << pq_min.top() << endl; // 10

    // Nota: priority_queue NÃO tem acesso por índice e nem iteradores.
    // Você só enxerga o topo.

    return 0;
}