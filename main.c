// @author Chuchu Ma, William Morriss
#include <unistd.h>
int main() {
    long a[52], *b = a, c = 0, d, e;
    *b++ = 8825482169325586993;
    *b++ = 755050531575706634;
    *b++ = 4038100534035114310;
    *b++ = 11521156007434;
    b = (long*)((short*)b - 1);
    do {
        *b++ = 734422135312381250 + (((d = (((c & 2) | (c & 4)) >> 1) + c)) 
                                 + ((e = ((c & 1 | (c & 1) << 2))) << 8) << 40);
        *b++ = 734985085265799494 + (d + (e << 8) << 40);
        *b++ = 4790275746227172401 + d + (e << 8);
        *b++ = 3533690944324532853 + ((d + (c & 1))
                                  + ((e ^ 5) << 8)
                                  + ((d + (c & 1)) << 24) << 32);
        *b++ = 3533771523796372018 + (e ^ 5) + ((d + (c & 1)) << 56);
        *b++ = 5046980998793923124 + (e ^ 5);
        *b++ = 3605749642169055849 + ((d << 24) + d + (e << 8) << 32);
        *b++ = 2949415937903155 + e;
        b = (long*)((char*)b - 1);
    } while (c ++< 5);
    *b = 45004518722;
    return write(1, a, 413) - 413;
}
