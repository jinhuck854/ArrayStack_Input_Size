#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ArrayStack { // Array Stack Struct
	int top;      // Stack top
	int capacity; // Max Size
	int* array;
}ArrayStack;

ArrayStack* createStack(void) { // Stack 동적 할당 초기화
	ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (!S) {
		return NULL;
	}
	else {
		S->top = -1; // top : -1
		printf("Stack의 Size를 입력하세요 : "); scanf("%d", &S->capacity); // Max Size 입력

		S->array = malloc(S->capacity * sizeof(int)); // capacity만큼 배열 생성
		if (!S->array) { // S 안 만들어졌을 때
			return NULL;
		}
	}
	return S;
}

void push(ArrayStack* S, element value) { // PUSH
	if (is_full(S)) { // is full
		fprintf(stderr, "스택 포화 에러\n");
		return 0;
	}
	else { // ! is full
		S->top += 1;
		S->top = value;
		printf("PUSH : %d\n", S->top); // PUSH된 값을 출력
	}
}

element pop(ArrayStack*S) { // POP
	if (is_empty(S)) { // is empty
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else { // ! is empty
		printf("POP : %d\n", S->top);
		return (S->array[S->top--]);
	}
}

element peek(ArrayStack*S) { // PEEK
	if (is_empty(S)) { // is empty
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else // ! is empty
		return S->top;
}

int is_full(ArrayStack* S) { // is full
	return (S->top >= (S->capacity - 1)); // full => return 1
}

int is_empty(ArrayStack* S) { // is empty
	return (S->top == -1); // empty => return 1
}

void start() {
	ArrayStack* mys = createStack();

	printf("\n=====PUSH=====\n");
	for (int i = 0; i < mys->capacity; i++) { // PUSH : capacity 만큼 반복
		push(mys, i);
	}

	printf("\n=====PEEK=====\n");
	printf("PEEK : %d\n", peek(mys)); // PEEK

	printf("\n======POP=====\n");
	for (int i = 0; i < mys->capacity; i++) { // POP : capacity 만큼 반복
		pop(mys);
	}
}

int main(void) {
	start();
	return 0;
}