#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));//�ϳ��� ��尡 �� �� �ִ� ���� �Ҵ�
	node->data = data; //node�� �����ʹ� �ְ��� �ϴ� �����͸� ����ְ�
	node->next = stack->top;//node�� next�� ������ top�� �� �� ����
	stack->top = node;//stack�� top�� ����node�� �ٲ���. �������� ���� �ֻ�� node�� top 
}
void pop(Stack *stack) {//Ư���� stack�� �Ű������� ����
	if (stack->top == NULL) {//���� stack�� ����ִٸ� 
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;//������ return���־�� �߻� �˷���
	}
	Node *node = stack->top; //������ node�� �ֻ�� node�� ��Ƴ��Ҵٰ�
	int data = node->data; //data�� ������ ����
	stack->top = node->next;//���� stack�� top�� node�� next(�ι�° node)�� �� �� �ֵ���
	free(node);//������ node�� �Ҵ�����
	return data;
}
void show(Stack *stack) {//���
	Node *cur = stack->top;
	printf("--������ �ֻ��--\n");
	while (cur != NULL) {
		printf("%d\n", cur->data); //top���� ���� ���
		cur = cur->next;
	}
	printf("--������ ���ϴ�--\n");
}
int main() {
	Stack s;
	s.top = NULL;//�ݵ�� NULL���� �־�� ����÷ο쳪 show�Լ����� üũ ����
	//stack�� �� �ֱ�
	push(&s, 7);//���ÿ� �޸� �ּҸ� ������ �ϱ� ������ &�� ����
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	system("pause");
	return 0;
}