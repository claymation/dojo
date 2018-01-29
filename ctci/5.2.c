#include <assert.h>
#include <string.h>

/**
 * Return the binary representation of num.
 *
 * Pre-condition: 0 < num < 1
 * Post-condition: strlen(digits) <= 33
 */
const char* dtob(double num)
{
    if (num >= 1 || num <= 0) {
        return "ERROR";
    }

    const size_t N = 32;
    static char digits[N + 2] = ".";
    size_t i = 1;
    double frac = 0.5;

    while (num > 0) {
        if (i > N) {
            return "ERROR";
        }

        if (num >= frac) {
            digits[i] = '1';
            num -= frac;
        } else {
            digits[i] = '0';
        }
        frac /= 2;
        ++i;
    }

    digits[i] = '\0';

    return digits;
}

int main()
{
    assert(strcmp(dtob(0.10), "ERROR") == 0);
    assert(strcmp(dtob(0.25), ".01") == 0);
    assert(strcmp(dtob(0.50), ".1") == 0);
    assert(strcmp(dtob(0.72), "ERROR") == 0);
    assert(strcmp(dtob(0.75), ".11") == 0);
}
