#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "Atd.h"

//Выделение памяти для Atd на N элементов размером Size
Atd_t * AtdAllocate(unsigned N, unsigned Size, unsigned AtdType)
{
    Atd_t * Atd;

    // Выделение памяти под структуру Atd_t
    Atd = (Atd_t *) malloc(sizeof(Atd_t));

    if (N <= 0)
    {
        printf("\nThe incorrect input ArraySize\n");
        N = 1;
    }
    if (Size <= 0)
    {
        printf("\nThe incorrect input ElementSize\n");
        Size = 1;
    }

    Atd->ArraySize = N;
    Atd->ElementSize = Size;
    Atd->AtdType = AtdType;

    // Выделение памяти под элементы массива ptrArray
    Atd->ptrArray = malloc(N * Size);

    return Atd;
}

//Освобождение памяти
void AtdFree(Atd_t * Atd)
{
    free(Atd->ptrArray);    // Освобождение памяти для void
    free(Atd);              // Освобождение памяти для структуры Atd
}


//Инициализация Atd_t
void AtdInit(Atd_t * Atd, void * ud_t)
{
    char * cptrArray = (char *) Atd->ptrArray;
    char * cptrSrc = (char *) ud_t;
    char * cptrTrgt;
    unsigned ArraySize = Atd->ArraySize;
    unsigned ElementSize = Atd->ElementSize;
    unsigned i, j;

    for (i = 0; i < ArraySize * ElementSize; i++)
    {
        cptrArray[i] = cptrSrc[i];
    }

    for (i = 0; i < ArraySize; i++)
    {
        cptrTrgt = &cptrArray[i * ElementSize];
        for (j = 0; j < ElementSize; j++)
            cptrTrgt[j] = cptrSrc[i * ElementSize + j];
    }
}


//Получение размера Atd_t массива
unsigned GetAtdSizeArray(Atd_t * Atd)
{
    return (Atd->ArraySize);
}


//Получение размера элемента Atd_t массива
unsigned GetAtdElementSize(Atd_t * Atd)
{
    return (Atd->ElementSize);
}

//Получение типа элемента Atd_t массива
unsigned GetAtdType(Atd_t * Atd)
{
    return (Atd->AtdType);
}


//Вывод на экран элементов АТД
void AtdPrint(Atd_t * Atd, char * cDelimiter)
{
    char * cptrArray = (char *) Atd->ptrArray;
    unsigned ArraySize = Atd->ArraySize;
    unsigned ElementSize = Atd->ElementSize;
    unsigned AtdType = Atd->AtdType;
    unsigned i;
    int IntElement;
    float FloatElement;
    double DoubleElement;

        for (i = 0; i < ArraySize; i++)
        {
            if (AtdType == 1) //1 - string
                printf("%c", cptrArray[i]);
            else if (AtdType == 2) //2 - int
            {
                IntElement = *((int*)&cptrArray[i *  ElementSize]);
                printf("%d", IntElement);
            }
            else if (AtdType == 3) //3- float
            {
                FloatElement = *((float*)&cptrArray[i *  ElementSize]);
                printf("%.2f", FloatElement);
            }
            else if (AtdType == 4) //4 - double
            {
                DoubleElement = *((double*)&cptrArray[i *  ElementSize]);
                printf("%.2f", DoubleElement);
            }

            printf("%s", cDelimiter);
        }
}


// Получение элементов массива с i-го по j-й
int GetAtdElements(Atd_t * AtdSrc, Atd_t * AtdElements, unsigned BegIndex, unsigned EndIndex)
{
    char * cptrSrc = (char *) AtdSrc->ptrArray;
    char * cptrTrgt = (char *) AtdElements->ptrArray;
    unsigned ArraySize = AtdSrc->ArraySize;
    unsigned ElementSize = AtdSrc->ElementSize;
    unsigned i;
    unsigned n = 0;

    if (AtdSrc->AtdType != AtdElements->AtdType)
    {
        printf("\nOperation is possible only for the same AtdType");
        return (-1); // Fatal Error
    }

    if (BegIndex <= 0 || BegIndex > EndIndex || EndIndex > ArraySize)
    {
        printf("\nIndex value i or j - Index i must be > 0 and <= j and j must be <= SizeArray", ArraySize);
        return (1); // Error
    }

    for (i = (BegIndex - 1) * ElementSize; i < EndIndex * ElementSize; i++)
        cptrTrgt[n++] = cptrSrc[i];

    return (0);
}

// Конкатенация
int AtdConcatenation(Atd_t * AtdSrc1, Atd_t * AtdSrc2, Atd_t * AtdTrgt)
{
    char * cptrSrc1 = (char *) AtdSrc1->ptrArray;
    char * cptrSrc2 = (char *) AtdSrc2->ptrArray;
    char * cptrTrgt = (char *) AtdTrgt->ptrArray;
    unsigned ElementSize = AtdSrc1->ElementSize;
    unsigned cElementsAtdSrc1 = AtdSrc1->ArraySize * ElementSize;
    unsigned cElementsAtdSrc2 = AtdSrc2->ArraySize * ElementSize;
    unsigned NewArraySize = AtdTrgt->ArraySize;
    unsigned ArrayConcat = AtdSrc1->ArraySize + AtdSrc2->ArraySize;
    unsigned i;

    if (AtdSrc1->AtdType != AtdSrc2->AtdType)
    {
        printf("\nOperation is possible only for the same AtdType");
        return (-1); //Error
    }

    if (NewArraySize != ArrayConcat)
    {
        printf("\nIncorrect Size Atd Concatenation", ArrayConcat, NewArraySize);
        return (-2); //Error
    }

    for (i = 0; i < cElementsAtdSrc1; i++)
        cptrTrgt[i] = cptrSrc1[i];

    for (i = 0; i < cElementsAtdSrc2; i++)
        cptrTrgt[cElementsAtdSrc1 + i] = cptrSrc2[i];

    return (0);