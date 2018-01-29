#include <assert.h>
#include <stdint.h>

uint32_t insertBits(uint32_t n, uint32_t m, int i, int j)
{
    uint32_t mask = ((1 << (j - i + 1)) - 1) << i;
    return (n & ~mask) | ((m << i) & mask);
}

int main(int argc, char *argv[])
{
    assert(insertBits(0x400U, 0x13U, 2, 6) == 0x44CU);
}
