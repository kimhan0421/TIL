/*���Ḯ��Ʈ �̿��� ť ����*/

#include <stdio.h>
#define SIZE 10000
#define INF 99999999

//ť ����
typedef struct{
	int	data;
	struct Node *next;
}Node;

typedef struct{ //front, rear�� ��
	Node *front;
	Node *rear;
	int count; //ť�� �ִ� ���ҵ� ī��Ʈ
}Queue;


//ť ����
void push(Queue *queue, int data){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {//ť�� ��������� ī��Ʈ�� 0
		queue->front = node;//front�� ���
	}//�ʱ� ����
	else {
		queue->rear->next = node;//rear�� �������� �� ��尡 ����]
	}
	queue->rear = node;//rear�� �ش� ��� ��
	queue->count++;
}
//ť ����
int pop(Queue *queue){
	if (queue->count == 0) {//ť ��� ����
		printf("ť ����÷ο찡 �߻��߽��ϴ�\n");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;//ť�� front�� ���� ��� ���� ����Ű���� �����
	free(node);
	queue->count--;
	return data;//������ �̾Ƽ� ��ȯ
}

//ť ��ü ���
void show(Queue *queue){//ť�� �տ������� ��������
	Node*cur = queue->front;
	printf("---------- ť�� �� -----------\n");
	while(cur != NULL){//��� �����ϸ� ��� ���
		printf("%d \n", cur->data);
		cur = cur->next;
	}
	printf("---------- ť�� �� -----------\n");
}

//�ϼ��� ť ���
int main(void) {
	Queue queue;
	queue.front = queue.rear = NULL;
	queue.count = 0;

	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	return 0;
}