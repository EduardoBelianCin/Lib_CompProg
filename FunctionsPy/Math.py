# ==============================================================================
# GUIA DE CONSULTA CP (COMPETITIVE PROGRAMMING) - MATEMÁTICA
#
# Foco: Fórmulas essenciais, Teoria dos Números e Combinatória.
# ==============================================================================

import math
import sys

# Em muitos problemas de CP, os resultados são pedidos "modulo" um
# número grande para evitar overflow. O mais comum é 10^9 + 7 (um primo).
MOD = 1_000_000_007

# ------------------------------------------------------------------------------
# 1. FUNÇÕES BÁSICAS E ESSENCIAIS
# ------------------------------------------------------------------------------
print("--- 1. Funções Básicas ---")

# MDC (Máximo Divisor Comum) | GCD (Greatest Common Divisor)
# O(log(min(a, b))) - Algoritmo de Euclides
# A função 'math.gcd' é implementada em C e muito rápida.
a, b = 54, 24
print(f"MDC({a}, {b}) = {math.gcd(a, b)}")
# Saída: MDC(54, 24) = 6

# MMC (Mínimo Múltiplo Comum) | LCM (Least Common Multiple)
# O(log(min(a, b)))
# Fórmula: lcm(a, b) = (a * b) // gcd(a, b)
# (Nota: 'math.lcm' foi adicionado no Python 3.9+, mas esta
# fórmula funciona em todas as versões e é segura contra overflow
# se escrita como (a // gcd(a, b)) * b)
def lcm(a, b):
    if a == 0 or b == 0:
        return 0
    return abs(a * b) // math.gcd(a, b)

print(f"MMC({a}, {b}) = {lcm(a, b)}")
# Saída: MMC(54, 24) = 216

# Soma de Progressão Aritmética (PA)
# Soma dos números de 1 até N
# O(1)
def soma_pa_1_n(n):
    return n * (n + 1) // 2

print(f"Soma de 1 a 100 = {soma_pa_1_n(100)}")
# Saída: Soma de 1 a 100 = 5050

# Distância Euclidiana
# O(1)
# 'math.hypot' é mais estável numericamente do que sqrt(dx*dx + dy*dy)
x1, y1 = 0, 0
x2, y2 = 3, 4
dist = math.hypot(x2 - x1, y2 - y1)
print(f"Distância entre (0,0) e (3,4) = {dist}")
# Saída: Distância entre (0,0) e (3,4) = 5.0

# ------------------------------------------------------------------------------
# 2. TEORIA DOS NÚMEROS (PRIMOS)
# ------------------------------------------------------------------------------
print("\n--- 2. Teoria dos Números (Primos) ---")

# Teste de Primalidade
# O(sqrt(N))
# Bom o suficiente para checar um único número grande.
def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    # Itera apenas pelos ímpares até a raiz de n
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

print(f"17 é primo? {is_prime(17)}")     # Saída: 17 é primo? True
print(f"18 é primo? {is_prime(18)}")     # Saída: 18 é primo? False
print(f"10**9 + 7 é primo? {is_prime(MOD)}") # Saída: 10**9 + 7 é primo? True

# Crivo de Eratóstenes (Sieve of Eratosthenes)
# O(N log log N)
# Usado para encontrar *todos* os primos de 0 até N.
# Muito rápido para "precomputar" primalidade.
def sieve(N):
    """Retorna uma lista booleana 'is_prime' de tamanho N+1."""
    is_prime_list = [True] * (N + 1)
    is_prime_list[0] = is_prime_list[1] = False
    
    for p in range(2, int(N**0.5) + 1):
        if is_prime_list[p]:
            # Marca todos os múltiplos de p como não-primos
            # Começa de p*p (otimização)
            for i in range(p * p, N + 1, p):
                is_prime_list[i] = False
                
    # Opcional: retornar a lista de números primos
    # primes = [i for i, is_p in enumerate(is_prime_list) if is_p]
    # return primes
    
    return is_prime_list

# Exemplo de uso do Crivo:
MAX_SIEVE = 50
crivo_primos = sieve(MAX_SIEVE)
print(f"Crivo até {MAX_SIEVE}:")
primes_ate_50 = [i for i, is_p in enumerate(crivo_primos) if is_p]
print(f"  Primos: {primes_ate_50}")
# Saída:   Primos: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
print(f"  Check (crivo): 47 é primo? {crivo_primos[47]}") # O(1)
print(f"  Check (crivo): 48 é primo? {crivo_primos[48]}") # O(1)

# Fatoração em Primos
# O(sqrt(N))
def prime_factors(n):
    """Retorna um dicionário (ou Counter) de fatores primos."""
    fatores = {}
    d = 2
    # Otimização: checa o fator 2 primeiro
    while n % d == 0:
        fatores[d] = fatores.get(d, 0) + 1
        n //= d
    d = 3
    # Checa fatores ímpares
    while d * d <= n:
        while n % d == 0:
            fatores[d] = fatores.get(d, 0) + 1
            n //= d
        d += 2
    # Se 'n' sobrou e é > 1, ele mesmo é um fator primo
    if n > 1:
        fatores[n] = fatores.get(n, 0) + 1
    return fatores

