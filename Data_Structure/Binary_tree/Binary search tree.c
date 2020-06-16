/*���� Ž�� Ʈ��*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int	data;
	struct Node * leftChild;
	struct Node * rightChild;
}Node;

//����
Node* insertNode(Node* root, int data){
	if (root == NULL) {//root�� null�� ���� �ʱ�ȭ 
		root = (Node *)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->data = data;
		return root;
	}
	else{
		if (root->data > data) {//��Ʈ�� ������ �ִ� ������ ����, �츮�� �����ϰ��� �ϴ� ��尡 �۴ٸ�
			root->leftChild = insertNode(root->leftChild, data);//�������� �̵��ؼ� ���ʿ� ����
		}
		else{
			root->rightChild = insertNode(root->rightChild, data);
		}
	}
	return root;
}

//Ž��
Node* searchNode (Node* root, int data ){
	if (root == NULL) return NULL;
	if (root->data == data) return root;//�ش� ��带 �߰��ߴٸ� ����
	else if (root->data > data) return searchNode(root->leftChild, data);//�츮�� ã���� �ϴ� �����Ͱ� �� �۴ٸ�
																		 //�����ڽ����� Ž��
	else return searchNode(root->rightChild, data);//�׷��� �ʴٸ� ������ �ڽ����� Ž��
}//Ž�� ���н� null��ȯ

//��ȸ
void preorder(Node * root){//���� ��ȸ ���
	if (root == NULL) return;
	printf("%d ", root->data);
	preorder(root->leftChild);
	preorder(root->rightChild);
}

//���� ���� ã��
Node* findMinNode(Node * root ){
	Node* node = root;
	while(node->leftChild != NULL){
		node = node->leftChild;
	}
	return node;
}

//���� �Լ�
Node* deleteNode(Node* root, int data ){
	Node* node = NULL;
	if (root == NULL) return NULL;//ã���� �ϴ� ��带 ��ã���� null
	if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);//ã���� �ϴ� ��尡 �� ������ ��������
	else if(root->data < data) root->rightChild = deleteNode(root->rightChild, data);//�׷��� ������ ����������
	else {//�ش� ��� �߰�
		if (root->leftChild != NULL && root->rightChild != NULL) {//��� �Ѱ� �̻� ����
			node = findMinNode(root->rightChild);//�����ʿ��� �ٷ� �������� ū �� ã��
			root->data = node->data;//����� �����ͷ� �ٲ�ġ��
			root->rightChild = deleteNode(root->rightChild, node->data);//�ش� ���� ������
		}
		else {
			node = (root->leftChild != NULL) ? root->leftChild : root->rightChild; 
			//���� �ڽ��� �����ϸ� ���� �ڽ��� ��忡 ���, �ƴ϶�� ������ �ڽ��� ��忡 ����
			free(root);// ���� ��� �Ҵ� ����
			return node;//�ش� �ڽĳ�带 ����
		}
	}
	return root;
}

//�̿�
int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	preorder(root);
	system("pause");
}
