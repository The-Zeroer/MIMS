// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

LinkList L = nullptr;

int InitList(LinkList& L)
{
	L = new LNode;
	L->next = nullptr;
	return 1;
}

int ReadGoods(LinkList& L)
{
	fstream file;
	file.open("goods.txt", ios::in | ios::app);
	if (!file)
	{
		return 0;
	}

	LinkList tp = L;
	goods data;
	file >> data.id >> data.name >> data.type >> data.price >> data.num >> data.descr;
	if (data.id == "")
	{
		return 1;
	}
	tp->next = new LNode;
	tp = tp->next;
	tp->data.id = data.id;
	tp->data.name = data.name;
	tp->data.type = data.type;
	tp->data.price = data.price;
	tp->data.num = data.num;
	tp->data.descr = data.descr;
	while (!file.eof())
	{
		tp->next = new LNode;
		tp = tp->next;
		file >> tp->data.id >> tp->data.name >> tp->data.type >> tp->data.price >> tp->data.num >> tp->data.descr;
		tp->next = nullptr;
	}
	file.close();
	return 1;
}