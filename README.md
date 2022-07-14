# Concept of As Long As Loop
Before we start, this is just a concept that might have already been implemented or maybe there's no need for such a feature. I am probably not updated with the standards if such a feature exists. There's probably a better solution than what I have provided here.
The code contained here is probably barebones and can be treated as an example.

This loop is an idea and a solution to when I came upon a certain problem that I had experienced before.
The problem was "**loop till a condition is true, check the condition each time a statement was executed in a loop and break out of it**". Ofcourse, we have our while loop to deal with this problem. The break statement also provides the function to break out of it. So, let's explore a bit how a while loop can solve this problem.

## 1. Solution by While loop

```
while the condition is true
  statement or function that may or may not modify the condition
  
  check the condition and break out of it
  
  another statement that may or may not modify the condition
  
  check the condition and break out of it
```

In code it might look like this:
```c++
while(condition){
  statement1;
  if(condition)
    break;
  statement2;
  if(condition)
    break;
  statement3;
  if(condition)
    break;
  statementN;
}
```

## 2. Problems with the Solution
- While loop only checks the condition after each iteration. Thus, the condition needs to be checked everytime after each statement.

- The problem is solved by an if and break statement. This in turn produces redundancy in code as you can see above.

- The loop does not itself guarantee that the condition is true while running.

## 3. How while loop works
![while loop](https://raw.githubusercontent.com/Yet-Zio/AsLongAs/main/img/whileloop.png?token=GHSAT0AAAAAABRX372WZH7HPU7NZZN5ANICYWQICPQ)

> A while loop is a control flow statement that allows code to be executed repeatedly based on a given Boolean condition. The while loop can be thought of as a repeating if statement.
> -- <cite>[Wikipedia][1]</cite>

[1]: https://en.wikipedia.org/wiki/While_loop

Since being an entry controlled loop, while loop checks the condition first, then executes a block of code and checks the condition again for further execution.
However, as the 2nd section provided, the loop does not check or guarantee by itself if the condition is true or false during the execution of the loop body.

## 4. The Actual Solution
The actual solution to this is quite simple and probably anyone can guess it. A loop that checks the condition provided after execution of each statement and breaks out of it if the condition ever becomes false. We can call it "**As Long As**" for now. Could have provided a better name, but anyway this is how it works:

![aslongas loop](https://raw.githubusercontent.com/Yet-Zio/AsLongAs/main/img/aslongasloop.png?token=GHSAT0AAAAAABRX372W6CO6W4AWNDTSZIEQYWQICYQ)

This can be seen as an automated process or function of the loop instead of providing a conditional statement.

## How this helps?
- Solves a lot of problems and removes redundancy in the code. 
- The programmer does not need to worry about unwanted code running.
- Does not need nested loops.

## Example
Files are provided in this repo providing a barebone functioning example. The loop is created as a variadic function template that takes a boolean condition and lambda functions to loop through each of them provided the condition is always true.

[<aslongas.h>](https://github.com/Yet-Zio/AsLongAs/blob/main/aslongas.h)
```c++
template<typename T, typename... ST>
void aslongas(bool &expression, T func, ST... fs){
    __aslong__as__:
    if(AS_LONG_AS_START){
        ASLONGAS_FSSIZE = sizeof...(fs)+1;
        AS_LONG_AS_START = false;
    }

    if(expression) {
        func();
    }

    if(sizeof...(fs) == 0){
        GLOBAL_ASLONGAS_COUNTER = ASLONGAS_FSSIZE;
    }

    if(GLOBAL_ASLONGAS_COUNTER > 1){
        GLOBAL_ASLONGAS_COUNTER--;
        return;
    }

    if(expression) {
        aslongas(expression, fs...);
    }

    if(GLOBAL_ASLONGAS_COUNTER > 1){
        GLOBAL_ASLONGAS_COUNTER--;
        return;
    }

    if(expression){
        reset_aslongas();
        goto __aslong__as__;
    }

}
```

## Usage

[<main.cpp>](https://github.com/Yet-Zio/AsLongAs/blob/main/main.cpp)
```c++
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
        std::string ch;
        std::cin >> ch;
        if(ch == "Bob"){
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

```

Hopefully, this solves the problem, but it can be improved more with new code, there's probably no need of this. Im sure there's a better solution to this that Im unaware of.
