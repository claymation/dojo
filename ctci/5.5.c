#include <assert.h>

int bitflips(int a, int b)
{
    int bits = 0;
    for (int c = a ^ b; c; c &= c - 1) {
        ++bits;
    }
    return bits;
}

int main()
{
    assert(bitflips(1, 1) == 0);
    assert(bitflips(1, 2) == 2);
    assert(bitflips(1, 3) == 1);
    assert(bitflips(42, 21) == 6);
}
