#include <iostream>

namespace TestNamespace
{
    class MyClass
    {
        private:
            static const int no_of_employees;
            int mAge;

            

        public:
            MyClass();
            MyClass(int age);
            ~MyClass();

            virtual void absmethod() = 0;

            void someMeth() const;
            void other();
            const MyClass operator + (const MyClass & ob);

            int sub(int a, int b);
    };

    int add(int a, int b);
}