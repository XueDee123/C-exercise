/*
* 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
* 显示联系人：显示通讯录中所有联系人信息
* 删除联系人：按照姓名进行删除指定联系人
* 查找联系人：按照姓名查看指定联系人信息
* 修改联系人：按照姓名重新修改指定联系人
* 清空联系人：清空通讯录中所有信息
* 退出通讯录：退出当前使用的通讯录
*/


#include "AddressBook.h"

void test()
{
    int index=0;
    addbook ab;
    init(&ab);
    do
    {
        std::cout << "---------------------------------"<<std::endl;
        std::cout << "---------1.添加-------2.显示------" << std::endl;
        std::cout << "---------3.删除-------4.查找------" << std::endl;
        std::cout << "---------5.修改-------6.清空------" << std::endl;
        std::cout << "---------0.退出-------------------" << std::endl;
        std::cout << "---------请输入命令---------------" << std::endl;
        std::cin >> index;
        switch (index)
        {
        case 1:
            add(&ab);
            break;
        case 2:
            display(&ab);
            break;
        case 3:
            del(&ab);
            break;
        case 4:
            select(&ab);
            break;
        case 5:
            update(&ab);
            break;
        case 6:
            clear(&ab);
            break;
        case 0:
            std::cout << "退出" << std::endl;
            break;
        default:
            std::cout << "输入有误，请重新输入" << std::endl;
            break;
        }
    } 
    while (index);

}

int main()
{
    test();
    std::cout << "Hello World!\n";
}


