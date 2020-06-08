#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct Node *leftC;
	struct Node *rightC;
} Node;

Node* initNode(int data, Node *leftC, Node *rightC) { //�ʱ�ȭ
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftC = leftC;
	node->rightC = rightC;
	return node; //����� ������ ��ȯ
}

/*���� ��ȸ*/
void preorder(Node* root) { //Ư���� root node�� �־����� ��
	if (root) {//node�� ���� null���� �ƴ϶��
		printf("%d ", root->data); //�ڱ��ڽ��� �����
		preorder(root->leftC); // ��������
		preorder(root->rightC); //�� �� ����������
	}
}

/*���� ��ȸ*/
void postorder(Node* root) {
	if (root) {//node�� ���� null���� �ƴ϶��		
		preorder(root->leftC); //��������
		preorder(root->rightC); //����������
		printf("%d ", root->data); //�ڱ��ڽ� ���
	}
}

int main(void){
	Node* n7 = initNode(50, NULL, NULL);
	Node* n6 = initNode(37, NULL, NULL);
	Node* n5 = initNode(23, NULL, NULL);
	Node* n4 = initNode(5, NULL, NULL);
	Node* n3 = initNode(48, n6, n7);
	Node* n2 = initNode(17, n4, n5);
	Node* n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	postorder(n1);
	system("pause");
	return 0;
}