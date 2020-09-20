/*
note: This try to understand struct and pointer of struct once again!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct pt
{
    int x;
    int y;
}point_t;

typedef struct image
{
    int         h;
    int         w;
    point_t     pArray[2];
    point_t     pArray1;
    point_t*    pPointers[2];
    point_t*    pPointers1;
}img_t;

int main()
{
    int pos_x = 0;
    int pos_y = 0;
    int h = 10;
    int w = 10;
    printf("Pls input position and width, height !\n");
    scanf("%d%d%d%d", &pos_x, &pos_y, &h, &w);
    printf("The relation info, pos_x:%d, pos_y:%d, h:%d, w:%d ~~~\n", pos_x, pos_y, h, w);
    printf("This laptop, size of 'int' is : %d ~~~\n", sizeof(int));
    
    int* int_pointer = (int*)malloc(sizeof(int));
    printf("Size of int pointer: %d ~~~~\n", sizeof(int_pointer));

    point_t* p = (point_t*)malloc(sizeof(point_t));
    printf("The size of p is : %d ~~\n", sizeof(p));
    printf("The size of point_t is: %d ~~~\n", sizeof(point_t));

    img_t* imgT = (img_t*)malloc(sizeof(img_t));
    memset(imgT, 0, sizeof(img_t));
    printf("The size of 'img_t' is : %d ~~~\n", (int)sizeof(img_t));
    printf("The size of 'imgT' is %d ~~~\n", sizeof(imgT));
    printf("The sizeof pPointers is: %d~~~\n", sizeof(imgT->pPointers1));
    
    imgT->pPointers[0] = (point_t*)malloc(sizeof(point_t) * 3);
    imgT->pPointers[1] = (point_t*)malloc(sizeof(point_t) * 2);
    imgT->pPointers1 = (point_t*)malloc(sizeof(point_t));

    //set value
        
    imgT->h = h;
    imgT->w = w;
    imgT->pArray1.x = pos_x;
    imgT->pArray1.y = pos_y;
    imgT->pArray[0].x = pos_x + 1;
    imgT->pArray[0].y = pos_y + 1;
    imgT->pPointers1->x = pos_x + 2;
    imgT->pPointers1->y = pos_y + 2;
    imgT->pPointers[0]->x = pos_x + 3;
    imgT->pPointers[0]->y = pos_y + 3;

   
    
    printf("The begining add of 'imgT' is : %p ~~~\n", &imgT);
    printf("The addr of pPointers1: %p ~~~ \n", imgT->pPointers1);
    printf("The addr of pPointers[0]: %p ~~~ \n", imgT->pPointers[0]);
    printf("The addr of pPointers[1]: %p ~~~ \n", imgT->pPointers[1]);
    printf("The addr of pArray1: %p ~~~ \n", &(imgT->pArray1));
    printf("The addr of pArray[0]: %p ~~~ \n", &(imgT->pArray[0]));
    printf("The addr of pArray[1]: %p ~~~ \n", &(imgT->pArray[1]));

    return 0;
}
/*
在结构体imgT中，整个结构体大小为56(4+4+2*8+8+2*8+8), 64为系统中指针大小为8；
&imgT->pArray1表示结构体imgT中 pArray1的地址，其值为imgT起始地址偏移8+2*8的大小；
imgT->pPointers1表示的是pPointers1的起始位置，与imgT起始位置没有实际联系，&imgT->pPointers1则是pPointers1的存储位置，是相对于imgT的起始位置偏移；
imgT->pPointers[0]与imgT->pPointers[1] 均和imgT->pPointers1类似；
*/

/*
下一步以此目录为起点构建cmake工程
*/