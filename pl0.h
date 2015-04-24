#ifndef PL0_H
#define PL0_H

#include<iostream>
#include<string>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define norw 13                          /*关键字个数*/
#define noopt 9						     /*运算符个数*/
#define nodel 5							 /*界符个数*/

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
bool isWORD(string ss);                  /*判断字符串是否为保留字*/
bool isOPT(char ss);					 /*判断字符是否为运算符*/
bool isDEL(char ss);					 /*判断字符是否为界符*/
void GETSYM();                           /*词法分析*/


bool readfile(int &num, string *line);   /*读取文件*/
bool isAlpha(char s);                    /*判断是否为字母*/
bool isNum(char s);						 /*判断是否为数字*/
bool isNeither(char s);                  /*既不是数字也不是字母*/

bool addSYM(string s);                   /*添加保留字符*/
bool addID(string s);                    /*添加自定义标示符*/    
bool addNUM(string s);                   /*添加数字*/
bool addDEL(string s);                   /*添加界符*/
bool addOPT(string s);                   /*添加运算符*/

bool showSYM();                          /*显示保留字符*/
bool showID();                           /*显示自定义标示符*/
bool showNUM();                          /*显示数字*/
bool showDEL();                          /*显示界符*/
bool showOPT();							 /*显示运算符*/

#endif