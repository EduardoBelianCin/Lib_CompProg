# ==============================================================================
# GUIA DE CONSULTA RÁPIDA PYTHON (EXEMPLOS E FUNÇÕES)
# ==============================================================================

# Salve este arquivo como "consulta_python.py" no seu VSCode para referência rápida.

# ------------------------------------------------------------------------------
# 1. FUNÇÕES INTEGRADAS (BUILT-IN FUNCTIONS)
# Funções que estão sempre disponíveis.
# ------------------------------------------------------------------------------

print("\n--- 1. Funções Integradas ---")

# print(): Imprime valores no console.
print("Olá, mundo!")
# Saída: Olá, mundo!

# len(): Retorna o número de itens em um objeto (string, lista, dicionário, etc.).
tamanho = len("abcde")
print(f"len('abcde'): {tamanho}")
# Saída: len('abcde'): 5

# type(): Retorna o tipo de um objeto.
tipo = type(123)
print(f"type(123): {tipo}")
# Saída: type(123): <class 'int'>

# int(), float(), str(): Convertem tipos de dados (casting).
num_str = "100"
num_int = int(num_str)
print(f"int('100'): {num_int}")
# Saída: int('100'): 100

num_float = float(num_int)
print(f"float(100): {num_float}")
# Saída: float(100): 100.0

texto = str(num_float)
print(f"str(100.0): '{texto}'")
# Saída: str(100.0): '100.0'

# input(): Lê uma entrada do usuário (sempre retorna uma string).
# Descomente a linha abaixo para testar:
# nome = input("Digite seu nome: ")
# print(f"Olá, {nome}")

# range(): Gera uma sequência de números. Muito usado em loops 'for'.
# range(stop)
for i in range(3):
    print(i, end=" ")  # end=" " imprime na mesma linha
# Saída: 0 1 2

# range(start, stop)
print("\nrange(2, 5):", end=" ")
for i in range(2, 5):
    print(i, end=" ")
# Saída: range(2, 5): 2 3 4

# range(start, stop, step)
print("\nrange(0, 10, 2):", end=" ")
for i in range(0, 10, 2):
    print(i, end=" ")
# Saída: range(0, 10, 2): 0 2 4 6 8
print() # Pula linha

# sorted(): Retorna uma *nova* lista ordenada a partir de um iterável.
lista_desordenada = [3, 1, 4, 1, 5, 9, 2]
lista_ordenada = sorted(lista_desordenada)
print(f"sorted([3, 1, 4...]): {lista_ordenada}")
# Saída: sorted([3, 1, 4...]): [1, 1, 2, 3, 4, 5, 9]
print(f"Lista original: {lista_desordenada}") # A original não muda
# Saída: Lista original: [3, 1, 4, 1, 5, 9, 2]

# sum(), max(), min(): Funções matemáticas básicas em iteráveis.
numeros = [1, 5, 2, 8]
print(f"sum(numeros): {sum(numeros)}")   # Saída: sum(numeros): 16
print(f"max(numeros): {max(numeros)}")   # Saída: max(numeros): 8
print(f"min(numeros): {min(numeros)}")   # Saída: min(numeros): 1

# zip(): Agrupa elementos de múltiplos iteráveis.
nomes = ["Ana", "Bruno", "Carla"]
idades = [25, 30, 22]
for nome, idade in zip(nomes, idades):
    print(f"{nome} tem {idade} anos.")
# Saída:
# Ana tem 25 anos.
# Bruno tem 30 anos.
# Carla tem 22 anos.

# enumerate(): Retorna o índice e o valor ao iterar.
frutas = ["Maçã", "Banana", "Uva"]
for indice, fruta in enumerate(frutas):
    print(f"Índice {indice}: {fruta}")
# Saída:
# Índice 0: Maçã
# Índice 1: Banana
# Índice 2: Uva


# ------------------------------------------------------------------------------
# 2. MÉTODOS DE STRING (str)
# Funções que pertencem a objetos do tipo string.
# ------------------------------------------------------------------------------

print("\n--- 2. Métodos de String ---")
texto_exemplo = "  Olá, Mundo! Bem-vindo ao Python!  "

