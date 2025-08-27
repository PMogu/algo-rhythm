from itertools import permutations

def check(P, D, T, H):
    cntA = (D == 1) + (H == 4) + (P ==3)
    cntB = (H == 1) + (D == 4) + (P == 2) + (T == 3)
    cntC = (H == 4) + (D == 3)
    cntD = (P == 1) + (T == 4) + (H == 2) + (D == 3)
    return cntA == cntB == cntC == cntD ==1

# generated all possible ordering, each ordering is a tuple like (1, 2, 3, 4).
# Unpack into variables
for P, D, T, H in permutations((1, 5), 4): 
    if check(P, D, T, H):
        print(P)
        print(D)
        print(T)
        print(H)