#include <assert.h>
#include <stdint.h>

uint32_t swapbits(uint32_t num)
{
    return ((num & 0xAAAAAAAAU) >> 1) | ((num & 0x55555555U) << 1);
}

int main()
{
    assert(swapbits(0) == 0);
    assert(swapbits(42) == 21);
    assert(swapbits(0xAAAA5555U) == 0x5555AAAAU);
}
