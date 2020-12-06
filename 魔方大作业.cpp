// 魔方大作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

void function_1();
void function_2();
void function_3();
void function_4();
void function_5();
void function_6();
void function_7();
void function_8();
void function_9();
void function_10();

struct corner_pieces {
    char first_side;
    char second_side;
    char third_side;
};
void search_cube(char A, char B, char C)//寻找特定角块
{

}

//Step1  还原底面白色十字
//step1 将四个白色棱块转至顶部黄色块周围（回头实现）
//step2 将四个白色棱块转至底部
void step2()
{
    front_ckw();
    front_ckw();
    right_ckw();
    right_ckw();
    back_ckw();
    back_ckw();
    left_ckw();
    left_ckw();
}

//Step2 还原底层四个角块
//step1 

int main()
{
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
