# Chapter 1: Programming

This chapter is a review of important concepts and their C++ implementation 
used in this course. Very good short explanations can be found in this
[C++ YouTube Playlist](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb).

## Classes and Templates
* A simple class called [IntCell](IntCell)
* [Function and class templates](templates)

## Dynamic Memory Allocation and Pointers
* Some Questions:
  - Where do programs store variables and objects?
  - Where does memory come from and how is memory returned?
  - Why do we need dynamic memory allocation?
  - What is the difference between the stack and the heap.
  - Example: Create a memory diagram for executing the following program:

    ```cpp
    int inc(int x) return x + 1;

    int main() {
      int a = 10;
      int b = inc(a);
      return 0;
    }
    ```

  - What are the differences between memory management in C, C++, Java and Python? (Most programming languages use similar mechanisms.)
    |                | C   | C++ | Java | Python |
    | :------------- | :-: | :-: | :--: | :----: |
    | Request memory |  ?  |  ?  |   ?  |   ?    |
    | Return memory  |  ?  |  ?  |   ?  |   ?    |

* Video: How do create [memory diagrams](http://vimeo.com/58710057)
* [Pointers and dynamic memory allocation](pointers)
* [Call-by-value vs call-by-reference](parameters) and using `const`.
* Reading: [References vs. pointers](https://isocpp.org/wiki/faq/references)
* Exercise: [Memory allocation](memory)
* Destructor, copy constructor, assignment operator, and move semantics: [The rule of three and the big five](big-five) for classes.

## Standard Template Library
* Reading: [The C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
* Examples: [Arrays vs STL vectors and C-strings vs STL strings.](vector_string)
* [How to compare objects](comparator) (`operator<` and function objects)

## Command Line Interface and File IO
* [The command line interface (CLI) and file IO](io)

## Recursion
* [Recursion to calculate factorials.](factorial)

## Testing
* [Testing a function to calculate factorials.](factorial)


## License

<img src="https://licensebuttons.net/l/by-sa/3.0/88x31.png" alt="CC BY-SA 4.0" align="left">

All code and documents in this repository are provided under [Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0) License.](https://creativecommons.org/licenses/by-sa/4.0/)