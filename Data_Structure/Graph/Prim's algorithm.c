/*���� �˰���*/

//���� ����ü ���� [�ִ� ��� : 1000�� / �ִ� ���� : 100,000��]
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 20001 // ����� �����̹Ƿ� 100,000 ��

//������ ���� ���� ��� ����ü
typedef struct {
	int cost;
	int node;
}Edge;

//�ΰ� ������ ���� ������ swap��.�켱���� ť�� ���� ���
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
	Edge *heap[EDGE_MAX];//�� ������ �� �� �ֵ��� �迭�� ����
	int count;
} priorityQueue;

void push(priorityQueue *pq, Edge *edge) {
	if (pq->count >= EDGE_MAX) return;//�����͸� ������, �� ������ �Ѿ�� ����
	pq->heap[pq->count] = edge;//������ �ε����� ���ο� ���Ҹ� �ְ�
	int now = pq->count;
	int parent = (pq->count - 1) / 2;
	//�� ���Ҹ� ���� �� ��������� �� ����
		//root������ �ö󰡸鼭 �� ����
	while (now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost) {
		swap(pq->heap[now], pq->heap[parent]);
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

//�켱���� ť ���� �Լ� ����
Edge* pop(priorityQueue *pq) { //���Ұ� ����(Edge)���� �ٲ����
	if (pq->count <= 0) return NULL;
	Edge *res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];//�� ���Ҹ� ��Ʈ���� ��ġ�� �ٲ㼭 ����
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����մϴ�.leaf������ �������� ��ü �� ����
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
}Node; // �� ������ ���Ḯ��Ʈ��(��������Ʈ�� ǥ��)

Node** adj;
int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge) {//Ư�� �ε����� ������ ������ �߰���
	if(target[index] == NULL) {
		target[index] = (Node*)malloc(sizeof(Node));
		target[index]->data = edge;
		target[index]->next = NULL;
	}//Ư�� ������ ����Ǿ� �ִ� ������ ���ٸ�, ù��° ���ҷ� �ش� �������� �־���
	else {//�ƴ϶�� ���Ḯ��Ʈ�� ���Ӱ� ���� 
		Node* node = (Node*)malloc(sizeof(Node));
		node->data = edge;
		node->next = target[index];
		target[index] = node;
	}
}

//���� ���
int main() {
	int n, m;//����, ���� ����
	scanf("%d %d", &n, &m);
	adj = (Node**)malloc(sizeof(Node*)*(n + 1)); //������ ������ŭ �����Ҵ��� ���Ḯ��Ʈ�� �������
	for (int i = 1; i <= n; i++) {
		adj[i] = NULL;//���Ḯ��Ʈ �ʱ�ȭ 		
	}
	priorityQueue *pq;//�켱���� ť�� ���� ��
	pq = (priorityQueue*)malloc(sizeof(priorityQueue));
	pq->count = 0;
	for (int i = 0; i < m; i++) {//��� ������ ���� ������ ���� ��
		int a, b, c;//c�� ����ġ(a���� b���� ���µ� c��ŭ �ҿ��)
		scanf("%d %d %d", &a, &b, &c);
		//������ �׷����� ����
		Edge *edge1 = (Edge*)malloc(sizeof(Edge));
		edge1->node = b;
		edge1->cost = c;
		addNode(adj, a, edge1);
		Edge *edge2 = (Edge*)malloc(sizeof(Edge));
		edge2->node = b;
		edge2->cost = c;
		addNode(adj, a, edge2);
	}

	//���� �˰����� �����մϴ�.
	long long res = 0;
	Edge *start = (Edge*)malloc(sizeof(Edge)); //������ �Է¹���
	start->cost = 0; start->node = 1; push(pq, start);//�������� 1, ó������� 0
	for (int i = 1; i <= n; i++) {//����Ʈ���� ��� �� n���� ������ ���������� ������� ����Ʈ���� ���ԵǾ� n������ for���� ����
		int nextNode = -1, nextCost = INT_MAX;//�������� ���
		while (1) { //�湮���� ���� ���� �߿���, ���� ����� ���� ��带 �켱���� ť���� ����
					//�켱���� ť���� ����� ���� ������ �Ǿ� ����
			Edge* now = pop(pq);
			if (now == NULL)break;
			nextNode = now->node;
			if (!d[nextNode]) { 
				nextCost = now->cost;
				break;
			}
		}
		if (nextCost == INT_MAX) {
			printf("���� �׷����� �ƴմϴ�.\n");//�� ã�Ҵٸ� ����׷����� �ƴ�
		}
		res += nextCost;//��ü �ּ� ���� Ʈ���� ����µ� �ʿ��� cost�� �� ���ؼ� 
		d[nextNode] = 1;//Ư�����(������ ���̰� ���� ���)�� �湮ó��
		Node* cur = adj[nextNode];
		while(cur != NULL) {//������ ������ Ȯ���ϸ鼭 �� ������ �켱���� ť�� ����
			push (pq, cur->data); 
			cur = cur->next;
		}
	}
	printf("%lld\n", res);
	system("pause");
}