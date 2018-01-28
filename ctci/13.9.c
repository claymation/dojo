#include <stdio.h>
#include <stdlib.h>

/**
 * Allocates size + align bytes:
 *
 * +--------+-----+-------------------+
 * | pad... | ptr | user space (size) |
 * +--------+-----+-------------------+
 *                ^
 *             returned
 *
 * align must be a power of two at least sizeof(void*).
 */
void* amalloc(size_t size, size_t align)
{
    void* ptr = malloc(size + align);

    if (!ptr) {
        return ptr;
    }

    uintptr_t addr = (uintptr_t)ptr;
    size_t pad = align - (addr & (align - 1));
    char *ret = (char*)ptr + pad;

    void** orig = ((void**)ret) - 1;
    *orig = ptr;

    return ret;
}

void afree(void* ptr)
{
    if (!ptr) {
        return;
    }

    void** orig = ((void**)ptr) - 1;
    free(*orig);
}

int main(int argc, char *argv[])
{
    char *p = amalloc(10, 16);
    printf("p: %p\n", p);
    p[0] = 'a';
    p[9] = 'z';
    afree(p);

    char *q = amalloc(10, 128);
    printf("q: %p\n", q);
    q[0] = 'a';
    q[9] = 'z';
    afree(q);

    char *r = amalloc(10, 1024);
    printf("r: %p\n", r);
    r[0] = 'a';
    r[9] = 'z';
    afree(r);

    return 0;
}
