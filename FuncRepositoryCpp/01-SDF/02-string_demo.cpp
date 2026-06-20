#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "--- Demonstração string ---" << endl;

    // --- 1. Inicialização ---
    string s1; // Vazia
    string s2 = "Hello";
    string s3("World");
    string s4(5, '!'); // "!!!!!"
    string s5 = s2; // Cópia

    // --- 2. Funções Essenciais (Modificadores) ---
    cout << "\n--- Modificadores ---" << endl;
    
    // Concatenação
    string s_ola = s2 + " " + s3; // "Hello World"
    s_ola.append("!!"); // "Hello World!!"
    cout << "Concatenada: " << s_ola << endl;

    // Tamanho
    cout << "Tamanho (size): " << s_ola.size() << endl;
    cout << "Tamanho (length): " << s_ola.length() << endl; // Sinônimos

    // Acesso
    cout << "Primeiro char: " << s_ola[0] << endl; // 'H'
    cout << "Último char: " << s_ola[s_ola.size() - 1] << endl; // '!'

    // Substring (substr): (posição_inicial, tamanho_da_substring)
    string sub = s_ola.substr(6, 5); // "World"
    cout << "Substring: " << sub << endl;

    // Busca (find): retorna a posição ou string::npos se não encontrar
    size_t pos = s_ola.find("World");
    if (pos != string::npos) {
        cout << "'World' encontrado na posição: " << pos << endl;
    } else {
        cout << "'World' não encontrado." << endl;
    }

    // Modificação
    s_ola.insert(6, "C++ "); // "Hello C++ World!!"
    cout << "Após insert: " << s_ola << endl;

    s_ola.erase(6, 4); // Remove 4 chars a partir da posição 6: "Hello World!!"
    cout << "Após erase: " << s_ola << endl;
    
    s_ola.replace(6, 5, "Universo"); // "Hello Universo!!"
    cout << "Após replace: " << s_ola << endl;

    s_ola.clear();
    cout << "Após clear, s_ola está vazia? " << (s_ola.empty() ? "Sim" : "Não") << endl;

    // --- 3. Conversões (String <-> Numérico) ---
    cout << "\n--- Conversões ---" << endl;

    // Numérico para String
    int ano = 2025;
    double pi = 3.14159;
    string str_ano = to_string(ano);
    string str_pi = to_string(pi);
    cout << "Int para String: " << str_ano << endl;
    cout << "Double para String: " << str_pi << endl;

    // String para Numérico (C++11)
    string s_num = "12345";
    string s_float = "98.76";

    try {
        int i_num = stoi(s_num); // String to Int
        double d_float = stod(s_float); // String to Double

        cout << "String para Int: " << i_num << endl;
        cout << "String para Double: " << d_float << endl;

        // Exemplo de erro
        // stoi("abc"); 
    } catch (const invalid_argument& e) {
        cerr << "Erro de conversão (formato inválido): " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Erro de conversão (fora do range): " << e.what() << endl;
    }
    
    // Método clássico (via Stringstream)
    stringstream ss;
    ss << "54321 3.14"; // Coloca coisas na stream
    int i_val;
    double d_val;
    ss >> i_val >> d_val; // Extrai coisas da stream
    cout << "Stringstream (int): " << i_val << endl;
    cout << "Stringstream (double): " << d_val << endl;

    return 0;
}