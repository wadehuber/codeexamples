#include<stdio.h>
#include<string.h>

#define RIGHT_BIT 0x01

int bits_in_byte(char c);

int count_bits(char * str, int len) {
    int ii;
    int count = 0;

    for (ii=0;ii<len;ii++) {
       count += bits_in_byte(*str);
       str ++; 
    }
    return count;
}

int bits_in_byte(char c) {
    int count = 0;
    int ii;
    for (ii=0;ii<sizeof(char) * 8;ii++) {
        count += c & RIGHT_BIT;
        c = c >> 1;
    }
    return count;
}

int bits_in_int(int c) {
    int count = 0;
    int ii;
    for (ii=0;ii<sizeof(int) * 8;ii++) {
        count += c & RIGHT_BIT;
        c = c >> 1;
    }
    return count;
}

unsigned int power_of_2(int n) {
    int ii;
    int result = 1;
    for(ii=0;ii<n;ii++) {
        result *= 2;
    }
    return result;
}

int main() {
    unsigned int num = 0x00000001; 
    char * str1 = "Hello, world";
    char * str2 = (char *) &num;
    int ii;
    unsigned int sum =0;

    printf("count_bits:\n");
    printf ("\nNumber of bits set in %s = %d\n\n", str1, count_bits(str1, strlen(str1)));

    printf("\n");
    printf("bits_in_int:\n");
    for (ii=1;ii<=20;ii++) {
        printf ("Number of bits set %d = %d\n", ii, bits_in_int(ii));
        num ++;
    }
    
    printf("\n");
    printf("bits_in_int & power_of_2:\n");
    for (ii=1;ii<=20;ii++) {
        sum  = sum  + power_of_2(ii);
        printf ("Number of bits set in %d = %d\n", power_of_2(ii), bits_in_int(power_of_2(ii)));
        printf ("Number of bits set in %d = %d\n", sum , bits_in_int(sum ));
        num ++;
    }

    return 0;
}

