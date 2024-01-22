#include "../header/register.h"

#include <stdio.h>

int main(){
    printf("AX = %d\n",AX);
    registerArr[0]= 1;
    printf("after put 1 in AX = %d\n",AX);
    printf("value AX after we put 1 = %d\n",registerArr[1]);
    registerArr[1]= 2;
    printf("value BX = %d\n",registerArr[1]);
    printf("BX = %d\n",BX);
    int z = registerArr[0] + registerArr[1];
    printf("sum of value of AX and BX =%d\n",z);
    printf("AX = %d, BX = %d, CX = %d, DX = %d\n",AX, BX, CX, DX);
    return 0;
}
