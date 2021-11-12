#include <stdbool.h>

#pragma once
#ifndef Atd_H
#define Atd_H

typedef struct Atd_t
{
    void * ptrArray; // Указатель на массив
    unsigned ArraySize; // Размерность массива
    unsigned ElementSize; // Размерность элемента массива
    unsigned AtdType; // Тип данных: 1 - string, 2 - int, 3 - float, 4 - double
} Atd_t;

unsigned LenStr (char * Str);

Atd_t * AtdAllocate(unsigned N, unsigned ElementSize, unsigned AtdType);

void AtdFree(Atd_t * Atd);

void AtdInit(Atd_t * Atd, void * ud_t);

void AtdPrint(Atd_t * Atd, char * cDelimiter);

unsigned GetAtdSizeArray(Atd_t * Atd);

unsigned GetAtdElementSize(Atd_t * Atd);

unsigned GetAtdType(Atd_t * Atd);

int GetAtdElements(Atd_t * AtdSrc, Atd_t * AtdElements, unsigned BegIndex, unsigned EndIndex);

int AtdConcatenation(Atd_t * AtdSrc1, Atd_t * AtdSrc2, Atd_t * AtdTrgt);

#endif /*Atd_H*/