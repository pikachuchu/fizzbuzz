// @author Chuchu Ma, William Morriss
#include <unistd.h>
int main() {
    long a[52], *b = a, c = 0, d, e, f, g;
    *b++ = 0x7A7A69460A320A31;
    *b++ = 0xA7A7A75420A340A;
    *b++ = 0x380A370A7A7A6946;
    *b++ = 0xA7A7A69460A;
    b = (long*)((short *)b - 1);
    loop:
        //TODO: find relationship between d and f and between e and g
        *b++ = 0xA31310A7A7A7542 + ((d = (((c > 1) << (c > 3)) + c)) 
                                 + (e = ((c & 1) + ((c & 1) << 2) << 8)) << 40);
        *b++ = 0xA33310A7A7A6946 + (d + e << 40);
        *b++ = 0x427A7A69460A3431 + d + e;
        *b++ = 0x310A31310A7A7A75 + ((f = (((c > 0) << (c > 2)) + c + (c == 5)))
                                  + ((g = (!(c & 1) + (!(c & 1) << 2))) << 8)
                                  + (f << 24) << 32);
        *b++ = 0x310A7A7A69460A32 + g + (f << 56);
        *b++ = 0x460A7A7A75420A34 + g;
        *b++ = 0x320A32320A7A7A69 + ((d << 24) + d + e << 32);
        *b++ = 0xA7A7A69460A33 + (e >> 8);
        b = (long*)((char *)b - 1);
        if (c ++< 5) goto loop;
    *b = 0xA7A7A7542;
    return write(1, a, 413) - 413;
}

