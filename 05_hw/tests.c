#include "stack.h"
#include <assert.h>
#include <stdio.h>

void test_createNode() {
    Node* node = createNode(123);

    assert(node != NULL);
    assert(node->data == 123);
    assert(node->next == NULL);

    free(node);
    printf("test_createNode passed.\n");
}

void test_initStack() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);
    printf("test_initStack passed.\n");
}

void test_destroyStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 4);
    push(&stack, 5);

    destroyStack(&stack);

    assert(isEmpty(&stack) == true); 
    printf("test_destroyStack passed.\n");
}

void test_push() {
    Stack stack;
    initStack(&stack);

    push(&stack, 3);
    assert(getTop(&stack)->data == 3);

    push(&stack, -2);
    assert(getTop(&stack)->data == -2);

    destroyStack(&stack);
    printf("test_push passed.\n");
}

void test_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);

    assert(getTop(&stack)->data == 2);
    pop(&stack);
    assert(getTop(&stack)->data == 1);
    pop(&stack);

    assert(isEmpty(&stack) == true);

    destroyStack(&stack);
    printf("test_pop passed.\n");
}

void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 15);
    push(&stack, 2);
    push(&stack, -12);
    push(&stack, 14);
    push(&stack, 12);
    push(&stack, 5);

    Node* result = searchByValue(&stack, 12);
    assert(result != NULL && result->data == 12);

    result = searchByValue(&stack, -12);
    assert(result != NULL && result->data == -12);

    assert(searchByValue(&stack, 33) == NULL);

    destroyStack(&stack);
    printf("test_searchByValue passed.\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    Node* result = searchByIndex(&stack, 0);
    assert(result != NULL && result->data == 5);

    result = searchByIndex(&stack, 2);
    assert(result != NULL && result->data == 3);

    assert(searchByIndex(&stack, 12) == NULL);

    destroyStack(&stack);
    printf("test_searchByIndex passed.\n");
}

void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 11);
    push(&stack, 12);
    push(&stack, 13);

    // Ожидаем, что будет выведено: 30 20 10
    printf("Expected values: Stack elements: 13 12 11\n");
    printf("Actual values: ");

    traverseStack(&stack);

    destroyStack(&stack);
    printf("test_traverseStack passed.\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack) == true);

    push(&stack, 42);
    assert(isEmpty(&stack) == false);

    pop(&stack);
    assert(isEmpty(&stack) == true);
    destroyStack(&stack);
    printf("test_isEmpty passed.\n");
}


void test_getTop() {
    Stack stack;
    initStack(&stack);
    
    push(&stack, 100);
    assert(getTop(&stack)->data == 100);

    push(&stack, 200);
    assert(getTop(&stack)->data == 200);

    destroyStack(&stack);
    printf("test_getTop passed.\n");
}

int main() {
    test_createNode();
    test_initStack();
    test_destroyStack();
    test_push();
    test_pop();
    test_searchByValue();
    test_searchByIndex();
    test_traverseStack();
    test_isEmpty();
    test_getTop();

    printf("All tests passed.\n");

    return 0;
}
