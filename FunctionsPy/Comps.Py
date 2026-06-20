# ==============================================================================
# GUIA DE CONSULTA CP (COMPETITIVE PROGRAMMING) - PYTHON
#
# Foco: Algoritmos eficientes e templates para problemas comuns.
# ==============================================================================

# ------------------------------------------------------------------------------
# 0. TEMPLATE BÁSICO (ENTRADA E SAÍDA RÁPIDA)
#
# Em CP, `input()` é muito lento. Use `sys.stdin.readline`.
# `print()` também é lento. Use `sys.stdout.write`.
# ------------------------------------------------------------------------------

import sys

# Descomente as duas linhas abaixo para acelerar I/O
# input = sys.stdin.readline
# print = sys.stdout.write

def fast_io_example():
    """
    Exemplo de como ler e escrever rapidamente.
    """
    try:
        # Lendo uma linha e removendo o '\n' do final
        linha = input().strip()

        # Lendo um número de casos de teste
        n_testes = int(input())

        for _ in range(n_testes):
            # Lendo múltiplos inteiros em uma linha
            a, b, c = map(int, input().split())
            
            # Calculando a resposta
            resultado = a + b + c
            
            # Escrevendo a resposta
            # Lembre-se: 'print' agora (se redefinido) requer string e '\n'
            # print(str(resultado) + '\n')
            
            # Se não redefinir o print, o print() normal funciona,
            # mas é mais lento. Para a maioria dos problemas, é OK.
            print(resultado) 

    except EOFError:
        pass # Fim da entrada

# ------------------------------------------------------------------------------
# 1. ESTRUTURAS DE DADOS ESSENCIAIS (ALTA PERFORMANCE)
# ------------------------------------------------------------------------------
from collections import deque, defaultdict
import heapq

print("\n--- 1. Estruturas de Dados Essenciais ---")

# collections.deque (Fila de Dupla Extremidade)
# O(1) para append/pop em *ambas* as extremidades.
# Perfeito para BFS (Busca em Largura) e "Sliding Window".
print("Deque:")
dq = deque([1, 2, 3])
dq.appendleft(0)  # Adiciona na esquerda
dq.append(4)      # Adiciona na direita (como lista)
print(f"  Deque: {dq}")
item_esquerda = dq.popleft() # Remove da esquerda
item_direita = dq.pop()      # Remove da direita
print(f"  Pop L/R: {item_esquerda}, {item_direita} -> {dq}")
# Saída:
#   Deque: deque([0, 1, 2, 3, 4])
#   Pop L/R: 0, 4 -> deque([1, 2, 3])

# collections.defaultdict (Dicionário com Valor Padrão)
# Evita ter que checar se uma chave já existe.
# Perfeito para construir grafos (lista de adjacência) e contar frequências.
print("\nDefaultdict:")
# Para lista de adjacência de um grafo
grafo = defaultdict(list)
grafo[1].append(2)
grafo[2].append(3)
grafo[1].append(4)
# Não precisa checar se '1' ou '2' existem primeiro
print(f"  Grafo (adj list): {dict(grafo)}")
# Saída:   Grafo (adj list): {1: [2, 4], 2: [3]}

# Para contar frequência
contador = defaultdict(int)
frase = "banana"
for letra in frase:
    contador[letra] += 1
print(f"  Contador: {dict(contador)}")
# Saída:   Contador: {'b': 1, 'a': 3, 'n': 2}

# heapq (Fila de Prioridade - Min-Heap)
# O(log N) para push e pop.
# Essencial para Dijkstra e problemas de "K-ésimo maior/menor elemento".
print("\nHeapq (Min-Heap):")
heap = []
heapq.heappush(heap, 5)
heapq.heappush(heap, 1)
heapq.heappush(heap, 7)
heapq.heappush(heap, 3)
print(f"  Heap (lista interna): {heap}") # Não está ordenado, é um heap binário
# Sempre remove o *menor* elemento
print(f"  heappop: {heapq.heappop(heap)}") # Sai 1
print(f"  heappop: {heapq.heappop(heap)}") # Sai 3
print(f"  heappop: {heapq.heappop(heap)}") # Sai 5
# Saída:
#   Heap (lista interna): [1, 3, 7, 5]
#   heappop: 1
#   heappop: 3
#   heappop: 5

# Dica: Para usar heapq como MAX-HEAP (pegar o maior),
# insira e remova os números *negativos*.
max_heap = []
heapq.heappush(max_heap, -5)
heapq.heappush(max_heap, -1)
heapq.heappush(max_heap, -7)
maior_item = -heapq.heappop(max_heap) # Sai -7, vira 7
print(f"  Max-Heap (pop): {maior_item}") # Saída:   Max-Heap (pop): 7


