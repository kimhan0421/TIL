/*���ͽ�Ʈ�� �˰���-���� �˰���� ���*/

//���� ����ü ���� [�ִ� ��� : 20,000�� / �ִ� ���� : 300,000��]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001 // ����� �����̹Ƿ� 300,000 ��

typedef struct {
	int cost;
	int node;
}Edge;
//�켱 ���� ť�ȿ��� Edge���� ���� ��ġ�� �ٲپ� �ϴ� ���� �߻��� �� �־� swap�Լ� ����
void swap(Edge *a, Edge *b) {
	Edge temp;
	temp.cost = a->cost;
	temp.node = a->node;
	a->cost = b->cost;
	a->node = b->node;
	b->cost = temp.cost;
	b->node = temp.node;
}
//�켱���� ť ���� �� �����Լ� ����
typedef struct {
	Edge *heap[EDGE_MAX];
	int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;
	pq->heap[pq->count] = edge;
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	//�� ���Ҹ� ���� �� ��������� �� ����
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

//�켱���� ť ���� �Լ� ����
Edge* pop(priorityQueue *pq) {
	if (pq->count <= 0) return NULL;
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����մϴ�.
	while (leftChild < pq->count) {
		if (pq->heap[target]->cost > pq->heap[leftChild]->cost) target = leftChild;
		if (pq->heap[target]->cost > pq->heap[rightChild]->cost && rightChild < pq->count) target = rightChild;
		if (target == now) break; //�� �̻� �������� �ʾƵ� �� �� ����
		else {
			swap(pq->heap[now], pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

//���� ���� ����Ʈ ����
typedef struct Node {
	Edge *data;
	struct Node *next;
}Node;
Node** adj;
int ans[NODE_MAX];//Ư���� �������� �ִ� �Ÿ��� �ǹ�

void addNode(Node** target, int index, Edge* edge) {
	if(target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}
	else {
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

//���ͽ�Ʈ�� ���
int main() {
	int n, m, k; //k�� ����ϴ� ���
	scanf("%d %d %d", &n, &m, &k);
	adj = (Node**)malloc(sizeof(Node*)*(n + 1)); //����� ������ŭ ���Ḯ��Ʈ ����
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;//���Ḯ��Ʈ �ʱ�ȭ 
		ans[i] = INT_MAX;//��ó�� ��� ���� �� �� �ִ� ����� �������� ����
	}
	priorityQueue *pq;//�켱���� ť�� ���� ��
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {//����׷��� �� �� ó�� ����
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);//a���� b�� ���� ����� c��� ���ڰ� �Է¹�����
		Edge *edge = (Edge*)malloc(sizeof(Edge));
		edge->node = b;//a��° �ε����� ���� b�� �߰�
		edge->cost = c;
		addNode(adj, a, edge);
	}//������ ������ �켱���� ť�� ���

	//���ͽ�Ʈ�� �˰����� �����մϴ�.
	ans[k] = 0;//����ϰ��� �ϴ� ��带 k��� ��
	Edge *start = (Edge*)malloc(sizeof(Edge));
	start->cost = 0; start->node = k; push(pq, start);//��� ��忡 ���� ���������� ť�� �ְ�
	while (1) {//ť���� pop�ϸ鼭 �˰��� ����
			   //��� ������ ���� ������ ť�� ��Ҵٰ� ���� ��
		Edge* now = pop(pq);//ť�� �ִ� ���Ҹ� �ϳ� ������
		if (now == NULL)break;//���Ұ� �ٴڳ������� pop
		int curNode = now->node;//����(���)�� ��� ������ ��´�
		int curCost = now->cost;
		if (ans[curNode] < curCost)continue;//���� ���� �ִ� �����, ������� ���̺� ���� ��뺸�� ũ�ٸ� ����
		Node* cur = adj[curNode];//�ƴ϶�� Ư�� ��尡 �߰� ���� �ǹ�

		//�߰��� ��忡 ����� ��� ��带  Ȯ���ϸ鼭 ���� ������� ���̺� ����
		while (cur != NULL) {//Ư�� ��带 Ȯ������ ��,
			Edge* temp = cur->data;
			temp->cost += curCost;//�ǳʰ��� ����� ���� ��
			if (temp->cost < ans[temp->node]) {//���� ���̺� ����ִ� �ش� ��忡 ���� �ִܰŸ� �����
											   //���� ���� �ִ� ��뺸�� ũ�ٸ�
				ans[temp->node] = temp->cost;//���� ������ ����
				push(pq, temp);//�ش� ������ ť�� ��Ƽ� �ٽ� ���������͸� Ȯ���� �� �ֵ��� ��
			}
			cur = cur->next;
		}
	}
	//���̺� ���·� ���
	for (int i = 1; i <= n; i++) {
		if (ans[i] == INT_MAX)printf("INF\n"); //�ʱ�ȭ ���� INT_MAX�� ���Ƹ� �ش� ���δ� ������ �� ���ٴ� �ǹ�
		else printf("%d\n", ans[i]);
	}
	system("pause");
}