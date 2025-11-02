#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;
int intStack[MAX];
int intTop = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

void pushInt(int val) {
    if (intTop == MAX - 1)
        printf("Stack Overflow\n");
    else
        intStack[++intTop] = val;
}

int popInt() {
    if (intTop == -1)
        return -1;
    else
        return intStack[intTop--];
}

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol, temp;
    top = -1;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while ((temp = pop()) != '(')
                postfix[j++] = temp;
        } else { 
            while (top != -1 && precedence(peek()) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int i, op1, op2, result;
    char symbol;
    intTop = -1;

    for (i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            pushInt(symbol - '0'); 
        } else {
            op2 = popInt();
            op1 = popInt();
            switch (symbol) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }
            pushInt(result);
        }
    }
    return popInt();
}
int checkBalancedBrackets(char expr[]) {
    top = -1;
    char symbol;

    for (int i = 0; i < strlen(expr); i++) {
        symbol = expr[i];
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (top == -1)
                return 0;

            char temp = pop();
            if ((symbol == ')' && temp != '(') ||
                (symbol == '}' && temp != '{') ||
                (symbol == ']' && temp != '['))
                return 0;
        }
    }
    return (top == -1);
}

int main() {
    int choice;
    char infix[MAX], postfix[MAX], expr[MAX];

    while (1) {
        printf("\n--- STACK APPLICATIONS (NOTATIONS) ---\n");
        printf("1. Infix to Postfix Conversion\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Check Balanced Brackets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter a postfix expression (digits only): ");
                scanf("%s", postfix);
                printf("Result = %d\n", evaluatePostfix(postfix));
                break;

            case 3:
                printf("Enter an expression with brackets: ");
                scanf("%s", expr);
                if (checkBalancedBrackets(expr))
                    printf("Brackets are balanced.\n");
                else
                    printf("Brackets are NOT balanced.\n");
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

