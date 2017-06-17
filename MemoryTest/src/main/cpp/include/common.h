//
// Created by ziv on 17-5-24.
//

#ifndef VALGRINDTEST_COMMON_H
#define VALGRINDTEST_COMMON_H


// MemoryError
void memoryNoFreeLeak();
void memoryLeak();
void memoryOverrunError();
void strcpyOverrunError();
void memoryDoubleFree();
void useWildPointer();
void memoryFreeWildPointer();

#endif //VALGRINDTEST_COMMON_H
