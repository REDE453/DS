#include"SeqList.h"

void TestSeqList()
{
	SeqList s;
	SeqListDataType* res = 0;
	SeqListInit(&s);

	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);


	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, 0);
	SeqListPrint(&s);


	SeqListPopBack(&s);
	SeqListPrint(&s);


	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 2, 10);
	SeqListPrint(&s);

	SeqListErase(&s, 2, 10);
	SeqListPrint(&s);

	SeqListRevise(&s, 0, -1);
	SeqListPrint(&s);

	SeqListDestory(&s);
}


int main()
{
	TestSeqList();
	return 0;
}