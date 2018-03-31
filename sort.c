#include "sort.h"

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertSort(int *A, int N)
{
	int tmp;
	for (int i = 1; i < N; i++)
	{
		tmp = A[i];
		for (int j = i; j > 0 && A[j - 1] > tmp; j--)
		{
			A[j] = A[j - 1];
			A[j -1] = tmp;
		}
	}
}

void shellSort(int *A, int N)
{
	int tmp;
	for (int Increment = N / 2; Increment > 0; Increment /= 2)
	{
		for (int i = Increment; i < N; i++)
		{
			tmp = A[i];
			for (int j = i; j >= Increment; j -= Increment)
			{
				if (A[j - Increment] > tmp) {
					A[j] = A[j - Increment];
					A[j - Increment] = tmp;
				}
				else {
					break;
				}
			}
		}
	}
}

/*cannot understand heapSort*/
//sort with a heap
void percDown(int *A, int i, int N) 
{
	int child;
	int tmp;
	for (tmp = A[i]; LeftChild(i) < N; i = child)
	{
		child = LeftChild(i);
		if (child != N - 1 && A[child + 1] > A[child])
			child++;
		if (tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = tmp;
}

void heapSort(int *A, int N)
{
	for (int i = N / 2; i >= 0; i--)
		percDown(A, i, N);
	for (int i = N - 1; i > 0; i--)
	{
		swap(&A[0], &A[i]);
		percDown(A, 0, i);
	}
}

void MSort(int *A, int *tmpArray, int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, tmpArray, Left, Center);
		MSort(A, tmpArray, Center + 1, Right);
		Merge(A, tmpArray, Left, Center + 1, Right);
	}
}

void MergeSort(int *A, int N)
{
	int *tmpArray;
	tmpArray = malloc(N * sizeof(int));
	if (tmpArray != NULL)
	{
		MSort(A, tmpArray, 0, N - 1);
		free(tmpArray);
	}
	else
		printf("No space for tmp array!");
}

void Merge(int *A, int *tmpArray, int Lpos, int Rpos, int RightEnd)
{
	//int i, LeftEnd, numElements, tmpPos;
	int LeftEnd = Rpos - 1;
	int tmpPos = Lpos;
	int numElements = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			tmpArray[tmpPos++] = A[Lpos++];
		else
			tmpArray[tmpPos++] = A[Rpos++];
	while (Lpos <= LeftEnd)
		tmpArray[tmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		tmpArray[tmpPos++] = A[Rpos++];
	for (int i = 0; i < numElements; i++, RightEnd--)
		A[RightEnd] = tmpArray[RightEnd];
}

/*quickSort 分割策略 快排*/
//三中值分割策略
int median3(int *A, int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		swap(&A[Center], &A[Right]);

	swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}

void quickSort(int *A, int Left, int Right)
{
	int pivot;
	if (Left + cutOff <= Right)
	{
		pivot = median3(A, Left, Right);
		int i = Left;
		int j = Right - 1;
		for (; ; )
		{
			while (A[++i] < pivot){}
			while (A[--j] > pivot){}
			if (i < j)
				swap(&A[i], &A[j]);
			else
				break;
		}
		swap(&A[i], &A[Right - 1]);
		quickSort(A, Left, i - 1);
		quickSort(A, i + 1, Right);
	}
	else {
		insertSort(A + Left, Right - Left + 1);
	}
}

int main()
{
	/*test insertSort*/
	/*int n = 6;
	int data[] = { 8, 34, 64, 51, 32, 21 };
	insertSort(data, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", data[i]);
	}*/

	/*test shellSort*/
	/*int data1[] = { 81, 94, 11, 96, 12, 35, 17, 95, 28, 58, 41, 75, 15 };
	int N = sizeof(data1) / sizeof(int);
	shellSort(data1, N);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", data1[i]);
	}*/

	/*test MergeSort*/
	/*int dataM[] = { 24, 13, 26, 1, 2, 27, 38, 15 };
	int N = sizeof(dataM) / sizeof(int);
	MergeSort(dataM, N);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", dataM[i]);
	}*/

	/*test swap ->_->*/
	/*int a = 1;
	int b = 2;
	swap(&a, &b);
	printf("a=%d\nb=%d\n", a, b);*/

	/*test quickSort*/
	int dataQ[] = { 8, 1, 4, 9, 0, 3, 5, 2, 7, 6 };
	int N = sizeof(dataQ) / sizeof(int);
	quickSort(dataQ, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d\n", dataQ[i]);
	}
	getchar();
	return 0;
}
