#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode{
	char key;					// ������ �ʵ�
	struct treeNode* left;		// ���� ����Ʈ�� ��ũ �ʵ�
	struct treeNode* right;		// ������ ����Ʈ�� ��ũ �ʵ� 
}treeNode;

typedef char element;			// char�� ���� Ž�� Ʈ�� element�� �ڷ������� ����
treeNode* insertNode(treeNode* p, char x)
{
	// ������p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
	treeNode* newNode;
	if(p==NULL){
		newNode=(treeNode*)malloc(sizeof(treeNode));
		newNode->key=x;
		newNode->left=NULL;
		newNode->right=NULL;
		return newNode;
	} 
	else if(x < p->key)
		p->left = insertNode(p->left, x);
	else if(x > p->key)
		p->right = insertNode(p->right, x);
	else
		printf("\n �̹� ���� Ű�� �ֽ��ϴ�!\n");
	return p;
 } 

void deleteNode(treeNode* root, element key)
{
	// root ������ Ž���Ͽ� key ���� ���� ��带 ã�� �����ϴ� ����
	treeNode* parent, *p, *succ, *succ_parent;
	treeNode* child;
	
	parent=NULL;
	p=root;
	while((p!=NULL) && (p->key != key)){ // ������ ����� ��ġ Ž�� 
		parent=p;
		if(key < p->key)
			p=p->left;
		else p=p->right;
	} 
	// ������ ��尡 ���� ���
	if(p==NULL){ 
		printf("\n ã�� Ű�� ����Ʈ���� �����ϴ�!");
		return; 
	}
	// ������ ��尡 �ܸ� ����� ��� 
	if ((p->left==NULL) && (p->right==NULL)){
		if(parent !=NULL){
			if(parent->left == p)
				parent->left=NULL;
			else parent->right=NULL;
		}
		else root=NULL;
	} 
	// ������ ��尡 �� ���� �ڽ� ��带 ���� ��� 
	else if((p->left==NULL) || (p->right==NULL)){
		if(p->left!=NULL)
			child=p->left;
		else child=p->right;
		if(parent!=NULL){
			if(parent->left==p)
				parent->left=child;
			else parent->right=child;
		}
		else root=child;
	}
	// ������ ��尡 �� ���� �ڽ� ��带 ���� ���
	else{
		succ_parent=p;
		succ=p->left;
		while(succ->right !=NULL){
			succ_parent=succ;
			succ=succ->right;
		}
		if(succ_parent->left==succ)
			succ_parent->left=succ->left;
		else succ_parent->right=succ->left;
		p->key=succ->key;
		p=succ;
	} 
	free(p);
}

treeNode* searchBST(treeNode* root, char x)
{
	// ���� Ž�� Ʈ������ Ŷ���� x�� ����� ��ġ�� Ž���ϴ� ����
	treeNode* p;
	p=root;
	while(p!=NULL){
		if(x < p->key)
			p=p->left;
		else if(x==p->key)
			return p;
		else p=p->right;
	} 
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

void displayInorder(treeNode* root)
{
	// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
	if(root){
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	} 
}

void searchTwoNodeBST(treeNode* root)
{
	// �ڽĳ���� ������ 2���� ������ �̸��� ����ϴ� ���� 
	if (root==NULL) return;
	if ((root->left!=NULL) && (root->right!=NULL)){
		searchTwoNodeBST(root->left);
		printf("%c ", root->key);
		searchTwoNodeBST(root->right);
	}
}

void searchNodeBST(treeNode* root)
{
	// �ܸ������� �̸��� ����ϴ� ���� 
	if (root==NULL) return;
	if ((root->left==NULL) && (root->right==NULL)) 
		printf("%c ", root->key);
	searchNodeBST(root->left);
	searchNodeBST(root->right);
}

void menu()
{
	printf("\n*------------------------------------------------*");
	printf("\n 1. Ʈ�� ���");
	printf("\n 2. ���� ����");
	printf("\n 3. ���� ����");
	printf("\n 4. ���� �˻�");
	printf("\n 5. �ڽĳ���� ������ 2���� ������ �̸� ���");
	printf("\n 6. �ܸ������� �̸� ���");
	printf("\n 7. ����");
	printf("\n*------------------------------------------------*");
	printf("\n�޴��Է�>>");
}

int main()
{
	treeNode* root=NULL;
	treeNode* foundedNode=NULL;
	int choice;
	char key;
	root=insertNode(root, 'G');	// Ʈ�� �����
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');
	
	while(1){
		menu();
		// choice=getchar();
		scanf("%d", &choice);
		getchar();
		// printf("%c", choice);
		switch(choice){
			case 1: printf("\t[����Ʈ�� ���] ");
					displayInorder(root);
					printf("/n");
					break;
			case 2: printf("������ ���ڸ� �Է��ϼ��� : ");
					key=getchar();
					getchar();
					insertNode(root, key);
					break;
			case 3: printf("������ ���ڸ� �Է��ϼ��� : ");
					key=getchar();
					getchar();
					deleteNode(root, key);
					break;
			case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
					key=getchar();
					getchar();
					foundedNode=searchBST(root, key);
					if(foundedNode!=NULL)
						printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
					else printf("\n ���ڸ� ã�� ���߽��ϴ�.\n");
					break;
			case 5: printf("\t[�ڽĳ���� ������ 2���� ����� �̸�] ");
					searchTwoNodeBST(root);
					break;
			case 6: printf("\t[�ܸ���� ���] ");
					searchNodeBST(root);
					break;
			case 7: return 0;
			default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���!\n");
			 		 break; 
		}
	}
 }
 
 
