#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Demonstração map ---" << endl;
    cout << "(Pares Chave-Valor, chaves ÚNICAS, ordenado por chave)" << endl;

    map<string, int> idades;

    // --- 1. Inserção ---
    // Método 1: insert() com pair
    idades.insert(pair<string, int>("Alice", 30));
    // Método 2: insert() com C++11 (make_pair)
    idades.insert(make_pair("Bob", 25));
    // Método 3: insert() com C++11 (lista de inicialização)
    idades.insert({"Charlie", 35});
    // Método 4: Operador [] (o mais fácil para inserir/atualizar)
    idades["David"] = 28;
    
    // Tentando inserir chave duplicada (será ignorado)
    idades.insert({"Alice", 99}); // Não vai mudar, "Alice" já existe
    
    // Atualizando valor com []
    idades["Alice"] = 31; // Agora "Alice" tem 31

    // --- 2. Iteração ---
    // Os elementos são iterados em ORDEM DE CHAVE (alfabética aqui)
    cout << "\n--- Iteração (Ordenada) ---" << endl;
    for (const auto& par : idades) {
        // 'par' é um pair<const string, int>
        cout << "Chave: " << par.first << ", Valor: " << par.second << endl;
    }

    // --- 3. Busca e Acesso ---
    cout << "\n--- Busca e Acesso ---" << endl;
    // Acesso com []
    cout << "Idade do Bob: " << idades["Bob"] << endl;
    
    // CUIDADO: Se a chave não existe, o operador [] CRIA um novo elemento!
    cout << "Idade do 'Frank' (não existe): " << idades["Frank"] << endl;
    cout << "Tamanho do map agora: " << idades.size() << " (Frank foi criado com valor 0)" << endl;
    
    // Método seguro de busca: find()
    string nome_busca = "David";
    auto it = idades.find(nome_busca); // 'it' é um iterador

    if (it != idades.end()) {
        // .end() é o "local" *após* o último elemento (significa "não encontrado")
        cout << nome_busca << " foi encontrado! Idade: " << it->second << endl;
    } else {
        cout << nome_busca << " não foi encontrado." << endl;
    }

    // --- 4. Remoção ---
    idades.erase("Frank"); // Remove pela chave
    cout << "Tamanho após remover Frank: " << idades.size() << endl;

    // -----------------------------------------------------------------

    cout << "\n\n--- Demonstração multimap ---" << endl;
    cout << "(Permite chaves DUPLICADAS, ordenado por chave)" << endl;

    multimap<string, string> telefones;
    telefones.insert({"Casa", "1234-5678"});
    telefones.insert({"Casa", "9999-8888"}); // Chave duplicada (permitido)
    telefones.insert({"Trabalho", "3333-4444"});

    // Nota: multimap NÃO tem o operador []

    cout << "\n--- Iterando multimap ---" << endl;
    for (const auto& par : telefones) {
        cout << "Local: " << par.first << ", Tel: " << par.second << endl;
    }

    // Buscando todos os valores de uma chave
    cout << "\n--- Telefones de 'Casa' ---" << endl;
    auto range = telefones.equal_range("Casa");
    // range.first = iterador para o primeiro "Casa"
    // range.second = iterador para DEPOIS do último "Casa"
    for (auto it_tel = range.first; it_tel != range.second; ++it_tel) {
        cout << it_tel->second << endl;
    }

    return 0;
}