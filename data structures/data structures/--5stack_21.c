#include <stdio.h>


typedef int element;
element stack[max_top];
/*
배열을 이용한 스택의 문제점은 스택을 생성할때 max_stack_size를 결정해야 한다는 점이다. 이 결점을 보완하는 한가지 방법은 max_top
이라는 변수를 도입하여 스택이 만들어질 때는 max_top을 0으로 시작하고, 만약 삽입 연산중에 새로운 요소를 추가할 공간이 없을 때에는
max_top을 max_top*2+1로 변경하고 변경된 크기만큼의 공간을 동적으로 할당하여 새로운 배열을 만든다. 요소들은 이전 배열에서
새로운 배열로 복사되고 이전 배열은 지워진다. 비슷하게 만약 삭제 연산 중에 요소들의 개수가 배열크기의 1/4로 떨어지게 되면
기존 크기의 절반인 배열을 생성하고 이전 요소들을 복사한다음, 이전의 배열을 삭제한다. 이스택을 구현하고 테스트 하라
1 -> 3 -> 7 -> 15 -> 31 -> 63  ... 
*/
typedef struct {
	element *stack;
	int top;
	int max_top;  //현재 배열의 크기
}Rstacktype;

element push(Rstacktype *kan, element item, element a[])
{
	kan->max_top = 0;
	kan->stack = a[(kan->max_top)*2+1];
	kan->top = 1;
}


int main(int argc, char* argv[])
{

}