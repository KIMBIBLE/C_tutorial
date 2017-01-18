#pragma once

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

void genericSort(void *, int, size_t, int (*)(void *, void *));
int integerCompare(void *, void *);
int doubleCompare(void *, void *);
int stringCompare(void *, void *);

void display(void *, int, size_t, void(*)(void *));
void integerPrint(void *);
void doublePrint(void *);
void stringPrint(void *);

