#ifndef __COMMON_H
#define __COMMON_H

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int comp(const void *a, const void *b);
int comb(const void *a, const void *b);
int cmp_twodimension(const void *a, const void *b);
#endif