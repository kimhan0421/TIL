#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000 //��ü stackũ�� ������
#define INF 99999999 


int stack[SIZE];
int top = -1;//stack�� �ֻ�� �ǹ�

void push(int data) {
	if (top == SIZE - 1) {
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	//�׷��� �ʴٸ� top�� 1�� ���� ���� index�� data�� �־���
	stack[++top] = data;

}
void pop() {
	if (top==-1) {//���Ұ� �ϳ��� ������� �ʴٸ�
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;//������ return���־� ���� �߻� �˷���
	}
	//������ ���ٸ� ���� top�� ����Ű�� �ִ� �� ������ ���� ��ȯ�ϸ鼭 
	//���Ұ� �پ����� �˸� 
	return stack[top--];
}

void show() {//���	
	printf("--������ �ֻ��--\n");
	for(int i=top; i>=0; i--){
		printf("%d\n", stack[i]); //�ֻ�ܺ��� ���
	}
	printf("--������ ���ϴ�--\n");
}
int main() {
	//stack�� �� �ֱ�
	push(7);//���ÿ� �޸� �ּҸ� ������ �ϱ� ������ &�� ����
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return 0;
}