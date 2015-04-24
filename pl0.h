#ifndef PL0_H
#define PL0_H

#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define norw 13                          /*�ؼ��ָ���*/
#define noopt 9						     /*���������*/
#define nodel 5							 /*�������*/

typedef struct SYM_Link{
	string SYM;
	SYM_Link *next;
}SYMNODE,*SYMLink;

typedef struct ID_Link{
	string ID;
	ID_Link *next;
}IDNODE,*IDLink;

typedef struct NUM_Link{
	string NUM;
	NUM_Link *next;
}NUMNODE,*NUMLink;

typedef struct OPT_Link{
	string OPT;
	OPT_Link *next;
}OPTNODE,*OPTLink;

typedef struct DEL_Link{
	string DEL;
	DEL_Link *next;
}DELNODE,*DELLink;

void init();
bool isWORD(string ss);                  /*�ж��ַ����Ƿ�Ϊ������*/
bool isOPT(char ss);					 /*�ж��ַ��Ƿ�Ϊ�����*/
bool isDEL(char ss);					 /*�ж��ַ��Ƿ�Ϊ���*/
void GETSYM();                           /*�ʷ�����*/


bool readfile(int &num, string *line);   /*��ȡ�ļ�*/
bool isAlpha(char s);                    /*�ж��Ƿ�Ϊ��ĸ*/
bool isNum(char s);						 /*�ж��Ƿ�Ϊ����*/
bool isNeither(char s);                  /*�Ȳ�������Ҳ������ĸ*/

bool addSYM(string s);                   /*��ӱ����ַ�*/
bool addID(string s);                    /*����Զ����ʾ��*/    
bool addNUM(string s);                   /*�������*/
bool addDEL(string s);                   /*��ӽ��*/
bool addOPT(string s);                   /*��������*/

bool showSYM();                          /*��ʾ�����ַ�*/
bool showID();                           /*��ʾ�Զ����ʾ��*/
bool showNUM();                          /*��ʾ����*/
bool showDEL();                          /*��ʾ���*/
bool showOPT();							 /*��ʾ�����*/

#endif