// @author Chuchu Ma, William Morriss
#include <unistd.h>
int main() {
    long a[52], *b = a, c = 0, d, e;
    *b++ = 0x7A7A69460A320A31;
    *b++ = 0xA7A7A75420A340A;
    *b++ = 0x380A370A7A7A6946;
    *b++ = 0xA7A7A69460A;
    b = (long*)((short*)b - 1);
    do {
        *b++ = 0xA31310A7A7A7542 + (((d = (((c & 2) | (c & 4)) >> 1) + c)) 
                                 + ((e = ((c & 1 | (c & 1) << 2))) << 8) << 40);
        *b++ = 0xA33310A7A7A6946 + (d + (e << 8) << 40);
        *b++ = 0x427A7A69460A3431 + d + (e << 8);
        *b++ = 0x310A31310A7A7A75 + ((d + (c & 1))
                                  + ((e ^ 5) << 8)
                                  + ((d + (c & 1)) << 24) << 32);
        *b++ = 0x310A7A7A69460A32 + (e ^ 5) + ((d + (c & 1)) << 56);
        *b++ = 0x460A7A7A75420A34 + (e ^ 5);
        *b++ = 0x320A32320A7A7A69 + ((d << 24) + d + (e << 8) << 32);
        *b++ = 0xA7A7A69460A33 + e;
        b = (long*)((char*)b - 1);
    } while (c ++< 5);
    *b = 0xA7A7A7542;
    return write(1, a, 413) - 413;
}
