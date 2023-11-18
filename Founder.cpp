#include"Founder.h"
#include<string>

Founder::Founder(int m,int n) 
{
    this->m = m;
    this->n = n;
    persons = new Person[m];
    projects = new Project[n];
}

Founder::~Founder()
{
    delete[] persons;
    delete[] projects;
}


void Founder::Input()
{
    //cout << "Founder's_Name:" ;
    //cin >> fname;
    cout << "---Nhap thong tin thanh vien :" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "+ Thanh vien thu " << i + 1 << ":" << endl;
        persons[i].Input();
    }
    cout << "---Nhap thong tin du an :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "+ Du an thu " << i + 1 << ":" << endl;
        projects[i].Input();
    }//phan nay khong can thiet
      tempData << "Thong tin cac thanh vien :" << endl;
        for (int i = 0; i < m; i++) {
            tempData << "Thong tin thanh vien thu" << i + 1 << ":" << endl;
            tempData << persons[i].GetInfo() << endl;
        }
        tempData << "Thong tin du an :" << endl;
        for (int i = 0; i < n; i++) {
            tempData << "Thong tin du an thu" << i + 1 << ":" << endl;
            tempData << projects[i].GetInfo() << endl;
        }//
}
void Founder:: SaveToFile() {
        ofstream file("Data.txt", ios::app); 
        if (file.is_open()) {
            
            file << tempData.str();

            file.close(); 
        } else {
            cout << "Không thể mở tệp để ghi!" << endl;
        }
    }
    


/*void Founder::SaveToFile() {
    ofstream file("Data.txt",ios_base::app); 
    if (file.is_open()) {
        file << "Thong tin cac thanh vien :" << endl;
        for (int i = 0; i < m; i++) {
            file << "Thong tin thanh vien thu " << i + 1 << ":" << endl;
            file << persons[i].GetInfo() << endl;
        }

        file << "Thong tin du an :" << endl;
        for (int i = 0; i < n; i++) {
            file << "Thong tin du an thu " << i + 1 << ":" << endl;
             file << projects[i].GetInfo() << endl; 
        }

        file.close(); 
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
}*/
/*void Founder::Sapxep()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (projects[j].getMoney() < projects[j + 1].getMoney())
            {
                // Swap
                Project temp = projects[j];
                projects[j] = projects[j + 1];
                projects[j + 1] = temp;
            }
        }
    }
}*/
//void Founder::Inputsearch()
//{
//cout << "nhap thong tin tim kiem: " << endl;
  //  getline(cin,search);
//}



/*bool Founder::searchProject(const string& search) const 
{     
    for (int i = 0; i < n; i++)
    {
        if (projects[i].getName().find(search) != string::npos)
        {
            return true;
        }
    }
    return false;
}*/

void Founder::showProject(const string& search) const 
{
    bool found = false;
    //cout << "nhap thong tin tim kiem: " << endl;
    //getline(cin,search);

    for (int i = 0; i < n; i++)
    {
        if (projects[i].getName().find(search) != string::npos)
        {
            projects[i].Output();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay du an nao khop voi tu khoa: " << search << endl;
    }
}

void Founder::Output()
{   cout <<"___________________________________________"<<endl;
    cout << "Thong tin cac thanh vien (Person):" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Thong tin thanh vien thu:" << i + 1 << ":" << endl;
        persons[i].Output();
    }

    cout << "Thong tin du an (Project):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin du an thu: " << i + 1 << ":" << endl;
        projects[i].Output();
    }

   /* cout << "Danh sach du an sau khi sap xep theo money:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Du an: " << projects[i].getName() << ", Money: " << projects[i].getMoney() << endl;
    }*/
}




/*int main()
{
    int m, n;
    cout << "sl thanh vien (m): ";
    cin >> m;
    cout << "so luong du an (n): ";
    cin >> n;
    string search;
    cin >> search;

    Founder founder(m, n);
    founder.Input();
    Founder.showProject(search);
   

    return 0;
}*/
