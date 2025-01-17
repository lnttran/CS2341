#include <iostream>
#include "IntCell.h"
#include "IntCellPtr.h"
#include "IntCellPtrOK.h"

using namespace std;

// Big-five Example

// Run with debugger: Set breakpoint to the first line of main() and watch the variables.

int main()
{
    /* Regular IntCell. Defaults work as expected */
    IntCell A(10);

    IntCell B = A; // uses implicit copy constructor (copy all member variables)

    A.write(20);

    B = A; // uses operator= (copy all member variables)

    /* IntCellPtr. Defaults do not work because of dynamic memory allocation */

    IntCellPtr C(10);

    IntCellPtr D = C;

    C.write(20);

    D = C;

    /* the pointer gets copied: we need a copy constructor and a copy assignment. Also, there is a new but no
       delete (destructor is missing) so we have a memory leak!

       You can activate the AddressSanitizer library in CMakeLists.txt (and run the program) or
       run valgrind in the VS Code terminal to detect memory leaks: 
       > valgrind --leak-check=full ./build/big-five
       
       valgrind says:

==180944== Memcheck, a memory error detector
==180944== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==180944== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==180944== Command: ./big-five
==180944==
==180944==
==180944== HEAP SUMMARY:
==180944==     in use at exit: 4 bytes in 1 blocks
==180944==   total heap usage: 2 allocs, 1 frees, 72,708 bytes allocated
==180944==
==180944== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==180944==    at 0x4849013: operator new(unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==180944==    by 0x109316: IntCellPtr::IntCellPtr(int) (IntCellPtr.cpp:9)
==180944==    by 0x109202: main (main.cpp:25)
==180944==
==180944== LEAK SUMMARY:
==180944==    definitely lost: 4 bytes in 1 blocks
==180944==    indirectly lost: 0 bytes in 0 blocks
==180944==      possibly lost: 0 bytes in 0 blocks
==180944==    still reachable: 0 bytes in 0 blocks
==180944==         suppressed: 0 bytes in 0 blocks
==180944==
==180944== For lists of detected and suppressed errors, rerun with: -s
==180944== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
       */

    /* IntCellPtrOK has a destructor, a copy constructor and an operator= */

    IntCellPtrOK E(10);

    IntCellPtrOK F = E;

    E.write(20);

    F = E;

    return 0;
}
