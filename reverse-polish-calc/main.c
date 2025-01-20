#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EXPRESSION_MAX_LEN 1024

int main() {
    char expression[EXPRESSION_MAX_LEN];
    int stack[64];
    int sp = -1;
    int idx = 0, len = 0;
    char* end_ptr;

    while (1) {
        printf("Expression: ");
        if (fgets(expression, EXPRESSION_MAX_LEN, stdin) == NULL)
            break;

        if (expression[0] == 'e' && expression[1] == 'x' && expression[2] == 'i' && expression[3] == 't') {
            break;
        }

        len = strlen(expression);

        while (idx < len) {
            while (isspace(expression[idx])) {
                idx++;
                continue;
            }

            if (idx >= len)
                break;

            if (isdigit(expression[idx])) {
                stack[++sp] = strtol(expression + idx, &end_ptr, 10);
                idx = end_ptr - expression;
                continue;
            }

            switch (expression[idx]) {
                case '+': {
                    stack[sp - 1] = stack[sp - 1] + stack[sp];
                    break;
                }
                case '-': {
                    stack[sp - 1] = stack[sp - 1] - stack[sp];
                    break;
                }
                case '*': {
                    stack[sp - 1] = stack[sp - 1] * stack[sp];
                    break;
                }
                case '/': {
                    stack[sp - 1] = stack[sp - 1] / stack[sp];
                    break;
                }
                default: {
                    printf("Unsupported op: %c\n", expression[idx]);
                    break;
                }
            }

            sp--;
            idx++;
        }

        printf("Result is %d\n", stack[sp]);
        sp = -1;
        idx = 0;
    }
}