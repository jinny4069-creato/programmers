#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long total = 0;
    for (int i = 1; i <= count; i++)
    {
        total += price * i;
    }

    long long gap = total - money;
    
    if (gap < 0)
        return 0;

    return  gap;
}