// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include "MD5.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

#pragma warning(disable : 4996)
string UserName = "0000000000";
string Privilege = "0000000000";
int updateflag2 = 0;
int updateflag3 = 0;


LinkList L = nullptr;
LogLinkList LogL = nullptr;
UserLinkList UserL = nullptr;


int InitList(LinkList& L)
{
	L = new LNode;
	L->next = nullptr;
	return 1;
}

int ReadGoods(LinkList& L)
{
	fstream infile;
	infile.open(".\\data\\goods.txt", ios::in);
	if (!infile)
	{
		return 0;
	}

	LinkList tp = L;
	goods data;
	infile >> data.id >> data.name >> data.type >> data.price >> data.num >> data.descr;
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
	tp->next = nullptr;
	while (!infile.eof())
	{
		tp->next = new LNode;
		tp = tp->next;
		infile >> tp->data.id >> tp->data.name >> tp->data.type >> tp->data.price >> tp->data.num >> tp->data.descr;
		tp->next = nullptr;
	}
	infile.close();
	return 1;
}

int WriteGoods(LinkList L)
{
	fstream outfile;
	outfile.open(".\\data\\goods.txt", ios::out);
	if (!outfile)
	{
		return 0;
	}
	else
	{
		LinkList tp = L->next;
		for (; tp; tp = tp->next)
		{
			outfile << tp->data.id << '\t' << tp->data.name << '\t' << tp->data.type << '\t' << tp->data.price << '\t' << tp->data.num << '\t' << tp->data.descr;
			if (tp->next)
			{
				outfile << '\n';
			}
		}
		return 1;
	}
}

int AddGoods(LinkList& L, goods data)
{
	LinkList tp = L;
	for (; tp->next; tp = tp->next)
	{
		if (data.id == tp->next->data.id || (data.name == tp->next->data.name && data.type == tp->next->data.type))
		{
			return 0;
		}
	}
	tp->next = new LNode;
	tp = tp->next;
	tp->data = data;
	tp->next = nullptr;
	return 1;
}

int DelGoods(LinkList& L, goods data)
{
	LinkList tp = L, temp = nullptr;
	for (; tp && tp->next; tp = tp->next)
	{
		if (tp->next->data.id == data.id && tp->next->data.name == data.name && tp->next->data.type == data.type)
		{
			temp = tp->next;
			tp->next = tp->next->next;
			delete temp;
			return 1;
		}
	}
	return 0;
}

int AltGoods(LinkList& L, goods data,int choose)
{
	switch (choose)
	{
	case 1:
		for (LinkList tp = L->next; tp; tp = tp->next)
		{
			if (tp->data.id == data.id)
			{
				tp->data.name = data.name;
				tp->data.type = data.type;
				tp->data.price = data.price;
				tp->data.descr = data.descr;
				return 1;
			}
		}



	case 2:
		for (LinkList tp = L->next; tp; tp = tp->next)
		{
			if (tp->data.id == data.id)
			{
				if (tp->data.num == data.num)
				{
					return 0;
				}
				tp->data.num = data.num;
				return 1;
			}
		}


	default:
		return 0;
	}
	return 0;
}



int InitLogList(LogLinkList& LogL)
{

	LogL = new LogLNode;
	LogL->next = nullptr;
	return 1;
}

int ReadLog(LogLinkList& LogL,string filename)
{
	fstream infile;
	string folderPath = ".\\data\\log\\" + filename + ".txt";
	infile.open(folderPath, ios::in);

	if (!infile)
	{
		return 0;
	}
	LogLinkList tp = LogL;
	while (!infile.eof())
	{
		tp->next = new LogLNode;
		tp = tp->next;
		infile >> tp->data.operate >> tp->data.username >> tp->data.time;
		tp->next = nullptr;
	}
	infile.close();
	return 1;
}

int WriteLog(string filename, opelog data, int flag)
{
	string folderPath = ".\\data\\log\\" + filename + ".txt";
	ofstream outfile;
	outfile.open(folderPath, ios::app);

	if (!outfile)
	{
		return 0;
	}
	if (flag)
	{
		outfile << '\n';
	}
	outfile << data.operate << '\t' << data.username << '\t' << data.time;
	outfile.close();
	return 1;
}

