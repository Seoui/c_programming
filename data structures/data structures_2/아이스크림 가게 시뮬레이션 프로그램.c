// 최소 히프 사용
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define ARRIVAL 1
#define ORDER 2
#define LEAVE 3

int free_seats = 10;
double profit = 0.0;

#define MAX_ELEMENT 100
typedef struct {
	int type;
	int key;
	int number;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 초기화 함수
void init(HeapType *h) {
	h->heap_size = 0;
}

int is_empty(HeapType *h) {

	if (h->heap_size == 0)
		return TRUE;
	else
		return FALSE;
}

void insert_min_heap(HeapType *h, element item) {

	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

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

int random(int n) {
	return (int)(n*rand() / (double)RAND_MAX);
}

// 자리가 가능하면 빈자리 수를 사람 수만큼 감소시킨다.
int is_seat_available(int number) {

	printf("%d명의 고객 도착\n", number);
	if (free_seats >= number) {
		free_seats -= number;
		return TRUE;
	}
	else {
		printf("자리가 없어서 떠남\n");
		return FALSE;
	}
}

// 주문을 받으면 순익을 나타내는 변수를 증가시킨다.
void order(int scoops) {

	printf("아이스크림 %d개 주문 받음\n", scoops);
	profit += 0.35 * scoops;
}

// 고객이 떠나면 빈자리 수를 증가시킨다.
void leave(int number) {

	printf("%d명이 매장을 떠남\n", number);
	free_seats += number;
}

// 이벤트 처리한다.
void process_event(HeapType *heap, element e) {

	int i = 0;
	element new_event;

	printf("현재 시간 = %d\n", e.key);
	switch (e.type) {
	case ARRIVAL:
		// 자리가 가능하면 주문 이벤트를 만든다
		if (is_seat_available(e.number)) {
			new_event.type = ORDER;
			new_event.key = e.key + 1 + random(4);
			new_event.number = e.number;
			insert_min_heap(heap, new_event);
		}
		break;
	case ORDER:
		// 사람 수만큼 주문을 받는다
		for (i = 0; i < e.number; i++) {
			order(1 + random(3));
		}
		//매장을 떠나는 이벤트를 생성한다
		new_event.type = LEAVE;
		new_event.key = e.key + 1 + random(10);
		new_event.number = e.number;
		insert_min_heap(heap, new_event);
		break;
	case LEAVE:
		// 고객이 떠나면 빈자리 수를 증가시킨다
		leave(e.number);
		break;
	}
}

// random 임에도 불구 하고 결과는 정해져 있으므로 현실상황에 반영하여 확장된 시뮬레이션을 만들어보라
// 랜덤이므로 매 번 다른 결과가 출력되어야 한다.

int main() {

	element event;
	HeapType heap;
	unsigned int t = 0;

	init(&heap);
	// 처음에 몇 개의 초기 이벤트를 생성시킨다
	while (t < 5) {
		t += random(6);
		event.type = ARRIVAL;
		event.key = t;
		event.number = 1 + random(4);
		insert_min_heap(&heap, event);
	}
	// 시뮬레이션을 수행한다
	while (!is_empty(&heap)) {
		event = delete_min_heap(&heap);
		process_event(&heap, event);
	}
	printf("전체 순이익은 =%f입니다\n", profit);
}