#include <stdio.h>

typedef struct {
    int r, c, v;
} spm;

spm a[10];
spm t[10];
int k = 0;

void read() {
    int m, n, ele;

    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    printf("Enter elements:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ele);
            if (ele != 0) {
                k++;
                a[k].r = i;
                a[k].c = j;
                a[k].v = ele;
            }
        }
    }

    a[0].r = m;
    a[0].c = n;
    a[0].v = k;
}

void display(spm a[]) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= k; i++) {
        printf("%d\t%d\t%d\n", a[i].r, a[i].c, a[i].v);
    }
}

void transpose(spm a[], spm t[]) {
    k = 0;
    t[0].v = a[0].v;
    t[0].c = a[0].r;
    t[0].r = a[0].c;
    for (int i = 0; i < a[0].c; i++) {
        for (int j = 1; j <= a[0].v; j++) {
            if (a[j].c == i) {
                k++;
                t[k].r = a[j].c;
                t[k].c = a[j].r;
                t[k].v = a[j].v;
            }
        }
    }
}

int main() {
    read();
    printf("Original Matrix:\n");
    display(a);

    transpose(a, t);
    printf("Transposed Matrix:\n");
    display(t);

    return 0;
}