print(f"Fatores de 560 = {prime_factors(560)}")
# Saída: Fatores de 560 = {2: 4, 5: 1, 7: 1} (560 = 2^4 * 5^1 * 7^1)

# ------------------------------------------------------------------------------
# 3. ARITMÉTICA MODULAR
# Essencial para cálculos com números gigantescos.
# ------------------------------------------------------------------------------
print("\n--- 3. Aritmética Modular (usando MOD =", MOD, ") ---")

# Exponenciação Modular Rápida (Fast Modular Exponentiation)
# O(log(exp))
# Calcula (base ^ exp) % mod de forma eficiente.
# Essencial, pois (a * b) % mod = ((a % mod) * (b % mod)) % mod
def mod_pow(base, exp, mod):
    res = 1
    base %= mod
    while exp > 0:
        # Se o bit menos significativo de exp é 1
        if exp % 2 == 1:
            res = (res * base) % mod
        # Quadrado da base
        base = (base * base) % mod
        # Divide o expoente por 2 (bit shift)
        exp //= 2
    return res

# Python tem uma função built-in que faz isso (e é mais rápida):
# pow(base, exp, mod)
base, exp = 3, 1000
print(f"({base}^{exp}) % {MOD} = {mod_pow(base, exp, MOD)}")
print(f"Usando pow(): {pow(base, exp, MOD)}")
# Saída: (3^1000) % 1000000007 = 85296811

# Inverso Modular (Modular Inverse)
# O(log(mod))
# Usado para "divisão" em aritmética modular.
# (a / b) % mod  ==  (a * (b ^ -1)) % mod
#
# Pelo Pequeno Teorema de Fermat:
# Se 'mod' é um número primo, o inverso de 'n' é (n ^ (mod - 2)) % mod
def mod_inverse(n, mod):
    """Calcula o inverso modular de n (mod m) usando Fermat."""
    # pow(n, mod - 2, mod)
    return mod_pow(n, mod - 2, mod)

# Exemplo: Calcular (100 / 5) % MOD
# 1. Inverso de 5 (mod MOD)
inv_5 = mod_inverse(5, MOD)
# 2. Multiplicar 100 pelo inverso
resultado = (100 * inv_5) % MOD
print(f"Inverso de 5 (mod {MOD}) = {inv_5}")
print(f"(100 / 5) % {MOD} = {resultado}")
# Saída: (100 / 5) % 1000000007 = 20

# ------------------------------------------------------------------------------
# 4. COMBINATÓRIA (nCr % MOD)
# (n "escolhe" k) - "Combinações de N, k a k"
# ------------------------------------------------------------------------------
print("\n--- 4. Combinatória (nCr % MOD) ---")

# Fórmula: nCr = n! / (k! * (n - k)!)
# Em modular: nCr % mod = (n! * (k! ^ -1) * ((n-k)! ^ -1)) % mod
#
# Isso requer precomputar os fatoriais e seus inversos.

def precompute_factorials(MAX_N, mod):
    """
    Precomputa fatoriais e seus inversos modulares.
    Retorna (fact, inv_fact)
    Complexidade: O(MAX_N + log(mod))
    """
    fact = [1] * (MAX_N + 1)
    inv_fact = [1] * (MAX_N + 1)
    
    # Precomputa fatoriais
    for i in range(2, MAX_N + 1):
        fact[i] = (fact[i - 1] * i) % mod
        
    # Precomputa inverso de MAX_N!
    # (Usamos (MAX_N)! ^ (mod - 2))
    inv_fact[MAX_N] = mod_inverse(fact[MAX_N], mod)
    
    # Precomputa os outros inversos de forma O(N) (de trás para frente)
    # (i-1)!^-1 = i!^-1 * i
    for i in range(MAX_N - 1, 1, -1):
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod
        
    return fact, inv_fact

# --- Template para usar nCr ---
MAX_N_COMB = 1000 # Ajuste o N máximo do seu problema
try:
    fact, inv_fact = precompute_factorials(MAX_N_COMB, MOD)
    print(f"Pré-cálculo de fatoriais feito para N={MAX_N_COMB}.")

    def nCr_mod(n, k, mod):
        """Calcula nCr % mod usando os valores precomputados."""
        if k < 0 or k > n:
            return 0 # Caso inválido
        if n > MAX_N_COMB:
            print("ERRO: N excede o valor pré-calculado!")
            return -1
        
        # n! * (k!^-1) * ((n-k)!^-1)
        numerador = fact[n]
        denominador = (inv_fact[k] * inv_fact[n - k]) % mod
        
        return (numerador * denominador) % mod

    # Exemplo: 10C5 (10 escolhe 5)
    n, k = 10, 5
    ncr_val = nCr_mod(n, k, MOD)
    print(f"{n}C{k} = {ncr_val}") # 10C5 = 252
    
    n, k = 100, 30
    ncr_val = nCr_mod(n, k, MOD)
    print(f"{n}C{k} % {MOD} = {ncr_val}")
    # Saída: 100C30 % 1000000007 = 307523173

except Exception as e:
    print(f"Erro no pré-cálculo (talvez MAX_N muito grande): {e}")


# ==============================================================================
# FIM DO GUIA DE MATEMÁTICA CP
# ==============================================================================