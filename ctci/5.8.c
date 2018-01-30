#include <stdint.h>
#include <stdio.h>

void drawHorizontalLine(uint8_t screen[], int width, int x1, int x2, int y)
{
    uint8_t* byte = screen + (y * width + x1) / 8;
    uint8_t start = x1 & 7;
    int len = x2 - x1 + 1;
    
    if (start) {
        uint8_t bit = 1 << (7 - start);
        uint8_t val = 0;
        while (len-- && bit) {
            val |= bit;
            bit >>= 1;
        }
        *byte++ |= val;
    }

    while (len >= 8) {
        *byte++ = 0xff;
        len -= 8;
    }

    if (len) {
        *byte |= ~((1 << (8 - len)) - 1);
    }
}

void printScreen(uint8_t screen[], int width, int height)
{
    uint8_t* byte = screen;
    for (int i = 0; i != height; ++i) {
        for (int j = 0; j != width / 8; ++j) {
            for (uint8_t bit = 1 << 7; bit; bit >>= 1) {
                printf("%c", (*byte & bit) ? '*' : '-');
            }
            ++byte;
        }
        printf("\n");
    }
}

int main()
{
    uint8_t screen[25 * 80 / 8] = { 0 };
    for (int y = 0; y != 13; ++y) {
        drawHorizontalLine(screen, 80, 39 - 2 * y, 40 + 2 * y, y);
    }
    for (int y = 13; y != 25; ++y) {
        drawHorizontalLine(screen, 80, 39 - 2 * (24 - y), 40 + 2 * (24 - y), y);
    }
    printScreen(screen, 80, 25);
}
