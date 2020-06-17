/*�켱���� ť-���� ���� Ʈ�� ������ ���� �̿��� ���� ����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

//����
void swap(int *a, int *b){
	int temp = *a;
	*a = b;
	*b = temp;
}//�ΰ� ��ġ �ٲ�

typedef struct{
	int	heap[MAX_SIZE];// �Ѱ��� ���� �迭���·� ������� ����
	int count;//���� ���� ����ִ� ���� ����
}priorityQueue; 

//����
void push(priorityQueue *pq, int data){//Ư���� �켱���� ť�� data�� ����
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data; //data�� q�� ����ִ� ������ ������ �ش��ϴ� �ε����� �־���
								//�̷��� �׻� ������ ����Ʈ���� ������ ���ҷν� ��
	int now = pq->count;//���Ե� data�� �ش��ϴ� �ε���
	int parent = (pq-> count - 1) / 2;
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����մϴ�
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {//�θ𺸴� ���� �� ũ�ٸ� 
		swap(&pq->heap[now], &pq->heap[parent]);//��ġ�� ���� �ٲ���
		now = parent;
		parent = (parent - 1) / 2;//�θ��� ��ġ���� �� ������ �ݺ��� �� �ֵ���
	}
	pq->count++;//���� �� count����
}

//ť ����
int pop(priorityQueue *pq){//Ư�� ť�� �Ű������� �Է� ����
	if (pq-> count <= 0) return -9999;//�� �̻� ������ ���� ������ ����
	int res = pq->heap[0];//������ ����. root����� ��
	pq->count--;//count-1 
	pq->heap[0] = pq->heap[pq->count];//count�� �ش��ϴ� ����(������ ����)�� ù��° root��忡 �־���
	//��, root��带 ���� �ش� root��忡 ������ ���� ����
	int	now = 0, leftChild = 1, rightChild = 2;
	int target = now;//target�� �ڱ��ڽ��� ����Ŵ.�Ŀ��� �ٲٰ����ϴ� �ڽĳ�尡 ��
	//�� ���Ҹ� ������ ���Ŀ� ��������� ���� �����մϴ�.
	while(leftChild < pq->count){//leftChild�� count���� ��������.�� ���Ұ� �����Ҷ�������
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;//target ,leftChild�ٲ�
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;//target�� rightChild�־���
																								   //rightChild < pq->count�� �ε��� ����� ����
		if(target == now) break; //�� �ڽĺ��� ������ �� ũ�ٸ�
								 //�� �̻� �������� �ʾƵ� �� �� ����
		else {
			swap(&pq->heap[now], &pq->heap[target]);//�ڽ� �߿��� ū ���� �ڽ��� �� �ٲ�
			now = target;//�Ʒ��� �������� ��
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

//���
int main(void){
	int n, data;
	scanf("%d", &n);
	priorityQueue	pq;
	pq.count = 0;

	for(int i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}
	for(int i = 0; i < n; i++) {
		int	data = pop(&pq);
		printf("%d ", data);
	}
	return	0;
}