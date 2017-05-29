// 최소 히프 사용
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100
typedef struct TreeNode {
	int weight;
	struct TreeNode *left_child;
	struct TreeNode *right_child;
} TreeNode;
typedef struct {
	TreeNode *ptree;
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
init(HeapType *h) {
	h->heap_size = 0;
}

// 삽입 함수
void insert_min_heap(HeapType *h, element item) {

	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// 삭제 함수
element delete_min_heap(HeapType *h) {

	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}

// 이진 트리 생성 함수
TreeNode *make_tree(TreeNode *left, TreeNode *right) {

	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	if (node == NULL) {
		fprintf(stderr, "메모리 에러\n");
		exit(1);
	}
	node->left_child = left;
	node->right_child = right;

	return node;
}

// 이진 트리 제거 함수
void destroy_tree(TreeNode *root) {

	if (root == NULL)
		return;
	destroy_tree(root->left_child);
	destroy_tree(root->right_child);
	free(root);
}

// 허프만 코드 생성 함수
void huffman_tree(int freq[], int n) {

	int i;
	TreeNode *node, *x;
	HeapType heap;
	element e, e1, e2;

	init(&heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(&heap, e);
	}
	for (i = 1; i < n; i++) {
		// 최솟값을 가지는 두 개의 노드를 삭제
		e1 = delete_min_heap(&heap);
		e2 = delete_min_heap(&heap);
		// 두 개의 노드를 합친다
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		insert_min_heap(&heap, e);
	}
	e = delete_min_heap(&heap); // 최종 트리
	destroy_tree(e.ptree);
}


// 허프만 코드 다 하고 나서 할 것
// 한 페이지 정도의 영어 단문에서 a~z의 빈도수를 계산하는 프로그램을 구현하라.
// 빈도수를 계산하고 허프만 코드 프로그램에 입력하여 
// 해당 영어 단문의 허프만 코드를 만들어 용량 크기를 비교해본다. (압축이 얼마나 되는지 알아내는 것이다)
int main() {

	int freq[] = { 15, 12, 8, 6, 4 };
	huffman_tree(freq, 5);
}

