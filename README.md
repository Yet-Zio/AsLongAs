# Concept of As Long As Loop
Before we start, this is just a concept that might have already been implemented or maybe there's no need for such a feature. I am probably not updated with the standards if such a feature exists.
The code contained here is probably barebones and can be treated as an example.

This loop is an idea and a solution to when I came upon a certain problem that I had experienced before.
The problem was "**loop till a condition is true, check the condition each time a statement was executed in a loop and break out of it**". Ofcourse, we have our while loop to deal with this problem. The break statement also provides the function to break out of it. So, let's explore a bit how a while loop can solve this problem.

## 1. Solution by while loop

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

## 2. Problems with the solution
- While loop only checks the condition after each iteration. Thus, the condition needs to be checked everytime after each statement.

- The problem is solved by an if and break statement. This in turn produces redundancy in code as you can see above.

- The loop does not itself guarantee that the condition is true while running.

## 3. The actual solution
This is how our traditional while loop works:
