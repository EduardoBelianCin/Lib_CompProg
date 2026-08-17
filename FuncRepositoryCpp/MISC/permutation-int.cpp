// converte uma permutação pra um idx unico
// O(n) mas o resultado pode ser gerado no range [0, n!-1]
// para n > 12 resultado precisa de LL

int permutation_to_int(vector<int> &p) {
    int mask = 0;
    int i = 0, r = 0;
    for(int x : p) {
        r = r * ++i + __builtin_popcountll(mask & -(1LL << x));
        mask |= 1LL << x;
    }
    return r;
}
