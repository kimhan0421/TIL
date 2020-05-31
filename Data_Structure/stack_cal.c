#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct Node {
	char data[100]; // ���� Ȥ�� ���ڿ��� �پ��ѵ�, ������ ��� ���̰� ��� �־� ���ڿ��� ó��
	struct Node *next;//���� node�� �� �� �ֵ���
}Node;

typedef struct Stack {
	Node *top;
}Stack;

void push(Stack *stack, char *data) { //������ stack�� ������. 									 
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data); //�� node���� �����͸� �����ϰ� �־�, �Ű������� �Ѿ�� ���ڿ� �����͸� ��� �ȿ� ���� �� �ֵ���
	node->next = stack->top;//���� stack�� top�� �ش� node�� ������ ����Ű����
	stack->top = node; //stack�� top�� �ش� node�� �ٲ�
}

char* getTop(Stack *stack) {//stack�� ��� node�� top�� ��ȯ
	Node *top = stack->top;
	return top->data;
}

char* pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node *node = stack->top;
	char *data = (char*)malloc(sizeof(char) * 100);
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return data;
}
//���� ǥ������� ��ȯ - �켱���� �Լ� �����
int getPriority(char *i) {
	if (!strcmp(i, "(")) return 0;//�켱���� ����
	if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
	if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
	return 3;
}

//���� ǥ��� ���
//������ ������ ���ڿ� s, ���ڿ��� ���� size //�� ���ڿ��� �˻�
char* transition(Stack *stack, char **s, int size) {
	char res[1000] = "";
	for (int i = 0; i < size; i++) {//�� ���ڿ��� �ϳ��� ���캸�鼭
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")) {//�ش繮�ڿ��� �������̸�
			while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])) {//�ڽź��� ���� �����ڴ�
				strcat(res, pop(stack)); strcat(res, " ");//stack���� ���� ��
				//res�� ����ǥ������� �ٲ� ������� ��� �� ���� ����� ����
			}
			push(stack, s[i]);//�ڽ��� stack�� �ִ´�
			
		}
		else if (!strcmp(s[i], "(")) push(stack, s[i]);//���°�ȣ �� ��� �ٷ� ���ÿ� �ֱ�
		else if (!strcmp(s[i], ")")) {//�ݴ� ��ȣ �� ���
			while (strcmp(getTop(stack), "(")) {//���� ��ȣ�� ���ö�����
				strcat(res, pop(stack)); strcat(res, " ");//stack���� �̾Ƽ� ����� ��´�.
			}
			pop(stack);//���� ��ȣ ���� ���� �� �ְ� ��.
		}
		else strcat(res, s[i]);	strcat(res, " ");//�Ϲ� ������ ���
	}
	while (stack->top != NULL) {//���� stack�� ���� �ִ� ���Ұ� ���� ��� �� ������
		strcat(res, pop(stack)); strcat(res, " ");
	}
	return res;//����ǥ��� �̾Ƴ�
}


void calculate(Stack *stack, char **s, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || strcmp(s[i], "/")) {//�����ڶ��
			//���ÿ��� 2���� �̾Ƽ�
			x = atoi(pop(stack)); 
			y = atoi(pop(stack));
			//�װ��� ���
			//y�� ���� ���� ������ x���� ���� ������

			if (!strcmp(s[i], "+")) z = y + x;
			if (!strcmp(s[i], "-")) z = y - x;
			if (!strcmp(s[i], "*")) z = y * x;
			if (!strcmp(s[i], "/")) z = y / x;
			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);//��� ����� �ٽ� stack�� ����
		}
		else {
			push(stack, s[i]);
		}
	}
	printf("%s ", pop(stack));
}

//�������� ���
int main(void) {
	Stack stack; 
	stack.top = NULL; //���� �ʱ�ȭ
	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10"; //��� ����
	int size = 1; //size�� ������ ���ڿ����� ���� 
	for (int i = 0; i < strlen(a); i++) {//���ڸ� ���캸�鼭
		if (a[i] == ' ') size++; //���Ⱑ ���ö����� 1�� ������
	}
	//string token�̶�� ���̺귯���� �̿��ؼ�,
	//������ ���ڿ��� ���⸦ �̿��ؼ� �и��� ��
	char **ptr = strtok(a, " ");
	char **input = (char**)malloc(sizeof(char*) * size);//���� ǥ��� ���⿡ �ְ��� �ϴ� �Է°��� ��������
	for (int i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);//�� ���ڿ��� �ִ� 100����ũ��
	}
	//��ū���� �и��� �� ���ڿ����� input�� ����
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");//���� ��ū�� Ȯ���� ���� string token�Լ��� �� �ҷ���.
	}
	//������ �и��� ��ū ���� input�� �־���

	char b[1000] = "";
	strcpy(b, transition(&stack, input, size));
	printf("���� ǥ��� : %s\n", b);
	size = 1;
	for (int i = 0; i < strlen(b) - 1; i++) { // �������� �׻� ������ ���Ƿ� 1 �� ����
		if (b[i] == ' ') size++;
	}
	char *ptr2 = strtok(b, " ");
	for (int i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}
	calculate(&stack, input, size);
	system("pause");
	return 0;
}

