#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


/* ��ũ������ ������ ���� Ʈ��*/
typedef struct TreeNode {

	int data;
	struct TreeNode *left, *right;
} TreeNode;

void main() {
	
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
}

/* ���� Ʈ���� 3���� ��ȸ ���*/
void inorder(TreeNode *root) {	// ���� ��ȸ

	if (root) {
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode *root) {	// ���� ��ȸ

	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root) {	// ���� ��ȸ

	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}


/* ���� ��ȸ ���α׷� (ť�� �ϰ� �ϼ���Ű��)*/

////////////////////////////////////////////
///////// ���� Ʈ�� ��� ���α׷� //////////
////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode *exp = &n7;

int evaluate(TreeNode *root) { // evaluate: ���ϴ�, �����ϴ�
	if (root = NULL)
		retrun 0;
	if (root->left == NULL & root->right == NULL)
		retrun root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}

	return 0;
}

int main() {
	printf("%d", evaluate(exp));
}

/* ���� Ʈ������ ��� ���� ���ϴ� �˰���*/
int get_node_count(TreeNode *node) {

	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

/* ���� Ʈ������ �ܸ� ��� ���� ���ϴ� �˰���*/
int get_leaf_count(TreeNode *node) {

	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}

	return count;
}

/* ���� Ʈ������ ���� ���ϴ� �˰���*/
int get_height(TreeNode *node) {

	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}
/////////////////////////////////
////// ������ ���� Ʈ�� /////////
/////////////////////////////////
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; //�������̸� TRUE
} TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *exp = &n7;

TreeNode *find_successor(TreeNode *p) {
	
	// q�� p�� ������ ������
	TreeNode *q = p->right;
	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// ���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL)
		q = q->left;
	
	return q;
}

void thread_inorder(TreeNode *t) {

	TreeNode *q;
	q = t;
	while (q->left)
		q = q->left; // ���� ���� ���� ����;
	do {
		printf("%c", q->data); // ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q);
}

main() {
	
	// ������ ����
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	// ���� ��ȸ
	thread_inorder(exp);
}

/////////////////////////////////
////// ���� Ž�� Ʈ�� ///////////
/////////////////////////////////

/* ��ȯ���� Ž�� �Լ�*/
TreeNode *search(TreeNode *node, int key) {

	if (node == NULL)
		return NULL;
	if (key == node->data)
		return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);
}

/* �ݺ����� Ž�� �Լ�*/
TreeNode *search(TreeNode *node, int key) {

	while (node != NULL) {
		if (key == node->data)
			return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}

	return NULL;
}

/* ���� Ʈ�� ���� ���α׷�*/
void insert_node(TreeNode **root, int key) {

	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;

	// Ž���� ���� ����
	while (t != NULL) {
		if (key == t->data)
			return;
		p = t;
		if (key < t->data)
			t = t->left;
		else
			t = t->right;
	}

	// key�� Ʈ�� �ȿ� �����Ƿ� ���� ����
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL)
		return;
	// ������ ����
	n->data = key;
	n->left = n->right = NULL;
	// �θ���� ����
	if (p != NULL)
		if (key < p->data)
			p->left = n;
		else
			p->right = n;
	else
		*root = n;
}

/* ���� Ʈ�� ���� �Լ�*/
void delete_node(TreeNode **root, int key) {

	TreeNode *p, *child, *succ, *succ_p, *t;

	// key�� ���� ��� i�� Ž��, p�� t�� �θ� ���
	p = NULL;
	t = *root;
	// key�� ���� ��� t�� Ž���Ѵ�.
	while (t != NULL & t->data != key) {
		p = t;
		t = (key < t->data) ? t->left : t->right;
	}

	// Ž���� ����� ������ t�� NULL�̸� Ʈ�� �ȿ� key�� ����
	if (t == NULL) {
		// Ž�� Ʈ���� ���� Ű
		printf("key is not in the tree");
		return;
	}

	// ù ��° ���: �ܸ� ����� ���
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			// �θ� ����� �ڽ� �ʵ带 NULL�� �����.
			if (p->left == t)
				p->left = NULL;
			else
				p->right = NULL;
		}
		else // ���� �θ� ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = NULL;
	}

	// �� ��°�� ���: �ϳ��� �ڽĸ� ������ ���
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)  // �θ� �ڽİ� ����
				p->left = child;
			else
				p->right = child;
		}
		else  // ���� �θ� ��尡 NULL�̸� �����Ǵ� ��尡 ��Ʈ
			*root = child;
	}

	// �� ��°�� ���: �� ���� �ڽ��� ������ ���
	else {
		// ������ ���� Ʈ������ �İ��ڸ� ã�´�
		succ_p = t;
		succ = t->right;
		// �İ��ڸ� ã�Ƽ� ��� �������� �̵��Ѵ�
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// �ļ����� �θ�� �ڽ��� ����
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// �ļ��ڰ� ���� Ű ���� ���� ��忡 ����
		t->data = succ->data;
		// ������ �ļ��� ����
		t = succ;
	}

	free(t);
}