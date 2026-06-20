#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve() {
    int n = 4, W = 7;
    vector<int> w = {3, 4, 2, 6};
    vector<int> v = {4, 5, 3, 7};

    vector<int> knapsack(W + 1);
    for (int i=0;i<n;i++) {
        for (int k=W-w[i];k>=0;k--) {
            knapsack[k + w[i]] = max(knapsack[k + w[i]], knapsack[k] + v[i]);
        }
    }
    return knapsack[W];
}

// Knapsack
// O que é o Knapsack?
// Você tem: uma mochila com capacidade W,
// n itens, cada um com: peso w[i] e valor v[i]

// Pergunta: qual o maior valor que dá pra colocar na mochila sem passar do peso?
// Cada item pode ser pego 1 vez ou não pego