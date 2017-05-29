#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


/* 링크법으로 생성된 이진 트리*/
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

/* 이진 트리의 3가지 순회 방법*/
void inorder(TreeNode *root) {	// 중위 순회

	if (root) {
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode *root) {	// 전위 순회

	if (root) {
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode *root) {	// 후위 순회

	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}


/* 레벨 순회 프로그램 (큐를 하고 완성시키자)*/

////////////////////////////////////////////
///////// 수식 트리 계산 프로그램 //////////
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

int evaluate(TreeNode *root) { // evaluate: 평가하다, 감정하다
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

/* 이진 트리에서 노드 개수 구하는 알고리즘*/
int get_node_count(TreeNode *node) {

	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

/* 이진 트리에서 단말 노드 개수 구하는 알고리즘*/
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

/* 이진 트리에서 높이 구하는 알고리즘*/
int get_height(TreeNode *node) {

	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}
/////////////////////////////////
////// 스레드 이진 트리 /////////
/////////////////////////////////
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; //스레드이면 TRUE
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
	
	// q는 p의 오른쪽 포인터
	TreeNode *q = p->right;
	// 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// 만약 오른쪽 자식이면 다시 가장 왼쪽 노드로 이동
	while (q->left != NULL)
		q = q->left;
	
	return q;
}

void thread_inorder(TreeNode *t) {

	TreeNode *q;
	q = t;
	while (q->left)
		q = q->left; // 가장 왼쪽 노드로 간다;
	do {
		printf("%c", q->data); // 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q);
}

main() {
	
	// 스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	// 중위 순회
	thread_inorder(exp);
}

/////////////////////////////////
////// 이진 탐색 트리 ///////////
/////////////////////////////////

/* 순환적인 탐색 함수*/
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

/* 반복적인 탐색 함수*/
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

/* 이진 트리 삽입 프로그램*/
void insert_node(TreeNode **root, int key) {

	TreeNode *p, *t;
	TreeNode *n;

	t = *root;
	p = NULL;

	// 탐색을 먼저 수행
	while (t != NULL) {
		if (key == t->data)
			return;
		p = t;
		if (key < t->data)
			t = t->left;
		else
			t = t->right;
	}

	// key가 트리 안에 없으므로 삽입 가능
	n = (TreeNode *)malloc(sizeof(TreeNode));
	if (n == NULL)
		return;
	// 데이터 복사
	n->data = key;
	n->left = n->right = NULL;
	// 부모노드와 연결
	if (p != NULL)
		if (key < p->data)
			p->left = n;
		else
			p->right = n;
	else
		*root = n;
}

/* 이진 트리 삭제 함수*/
void delete_node(TreeNode **root, int key) {

	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 i를 탐색, p는 t의 부모 노드
	p = NULL;
	t = *root;
	// key를 갖는 노드 t를 탐색한다.
	while (t != NULL & t->data != key) {
		p = t;
		t = (key < t->data) ? t->left : t->right;
	}

	// 탐색이 종료된 시적에 t가 NULL이면 트리 안에 key가 없음
	if (t == NULL) {
		// 탐색 트리에 없는 키
		printf("key is not in the tree");
		return;
	}

	// 첫 번째 경우: 단말 노드인 경우
	if ((t->left == NULL) && (t->right == NULL)) {
		if (p != NULL) {
			// 부모 노드의 자식 필드를 NULL로 만든다.
			if (p->left == t)
				p->left = NULL;
			else
				p->right = NULL;
		}
		else // 만약 부모 노드가 NULL이면 삭제되는 노드가 루트
			*root = NULL;
	}

	// 두 번째인 경우: 하나의 자식만 가지는 경우
	else if ((t->left == NULL) || (t->right == NULL)) {
		child = (t->left != NULL) ? t->left : t->right;
		if (p != NULL) {
			if (p->left == t)  // 부모를 자식과 연결
				p->left = child;
			else
				p->right = child;
		}
		else  // 만약 부모 노드가 NULL이면 삭제되는 노드가 루트
			*root = child;
	}

	// 세 번째인 경우: 두 개의 자식을 가지는 경우
	else {
		// 오른쪽 서브 트리에서 후계자를 찾는다
		succ_p = t;
		succ = t->right;
		// 후계자를 찾아서 계속 왼쪽으로 이동한다
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// 후속자의 부모와 자식을 연결
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;
		// 후속자가 가진 키 값을 현재 노드에 복사
		t->data = succ->data;
		// 원래의 후속자 삭제
		t = succ;
	}

	free(t);
}