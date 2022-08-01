#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int SeqListDataType;

typedef struct SeqList
{
	SeqListDataType* arr;
	int size;		         //��Ч���ݸ���
	int capacity;		    //����
}SeqList;

void SeqListInit(SeqList* seq);                                        //��ʼ��

void SeqListDestory(SeqList* seq);                                 //����

void SeqListPrint(SeqList* seq);                                      //���

void SeqListCheckCapacity(SeqList* seq);                       //����

void SeqListPushBack(SeqList* seq, SeqListDataType x);      //β��

void SeqListPushFront(SeqList* seq, SeqListDataType x);     //ͷ��

void SeqListPopBack(SeqList* seq);       //βɾ

void SeqListPopFront(SeqList* seq);      //ͷɾ

int SeqListFind(SeqList* seq, SeqListDataType x);                  //����

void SeqListInsert(SeqList* seq, int pos, SeqListDataType x);  //����

void SeqListErase(SeqList* seq, int pos);                                //ɾ��

void SeqListRevise(SeqList* seq, int pos, SeqListDataType x);        //�޸