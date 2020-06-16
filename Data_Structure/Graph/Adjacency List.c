/*���Ⱑ��ġ �׷����� ���� ����Ʈ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//���Ḯ��Ʈ ����ü �����
typedef struct{ //�Ѱ��� ��带 ���� ����.
	int	index; //�ε���
	int distance;//����ġ(�Ÿ�)
	struct Node *next;//���Ḯ��Ʈ��, ���� ��忡 ����
}Node;

//���Ḯ��Ʈ ���� �Լ�
void addFront (Node *root, int index, int distance ){//�տ� �߰�
	Node *node = (Node *)malloc(sizeof(Node));//�Ѱ��� ��带 ��� ũ�⸸ŭ �����Ҵ�
	node->index = index;
	node->distance = distance;//�ʱ�ȭ
	node->next = root->next;//���ʴ�� ����
	root->next = node;
}

//���Ḯ��Ʈ ����Լ�
void showAll( Node *root ){//Ư�� root�� ���� �� ���
	Node*cur = root->next;//root�� next���� ���
	while (cur != NULL) {
		printf("%d(�Ÿ� : %d) ", cur->index, cur->distance);//� ����, �� ���ұ��� ���� �Ÿ�
		cur = cur->next;//�̷��� ���Ḯ��Ʈ�� ������ ����
	}
}

//���Ḯ��Ʈ ���
int main() {
	int n, m;//����� ����, ������ ����
	scanf("%d %d", &n,&m);
	Node** a = (Node**)malloc(sizeof(Node*)*(n + 1));//��������Ʈ�� ������, ����� ������ŭ ���Ḯ��Ʈ �ʿ� 
													 //��尳�� +1��ŭ �����Ҵ� :
													 //�� �ε����� 1���� ������ ���̶�� �Ұ��̱� ����
	for (int i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));//�� ��带 �����Ҵ����� �ʱ�ȭ
		a[i]->next = NULL;//root�� ���� NULL���� ����ų �� �ֵ���
	}
	for (int i = 0; i < m; i++) {
		int x, y, distance; //�� ������ �������� ����ڵ��� �Է�
		scanf("%d %d %d", &x, &y, &distance);
		addFront(a[x], y, distance);// �տ� �����ִ� ��� �̿� 
									//Ư���� �ε���(���)�� ����Ǿ� �ִ� ������ Y��� �ؼ� �����ϰ�
									//�� ����ġ (distance)�� �־���
	}
	for (int i = 1; i < n; i++) {
		printf("���� [%d]: ",i);//�� ���� ���
		showAll(a[i]);//Ư�� ����(Ư�� ���, ����)�� ����Ǿ� �ִ� �ٸ� �������� ���� ���
		printf("\n");
	}
	system("pause");
	return 0;
}