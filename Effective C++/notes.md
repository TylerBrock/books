Effective C++ (Third Edition)
=============================

Item 1
------

View C++ as a federation of languages

The 4 sublanguages can be thought of as follows:
  - C
  - Object-Oriented C++
  - Template C++
  - The STL

### Things to Remember
  - Rules for effective C++ vary, depending on the part of C++ you are using.

Item 2
------

Prefer consts, enums, and inlines to #defines. Another way to think about this is prefering the compiler to the preprocessor.

    // Using the preprocessor
    #define ASPECT_RATIO 1.653

    // Using the compiler
    const double AspectRatio = 1.653;

Using a language constant allows AspectRatio to be seen by compilers which provides:
  - More useful error messages and debugging (name is in the symbol table).
  - Potentially smaller code (one copy vs blind substitution).

### Special Cases

Constant pointers should be declared const in addition to what the pointer points to.

    // const pointer to const char
    const char * const authorName = "Scott Meyers";

String objects are generally preferable.

    const std::string authorName("Scott Meyers");

Class specific constants

    // in header file
    class GamePlayer {
    private:
        static const int NumTurns = 5;
        int scores[NumTurns];
    };

    // in implementation
    const int GamePlayer::NumTurns;

  - Preferable to #define for similar use as it has class specific scope and provides encapsulation.
  - Older compilers may require initial value at the point of definition instead of at the point of  declaration.
  - The enum hack can be used in cases where we want to enforce not being able to the address.

    class GamePlayer {
    private:
        enum { NumTurns = 5 };
        int scores[NumTurns];
    };

### Macros that look like functions

Avoid at all costs:

    // call f with the maximum of a and b
    #define CALL_WITH_MAX(a,b) f((a) > (b) ? (a) : (b))

Prefer the template approach:

    template <typename T>
    inline void callWithMax(const T&a, const T&b)
    {
        f(a > b ? a: b);
    }

### Things to Remember
  - For simple constants, prefer const objects or enums to #defines
  - For function-like macros, prefer inline functions to #defines

Item 3
------

### Things to Remember
  - Declaring something const helps compilers detect usage errors. const can be applied to objects at any scope, to function parameters and return types, and to member functions as a whole.
  - Compilers enforce bitwise constness, but you should program using logical constness.
  - When const and non-const member functions have essentially identical implementations, code duplication can be avoided by having the non-const version call the const version.

Item 4
------

### Things to Remember
  - Manually initialize objects of built-in type, because C++ only sometimes initializes them itself.
  - In a constructor, prefer use of the member initialization list to assignment inside the body of the constructor. List data members in the initialization list in the same order they're declared in the class.
  - Avoid initialization order problems across translation units by replacing non-local static objects with local static objects.
