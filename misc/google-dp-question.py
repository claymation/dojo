SYLLABLES = {
    "ab",
    "abc",
    "def",
}

def cost(w):
    return 0 if w in SYLLABLES else len(w)

def minUnmatchedChars(S):
    T = [0] * (len(S) + 1)

    T[0] = cost(S[0])

    for i in range(1, len(S)):
        T[i] = min(T[j-1] + cost(S[j:i+1]) for j in range(i+1))

    return T[-2]

print(minUnmatchedChars("xabcdefg"))
