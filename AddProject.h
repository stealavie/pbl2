#include "Project.h"
#include <fstream>

class AddProject {
private:
    Project project;

public:
    AddProject();
    ~AddProject();
    void Add();
    void WriteToCSV(const string& filename) const;
};