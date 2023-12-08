#include"Project.h"

Project::Project()
{
     this->name = "";  
     this->goal = "";
     this->money = 0.0;
}
Project::~Project()
{

}

void Project::Input()
 {
    cout << "nhap ten du an:" << endl;
    // su dung ham getline de nham chuoi dau cach;
    getline(cin, this->name);
    cout << "muc tieu du an:" << endl;
    getline(cin, this->goal);
    cout << "von dau tu:";
    cin >> this->money;
    cin.ignore();
}

string Project::GetInfo() const
{
        stringstream ss;
        ss  << this->name << "," <<  this->goal << ","<<to_string(this->money) << endl;
        return ss.str();
}
string Project::ReadInfo() const {
    stringstream ss;
    ss << "Ten du an: " << this->name << endl << "Muc tieu du an: " << this->goal << endl << "Von dau tu: " << to_string(this->money) << endl;
    return ss.str();
}
void Project::Output()
{
        cout<<" Ten du an: " << this->name << endl;
        cout<<" Muc tieu: " << this->goal << endl;
        cout<<" Von dau tu: " << this->money << endl;
}

