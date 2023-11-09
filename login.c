#include <stdio.h>
#include <string.h>

// Run: gcc ./login.c -fno-stack-protector -o ./login
// Then run the program: ./vul1

char* getPasswd(){

    return "1337";
}

int accountManipulation(){
    printf("> Log in successfully, account manipulating...\n");
    return 0;
}

int loginFail(){
    printf("> Log in unsuccessfully, exiting!\n");

}

int main(void)
{
    char *passwd = getPasswd();
    char buff[100];
    int log_in = 0;
    char tryPasswd[4];

    printf("Please input a 4 BYTES password: ");
    gets(tryPasswd);

    if(strcmp(tryPasswd, passwd) == 0){
        log_in = 1;
    }

    if(log_in != 0){
        accountManipulation();
    }
    else{
        loginFail();
    }
}