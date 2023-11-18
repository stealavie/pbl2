#include"Person.h"
#include"Project.h"

class Founder
{
private:
    int m; // so nguoi
    int n; // So du an
    //string fname;
    string search;
    std::stringstream tempData;
    Person *persons; 
    Project *projects; 
public:
    Founder( int, int );
    ~Founder();
    //void Sapxep();
    //void Inputsearch()
    //bool searchProject(const string& search)const;
    void showProject(const string& search)const;
    void Input();
    void Output();
};
