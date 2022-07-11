#include <iostream>
#include "aslongas.h"

int main() {

    bool ex = true;
    int input;

    aslongas(ex, [&ex, &input]()
    {
        printf_s("Enter a number:\n");
        scanf_s("%d", &input);
        if(input == 2)
        {
            ex = false;
        }
    },
        [&ex, &input]()
    {
        printf_s("Enter 4");
        scanf_s("%d", &input);
        if(input == 4){
            printf_s("bruh");
            ex = false;
        }
    },
    [&ex](){
        printf_s("What is your name?");
        int ch;
        scanf_s("%d", &ch);
        if(ch == 5){
            ex = false;
        }
    },
    [&ex](){
        printf_s("Enter sus: ");
        std::string ch;
        std::cin >> ch;
        if(ch == "amogus"){
            ex = false;
        }
    });

    return 0;
}
