#include"pl0.h"
using namespace std;

int main()
{
	init();
	GETSYM();
	
	cout<<"该程序词法分析结果如下："<<endl;
	cout<<"基本字有：";
	showSYM();
	cout<<endl<<"运算符有：";
	showOPT();
	cout<<endl<<"标示符有：";
	showID();
	cout<<endl<<"常数有：";
	showNUM();
	cout<<endl<<"界符有：";
	showDEL();
	cout<<endl;

	system("pause");
	return 1;
}