// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头

#include "framework.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


typedef struct
{
	string id;
	string name;
	string type;
	double price = 0;
	int num = 0;
	string descr;
}goods;

typedef struct LNode
{
	goods data;
	struct LNode* next;
}LNode, * LinkList;



typedef struct
{
	string operate;
	string username;
	time_t time;
}opelog;

typedef struct LogLNode
{
	opelog data;
	struct LogLNode* next;
}LogLNode, * LogLinkList;



typedef struct
{
	string username;
	string passworld;
	string privilege;
	string reguser;
	time_t time;
}user;

typedef struct UserLNode
{
	user data;
	struct UserLNode* next;
}UserLNode, * UserLinkList;



extern LinkList L;
extern LogLinkList LogL;
extern UserLinkList UserL;
extern string UserName;
extern string Privilege;
extern int updateflag2;
extern int updateflag3;


//处理货物信息的函数
int InitList(LinkList& L);
int ReadGoods(LinkList& L);
int WriteGoods(LinkList L);
int AddGoods(LinkList& L, goods data);
int DelGoods(LinkList& L, goods data);
int AltGoods(LinkList& L, goods data,int choose);


//处理日志信息的函数
int InitLogList(LogLinkList& LogL);
int ReadLog(LogLinkList& LogL, string filename);
int WriteLog(string filename, opelog data, int flag);
string TimeToString(time_t time);


//处理用户信息的函数
int InitUserList(UserLinkList& UserL);
int ReadUser(UserLinkList& UserL);
int WriteUser(UserLinkList& UserL);
int AddUser(UserLinkList& UserL, user data);
int DelUser(UserLinkList& UserL, user data);
int AltUser(UserLinkList& UserL, user data,int flag);
int Login(UserLinkList& UserL, user data);
int ViewUserPrivilege(string Privilege, int flag);


#endif //PCH_H