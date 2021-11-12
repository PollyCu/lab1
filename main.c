#include <stdio.h>
#include <malloc.h>
#include "Atd.h"

int main() {
    Atd_t *String1, *String2;
    Atd_t *AtdElements, *ConcatAtd;
    Atd_t *Int1, *Int2;
    Atd_t *Float1, *Float2;

    int MaxLenStr = 128;
    char *Str = (char *) malloc(sizeof(char) * MaxLenStr);
    unsigned i, j;
    unsigned AtdSizeArray;
    char ChoiceNext;

    unsigned SizeIntArray1 = 10;
    unsigned SizeIntArray2 = 10;
    int IntArray1[] = {10, 11, 21, 31, 41, 51, 61, 71, 81, 91};
    int IntArray2[] = {91, 81, 71, 61, 51, 41, 31, 21, 11, 10};

    unsigned SizeFloatArray1 = 10;
    unsigned SizeFloatArray2 = 10;
    float FloatArray1[] = {10.0, 11.1, 21.2, 31.3, 41.4, 51.5, 61.6, 71.7, 81.8, 91.9};
    float FloatArray2[] = {91.1, 81.2, 71.3, 61.4, 51.5, 41.6, 31.7, 21.8, 11.9, 10.0};


    // Проверка полиморфизма для элементов типа int и float

    // int
    printf("\n\n\nCheck polymorphism for elements of type int\n");
    printf("\nInit array type int for Int1:\n");
    for (i = 0; i < SizeIntArray1; i++)
        printf("%d, ", IntArray1[i]);

    // Выделение памяти для Atd_t
    Int1 = AtdAllocate(SizeIntArray1, sizeof(int), 2);   /* AtdType = 2 - int */

    // Инициализация Atd_t
    AtdInit(Int1, IntArray1);

    // Вывод на экран после инициализации int1
    printf("\nOutput Elements Atd with Delimiter:\n");
    AtdPrint(Int1, "|");

    //Получение элементов Atd Int1 с i-го по j-й элемент
    i = 2;
    j = 5;

    // Выделение памяти для Atd_t Array Size = j - i + 1
    AtdElements = AtdAllocate(j - i + 1, GetAtdElementSize(Int1), GetAtdType(Int1));

    if (GetAtdElements(Int1, AtdElements, i, j) == 0)
        // Если получение элементов с i-го по j-й успешно, вывод элементов на экран
    {
        printf("\n\nOutput Elements from %d to %d with Delimiter:\n", i, j);
        AtdPrint(AtdElements, "|");
    }

    AtdFree(AtdElements);

    printf("\n\nInit array type int for Int2:\n");
    for (i = 0; i < SizeIntArray2; i++)
        printf("%d, ", IntArray2[i]);

    // Выделение памяти для Atd_t
    Int2 = AtdAllocate(SizeIntArray2, sizeof(int), 2);

    // Инициализация Atd_t
    AtdInit(Int2, IntArray2);

    // Вывод на экран после инициализации int2
    printf("\nOutput Elements Atd with Delimiter:\n");
    AtdPrint(Int2, "|");

    // Выделение памяти для Сoncatenation Atd_t
    ConcatAtd = AtdAllocate(GetAtdSizeArray(Int1) + GetAtdSizeArray(Int2), GetAtdElementSize(Int1), GetAtdType(Int1));

    if (AtdConcatenation(Int1, Int2, ConcatAtd) == 0)
        // Если Конкатенация успешно, вывод на экран
    {
        printf("\n\nOutput Elements after Concatenation with Delimiter:\n");
        AtdPrint(ConcatAtd, "|");
    }

    AtdFree(Int2);
    AtdFree(ConcatAtd);
    AtdFree(Int1);


    // float
    printf("\n\n\nCheck polymorphism for elements of type float");

    printf("\n\nInit array type float for Float1:\n");
    for (i = 0; i < SizeFloatArray1; i++)
        printf("%5.2f, ", FloatArray1[i]);

    // Выделение памяти для Atd_t
    Float1 = AtdAllocate(SizeFloatArray1, sizeof(float), 3);

    // Инициализация Atd_t
    AtdInit(Float1, FloatArray1);

    // Вывод на экран после инициализации Float1
    printf("\n\nOutput Elements Atd with Delimiter:\n");
    AtdPrint(Float1, "|");

    // Получение элементов Atd Float1 с i-го по j-й элемент
    i = 2;
    j = 5;

    // Выделение памяти для Atd_t Array Size = j - i + 1
    AtdElements = AtdAllocate(j - i + 1, GetAtdElementSize(Float1), GetAtdType(Float1));

    if (GetAtdElements(Float1, AtdElements, i, j) ==
        0)
        // Если получение элементов с i-го по j-й успешно, выводим элементы на экран
    {
        printf("\n\nOutput Elements from %d to %d with Delimiter:\n", i, j);
        AtdPrint(AtdElements, "|");
    }

    AtdFree(AtdElements);

    printf("\n\nInit array type float for Float2:\n");
    for (i = 0; i < SizeFloatArray2; i++)
        printf("%5.2f, ", FloatArray2[i]);


    // Выделение памяти для Atd_t
    Float2 = AtdAllocate(SizeFloatArray2, sizeof(float), 3);

    // Инициализация Atd_t
    AtdInit(Float2, FloatArray2);

    // Вывод на экран после инициализации Int2
    printf("\n\nOutput Elements Atd with Delimiter:\n");
    AtdPrint(Float2, "|");

    // Выделение памяти для Сoncatenation Atd_t
    ConcatAtd = AtdAllocate(GetAtdSizeArray(Float1) + GetAtdSizeArray(Float2), GetAtdElementSize(Float1),
                            GetAtdType(Float1));

    if (AtdConcatenation(Float1, Float2, ConcatAtd) == 0)
        // Если Конкатенация успешно, вывод на экран
    {
        printf("\n\nOutput Elements after Concatenation with Delimiter:\n");
        AtdPrint(ConcatAtd, "|");
    }

    AtdFree(Float2);
    AtdFree(ConcatAtd);

    AtdFree(Float1);


    return (0);
}