# ------------------------------------------------------------------------------
# 2. BUSCA E ORDENAÇÃO
# ------------------------------------------------------------------------------
import bisect

print("\n--- 2. Busca e Ordenação ---")

# Busca Binária (Binary Search) com `bisect`
# O(log N). Muito mais rápido e seguro do que implementar na mão.
# `bisect_left` e `bisect_right` são essenciais.
lista_ordenada = [10, 20, 20, 20, 30, 40]
print(f"Lista: {lista_ordenada}")

# bisect_left(lista, x): Retorna o índice da *primeira* ocorrência de x
# (ou onde x deveria ser inserido para manter a ordem).
idx_left = bisect.bisect_left(lista_ordenada, 20)
print(f"  bisect_left(20): {idx_left}") # Saída:   bisect_left(20): 1

# bisect_right(lista, x): Retorna o índice *após* a última ocorrência de x.
idx_right = bisect.bisect_right(lista_ordenada, 20)
print(f"  bisect_right(20): {idx_right}") # Saída:   bisect_right(20): 4

# Dica: Contar ocorrências de 'x' em lista ordenada O(log N)
count = idx_right - idx_left
print(f"  Contagem de 20s: {count}") # Saída:   Contagem de 20s: 3

# Ordenação Customizada (Custom Sort)
# O(N log N). Essencial para "greedy algorithms".
pontuacoes = [("Ana", 100, 5), ("Bruno", 80, 2), ("Carla", 100, 3)]

# Ordenar por pontuação (decrescente) e depois por penalidade (crescente)
# Dica: use -x para ordem decrescente em números
pontuacoes.sort(key=lambda item: (-item[1], item[2]))
print(f"\nOrdenação customizada: {pontuacoes}")
# Saída: Ordenação customizada: [('Carla', 100, 3), ('Ana', 100, 5), ('Bruno', 80, 2)]


# ------------------------------------------------------------------------------
# 3. ALGORITMOS DE GRAFO (Templates)
# ------------------------------------------------------------------------------
print("\n--- 3. Algoritmos de Grafo ---")

# Setup do Grafo (Lista de Adjacência)
# N = nós, M = arestas
# Vamos usar o defaultdict que vimos acima.
# grafo_ex = defaultdict(list)
# n_nos = 5
# arestas = [(0, 1), (0, 2), (1, 3), (2, 3), (3, 4)]
# for u, v in arestas:
#     grafo_ex[u].append(v)
#     grafo_ex[v].append(u) # Se o grafo não for direcionado

# Template: BFS (Busca em Largura)
# O(V + E) - V = Vértices, E = Arestas
# Usado para: encontrar caminho mínimo em grafo NÃO-ponderado,
# visitar todos os nós por "camadas".
def bfs(grafo, inicio, n_nos):
    distancias = [-1] * n_nos # -1 significa não visitado
    fila = deque([inicio])
    distancias[inicio] = 0
    
    print(f"  Iniciando BFS a partir de {inicio}:")
    
    while fila:
        no_atual = fila.popleft()
        print(f"    Visitando: {no_atual} (dist: {distancias[no_atual]})")
        
        for vizinho in grafo[no_atual]:
            if distancias[vizinho] == -1: # Se não foi visitado
                distancias[vizinho] = distancias[no_atual] + 1
                fila.append(vizinho)
                
    return distancias

# Exemplo de BFS:
# n_ex = 5
# grafo_ex = defaultdict(list, {0: [1, 2], 1: [0, 3], 2: [0, 3], 3: [1, 2, 4], 4: [3]})
# dist = bfs(grafo_ex, 0, n_ex)
# print(f"  Distâncias (BFS): {dist}")
# Saída:  Distâncias (BFS): [0, 1, 1, 2, 3]

# Template: DFS (Busca em Profundidade) - Iterativa
# O(V + E)
# Usado para: encontrar componentes conexos, detecção de ciclos,
# ordenação topológica.
# A versão iterativa (com pilha) é preferida em CP para evitar
# "RecursionError: maximum recursion depth exceeded".
def dfs_iterativa(grafo, inicio, n_nos):
    visitados = [False] * n_nos
    pilha = [inicio] # 'stack'
    ordem_visita = []

    print(f"\n  Iniciando DFS iterativa de {inicio}:")
    
    while pilha:
        no_atual = pilha.pop()
        
        if not visitados[no_atual]:
            visitados[no_atual] = True
            ordem_visita.append(no_atual)
            print(f"    Visitando: {no_atual}")
            
            # Adiciona vizinhos na pilha em ordem reversa
            # para visitar em ordem "normal" (ex: 0->1, 0->2)
            for vizinho in reversed(grafo[no_atual]):
                if not visitados[vizinho]:
                    pilha.append(vizinho)
                    
    return ordem_visita

