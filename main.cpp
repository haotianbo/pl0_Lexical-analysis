#include"pl0.h"
using namespace std;

int main()
{
	init();
	GETSYM();
	
	cout<<"�ó���ʷ�����������£�"<<endl;
	cout<<"�������У�";
	showSYM();
	cout<<endl<<"������У�";
	showOPT();
	cout<<endl<<"��ʾ���У�";
	showID();
	cout<<endl<<"�����У�";
	showNUM();
	cout<<endl<<"����У�";
	showDEL();
	cout<<endl;

	system("pause");
	return 1;
}