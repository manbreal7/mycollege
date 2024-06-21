#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
    struct Term* prev;
};

struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm) {
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = newTerm;
        newTerm->prev = newTerm;
    }
    return newTerm;
}

void insertTerm(struct Term* head, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (newTerm) {
        newTerm->prev = head->prev;
        newTerm->next = head;
        head->prev->next = newTerm;
        head->prev = newTerm;
    }
}

struct Term* multiplyPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = createTerm(0, 0);  

    struct Term* current1 = poly1->next;
    while (current1 != poly1) {
        struct Term* current2 = poly2->next;
        while (current2 != poly2) {
            int coeff = current1->coefficient * current2->coefficient;
            int exp = current1->exponent + current2->exponent;
            insertTerm(result, coeff, exp);
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    return result;
}

void displayPolynomial(struct Term* head) {
    struct Term* current = head->next;
    while (current != head) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != head) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Term* head) {
    struct Term* current = head->next;
    while (current != head) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    struct Term* poly1 = createTerm(0, 0);  
    struct Term* poly2 = createTerm(0, 0);  

    printf("Enter the first polynomial (coefficient exponent), enter 0 0 to end:\n");
    int coeff, exp;
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        insertTerm(poly1, coeff, exp);
    }

    printf("Enter the second polynomial (coefficient exponent), enter 0 0 to end:\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        insertTerm(poly2, coeff, exp);
    }

    struct Term* result = multiplyPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
