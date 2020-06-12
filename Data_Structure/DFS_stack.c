#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
typedef struct {
	int	index;
	struct	Node *next;
}Node;

Node**a; //���Ḯ��Ʈ ������
int n, m, c[MAX_SIZE]; //n-����, m-����,c- �湮 �ߴ��� Ȯ��

/*����(stack)����ó�� ����*/
void addFront(Node *root, int index) {//���Ḯ��Ʈ �����Լ�
	Node *node = (Node*)malloc(sizeof(Node)); //�����Ҵ�-
	node->index = index;
	node->next = root->next;//root�� �ִ� next��ü�� node�� next�� ����.
	root->next = node; // ���Ḯ��Ʈ ���ʿ� ���� �� �ֵ���
}

/*���� �켱 Ž��*/
void dfs(int x) {//Ư�� x, �ε����� ��忡�� ���̿켱 Ž��
	if (c[x]) { return; }//�ش��带 �湮�� �������� return
	c[x] = 1;//���Ŀ� �ش� ��带 �湮�ߴٰ�, �湮 ó����
	printf("%d ",x);// �ش� ��� ���
	Node *cur = a[x]->next;//�ش��忡 ����Ǿ� �ִ� ���� Ȯ��
	while (cur != NULL) {//NULL���� �ƴ� ������ �ݺ� ��� ��� �湮 ����
		int next = cur->index;//����Ǿ� �ִ� ��带 Ȯ���ؼ�
		dfs(next);//��忡 dfs�� ����=>��������� �Լ� ȣ��Ǿ� ~
		cur = cur->next;//�ݺ������� �湮 ����.
	}
}

/*���� �켱 Ž�� �̿�*/
int main() {
	scanf("%d %d",&n,&m);
	a = (Node**)malloc(sizeof(Node*)*(MAX_SIZE));//������ ������ŭ ������ �Ҵ�
	for (int i = 1; i <= n; i++) {//n�������� �ʱ�ȭ
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addFront(a[x], y); //x���� y�� �� �� ����
		addFront(a[y], x); //y���� x�� �� �� ����	
	}
	dfs(1);//1���� ���̿켱Ž�� ����
	system("pause");
	return	0;
}
//�湮 ������ ��õǾ� ���� ����