# Exemplo de DFS:
# ordem = dfs_iterativa(grafo_ex, 0, n_ex)
# print(f"  Ordem (DFS): {ordem}")
# Saída:  Ordem (DFS): [0, 1, 3, 2, 4] (ou [0, 2, 3, 1, 4], depende da ordem)


# Template: Dijkstra (Caminho Mínimo Ponderado)
# O(E log V) - com min-heap
# Usado para: caminho mínimo em grafo PONDERADO com arestas NÃO-NEGATIVAS.
# Requer `heapq`.
def dijkstra(grafo_ponderado, inicio, n_nos):
    # Inicializa distâncias com infinito
    distancias = [float('inf')] * n_nos
    distancias[inicio] = 0
    
    # Fila de prioridade: armazena (distancia, no)
    # O heapq sempre pegará a menor distância
    pq = [(0, inicio)] # (dist, no)
    
    while pq:
        dist_atual, no_atual = heapq.heappop(pq)
        
        # Otimização: se já encontramos um caminho melhor, ignora
        if dist_atual > distancias[no_atual]:
            continue
            
        # Grafo ponderado: (vizinho, peso)
        for vizinho, peso in grafo_ponderado[no_atual]:
            nova_dist = dist_atual + peso
            
            # Se encontramos um caminho mais curto
            if nova_dist < distancias[vizinho]:
                distancias[vizinho] = nova_dist
                heapq.heappush(pq, (nova_dist, vizinho))
                
    return distancias

# Exemplo Dijkstra:
# n_dij = 5
# grafo_dij = defaultdict(list, {
#     0: [(1, 10), (2, 3)],
#     1: [(3, 2)],
#     2: [(1, 4), (3, 8), (4, 2)],
#     3: [(4, 5)],
#     4: []
# })
# dist_dij = dijkstra(grafo_dij, 0, n_dij)
# print(f"\nDistâncias (Dijkstra): {dist_dij}")
# Saída: Distâncias (Dijkstra): [0, 7, 3, 9, 5]


# ------------------------------------------------------------------------------
# 4. TÉCNICAS COMUNS
# ------------------------------------------------------------------------------
print("\n--- 4. Técnicas Comuns ---")

# Soma de Prefixo (Prefix Sum)
# O(N) para construir, O(1) para consultar soma de intervalo.
# Usado para: responder rapidamente "qual a soma dos elementos do índice L até R?"
print("Soma de Prefixo:")
array = [2, 1, 5, 3, 4]
n = len(array)
prefix_sum = [0] * (n + 1) # 1-based para facilitar

for i in range(n):
    prefix_sum[i+1] = prefix_sum[i] + array[i]

print(f"  Array original: {array}")
print(f"  Soma de prefixo: {prefix_sum}")
# Saída:
#   Array original: [2, 1, 5, 3, 4]
#   Soma de prefixo: [0, 2, 3, 8, 11, 15]

# Como usar: Soma do intervalo [L, R] (inclusivo)
# Lembre-se que 'array' é 0-indexado e 'prefix_sum' é 1-indexado
L, R = 1, 3 # Soma de [1, 5, 3]
soma_intervalo = prefix_sum[R + 1] - prefix_sum[L]
print(f"  Soma do intervalo [1..3] (indices): {soma_intervalo}") # 1+5+3 = 9
# Saída:   Soma do intervalo [1..3] (indices): 9


# Memoização (Programação Dinâmica Top-Down)
# Usado para: otimizar recursões com subproblemas repetidos.
print("\nMemoização (Fibonacci):")

# Versão LENTA O(2^N)
def fib_lento(n):
    if n <= 1:
        return n
    return fib_lento(n-1) + fib_lento(n-2)

# Versão RÁPIDA (Memoizada) O(N)
memo_fib = {} # Dicionário para cache
def fib_rapido(n):
    if n <= 1:
        return n
    if n in memo_fib:
        return memo_fib[n] # Retorna do cache
    
    # Calcula e armazena no cache
    resultado = fib_rapido(n-1) + fib_rapido(n-2)
    memo_fib[n] = resultado
    return resultado

# print(f"  Fib Lento(35): ...calculando...")
# print(f"  Fib Lento(35) = {fib_lento(35)}")
print(f"  Fib Rápido(100): {fib_rapido(100)}")
# Saída:   Fib Rápido(100): 354224848179261915075


# ==============================================================================
# FIM DO GUIA CP
# ==============================================================================