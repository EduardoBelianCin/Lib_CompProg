#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. DECLARAÇÃO
    list<string> compras;

    // 2. INSERÇÃO NAS EXTREMIDADES (O(1))
    compras.push_back("Arroz");    // Adiciona no fim
    compras.push_back("Feijao");
    compras.push_front("Cafe");    // Adiciona no início (muito rápido na list)

    // 3. USO DE ITERADORES (O "Cursor")
    // Como não existe compras[1], usamos iteradores para navegar
    auto it = compras.begin(); 
    it++; // Agora o cursor aponta para o segundo elemento ("Arroz")

    // 4. INSERÇÃO NO MEIO (O(1) se você já tem o iterador)
    compras.insert(it, "Açúcar"); // Insere ANTES da posição do iterador

    // 5. REMOÇÃO (O(1))
    compras.pop_front(); // Remove o primeiro ("Cafe")
    
    // Para remover um elemento específico, usamos o iterador
    // Vamos remover onde o 'it' está apontando ("Arroz")
    compras.erase(it); 

    // 6. UTILITÁRIOS ÚTEIS
    cout << "Tamanho da lista: " << compras.size() << endl;
    
    compras.sort(); // Ordena alfabeticamente

    compras.reverse(); // Inverte a ordem

    // 7. LIMPEZA
    compras.clear();
    if (compras.empty()) {
        cout << "A lista está vazia agora!" << endl;
    }

    return 0;
}