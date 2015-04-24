#include"pl0.h"

string WORD[norw];
char OPT[noopt];
char DEL[nodel];

SYMLink symlink = new SYMNODE();
IDLink idlink = new IDNODE();
NUMLink numlink = new NUMNODE();
OPTLink optlink = new OPTNODE();
DELLink dellink = new DELNODE();

void init()
{
	/*
	设置保留字，运算符，界符
	*/
	WORD[0]="BEGIN";															
	WORD[1]="CALL";
	WORD[2]="CONST";
	WORD[3]="DO";
	WORD[4]="END";
	WORD[5]="IF";
	WORD[6]="ODD";
	WORD[7]="PROCEDURE";
	WORD[8]="READ";
	WORD[9]="THEN";
	WORD[10]="VAR";
	WORD[11]="WHILE";
	WORD[12]="WRITE";

	OPT[0]='+';
	OPT[1]='-';
	OPT[2]='*';
	OPT[3]='/';
	OPT[4]=':';
	OPT[5]='=';
	OPT[6]='<';
	OPT[7]='>';
	OPT[8]='#';

	DEL[0]=',';
	DEL[1]='.';
	DEL[2]=';';
	DEL[3]='(';
	DEL[4]=')';

	/*
	初始化链表
	*/
	symlink->SYM="";
		symlink->next=NULL;
	idlink->ID="", idlink->next=NULL;
	numlink->NUM="", numlink->next=NULL;
	optlink->OPT="", optlink->next=NULL;
	dellink->DEL="", dellink->next=NULL;
}

bool isWORD(string ss)
{
	int i = 0,j = norw,k;
	while(i <= j)
	{
		k = (i+j)/2;
		string word = WORD[k];
		if(ss.compare(word)<0)
			j = k - 1;
		if(ss.compare(word)==0)
			return true;
		if(ss.compare(word)>0)
			i = k + 1;
	}

	return false;
}

bool isOPT(char ss)
{
	int i = 0;
	for (int i = 0; i < noopt; i++)
		if(ss == OPT[i])
			return true;

	return false;
}

bool isDEL(char ss)
{
	int i = 0;
	for (int i = 0; i < noopt; i++)
		if(ss == DEL[i])
			return true;

	return false;
}

void GETSYM()
{
	int num;                                    /*控制行数*/
	string line[1000];		                    /*每行的源码*/
	string sym;									/*保留字缓冲区*/
	//string id;								/*自定义标示符缓冲区*/
	string opt;                                 /*运算符缓冲区*/
	string number;                              /*值缓冲区*/
	string del;                                 /*界符缓冲区*/

	readfile(num,line);

	sym= "",opt = "", number = "", del = "";              /*清空缓存区*/
	

	for (int i = 0; i < num; i++)
	{
		line[i] += '\0';
		for (int j = 0; line[i][j]!='\0'; j++)
		{
			if (isAlpha(line[i][j]))
			{
				if(del != "")
				{
					addDEL(del);
					del = "";
				}
				if(opt != "")
				{
					addOPT(opt);
					opt = "";
				}
				sym += line[i][j];
			}

			if (isNeither(line[i][j]))
			{
				if(sym != "")
				{
					if(isWORD(sym))
						addSYM(sym);
					else
						addID(sym);

					sym = "";
				}
				if(number != "")
				{
					addNUM(number);
					number = "";
				}
				if(isOPT( line[i][j] ))
				{
					if(del != "")
					{
						addDEL(del);
						del = "";
					}
					opt += line[i][j];
				}
				if(isDEL( line[i][j] ))
				{
					if(opt != "")
					{
						addOPT(opt);
						opt = "";
					}
					del += line[i][j];
				}
			}

			if (isNum(line[i][j]))
			{
				if(opt != "")
				{
					addOPT(opt);
					opt = "";
				}
				if(del != "")
				{
					addDEL(del);
					del = "";
				}
				if(sym != "")
					sym += line[i][j];
				else 
					number += line[i][j];
			}
		}
	}
}

bool readfile(int &num,string *line)
{
	ifstream file;
	file.open("C:\\pl0.txt");

	if(!file.good())
	{
		cout<<"文件打开失败！"<<endl;
		return false;
	}

	num = 0;
	while ( getline(file,line[num]) )
		num++;

	return true;
}

bool isAlpha(char s)
{
	if( s >= 'a' && s <= 'z'||s >='A' && s <= 'Z' || s=='_' )
		return true;
	return false;
}

bool isNum(char s)
{
	if( s >= '0' && s <= '9' )
		return true;
	return false;
}

bool isNeither(char s)
{
	if(!isAlpha(s) && !isNum(s))
		return true;
	return false;
}

bool addID(string s)
{
	IDLink p = idlink;
	while ( p->next!=NULL )
		p = p->next;

	IDLink newid = new IDNODE();
	newid -> ID = s;
	newid -> next = NULL;

	p -> next = newid;

	return true;
}

bool addNUM(string s)
{
	NUMLink p = numlink;
	while ( p->next!=NULL )
		p = p->next;

	NUMLink newnum = new NUMNODE();
	newnum -> NUM = s;
	newnum -> next = NULL;

	p -> next = newnum;

	return true;
}

bool addSYM(string s)
{
	SYMLink p = symlink;
	while ( p->next!=NULL )
		p = p->next;

	SYMLink newsym = new SYMNODE();
	newsym -> SYM = s;
	newsym -> next = NULL;

	p -> next = newsym;

	return true;
}

bool addDEL(string s)
{
	DELLink p = dellink;
	while ( p -> next!= NULL)
		p = p -> next;

	DELLink newdel = new DELNODE();
	newdel -> DEL = s;
	newdel -> next = NULL;

	p -> next =newdel;

	return true;
}

bool addOPT(string s)
{
	OPTLink p = optlink;
	while ( p ->next != NULL)
		p = p -> next;

	OPTLink newopt = new OPTNODE();
	newopt -> OPT = s;
	newopt -> next = NULL;

	p -> next = newopt;

	return true;
}

bool showSYM()
{
	SYMLink h = symlink -> next;
	while (h)
	{
		cout<<h -> SYM<<"   ";
		h = h ->next;
	}

	return true;
}

bool showID()
{
	IDLink h = idlink -> next;
	while (h)
	{
		cout<<h -> ID<<"   ";
		h = h ->next;
	}

	return true;
}   

bool showNUM()  
{
	NUMLink h = numlink -> next;
	while (h)
	{
		cout<<h -> NUM<<"   ";
		h = h ->next;
	}
	return true;
}

bool showDEL() 
{
	DELLink h = dellink -> next;
	while (h)
	{
		cout<< h -> DEL <<"   ";
		h = h ->next;
	}

	return true;
}

bool showOPT()
{
	OPTLink h = optlink -> next;
	while (h)
	{
		cout<<h -> OPT<<"   ";
		h = h ->next;
	}

	return true;
}
