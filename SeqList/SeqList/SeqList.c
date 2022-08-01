#include"SeqList.h"

void SeqListInit(SeqList* seq)                                      //初始化
{
	assert(seq);
	seq->arr = NULL;
	seq->size = seq->capacity = 0;
}

void SeqListDestory(SeqList* seq)                                //销毁
{
	assert(seq);
	free(seq->arr);
	seq->arr = NULL;
	seq->size = seq->capacity = 0;
}

void SeqListPrint(SeqList* seq)
{
	assert(seq);
	for (int i = 0; i < seq->size; ++i)
	{
		printf("%d ", seq->arr[i]);
	}
	printf("\n");
}

void SeqListCheckCapacity(SeqList* seq)
{
	if (seq->size == seq->capacity)                  //容量不够，扩容
	{
		int newcapacity = seq->capacity == 0 ? 4 : seq->capacity * 2;          //初始容量为0则默认开4空间容量不够扩容两倍
		SeqListDataType* newarr = realloc(seq->arr, sizeof(SeqListDataType)*newcapacity);
		if (newarr == NULL)                           //扩容失败
		{
			exit(-1);
		}
		seq->arr = newarr;
		seq->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, SeqListDataType x)      //尾插
{
	//SeqListInsert(seq, seq->size, x);
	assert(seq);
	SeqListCheckCapacity(seq);
	seq->arr[seq->size] = x;
	seq->size++;
}

void SeqListPushFront(SeqList* seq, SeqListDataType x)     //头插
{
	//SeqListInsert(seq, 0, x);
	assert(seq);
	SeqListCheckCapacity(seq);
	int end = seq->size - 1;
	while (end >= 0)
	{
		seq->arr[end + 1] = seq->arr[end];
		--end;
	}
	seq->arr[0] = x;
	seq->size++;
}

void SeqListPopBack(SeqList* seq)       //尾删
{
	assert(seq);
	assert(seq->size > 0);
	seq->size--;
}

void SeqListPopFront(SeqList* seq)      //头删
{
	assert(seq);
	assert(seq->size > 0);
	int begin = 0;
	while (begin < seq->size - 1)
	{
		seq->arr[begin] = seq->arr[begin + 1];
		begin++;
	}
	seq->size--;
}

int SeqListFind(SeqList* seq, SeqListDataType x)                 //查找
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* seq, int pos, SeqListDataType x)                 //插入
{
	assert(seq);
	assert(pos >= 0 && pos <= seq->size);
	SeqListCheckCapacity(seq);
	int end = seq->size - 1;
	while (end >= pos)
	{
		seq->arr[end + 1] = seq->arr[end];
		end--;
	}
	seq->arr[pos] = x;
	seq->size++;
}

void SeqListErase(SeqList* seq, int pos)                   //删除
{
	assert(seq);
	assert(pos >= 0 && pos < seq->size);
	int begin = pos;
	while (begin <= seq->size - 1)
	{
		seq->arr[begin] = seq->arr[begin + 1];
		begin++;
	}

	seq->size--;
}

void SeqListRevise(SeqList* seq, int pos, SeqListDataType x)                        //修改
{
	assert(seq);
	assert(pos >= 0 && pos < seq->size);
	seq->arr[pos] = x;
}
