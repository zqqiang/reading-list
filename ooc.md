# Object Oriented Programming in C
[Source Code](https://github.com/shichao-an/ooc.git)

## 1. Abstract Data Types Information Hiding
## 2. Dynamic Linkage Generic Functions
## 3. Programming Savvy Arithmetic Expressions
## 4. Inheritance Code Reuse and Refinement
## 5. Programming Savvy Symbol Table

## 6. Class Hierarchy Maintainability
### 6.6 Implementation — Class
How to write dynamic parameters function.
~~~~
extern void * Class_ctor (void * _self, ...);

void * Class_ctor (void * _self, va_list * app)
{
    typedef void (* voidf) ();  /* generic function pointer */
    voidf selector;

    va_list ap = * app;
    while ((selector = va_arg(ap, voidf)))
    {   voidf method = va_arg(ap, voidf);

        if (selector == (voidf) ctor)
            // do something
    }
    va_end(ap);
}
~~~~

## 7. The ooc Preprocessor Enforcing a Coding Standard