#include"SeqList.h"

void SeqListInit(SeqList* seq)                                      //��ʼ��
{
	assert(seq);
	seq->arr = NULL;
	seq->size = seq->capacity = 0;
}

void SeqListDestory(SeqList* seq)                                //����
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
	if (seq->size == seq->capacity)                  //��������������
	{
		int newcapacity = seq->capacity == 0 ? 4 : seq->capacity * 2;          //��ʼ����Ϊ0��Ĭ�Ͽ�4�ռ�����������������
		SeqListDataType* newarr = realloc(seq->arr, sizeof(SeqListDataType)*newcapacity);
		if (newarr == NULL)                           //����ʧ��
		{
			exit(-1);
		}
		seq->arr = newarr;
		seq->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* seq, SeqListDataType x)      //β��
{
	//SeqListInsert(seq, seq->size, x);
	assert(seq);
	SeqListCheckCapacity(seq);
	seq->arr[seq->size] = x;
	seq->size++;
}

void SeqListPushFront(SeqList* seq, SeqListDataType x)     //ͷ��
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

void SeqListPopBack(SeqList* seq)       //βɾ
{
	assert(seq);
	assert(seq->size > 0);
	seq->size--;
}

void SeqListPopFront(SeqList* seq)      //ͷɾ
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

int SeqListFind(SeqList* seq, SeqListDataType x)                 //����
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

void SeqListInsert(SeqList* seq, int pos, SeqListDataType x)                 //����
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

void SeqListErase(SeqList* seq, int pos)                   //ɾ��
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

void SeqListRevise(SeqList* seq, int pos, SeqListDataType x)                        //�޸�
{
	assert(seq);
	assert(pos >= 0 && pos < seq->size);
	seq->arr[pos] = x;
}
