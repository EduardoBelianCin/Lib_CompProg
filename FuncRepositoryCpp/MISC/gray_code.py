def bin_to_gray(x):
    return x ^ (x >> 1)

def gray_to_bin(x):
    num = 0
    while(x > 0):
        num ^= x
        x >>= 1
    return num

# string binaria pra inteiro
int("1100", 2)

# inteiro pra string binaria
# (0 = preenche, 4 = tamanho, b = binario)
format(12, '04b')