def bin_to_gray(x):
    return x ^ (x >> 1)

def gray_to_bin(x):
    num = 0
    while(x > 0):
        num ^= x
        x >>= 1
    return num