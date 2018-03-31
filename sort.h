#pragma once
#include<stdio.h>
#include<stdlib.h>

#define LeftChild(i) (2 * ( i ) +1)
#define cutOff 3

void Merge(int *A, int *tmpArray, int Lpos, int Rpos, int RightEnd);
void MSort(int *A, int *tmpArray, int Left, int Right);
int median3(int *A, int Left, int Right);
void swap(int *a, int *b);
void insertSort(int *A, int N);
void shellSort(int *A, int N);
void percDown(int *A, int i, int N);
void heapSort(int *A, int N);
void MergeSort(int *A, int N);
void quickSort(int *A, int Left, int Right);