string TimeToString(time_t time)
{
	if (!time)
	{
		return "无记录时间";
	}
	string str;
	tm* tm_ = localtime(&time);
	int year, month, day, hour, minute, second;
	year = tm_->tm_year + 1900;
	month = tm_->tm_mon + 1;
	day = tm_->tm_mday;
	hour = tm_->tm_hour;
	minute = tm_->tm_min;
	second = tm_->tm_sec;
	str = to_string(year) + '/' + to_string(month) + '/' + to_string(day);
	if (month < 10)
	{
		str += ' ';
	}
	if (day < 10)
	{
		str += ' ';
	}
	str += "   ";
	str += to_string(hour);
	str += ':';
	if (minute < 10)
	{
		str += "0";
	}
	str += to_string(minute);
	str += ':';
	if (second < 10)
	{
		str += "0";
	}
	str += to_string(second);
	return str;
}



int InitUserList(UserLinkList& UserL)
{
	UserL = new UserLNode;
	UserL->next = nullptr;
	return 1;
}

int ReadUser(UserLinkList& UserL)
{
	fstream infile;
	infile.open(".\\data\\user.txt", ios::in);
	if (!infile)
	{
		return 0;
	}

	UserLinkList tp = UserL;
	user data;
	infile >> data.username >> data.password >> data.privilege >> data.reguser >> data.time;
	if (data.username == "")
	{
		return 1;
	}
	tp->next = new UserLNode;
	tp = tp->next;
	tp->data = data;
	tp->next = nullptr;
	while (!infile.eof())
	{
		tp->next = new UserLNode;
		tp = tp->next;
		infile >> tp->data.username >> tp->data.password >> tp->data.privilege >> tp->data.reguser >> tp->data.time;
		tp->next = nullptr;
	}
	infile.close();
	return 1;
}

int WriteUser(UserLinkList& UserL)
{
	fstream outfile;
	outfile.open(".\\data\\user.txt", ios::out);
	if (!outfile)
	{
		return 0;
	}
	else
	{
		UserLinkList tp = UserL->next;
		for (; tp; tp = tp->next)
		{
			outfile << tp->data.username << '\t' << tp->data.password << '\t' << tp->data.privilege << '\t' << tp->data.reguser << '\t' << tp->data.time;
			if (tp->next)
			{
				outfile << '\n';
			}
		}
		return 1;
	}
}

int AddUser(UserLinkList& UserL, user data)
{
	if (data.username == "Admin")
	{
		return 0;
	}

	UserLinkList tp = UserL;
	for (; tp->next; tp = tp->next)
	{
		if (data.username == tp->next->data.username)
		{
			return 0;
		}
	}

	data.password = MD5(data.password).toStr();

	tp->next = new UserLNode;
	tp = tp->next;
	tp->data = data;
	tp->next = nullptr;
	return 1;
}

int DelUser(UserLinkList& UserL, user data)
{
	UserLinkList tp = UserL, temp = nullptr;
	for (; tp && tp->next; tp = tp->next)
	{
		if (tp->next->data.username == data.username)
		{
			temp = tp->next;
			tp->next = tp->next->next;
			delete temp;
			return 1;
		}
	}
	return 0;
}

int AltUser(UserLinkList& UserL, user data,int flag)
{
	for (UserLinkList tp = UserL->next; tp; tp = tp->next)
	{
		if (tp->data.username == data.username)
		{
			if (flag)
			{
				data.password = MD5(data.password).toStr();
				tp->data.password = data.password;
				return 1;
			}
			else
			{
				tp->data.privilege = data.privilege;
				return 1;
			}
		}
	}
	return 0;
}

int Login(UserLinkList& UserL, user data, int flag)
{
	UserLinkList tp = UserL->next;
	if (!tp)
	{
		return 0;
	}

	if (!flag)
	{
		data.password = MD5(data.password).toStr();
	}

	for (; tp; tp = tp->next)
	{
		if (data.username == tp->data.username && data.password == tp->data.password)
		{
			UserName = data.username;
			Privilege = tp->data.privilege;
			return 1;
		}
	}
	return 0;
}

int ViewUserPrivilege(string Privilege, int flag)
{
	CString temp;
	temp = Privilege[flag - 1];
	return atoi(temp);
}