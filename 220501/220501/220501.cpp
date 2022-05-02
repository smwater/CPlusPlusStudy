#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//strcpy()
char* strcpy(char* copyStr, const char* originalStr) {
    char* temp = copyStr;

    while (*originalStr != '\0') {
        *temp = *originalStr;
        temp++;
        originalStr++;
    }

    return copyStr;
}

//strcat()
char* strcat(char* pasteStr, const char* originalStr) {
    char* temp = pasteStr;

    while (*temp != '\0') {
        temp++;
    }

    while (*originalStr != '\0') {
        *temp = *originalStr;
        temp++;
        originalStr++;
    }

    return pasteStr;
}

//strlen()
int strlen(const char* lengthStr) {
    int length = 0;

    while (*lengthStr != '\0') {
        lengthStr++;
        length++;
    }

    return length;
}

//strcmp()
int strcmp(const char* compareStr1, const char* compareStr2) {
    while (*compareStr1 != '\0' && *compareStr2 != '\0') {
        if (*compareStr1 != *compareStr2) {
            if (*compareStr1 > *compareStr2) {
                return 1;
            }
            else {
                return -1;
            }
        }

        compareStr1++;
        compareStr2++;
    }

    return 0;
}

//strchr()
char* strchr(const char* originalStr, int key) {
    while (*originalStr != '\0') {
        if (*originalStr == key) {
            return (char*)originalStr;
        }
        originalStr++;
    }

    return NULL;
}

//strrchr()
char* strrchr(const char* originalStr, int key) {
    while (*originalStr != '\0') {
        originalStr++;
    }

    originalStr--;

    while (*originalStr != '\0') {
        if (*originalStr == key) {
            return (char*)originalStr;
        }
        originalStr--;
    }

    return NULL;
}

//strstr() 풀었는데 너무 복잡하다
char* strstr(char* originalStr, const char* keyStr) {
    int count = 0;
    
    while (*originalStr != '\0') {
        if (*originalStr == *keyStr) {
            while (++count && *++originalStr == *++keyStr) {
                if (*++keyStr == '\0') {
                    while (count) {
                        originalStr--;
                        count--;
                    }

                    return originalStr;
                }

                keyStr--;
            }
            
            if (*keyStr == '\0') {
                while (count) {
                    originalStr--;
                    count--;
                }

                return originalStr;
            }
        }

        while (count) {
            keyStr--;
            count--;
        }

        originalStr++;
    }

    return NULL;
}

int main(void) {
    char copyStr1[20] = "";
    char copyStr2[20] = "ABCDE";

    printf("%s\n", strcpy(copyStr1, copyStr2));

    char pasteStr1[20] = "ABCD";
    char pasteStr2[20] = "EFGH";

    printf("%s\n", strcat(pasteStr1, pasteStr2));

    char lengthStr[20] = "12345";

    printf("%d\n", strlen(lengthStr));

    char compareStr1[20] = "1234";
    char compareStr2[20] = "1234";

    printf("%d\n", strcmp(compareStr1, compareStr2));

    char searchStr[20] = "ABCDEFGHIJKLEFNOPE";

    printf("%p\n", strchr(searchStr, 'E'));
    printf("%p\n", strrchr(searchStr, 'E'));

    char searchStr2[20] = "EFN";

    printf("%p\n", strstr(searchStr, searchStr2));
}