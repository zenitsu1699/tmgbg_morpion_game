#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

class Parent
{
    private:
        std::string s;
        std::vector<int> v;
        size_t z;

    public:
        Parent(const std::string &ss = "", const std::vector<int> &vv = {})
        {
            this->s = ss;
            this->v = vv;
            this->z = 5;
        };
        Parent &operator=(const Parent &other)
        {
            if ((this->s == other.s) && (this->v == other.v)
                && (this->z == other.z))
                return *this;
            
            this->s = other.s;
            this->v = other.v;
            this->z = other.z;
            return *this;
        };
        Parent(const Parent &other)
        {
            if ((this->s == other.s) && (this->v == other.v)
                && (this->z == other.z))
                return *this;
            
            this->s = other.s;
            this->v = other.v;
            this->z = other.z;
            return *this;
        };
        Parent(const Parent &&other)
        {
            
        };
        ~Parent();
};

int main()
{
    return 0;
}