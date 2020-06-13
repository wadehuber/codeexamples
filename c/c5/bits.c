#include<stdio.h>
#include<string.h>

#define RIGHT_BIT 0x01    /* 0000 0001 */

int bits_in_byte(char c) {
    int count = 0;
    
    for(int ii=0;ii<sizeof(char) * 8;ii++) {
        count += c & RIGHT_BIT;
        c = c >> 1;
    }
    return count;
}

int bits_in_int(int c) {
    int count = 0;
    
    for(int ii=0;ii<sizeof(int) * 8;ii++) {
        count += c & RIGHT_BIT;
        c = c >> 1;
    }
    return count;
}

int count_bits(char * str, int len) {
    int count = 0;
    
    for(int ii=0;ii<len;ii++) {
        count += bits_in_byte(*str);
        str++;
    }
    return count;
}

unsigned int power_of_2(unsigned int n) {
    int result = 1;
    result = RIGHT_BIT << n;
    return result;
}

int main() {
    char class[] = "CSC220 Summer 2020";
    char * state = "Arizona, USA";
    unsigned int sum = 0;

    for(char cc=0;cc<=8;cc++) {
        printf("  bits_in_byte(%d)=%d\n", cc, bits_in_byte(cc));
    }

    printf("\n");
    printf("  count_bits(\"Hello, World!\") = %d\n", 
              count_bits("Hello, World!", strlen("Hello, World!")));
    printf("  count_bits(\"%s\") = %d\n", class, count_bits(class, strlen(class)));
    printf("  count_bits(\"%s\") = %d\n", state, count_bits(state, strlen(state)));

    printf("\n");
    for(int ii=-16;ii<=16;ii++) {
        printf("  bits_in_int(%d)=%d\n", ii, bits_in_int(ii));
    }

    printf("\n");
    for(int ii=1;ii<=20;ii++) {
        sum = sum + power_of_2(ii);
        printf("%d: sum=%d, power_of_2(ii)=%d, ", ii, sum, power_of_2(ii));
        printf("bits_in_int(%d)=%d, ", power_of_2(ii), bits_in_int(power_of_2(ii)));
        printf("bits_in_int(%d)=%d\n", sum, bits_in_int(sum));
    }

    return 0;
}

