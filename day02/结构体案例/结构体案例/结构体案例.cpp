#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <ctime>
/*
* 案例
* 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
* 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
* 学生的成员有姓名、考试分数、创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
* 最终打印出老师数据以及老师所带的学生数据
*/


typedef struct Student
{
   std::string name;
   int score;
}stu;
typedef struct Teacher
{
    std::string name;
    stu st[5];
}teach;
void init(teach* p, int num);
void initStu(stu* p, int num);
void print(teach* p, int num);
int main()
{
    //随机数种子
    srand((unsigned int)time(NULL));
    teach arr[3];
    int len = sizeof(arr) / sizeof(arr[0]);
    init(arr, len);
    print(arr, len);
    std::cout << "Hello World!\n";
}

void init(teach* p, int num)
{
    std::string nameSeed= "ABCDE";
    for (int i = 0; i < num; i++)
    {
        p[i].name = "Teacher_";
        p[i].name += nameSeed[i];
        initStu(p[i].st,sizeof(p[i].st)/sizeof(p[i].st[0]));
       
    }
}

void initStu(stu* p, int num)
{
    std::string nameSeed = "ABCDE";
    for (int i = 0; i < num; i++)
    {
        p[i].name = "Student_";
        p[i].name += nameSeed[i];
        int random = rand() % 61 + 40;
        p[i].score = random;
    }
}
void print(teach* p, int num)
{
    for (int i = 0; i < num; i++)
    {
        std::cout << p[i].name<<std::endl;
        for (int j = 0; j < 5; j++)
        {
            std::cout <<"\t姓名"<< p[i].st[j].name<<"  成绩"<< p[i].st[j].score<<std::endl;
        }
        std::cout << std::endl;
    }
}