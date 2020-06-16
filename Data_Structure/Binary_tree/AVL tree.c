/*���� ���� Ž�� Ʈ��*/

#include <stdio.h>
#include <stdlib.h>

int getMax( int a, int b ){
	if (a > b) return a;
	return b;
}
typedef struct{
	int	data;
	int height; // ���̸� �����ؾ� �ð� ���⵵�� ������ �� ����
	struct 	Node * leftChild;
	struct	Node * rightChild;
}Node;

//���� ��� �Լ�
int getHeight (Node * node ){
	if (node == NULL ) return 0;
	return node->height;
}
//��� ���� ȸ���� ������ ���Ŀ� ���̸� �ٽ� ���
void setHeight (Node * node ){
	node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
}

int getDifference( Node * node ){
	if (node == NULL ) return 0;
	Node* leftChild = node->leftChild;
	Node* rightChild = node->rightChild;
	return getHeight(leftChild) - getHeight(rightChild);
}

//LLȸ��
Node* rotateLL (Node * node ){
	Node *leftChild = node->leftChild;
	node->leftChild = leftChild->rightChild;
	leftChild->rightChild = node;
	setHeight(node ); // ȸ�� ���Ŀ� ���̸� �ٽ� ���
	return leftChild;
}
//RRȸ�� - LLȸ�� �ݴ�
Node* rotateRR (Node * node ){
	Node* rightChild = node->rightChild;
	node->rightChild = rightChild->leftChild;
	rightChild->leftChild = node;
	setHeight(node ); // ȸ�� ���Ŀ� ���̸� �ٽ� ���
	return rightChild;
}

//LRȸ��)LL+RR
Node *rotateLR (Node * node ){
	Node *leftChild = node->leftChild;
	node->leftChild = rotateRR(leftChild);
	return rotateLL(node);
}

//RLȸ�� - LRȸ�� �ݴ�
Node *rotateRL(Node * node) {
	Node *rightChild = node->rightChild;
	node->rightChild = rotateLL(rightChild);
	return rotateRR(node);
}

//���� ���
Node* balance(Node * node ){
	int difference = getDifference(node);
	if (difference >= 2) {
		if (getDifference(node->leftChild) >= 1) {
			node = rotateLL(node);
		}
		else {
			node = rotateLR(node);
		}
	}
	else if (difference <= -2) {
		if(getDifference (node->rightChild ) <= 1) {
			node = rotateRR(node);
		}
		else {
			node = rotateRL(node);
		}
	}
	setHeight(node ); // ȸ�� ���Ŀ� ���̸� �ٽ� ���
	return node;
}

//����
Node *insertNode (Node * node, int data ){
	if (!node) {
		node = (Node *)malloc(sizeof(Node));
		node->data = data;
		node->height = 1;//���� ���̰��� 1
		node->leftChild = node->rightChild = NULL;
	}
	else if (data < node->data) {
		node->leftChild = insertNode(node->leftChild, data);
		node = balance(node);
	}
	else if (data > node->data) {
		node->rightChild = insertNode(node->rightChild, data);
		node = balance(node);
	}
	else {
		printf("������ �ߺ��� �߻��߽��ϴ�. \n");
	}
	return node;
}

//����Լ�
Node* root = NULL;
void display(Node * node, int level){
	if (node != NULL) {
		display(node->rightChild, level + 1);//������ ���� ���
		printf("\n");
		if (node == root) {//root�߽߰� �˷���
			printf("Root: ");
		}
		for (int i = 0; i < level && node != root; i++) {
			printf("  ");//�ش� ������ŭ ����
		}
		printf("%d (%d)", node->data, getHeight(node));
		display(node->leftChild, level + 1);
	}
}

int main(void) {
	root = insertNode(root, 7);
	root = insertNode(root, 6);
	root = insertNode(root, 5);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 9);
	root = insertNode(root, 8);
	root = insertNode(root, 12);
	root = insertNode(root, 16);
	root = insertNode(root, 18);
	root = insertNode(root, 23);
	root = insertNode(root, 21);
	root = insertNode(root, 14);
	root = insertNode(root, 15);
	root = insertNode(root, 19);
	root = insertNode(root, 20);
	display	(root, 1);
	printf("\n");
	system("pause");

}