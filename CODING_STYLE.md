# Coding Style/Standard

## Braces

```C++
int add(int a, int b)
{
    return a + b;
}
// same for classes and namespaces

// but
if (1 < 2) {
    // do something
}
else {
    // something else
}
// same for while, for, do...while loops
```

## Pointer

```C++
double a = 0.0;           // always initialize
double* ptr = nullptr;  // always initialize to nullptr
ptr = &a;
```