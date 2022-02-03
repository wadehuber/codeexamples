/* Do not try this at home! */

#include<stdio.h>
#include<string.h>

struct smashed {
   char str1[8];
   char str2[8];
   char str3[8];
};

int main(void) {
    struct smashed smash = {"ABCDEFG", "XXXXXXX", "1234567"};
    printf("smash: %s %s %s\n", smash.str1, smash.str2, smash.str3); 

    strncpy(smash.str2, "LMNOPQRSTUVW", sizeof("LMNOPQRSTUVW"));
    printf("smash: %s %s %s\n", smash.str1, smash.str2, smash.str3); 

    char * scan = &smash;
    printf("\nCharacter by character:\n");
    for(int ii=0;ii<sizeof(smash);ii++) {
        printf("ii: %c [%X]\n", scan[ii], scan[ii]);
    }

    /* This will cause trouble!
    strncpy(smash.str3, "What will happen now?", sizeof("What will happen now?"));
    printf("\nsmash: %s %s %s\n", smash.str1, smash.str2, smash.str3); 
    */

    return 0;
}
