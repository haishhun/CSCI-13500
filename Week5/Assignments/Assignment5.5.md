# Pointer Detective
Welcome to the agency detective. We ran into a couple of tough cases, and we need your help. As the best pointer detective in town, we thought of you first. 

## Introduction

A mysterious bug has appeared in several C++ programs. Your job as a **Pointer Detective** is to investigate each program and determine what is happening behind the scenes.

For **each mystery**, complete the following tasks **before running the program**:

1. Predict the program's output.
2. Explain **why** the output occurs.
3. Draw the call stack while the function executes.
4. Identify whether the function uses:
   - Pass by Copy
   - Pass by Reference
   - Pass by Pointer

After completing your predictions, compile and run the program to verify your answers.

---

# Mystery #1 – The Copycat

**Concepts:** Pass by Copy, Scope, Call Stack

```cpp
#include <iostream>

void addFive(int number)
{
    number += 5;
    std::cout << "Inside addFive(): " << number << std::endl;
}

int main()
{
    int value = 10;

    addFive(value);

    std::cout << "In main(): " << value << std::endl;
}
```

### Questions

1. What is the output of this program?
```cpp
Inside addFive(): 15
In main(): 10
```
2. Why doesn't `value` change after calling `addFive()`?
* Because `addFive` receives a copy of `value` and doesn't change the original value.
3. Where does the variable `number` exist?
* Only in `addFive` and gets removed after the function.
4. Draw the call stack while `addFive()` is executing.
* ### TODO
5. What happens to `number` after the function returns?
* Getting removed from memory.
---

# Mystery #2 – The Mirror

**Concepts:** References, `const`, Modifying Variables

```cpp
#include <iostream>

void investigate(int& suspect, const int& clue)
{
    suspect += clue;

    std::cout << "Inside investigate(): "
         << suspect << " " << clue << std::endl;
}

int main()
{
    int score = 10;
    int bonus = 5;

    investigate(score, bonus);

    std::cout << score << " " << bonus << std::endl;
}
```

### Questions

1. What is the output of this program?
```
Inside investigate(): 15 5
15 5
```
2. Why does `score` change while `bonus` does not?
* We are not changing bonus anywhere, but even if we were then we put it as a const in `investigate` function.
3. Why is `clue` declared as a `const` reference?
*  To pass the original value by reference into the `investigate` function without being able to change the value itself.
4. What would happen if the function attempted to modify `clue`?
* We will get an error because `clue` is a const (immutable.)
5. Draw the call stack while `investigate()` is executing.
* ### TODO

---

# Mystery #3 – Following the Pointer

**Concepts:** Raw Pointers, Dereferencing, `nullptr`

```cpp
#include <iostream>

void investigate(int* evidence)
{
    if (evidence != nullptr)
    {
        *evidence *= 2;
    }
}

int main()
{
    int clue = 7;

    investigate(&clue);

    std::cout << clue << std::endl;
}
```

### Questions

1. What is the output of this program?
* 14
2. Why do we pass `&clue` instead of `clue`?
* it's the address of a clue value, and a formal parameter of `investigate` is a pointer.
3. What does `*evidence` do?
* Gets the value of `clue` by dereferencing `evidence`.
4. Why is the `nullptr` check important?
* To prevent undefined behaviour like dereferencing null address.
5. What would happen if the function was called as `investigate(nullptr);`?
* Then it won't pass a check if (evidence != nullptr) and the function won't do anything. So the output would be 7.
6. Draw the call stack while `investigate()` is executing.
* ### TODO

---

# Mystery #4 – The Master Case

**Concepts:** Pass by Copy, Pass by Reference, Pass by Pointer, Return Values

```cpp
#include <iostream>

int mysteryA(int x)
{
    x += 10;
    return x;
}

void mysteryB(int& y)
{
    y *= 2;
}

void mysteryC(int* z)
{
    if (z != nullptr)
    {
        (*z)--;
    }
}

int main()
{
    int value = 5;

    value = mysteryA(value);
    mysteryB(value);
    mysteryC(&value);

    std::cout << value << std::endl;
}
```

### Questions

1. Predict the output of the program.
*29
2. Draw the call stack after each function call.
* ### TODO
3. Which function uses:
   - Pass by Copy?
        * mysteryA
   - Pass by Reference?
        * mysteryB
   - Pass by Pointer?
        * mysteryC
4. Which functions modify the original variable?
    * mysteryB by reference and mysteryC by pointer
5. Why does `mysteryA()` return a value, while `mysteryB()` and `mysteryC()` do not?
* Because in `mysteryA` we work with copy that will be removed after function finishes, so to save the value we received we reassign the `value` by calling `value = mysteryA(value);` which reassigns `value` to modified copy inside `mysteryA`.
6. Which approach would you choose if your goal was to modify the original variable? Explain your reasoning.
* Based on the examples above, I would choose changing by reference, because we could see that for pointers we need to check if pointer != nullptr, which we didn't need for reference.

---

# Reflection

Answer the following questions in complete sentences.

1. What is the difference between passing a variable by copy, by reference, and by pointer?
* Passing by copy creates a copy of original variable and passes it in a function without being able to change the original value. Passing by reference passes an explicit link to the original variable that can be changed in a function. For passing by pointer we pass the address of a value, need to check if the address is not null and then dereference to be able to change the original value.
2. When would you choose to use a reference instead of a pointer?
* I would choose a reference when we are sure that the value exists and we don't need to check for null.
3. Why might a function accept a pointer instead of a reference?
* We can use pointer when the argument can be absent (null).
4. What role does the `const` keyword play when working with references and pointers?
* Makes the value unmodifiable in the function when we pass by reference or pointer.
5. How does understanding the call stack help explain why variables change—or do not change—during function calls?
* ### TODO