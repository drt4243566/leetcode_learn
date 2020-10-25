#include <map>
#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    std::map<int, string> mapStudent;
    mapStudent.insert(std::pair<int, string>(000, "zero"));
    mapStudent.insert(std::map<int, string>::value_type(001, "one"));

    std::pair<std::map<int, string>::iterator, bool> Insert_pair;
    Insert_pair = mapStudent.insert(std::map<int, string>::value_type(002, "second"));
    if (!Insert_pair.second)
    {
        cout << "err" << std::endl;
    }

    std::map<int, string>::iterator iter = mapStudent.find(001);
}