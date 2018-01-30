#include <assert.h>
#include <stddef.h>

int nextSmallest(int num)
{
    if (num < 1) return -1;

    unsigned mask = 1;
    int ones = 0;
    int zeros = 0;
    const int bits = sizeof(int) * 8 - 1;

    // Count leading ones
    while (num & mask) {
        ++ones;
        mask <<= 1;
    }

    // Count zeros
    while (!(num & mask)) {
        ++zeros;
        if (ones + zeros == bits) return -1;
        mask <<= 1;
    }

    // Found a one
    ++ones;
    --zeros;

    num &= ~((mask << 1) - 1);
    num |= ((1 << ones) - 1) << zeros;

    return num;
}

int nextLargest(int num)
{
    if (num < 1) return -1;

    unsigned mask = 1;
    int ones = 0;
    int zeros = 0;
    const int bits = sizeof(int) * 8 - 1;

    // Count leading zeros
    while (!(num & mask)) {
        ++zeros;
        mask <<= 1;
    }

    // Count ones
    while (num & mask) {
        ++ones;
        if (ones + zeros == bits) return -1;
        mask <<= 1;
    }

    // Found a zero
    --ones;

    num |= mask;
    num &= ~(mask - 1);
    num |= (1 << ones) - 1;

    return num;
}

int main()
{
    assert(nextSmallest(1) == -1);
    assert(nextSmallest(10115) == 10096);

    assert(nextLargest(1 << 30) == -1);
    assert(nextLargest(13948) == 13967);
}
