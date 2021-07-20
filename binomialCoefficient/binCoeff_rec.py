# nk = "n,k"
def BinomialCoefficient(nk, bc={}):
    if nk in bc: return bc[nk]
    if nk.split(',')[1] == '0': return 1
    if nk.split(',')[0]==nk.split(',')[1]: return 1
    else:
        n = int(nk.split(',')[0])
        k = int(nk.split(',')[1])
        bc[nk] = BinomialCoefficient('{},{}'.format(str(n-1), str(k)), bc) + BinomialCoefficient('{},{}'.format(str(n-1), str(k-1)), bc)
        # n choose k = n-1 choose k + n-1 choose k-1
        return bc[nk]

n, k = input().split(' ')
print(BinomialCoefficient(n+','+k))