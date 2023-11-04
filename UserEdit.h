#include"UserLogin.h"

class Profile
{
    private:
    UserLogin* user;
    public:
    Profile();
    ~Profile();
    void EditCountry(const std::string&, const std::string&, const std::string&);
};