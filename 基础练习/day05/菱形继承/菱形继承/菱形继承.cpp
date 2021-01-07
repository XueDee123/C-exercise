

#include <iostream>
#include"SheepTuo.h"

void Test()
{
    SheepTuo st;
    st.Sheep::age = 18;
    st.Tuo::age = 28;
    //当菱形继承时，两个父类拥有相同的数据，需要加作用域来区分
    std::cout << st.Sheep::age << std::endl;
    std::cout << st.Tuo::age << std::endl;
    
    //这份数据我们知道只有一份就可以，菱形继承导致数据有两份
    //在继承之前加上关键字virtual关键字变成虚继承
    //Animal类成为虚基类

    std::cout << st.age << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";
}

