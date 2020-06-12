#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

/*���Ḯ��Ʈ ����-��尡 ����� ����*/
typedef struct {
	int index;
	struct Node *next;
}Node;

/*ť ����*/
typedef struct {
	Node *front;
	Node *rear;
	int count;
}Queue;

Node **a; //������ �������� ���Ḯ��Ʈ ���·� ������ �������� ������ ������� - ����������Ʈ �̿�
int n, m, c[MAX_SIZE];//����, ����, �湮�� ����

/*���Ḯ��Ʈ ���� �Լ�*/
void addFront(Node *root, int index) {
	Node *node = (Node*)malloc(sizeof(Node));//�ϳ��� ��尡 ���Ӱ� �־��� ��
	node->index = index;//����� �ε������� �ְ����ϴ� ���� ��-����Ǿ� �ִ� �ش� ����
	node->next = root->next;//���Ḯ��Ʈ �߰�
	root->next = node;
}

/*ť ���� �Լ�*/
void queuePush(Queue *queue, int index) {
	Node *node = (Node*)malloc(sizeof(Node));//��� �Ҵ�
	node->index = index;
	node->next = NULL;
	if (queue->count == 0) { //ť�� ����ִٸ� 
		queue->front = node;//ť�� front�� ��� �ֱ�
	}
	else {//ť�� ��� ���� �ʴٸ�
		queue->rear->next = node;//ť�� rear�� �ֱ�
	}
	queue->rear = node;//�ڸ����� ����߰�
	queue->count++;//ť�� count����
}

/*ť ���� �Լ�*/
int	queuePop(Queue *queue) {
	if (queue->count == 0) {//ť�� ����ִٸ�
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = queue->front;//front���� ��� �Ѱ� ����
	int index = node->index;//�ش� �ε��� ������ ��
	queue->front = node->next;
	free(node);//�޸� ����
	queue->count--;//�ϳ� �������� count����
	return index;//�ش� ������ ���
}

/*�ʺ� �켱 Ž�� �Լ�*/
void bfs(int start) {//Ư�� ��ġ���� �ʺ�켱 Ž�� ���
	Queue q;
	q.front = q.rear = NULL;//ť �ʱ�ȭ
	q.count = 0;
	queuePush(&q, start);//ť�� �����ϴ� �ε��� �ֱ�
	c[start] = 1;//�ش� ��带 �湮ó��
	while (q.count != 0) {//ť�� �� �� ���� �ݺ�
		int x = queuePop(&q); //ť�� �ִ� ���� �ϳ� �̱�
		printf("%d ", x);//�湮 �� �� ���
		Node *cur = a[x]->next;//���ҿ� ����Ǿ� �ִ� ��� �ϳ��� Ȯ��
		/*������ ������ �湮�Ǿ� �ִ��� ���ο� ���� ť�� �������� ����*/
		while (cur != NULL) {
			int next = cur->index;//���� ��� Ȯ��
			if (!c[next]) {//�湮���� �ʾҴٸ�
				queuePush(&q, next);//ť�� �ְ�
				c[next] = 1;	//�湮ó��
			}
			cur = cur->next;//��� ��� Ȯ�� �ϱ�
		}
	}
}

/*�ʺ� �켱 Ž�� �̿�*/
int main(void) {
	scanf("%d %d", &n, &m);//��������, ���� ���� �Է� �ޱ�
	a = (Node **)malloc(sizeof(Node *) * (MAX_SIZE)); //�����Ҵ�
	for (int i = 1; i <= n; i++) {
		a[i] = (Node *)malloc(sizeof(Node));//���Ḯ��Ʈ �ʱ�ȭ
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y);
		addFront(a[y], x);
	}
	bfs(1);//��� 1�� �������� �ʺ�켱Ž��
	system("pause");
	return	0;
}
