# Dynamic Arrays in C

## Usage
Include the Header File in your .c or .cpp file. Declare a struct with three fields:
- contents
- count
- capacity

e.g

``` C
typedef struct Stack {
    int *contents;
    size_t count;
    size_t capacity;
} Stack;
```
