#include "login.h"
using namespace std;
Login::Login(Data* data) : data(data)
{}

void Login::LoginSite()
{
	while (true)
	{
		string user, pass;
		x:
		cout << "Nhap email:";
		cin >> user;
		cout << "\nNhap mat khau:";
		cin >> pass;
		if (this->data == NULL)
		{
			cout << "\nKHONG TIM THAY TAI KHOAN";
			goto x;
		}
		else
		{
			if (this->data->checkAcc(user, pass) == true)
			{
				cout << "\nDang nhap thanh cong\n";
				break;
			}
			else cout << "\nKhong tim thay tai khoan\n";
		}
	}
}

Data Login::registerSite()
{
	while (true)
	{
		string user, pass;
	x:
		cout << "Nhap email:";
		cin >> user;
		cout << "\nNhap mat khau:";
		cin >> pass;
		if (this->data == NULL)
		{
			this->data->AddAccount(user, pass);
			
		}
		else
		{
			if (this->data->checkExist(user) == true)
			{
				cout << "\nTAI KHOAN DA TON TAI"
					<< "\nVUI LONG NHAP LAI\n";
				goto x;
			}
			else this->data->AddAccount(user,pass);
		}
		
	}
}