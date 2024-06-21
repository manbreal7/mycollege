#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm) {
        newTerm->coefficient = coefficient;
        newTerm->exponent = exponent;
        newTerm->next = NULL;
    }
    return newTerm;
}

struct Term* insertTerm(struct Term* head, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (head == NULL) {
        return newTerm;
    }
    struct Term* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTerm;
    return head;
}

struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            result = insertTerm(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            result = insertTerm(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                result = insertTerm(result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        result = insertTerm(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        result = insertTerm(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

void displayPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    printf("Enter the first polynomial (coefficient exponent), enter 0 0 to end:\n");
    int coeff, exp;
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        poly1 = insertTerm(poly1, coeff, exp);
    }

    printf("Enter the second polynomial (coefficient exponent), enter 0 0 to end:\n");
    while (1) {
        scanf("%d %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) {
            break;
        }
        poly2 = insertTerm(poly2, coeff, exp);
    }

    struct Term* sum = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    displayPolynomial(sum);

    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);

    return 0;
}
