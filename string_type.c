#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*leetcode 3 start*/
/*
* leetcode 3.无重复字符的最长子串
* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
*/
int lengthOfLongestSubstring(char * s){
    int len = strlen(s);
    int cnt = 0;
    int p = 0;

    if (s == NULL)
        return 0;
    for (int i = 0; i < len; i++) {
        for (int j = p; j < i; j++) {
            if (s[j] == s[i]) {
               //. cnt = max(cnt, i - p);
                p = j + 1;
            }
        }
        cnt = max(cnt, i - p + 1);
    }
    return cnt;
}

void test_lengthOfLongestSubstring(void) {
    int len;
    char s[][1000] = {
        "abcabcbb",
        "pwwkew",
        ""
    };

    for (int i = 0; i < ARRAY_SIZE(s); i++) {
        len = lengthOfLongestSubstring(s[i]);
        printf("len = %d\n", len);
    }

    return;
}
/*leetcode 3 end*/


/*leetcode 5 start*/
/*
* leetcode 5.最长回文子串
* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/
char * longestPalindrome(char * s){
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int start = 0;
    int k = 0;
    int len = strlen(s);
    char *returnstr = (char *)malloc(sizeof(char) * len);

    while (s[k]) {
        right = k;
        left = k - 1;

        while (s[right] == s[k])
            right++;
        k = right;

        while (left >= 0 && s[left] == s[right]) {
            left--;
            right++;
        }
        if (right - left - 1 > maxlen) {
            start = left + 1;
            maxlen = right - left - 1;
        }
    }
    returnstr[maxlen] = '\0';
    for (int i = 0; i < maxlen; i++)
        returnstr[i] = s[start + i];

    return returnstr;
}

void test_longestPalindrome(void) {
    char *returnstr;
    char s1[] = "abcabcbb";
    char s2[][1000] = {
        "babad",
        "cbbd",
        "acbca"
    };
    for (int i = 0; i < ARRAY_SIZE(s2); i++) {
        returnstr = longestPalindrome(s2[i]);
        printf("the returnstr is %s\n", returnstr);
    }
}
/* leetcode 5 end */

/* leetcode 10 start */
/* leetcode 10. 正则表达式匹配
* 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
* '.' 匹配任意单个字符
* '*' 匹配零个或多个前面的那一个元素
* 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
*/
bool isMatch(char * s, char * p)
{
    int lens = strlen(s);
    int lenp = strlen(p);
    bool dp[lens + 1][lenp + 1];
    memset(dp, false, sizeof(bool) * (lens + 1) * (lenp + 1));
    dp[lens][lenp] = true;

    for (int i = lens; i >= 0; --i) {
        for (int j = lenp - 1; j >= 0; --j) {
            bool curdp = (s[i] == p[j] || p[j] == '.');
            if (p[j + 1] == '*') {
                if (i == lens)
                    dp[i][j] = dp[i][j + 2];
                else
                    dp[i][j] = dp[i][j + 2] || (dp[i + 1][j] && curdp);
            }
            else {
                if (i == lens)
                    dp[i][j] = false;
                else
                    dp[i][j] = curdp && dp[i + 1][j + 1];
            }
        }
    }
    return dp[0][0];
}

void test_isMatch(void)
{
    bool res;
    char s_str[][1000] = {
        "aa",
        "aa",
        "ab",
        "aab",
        "mississippi"
    };
    char p_str[][1000] = {
        "a",
        "a*",
        ".*",
        "c*a*b",
        "mis*is*p*."
    };

    for (int i = 0; i < ARRAY_SIZE(s_str); i++) {
        res = isMatch(s_str[i], p_str[i]);
        if (res)
            printf("%d, %s isMatch %s is true \n", i, p_str[i], s_str[i]);
        else
            printf("%d, %s isMatch %s is false \n", i, p_str[i], s_str[i]);
    }
}
/*leetcode 10 end*/

