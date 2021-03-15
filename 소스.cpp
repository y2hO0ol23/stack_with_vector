#include "myvector.h"

#include <string.h>
#pragma warning(disable: 4996) 

struct stack {
	struct vector* vec;
};

struct stack* stack_create();
void stack_destructor(struct stack* st);

void stack_push(struct stack* st, int value);
void stack_pop(struct stack* st);
int stack_top(struct stack* st);
int stack_size(struct stack* st);
int stack_empty(struct stack* st);

char n[100000];

int main() {
	struct stack* mystack = stack_create();
	scanf("%s", &n);
	int flag;
	int m=0;
	for (int i = 0; i < strlen(n); i++) {
		if (n[i] == '(') {
			flag = 0;
			stack_push(mystack, 1);
		}
		if (n[i] == ')') {
			if (flag == 0) {
				flag = 1;
				stack_pop(mystack);
				m += stack_size(mystack);
			}
			else {
				m++;
				stack_pop(mystack);
			}
		}
	}
	printf("%d", m);
}

struct stack* stack_create() {
	struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));
	new_stack->vec = vector_create();

	return new_stack;
}

void stack_destructor(struct stack* st) {
	vector_destructor(st->vec);
	free(st);
}

void stack_push(struct stack* st, int value) {
	vector_push_back(st->vec, value);
}

void stack_pop(struct stack* st) {
	vector_pop_back(st->vec);
}

int stack_top(struct stack* st) {
	return *vector_back(st->vec);
}

int stack_size(struct stack* st) {
	return vector_size(st->vec);
}

int stack_empty(struct stack* st) {
	return vector_empty(st->vec);

}