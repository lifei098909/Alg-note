#ifndef __COMMON_H
#define __COMMON_H

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int comp(const void *a, const void *b);

#endif