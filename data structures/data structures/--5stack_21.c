#include <stdio.h>


typedef int element;
element stack[max_top];
/*
�迭�� �̿��� ������ �������� ������ �����Ҷ� max_stack_size�� �����ؾ� �Ѵٴ� ���̴�. �� ������ �����ϴ� �Ѱ��� ����� max_top
�̶�� ������ �����Ͽ� ������ ������� ���� max_top�� 0���� �����ϰ�, ���� ���� �����߿� ���ο� ��Ҹ� �߰��� ������ ���� ������
max_top�� max_top*2+1�� �����ϰ� ����� ũ�⸸ŭ�� ������ �������� �Ҵ��Ͽ� ���ο� �迭�� �����. ��ҵ��� ���� �迭����
���ο� �迭�� ����ǰ� ���� �迭�� ��������. ����ϰ� ���� ���� ���� �߿� ��ҵ��� ������ �迭ũ���� 1/4�� �������� �Ǹ�
���� ũ���� ������ �迭�� �����ϰ� ���� ��ҵ��� �����Ѵ���, ������ �迭�� �����Ѵ�. �̽����� �����ϰ� �׽�Ʈ �϶�
1 -> 3 -> 7 -> 15 -> 31 -> 63  ... 
*/
typedef struct {
	element *stack;
	int top;
	int max_top;  //���� �迭�� ũ��
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