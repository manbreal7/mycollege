#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeConsecutiveSame(char** v, int n) {
    for (int i = 0; i < n - 1;) {
        if (strcmp(v[i], v[i + 1]) == 0) {
            free(v[i]);
            free(v[i + 1]);
            for (int j = i; j < n - 2; j++) {
                v[j] = v[j + 2];
            }
            n = n - 2;
        } else {
            i++;
        }
    }
    return n;
}

int main() {
    char* v[] = {"tom", "jerry", "jerry", "tom"};
    int n = sizeof(v) / sizeof(v[0]);
    printf("%d", removeConsecutiveSame(v, n));
    return 0;
}