#include<stdio.h>

/* Big Endian vs Little Endian
 *
 *  Big Endian - the most significant byte is stored at the
 *               lowest memory address
 *  Little Endian - the least significant byte is stored at the
 *               lowest memory address
 * 
 *   Integer value: 0xA1B2C3D4
 *
 *  Memory      Big       Little
 *  Address    Endian     Endian
 *  =======    ======     ======
 *  0x100        A1         D4
 *  0x101        B2         C3
 *  0x102        C3         B2
 *  0x103        D4         A1
 *
 */

union endian_check {
    char c;
    unsigned int n;
};

int main() {
    /* Only the low-order (least significant) bit is set */
    unsigned int n = 1;  /* 00 00 00 01 */
    union endian_check un;

    char *c = (char *) &n;

    printf("Determine endian-ness with a char pointer:\n");
    /* If little endian, n will be store in memory as 
     *    01 00 00 00, so *c = 1 */
    if (*c) {
        printf("  Little endian\n");
    }
    /* If big endian, n will be store in memory as 
     *    00 00 00 01, so *c = 0 */
    else {
        printf("  Big endian\n");
    }

    /* Use a union to determine endian-ness */
    printf("\nDetermine endian-ness with a union:\n");
    un.n = 0x01;
    
    if(un.c == 1) {
        printf("  Little endian\n");
    }
    else {
        printf("  Big endian\n");
    }
    return 0;
}
