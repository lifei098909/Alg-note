#include "common.h"

/* ��С�������� */
int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

/* �Ӵ�С���� */
int comb(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}