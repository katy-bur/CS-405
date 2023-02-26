// QuestionableCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>


class C
{
    std::set<int> typedefs;
    bool is_type(int type) const
    {

        if (typedefs.find(type) != typedefs.end())
            return true;
        return false;
    }
};

class A
{
    int x;
    A(const A& other) = default;//adding default constructor
};
class MySpecialType
{
public:
    int MyVal = 1;

    void DontThrow() noexcept(false) //Removes noexcept specifier
    {
        throw "Ha! I threw anyway!";
    }
};

void foo(int** a)
{
    int b = 1;
    *a = &b;
}

void work_with_arrays(int count)
{
    int buf[10];
    if (count < 10) //Checks if count is less than 10
        buf[count] = 0;
}

void do_something_useless()
{
    int sum = 0;
    for (auto i = 0; i < 1000; ++i)
    {
        sum += i;
    }

    std::cout << "I summed up " << sum << " as the answer." << std::endl;
}

void vector_test()
{
    std::vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);
    std::vector<int>::iterator iter;
    for (iter = items.begin(); iter != items.end();) {  // Remove the increment of iter
        if (*iter == 2) {
            iter = items.erase(iter);  // Update the iterator after erase
        }
        else {
            ++iter;
        }
    }
}

int a;
bool my_function()
{
    a = 1 + 2;
    return a;
}

struct Token
{
    Token* next() { return nullptr; }
};

int foo(Token* tok)
{
    while (tok);
    tok = tok->next();

    return 0;
}

int main()
{
    std::vector<int> counts{ 1, 2, 3, 5 };
    int x = 0;
    int y = 0;
    int z = 0;

    std::cout << "Welcome to the Questionable Code Test!" << std::endl;

    //do_something_useless();

    work_with_arrays(10);

    assert(z = 2);

    //assert(my_function() == 3);

    try
    {
        int x = 5;
        int y = 5;
        int z = 5;
        std::cout << "x + y + z = " << (x + y + z) << std::endl;
    }
    catch (...)
    {

    }

    int* c;
    foo(&c);

    vector_test();

    MySpecialType myobject;
    std::cout << "myobject.MyVal = " << myobject.MyVal << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
