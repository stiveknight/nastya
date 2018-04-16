#include "MyForm.h"
//#include "BigInteger.h"
//#include "rsa.h"


//using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
//void Main(array<String^>^ args) {
void Main() {
	setlocale(LC_ALL, "Russian");

	//pair <pair<BI, BI>, pair<BI, BI>> keys = gen_keys();
	//pair<BI, BI> o_key = make_pair(keys.first.first, keys.first.second);
	//pair<BI, BI> s_key = make_pair(keys.second.first, keys.second.second);
	//string a= crypt(text, o_key);
	//cout << a << endl;


	//system("pause");
	//return;

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	nastya::MyForm form;
	Application::Run(%form);
}
//cthdth