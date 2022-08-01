#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SeqListDataType;

typedef struct SeqList
{
	SeqListDataType* arr;
	int size;		         //有效数据个数
	int capacity;		    //容量
}SeqList;

void SeqListInit(SeqList* seq);                                        //初始化

void SeqListDestory(SeqList* seq);                                 //销毁

void SeqListPrint(SeqList* seq);                                      //输出

void SeqListCheckCapacity(SeqList* seq);                       //扩容

void SeqListPushBack(SeqList* seq, SeqListDataType x);      //尾插

void SeqListPushFront(SeqList* seq, SeqListDataType x);     //头插

void SeqListPopBack(SeqList* seq);       //尾删

void SeqListPopFront(SeqList* seq);      //头删

int SeqListFind(SeqList* seq, SeqListDataType x);                  //查找

void SeqListInsert(SeqList* seq, int pos, SeqListDataType x);  //插入

void SeqListErase(SeqList* seq, int pos);                                //删除

void SeqListRevise(SeqList* seq, int pos, SeqListDataType x);        //修改