#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

struct file
{
    FILE *f;

    file(std::string const &s)
    {
        f = fopen(s.c_str(), "w");
    }

    void write(std::string const &s)
    {
        if (f != NULL)
        {
            fputs(s.c_str(), f);
        }
    }

    file(file const &) = delete;
    file &operator =(file &&f)= delete;

    file(file &&f2): f(f2.f) {f2.f = nullptr;}

    ~file(){
        fclose(f);
    }
};

int main()
{
    file f("test1.txt");
    f.write(" first string for test1 \n ");
    file g("test2.txt");
    g.write(" first string for test2 \n ");
    f.write(" second string for test1 \n ");
    return 0;
}
