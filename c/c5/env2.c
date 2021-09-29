#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {

    printf("Changing an environment variable using setenv:\n");
    const char * home = getenv("HOME");
    printf("Original HOME=%s\n", home);
    setenv("HOME", "wheretheheartis", 1);

    const char * newhome = getenv("HOME");
    printf("New HOME=%s\n", newhome);


    printf("\nAdding a new environment variable:\n");
    const char * env_value;
    putenv("PUTENV=123");
    putenv("SETENV_TEST=42");
    env_value = getenv("PUTENV");
    printf("PUTENV=%s\n", env_value);
    env_value = getenv("SETENV_TEST");
    printf("SETENV_TEST=%s\n", env_value);

    printf("\nUpdating a newly added environment variable:\n");
    env_value = getenv("SETENV_TEST");
    printf("BEFORE: SETENV_TEST=%s\n", env_value);
    setenv("SETENV_TEST", "Success", 1);
    env_value = getenv("SETENV_TEST");
    printf("AFTER: SETENV_TEST=%s\n", env_value);



    return 0;
}
