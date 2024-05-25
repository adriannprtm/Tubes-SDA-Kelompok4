// Modified by:
// Krisna Purnama 1B-231524048: "isOperator, inspectExpression"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "../include/tree.h"
#include "../include/StackDinamis.h"
#include "../include/calculator.h"
//#include "./gotoxy.c"
#define MAX 0x3f3f3f3f

bool isTrigFunction(const char *str) {
    return (strncmp(str, "sin(", 4) == 0 ||
            strncmp(str, "cos(", 4) == 0 ||
            strncmp(str, "tan(", 4) == 0);
}

double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

bool isOperasi(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '!';
}

double round_double(double number, int decimal_places) {
    double multiplier = pow(10.0, decimal_places);
    double rounded_number = roundf(number * multiplier) / multiplier;
    return rounded_number;
}

bool isOperator(struct calcTree *node) {
    return (node->isi_data.mathOperator[0] != '\0');
}

double factorial(double n) {
    if (n < 0) {
        return -1; // Factorial untuk angka negatif tidak terdefinisi
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    double result = 1;
    for (int i = 2; i <= (int) n; i++) {
        result *= i;
    }
    return result;
}

double count(struct calcTree *root) {
    if (isOperator(root)) {
        switch (root->isi_data.mathOperator[0]) {
            case '+': {
                return count(root->lChild) + count(root->rChild);
            }
            case '-': {
                return count(root->lChild) - count(root->rChild);
            }
            case '/': {
                return count(root->lChild) / count(root->rChild);
            }
            case '*': {
                return count(root->lChild) * count(root->rChild);
            }
            case '^': {
                return pow(count(root->lChild), count(root->rChild));
            }
            case '!': {
                double operand = count(root->lChild);
                if (operand < 0 || operand != (int) operand) {
                    return -1; // Faktor untuk angka negatif atau non-integer tidak terdefinisi
                }
                return factorial(operand);
            }
            default: {
                // Handle trigonometric functions
                if (strncmp(root->isi_data.mathOperator, "sin", 3) == 0) {
                    return sin(toRadians(count(root->lChild)));
                } else if (strncmp(root->isi_data.mathOperator, "cos", 3) == 0) {
                    return cos(toRadians(count(root->lChild)));
                } else if (strncmp(root->isi_data.mathOperator, "tan", 3) == 0) {
                    return tan(toRadians(count(root->lChild)));
                }
                return 0;
            }
        }
    }
    return root->isi_data.angka;
}

double inspectExpression(char mathExpression[], int firstIndex, int lastIndex) {
    char numStr[100];
    int len = lastIndex - firstIndex + 1;
    strncpy(numStr, mathExpression + firstIndex, len);
    numStr[len] = '\0';
    char *endptr;
    double num = strtod(numStr, &endptr);
    if (*endptr == '\0') {
        return num;
    }
    return MAX;
}

void infixToPostfix(struct calcTree *root) {
    if (root) {
        infixToPostfix(root->lChild);
        infixToPostfix(root->rChild);
        if (!isOperator(root)) {
            printf("\033[0;37m%f ", root->isi_data.angka);
        } else {
            if (strlen(root->isi_data.mathOperator) > 1) {
                // Fungsi trigonometri
                printf("\033[0;37m%s ", root->isi_data.mathOperator);
            } else {
                // Operator biasa
                printf("\033[0;37m%c ", root->isi_data.mathOperator[0]);
            }
        }
    }
}

void infixToPrefix(struct calcTree *root) {
    if (root) {
        if (!isOperator(root)) {
            printf("\033[0;37m%f ", root->isi_data.angka);
        } else {
            if (strlen(root->isi_data.mathOperator) > 1) {
                // Fungsi trigonometri
                printf("\033[0;37m%s ", root->isi_data.mathOperator);
            } else {
                // Operator biasa
                printf("\033[0;37m%c ", root->isi_data.mathOperator[0]);
            }
        }
        infixToPrefix(root->lChild);
        infixToPrefix(root->rChild);
    }
}

bool isValid(char input[]) {
    if (!(input[0] == '-' || isdigit(input[0]) || input[0] == '(' || isTrigFunction(input))) {
        printf("ERROR: Invalid start of expression [%c%c]\n", input[0], input[1]);
        return false;
    }

    input[strlen(input)] = '\0';

    if (checkBracket(input)) {
        for (int i = 0; i < strlen(input); i++) {
            if (isdigit(input[i]) || isOperasi(input[i]) || input[i] == '(' || input[i] == ')' || input[i] == '.' ||
                isTrigFunction(&input[i])) {
                if (isTrigFunction(&input[i])) {
                    i += 2; // Skip the next 2 characters as we've already checked a trig function
                }
                if (input[i] == '(' && !((isOperasi(input[i - 1]) || input[i - 1] == '(' ||
                                          isTrigFunction(&input[i - 3])) && (
                                             isdigit(input[i + 1]) || input[i + 1] == '(' || input[i + 1] == '-'))) {
                    printf("ERROR: Invalid character before '('. [%c%c%c]\n", input[i - 1], input[i], input[i + 1]);
                    return false;
                } else if (input[i] == ')' && !((isdigit(input[i - 1]) || input[i - 1] == ')') && (
                                                    isOperasi(input[i + 1]) || input[i + 1] == ')' || input[i + 1] ==
                                                    '\0'))) {
                    printf("ERROR: Invalid character after ')'. [%c%c%c]\n", input[i - 1], input[i], input[i + 1]);
                    return false;
                }
                if ((isOperasi(input[i]) && isOperasi(input[i + 1]) && isOperasi(input[i + 2])) || (
                        isOperasi(input[i]) && isOperasi(input[i + 1] && input[i + 1] != '-'))) {
                    printf("ERROR: Consecutive operators. [%c%c%c]\n", input[i - 1], input[i], input[i + 1]);
                    return false;
                }
                if (input[i] == '/' && input[i + 1] == '0') {
                    int j = i + 1;
                    while (j < strlen(input)) {
                        if (input[j] != '0' && isdigit(input[j])) {
                            break;
                        } else if (isOperasi(input[j]) || j == strlen(input) - 1) {
                            printf("ERROR: Division by zero. [%c%c%c]\n", input[i - 1], input[i], input[i + 1]);
                            return false;
                        }
                        j++;
                    }
                }
            } else {
                printf("ERROR: Invalid character. [%c%c]\n", input[i], input[i + 1]);
                return false;
            }
        }
    } else {
        printf("ERROR: Unmatched brackets. [%c%c]\n", input[0], input[1]);
        return false;
    }

    return true;
}

struct calcTree *createTree(char mathExpression[], int firstIndex, int lastIndex) {
    if (firstIndex > lastIndex) {
        return NULL;
    }

    struct calcTree *root = (struct calcTree *) malloc(sizeof(struct calcTree));
    if (!root) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    int posPlusOrSub = -1; // Posisi dari operator penjumlahan (+) dan pengurangan (-)
    int posDivOrMul = -1; // Posisi dari operator perkalian (*) dan pembagian (/)
    int posExp = -1; // Posisi dari operator pangkat (^)
    int posFact = -1; // Posisi dari operator faktorial (!)
    int posTrig = -1; // Posisi dari operator trigonometri
    double num;

    num = inspectExpression(mathExpression, firstIndex, lastIndex);

    if (num != MAX) {
        root->isi_data.mathOperator[0] = '\0';
        root->isi_data.angka = num;
        root->lChild = NULL;
        root->rChild = NULL;
        return root;
    }

    int in_brackets = 0;
    for (int k = firstIndex; k <= lastIndex; k++) {
        if (mathExpression[k] == '(') {
            in_brackets++;
        } else if (mathExpression[k] == ')') {
            in_brackets--;
        }

        if (!in_brackets) {
            if (mathExpression[k] == '+' || mathExpression[k] == '-') {
                posPlusOrSub = k;
            } else if (mathExpression[k] == '*' || mathExpression[k] == '/') {
                posDivOrMul = k;
            } else if (mathExpression[k] == '^') {
                posExp = k;
            } else if (mathExpression[k] == '!') {
                posFact = k;
            } else if (strncmp(&mathExpression[k], "sin", 3) == 0 || strncmp(&mathExpression[k], "cos", 3) == 0 ||
                       strncmp(&mathExpression[k], "tan", 3) == 0) {
                posTrig = k;
            }
        }
    }

    if (posPlusOrSub != -1) {
        root->isi_data.mathOperator[0] = mathExpression[posPlusOrSub];
        root->isi_data.mathOperator[1] = '\0';
        root->lChild = createTree(mathExpression, firstIndex, posPlusOrSub - 1);
        root->rChild = createTree(mathExpression, posPlusOrSub + 1, lastIndex);
        return root;
    } else if (posDivOrMul != -1) {
        root->isi_data.mathOperator[0] = mathExpression[posDivOrMul];
        root->isi_data.mathOperator[1] = '\0';
        root->lChild = createTree(mathExpression, firstIndex, posDivOrMul - 1);
        root->rChild = createTree(mathExpression, posDivOrMul + 1, lastIndex);
        return root;
    } else if (posExp != -1) {
        root->isi_data.mathOperator[0] = mathExpression[posExp];
        root->isi_data.mathOperator[1] = '\0';
        root->lChild = createTree(mathExpression, firstIndex, posExp - 1);
        root->rChild = createTree(mathExpression, posExp + 1, lastIndex);
        return root;
    } else if (posFact != -1) {
        root->isi_data.mathOperator[0] = mathExpression[posFact];
        root->isi_data.mathOperator[1] = '\0';
        root->lChild = createTree(mathExpression, firstIndex, posFact - 1);
        root->rChild = NULL;
        return root;
    } else if (posTrig != -1) {
        strncpy(root->isi_data.mathOperator, &mathExpression[posTrig], 3);
        root->isi_data.mathOperator[3] = '\0';
        root->lChild = createTree(mathExpression, posTrig + 4, lastIndex - 1); // Move inside the parentheses
        root->rChild = NULL;
        return root;
    } else {
        return createTree(mathExpression, firstIndex + 1, lastIndex - 1);
    }
}