# .upper() / .lower(): Converte para maiúsculas / minúsculas.
print(f"upper(): {texto_exemplo.upper()}")
# Saída: upper():   OLÁ, MUNDO! BEM-VINDO AO PYTHON!  
print(f"lower(): {texto_exemplo.lower()}")
# Saída: lower():   olá, mundo! bem-vindo ao python!  

# .strip() / .lstrip() / .rstrip(): Remove espaços em branco (ou caracteres) do início e/ou fim.
print(f"strip(): '{texto_exemplo.strip()}'")
# Saída: strip(): 'Olá, Mundo! Bem-vindo ao Python!'
print(f"lstrip(): '{texto_exemplo.lstrip()}'")
# Saída: lstrip(): 'Olá, Mundo! Bem-vindo ao Python!  '

# .replace(antigo, novo): Substitui uma substring por outra.
print(f"replace('!','?'): {texto_exemplo.strip().replace('!', '?')}")
# Saída: replace('!','?'): Olá, Mundo? Bem-vindo ao Python?

# .split(separador): Divide a string em uma lista.
palavras = texto_exemplo.strip().split(" ")
print(f"split(' '): {palavras}")
# Saída: split(' '): ['Olá,', 'Mundo!', 'Bem-vindo', 'ao', 'Python!']

# .join(lista): Junta os elementos de uma lista em uma única string, usando a string como separador.
separador = "---"
texto_junto = separador.join(palavras)
print(f"join(palavras): '{texto_junto}'")
# Saída: join(palavras): 'Olá,---Mundo!---Bem-vindo---ao---Python!'

# .find(substring): Retorna o índice da primeira ocorrência (ou -1 se não encontrar).
indice = texto_exemplo.find("Mundo")
print(f"find('Mundo'): {indice}")
# Saída: find('Mundo'): 8 (contando os espaços do início)

# .startswith(prefixo) / .endswith(sufixo): Verifica se começa ou termina com...
texto_limpo = texto_exemplo.strip()
print(f"startswith('Olá'): {texto_limpo.startswith('Olá')}")   # Saída: startswith('Olá'): True
print(f"endswith('Java!'): {texto_limpo.endswith('Java!')}") # Saída: endswith('Java!'): False

# f-strings (Formatação): A forma moderna de formatar strings.
nome = "Maria"
idade = 30
print(f"Formatação (f-string): {nome} tem {idade} anos.")
# Saída: Formatação (f-string): Maria tem 30 anos.


# ------------------------------------------------------------------------------
# 3. MÉTODOS DE LISTA (list)
# Funções que modificam ou analisam objetos do tipo lista.
# ------------------------------------------------------------------------------

print("\n--- 3. Métodos de Lista ---")
minha_lista = [10, 20, 30]
print(f"Lista inicial: {minha_lista}")

# .append(item): Adiciona um item ao final da lista.
minha_lista.append(40)
print(f"append(40): {minha_lista}")
# Saída: append(40): [10, 20, 30, 40]

# .insert(indice, item): Insere um item em uma posição específica.
minha_lista.insert(1, 15) # Insere 15 no índice 1
print(f"insert(1, 15): {minha_lista}")
# Saída: insert(1, 15): [10, 15, 20, 30, 40]

# .pop(indice): Remove e retorna o item de um índice (padrão: último item).
item_removido = minha_lista.pop() # Remove o 40
print(f"pop(): {minha_lista}, item removido: {item_removido}")
# Saída: pop(): [10, 15, 20, 30], item removido: 40

item_removido = minha_lista.pop(1) # Remove o 15 (índice 1)
print(f"pop(1): {minha_lista}, item removido: {item_removido}")
# Saída: pop(1): [10, 20, 30], item removido: 15

# .remove(valor): Remove a primeira ocorrência de um *valor* específico.
minha_lista.append(20) # Adicionando outro 20
print(f"Lista antes de remover: {minha_lista}") # [10, 20, 30, 20]
minha_lista.remove(20) # Remove o primeiro 20
print(f"remove(20): {minha_lista}")
# Saída: remove(20): [10, 30, 20]

