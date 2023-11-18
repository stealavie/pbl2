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
void Project::Field()
{
    char keyPressed;
    cout << "__Pham vi de tai: " << endl;
    cout << " ban hay lua chon de tai bang cach an ban phim cac so tuong ung:"<< endl;
    cout << "Linh vuc Nong nghiep: an phim 2" <<endl;
    cout << "Linh vuc Co khi:an phim 3" << endl;
    cout << "Linh vuc Y te: an phim 4";
    keyPressed = cin.get();
        

    switch (keyPressed) {
        case '1':
            cout << "CNTT" << endl;
                break;
        case '2':
                cout << "Nong nghiep" << endl;
                break;
        case '3':
                cout << "Co khi" << endl;
                break;
        case '4':
                cout << " y te" << endl;
                break;

        default:
                cout << "Phim khong duoc ho tro." << endl;
        break;
    }
}
void Project::Input()
{
   /*cout << "nhap ten du an:" << endl;
    getline(cin,this->name);
    cout << "muc tieu du an:" << endl;
    getline(cin,this->goal);
    cout << "von dau tu:";
    cin >> this->money;
    cin.ignore();*/
    cout << "nhap ten du an:" << endl;
    cin >> this->name;
    cout << "muc tieu du an:" << endl;
    cin >> this->goal;
    cout << "von dau tu:";
    cin >> this->money;
}

string Project::GetInfo() const
{
        stringstream ss;
        ss << "Ten du an: " << this->name << endl << "Muc tieu du an: " <<  this->goal << endl << "Von dau tu: " <<to_string(this->money) << endl;
        return ss.str();
}

void Project::Output()
{
        cout<<" Ten du an: " << this->name << endl;
        cout<<" Muc tieu: " << this->goal << endl;
        cout<<" Von dau tu: " << this->money << endl;
}
 

