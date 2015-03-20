// @author Chuchu Ma, William Morriss
#include <unistd.h>
int main() {
    long buffer[52], *curr = buffer, i = 0, base = 9;
    *curr++ = 0x7A7A69460A320A31;
    *curr++ = 0x0A7A7A75420A340A;
    *curr++ = 0x380A370A7A7A6946;
    *curr++ = 0x00000A7A7A69460A;
    curr = (long*)((short *)curr - 1);
    loop:
        base += 1;
        *curr++ = 0x0A30300A7A7A7542 + (++base / 10 + (base++ % 10 << 8) << 40);
        *curr++ = 0x0A30300A7A7A6946 + (++base / 10 + (base++ % 10 << 8) << 40);
        *curr++ = 0x427A7A69460A3030 + (base / 10 + (base++ % 10 << 8));
        *curr++ = 0x300A30300A7A7A75 + (((++base + 1) / 10 << 24) 
                                   + base / 10 + (base++ % 10 << 8) << 32);
        *curr++ = 0x300A7A7A69460A30 + base % 10 + ((base++ + 2) / 10 << 56);
        *curr++ = 0x460A7A7A75420A30 + ++base % 10;
        base += 2;
        *curr++ = 0x300A30300A7A7A69 + (((++base + 1) / 10 << 24) 
                                   + base / 10 + (base++ % 10 << 8) << 32);
        *curr++ = 0x000A7A7A69460A30 + base++ % 10;
        curr = (long*)((char *)curr - 1);
        if (i ++< 5) goto loop;
    *curr++ = 0x0000000A7A7A7542;
    return write(1, buffer, 413) - 413;
}
