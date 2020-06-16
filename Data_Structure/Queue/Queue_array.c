/*�迭 �̿��� ť ����*/

//ť ����
#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

//ť ���� 
void push(int data){
	if(rear >= SIZE){
		printf("ť �����÷ο찡 �߻��߽��ϴ�. \n");
		return;
	}
	queue[rear++] = data;
}

//ť ����
int pop() {
	if (front == rear) {
		printf("ť ����÷ο찡 �߻��߽��ϴ� \n");
		return -INF;
	}
	return queue[front++];
}

//ť ��ü ��� �Լ�
void show() {
	printf("ť�� �� \n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", queue[i]);
	}
	printf("-------ť�� �� n------------");
}

//ť ���
int main(void){
	push(7);push(5);push(4);
	pop();
	push(6);
	pop();
	show();
	return 0;
}