# .sort(): Ordena a lista *no local* (modifica a original).
outra_lista = [5, 1, 9, 3]
outra_lista.sort()
print(f"sort(): {outra_lista}")
# Saída: sort(): [1, 3, 5, 9]
outra_lista.sort(reverse=True) # Ordena em ordem decrescente
print(f"sort(reverse=True): {outra_lista}")
# Saída: sort(reverse=True): [9, 5, 3, 1]

# .index(valor): Retorna o índice da primeira ocorrência do valor.
print(f"index(5): {outra_lista.index(5)}")
# Saída: index(5): 1

# .count(valor): Conta quantas vezes um valor aparece.
lista_contagem = [1, 2, 2, 3, 2, 4]
print(f"count(2): {lista_contagem.count(2)}")
# Saída: count(2): 3

# Fatiamento (Slicing) [start:stop:step] - Não é um método, mas é essencial!
numeros = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(f"Fatiamento [2:5]: {numeros[2:5]}")   # Saída: Fatiamento [2:5]: [2, 3, 4]
print(f"Fatiamento [:3]: {numeros[:3]}")    # Saída: Fatiamento [:3]: [0, 1, 2]
print(f"Fatiamento [6:]: {numeros[6:]}")    # Saída: Fatiamento [6:]: [6, 7, 8, 9]
print(f"Fatiamento [::2]: {numeros[::2]}")  # Saída: Fatiamento [::2]: [0, 2, 4, 6, 8] (de 2 em 2)
print(f"Fatiamento [::-1]: {numeros[::-1]}") # Saída: Fatiamento [::-1]: [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] (inverte)


# ------------------------------------------------------------------------------
# 4. MÉTODOS DE DICIONÁRIO (dict)
# Pares de chave-valor.
# ------------------------------------------------------------------------------

print("\n--- 4. Métodos de Dicionário ---")
carro = {
    "marca": "Ford",
    "modelo": "Ka",
    "ano": 2020
}
print(f"Dicionário inicial: {carro}")

# Acessando valores:
print(f"Acessando 'modelo': {carro['modelo']}")
# Saída: Acessando 'modelo': Ka

# .get(chave, default): Forma segura de acessar. Retorna None (ou 'default') se a chave não existe.
print(f"get('cor'): {carro.get('cor')}")
# Saída: get('cor'): None                     # retorna 'Preto' se nao existe cor
print(f"get('cor', 'Preto'): {carro.get('cor', 'Preto')}")
# Saída: get('cor', 'Preto'): Preto

# Adicionando / Atualizando:
carro["ano"] = 2021 # Atualiza
carro["cor"] = "Azul" # Adiciona
print(f"Após atualizar/adicionar: {carro}")
# Saída: Após atualizar/adicionar: {'marca': 'Ford', 'modelo': 'Ka', 'ano': 2021, 'cor': 'Azul'}

# .pop(chave): Remove a chave e retorna o seu valor.
ano_removido = carro.pop("ano")
print(f"pop('ano'): {carro}, item removido: {ano_removido}")
# Saída: pop('ano'): {'marca': 'Ford', 'modelo': 'Ka', 'cor': 'Azul'}, item removido: 2021

# .keys(): Retorna uma visão de todas as chaves.
print(f"keys(): {carro.keys()}")
# Saída: keys(): dict_keys(['marca', 'modelo', 'cor'])

# .values(): Retorna uma visão de todos os valores.
print(f"values(): {carro.values()}")
# Saída: values(): dict_values(['Ford', 'Ka', 'Azul'])

# .items(): Retorna uma visão de todos os pares (chave, valor).
print(f"items(): {carro.items()}")
# Saída: items(): dict_items([('marca', 'Ford'), ('modelo', 'Ka'), ('cor', 'Azul')])

# Iterando sobre um dicionário (usando .items() é o mais comum):
for chave, valor in carro.items():
    print(f"  {chave}: {valor}")
# Saída:
#   marca: Ford
#   modelo: Ka
#   cor: Azul


# ------------------------------------------------------------------------------
# 5. MÉTODOS DE CONJUNTO (set)
# Coleção não ordenada de itens *únicos*.
# ------------------------------------------------------------------------------

