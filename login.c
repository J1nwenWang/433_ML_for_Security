// Run: gcc ./login.c -fno-stack-protector -o ./login
// Then run the program: ./vul1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkPasswd(const char* entered, const char* actual) {
    return strcmp(entered, actual) == 0;
}

int accountManipulation(){
    printf("> Log in successfully, account manipulating...\n");
    return 0;
}

int loginFail(){
    printf("> Log in unsuccessfully, exiting!\n");
    return 1;
}

int main(void)
{
    char *passwd = "1337"; // The password we expect
    char buff[100]; 
    int log_in = 0;
    char tryPasswd[4];
    void (*nextStep)(void) = loginFail; 
    printf("Please input username: ");
    gets(buff); 

    printf("Please input a 4 BYTES password: ");
    gets(tryPasswd);

    if(checkPasswd(tryPasswd, passwd)) {
        log_in = 1;
    }

    if(log_in!=0){
        nextStep = accountManipulation; 
    }

    nextStep();

    return 0;
}
