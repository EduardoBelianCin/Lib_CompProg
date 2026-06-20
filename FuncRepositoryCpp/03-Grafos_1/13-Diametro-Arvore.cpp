// Dado uma árvore, o seu diâmetro é a maior distância entre dois vértices
// Podem existir diferentes pares que representam o diâmetro,
// mas a distância entre cada par é a maior possível.

// Primeiro, escolhe-se qualquer nó e realiza-se uma busca (BFS ou DFS)
// para encontrar o nó mais distante, chamado de A.

// Em seguida, faz-se uma nova busca começando em A
// para encontrar o nó mais distante dele, chamado de B.

// A distância entre A e B é o diâmetro da árvore,
// isto é, o comprimento do maior caminho simples entre dois nós.

// Obs: Em uma árvore existe exatamente um único caminho entre quaisquer dois vértices.

// Portanto, a distância pode ser calculada tanto com BFS quanto com DFS.