print("\n--- 5. Métodos de Conjunto (Set) ---")
set_a = {1, 2, 3, 4, 4, 4} # Elementos repetidos são ignorados
set_b = {3, 4, 5, 6}
print(f"Set A: {set_a}") # Saída: Set A: {1, 2, 3, 4}
print(f"Set B: {set_b}") # Saída: Set B: {3, 4, 5, 6}

# .add(item): Adiciona um item.
set_a.add(5)
print(f"add(5) em A: {set_a}")
# Saída: add(5) em A: {1, 2, 3, 4, 5}

# .remove(item): Remove um item (dá erro se o item não existir).
set_a.remove(1)
print(f"remove(1) de A: {set_a}")
# Saída: remove(1) de A: {2, 3, 4, 5}

# .discard(item): Remove um item (NÃO dá erro se o item não existir).
set_a.discard(99) # Não faz nada, não dá erro
print(f"discard(99) de A: {set_a}")
# Saída: discard(99) de A: {2, 3, 4, 5}

# Operações de conjunto:
# .union() ou | (União: todos os elementos)
print(f"União (A | B): {set_a | set_b}")
# Saída: União (A | B): {2, 3, 4, 5, 6}

# .intersection() ou & (Interseção: elementos em comum)
print(f"Interseção (A & B): {set_a & set_b}")
# Saída: Interseção (A & B): {3, 4, 5}

# .difference() ou - (Diferença: elementos que estão em A, mas não em B)
print(f"Diferença (A - B): {set_a - set_b}")
# Saída: Diferença (A - B): {2}
print(f"Diferença (B - A): {set_b - set_a}")
# Saída: Diferença (B - A): {6}


# ------------------------------------------------------------------------------
# 6. MANIPULAÇÃO DE ARQUIVOS (File I/O)
# Lendo e escrevendo em arquivos de texto.
# ------------------------------------------------------------------------------

print("\n--- 6. Manipulação de Arquivos ---")

# A forma recomendada de trabalhar com arquivos é usando 'with open()',
# pois ele fecha o arquivo automaticamente.

# --- Escrevendo em um arquivo ('w' = write, apaga o conteúdo anterior) ---
try:
    with open("meu_arquivo_teste.txt", "w", encoding="utf-8") as f:
        f.write("Linha 1: Olá\n")
        f.write("Linha 2: Mundo\n")
    print("Arquivo 'meu_arquivo_teste.txt' escrito com sucesso.")

    # --- Lendo um arquivo ('r' = read) ---
    print("\nLendo o arquivo completo (.read()):")
    with open("meu_arquivo_teste.txt", "r", encoding="utf-8") as f:
        conteudo = f.read()
        print(f"'{conteudo}'")
    # Saída:
    # 'Linha 1: Olá
    # Linha 2: Mundo
    # '

    # --- Lendo linha por linha (.readlines()) ---
    print("Lendo linha por linha (.readlines()):")
    with open("meu_arquivo_teste.txt", "r", encoding="utf-8") as f:
        linhas = f.readlines() # Retorna uma lista de linhas
        print(linhas)
        for linha in linhas:
            print(f"  -> {linha.strip()}") # .strip() remove o '\n' do final
    # Saída:
    # ['Linha 1: Olá\n', 'Linha 2: Mundo\n']
    #   -> Linha 1: Olá
    #   -> Linha 2: Mundo

    # --- Adicionando ao final ('a' = append) ---
    with open("meu_arquivo_teste.txt", "a", encoding="utf-8") as f:
        f.write("Linha 3: Python\n")
    print("\nArquivo atualizado com 'append'.")

    # Verificando o 'append'
    with open("meu_arquivo_teste.txt", "r", encoding="utf-8") as f:
        print("Conteúdo final:")
        print(f"'{f.read()}'")
    # Saída:
    # 'Linha 1: Olá
    # Linha 2: Mundo
    # Linha 3: Python
    # '
except IOError as e:
    print(f"Ocorreu um erro de E/S: {e}")

# ==============================================================================
# FIM DO GUIA
# ==============================================================================