// 魔方大作业.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/***********************************************************
 *            -----------
 *            |         |
 *            |   Up_0  |
 *            |         |
 * ------------------------------------------
 * |          |         |         |         |
 * |  Left_1  | Front_2 | Right_3 |  Back_4 |
 * |          |         |         |         |
 * ------------------------------------------
 *            |         |
 *            |  Down_5 |
 *            |         |
 *            -----------
 * 用cube[6][3][3]表示魔方状态, [6]代指六个面, 以如上方式对应   
 *                             [3][3]代指行列 |  [0][0]  [0][1]  [0][2]  |
 *                                           |  [1][0]  [1][1]  [1][2]  |
 *                                           |  [2][0]  [2][1]  [2][2]  |
 * 
 * R-红色  B-蓝色  Y-黄色  G-绿色  O-橙色  W-白色
 * *******************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

//== Global Variables and Structures ==//
char cube[6][3][3] = {0}; //表示魔方状态
struct edge_pieces{
    char face1;
    char face2;
    int face1_pos[6][3][3]={{{0}}};
    int face2_pos[6][3][3]={{{0}}};
};
struct corner_pieces {
    char face1;
    char face2;
    char face3;
    int face1_pos[6][3][3]={{{0}}};
    int face2_pos[6][3][3]={{{0}}};
    int face3_pos[6][3][3]={{{0}}};
};



// ==== Claim of Functions
void face_ckw(int face) ;
void face_ccw(int face) ;
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
//== Functions ==//

void search_corners(corner_pieces* corner)//寻找特定角块,
{//每个块的顺序：abc,acb,bac,bca,cab,cba
    if (cube[0][0][2] == (*corner).face1 && cube[4][0][0] == (*corner).face2 && cube[3][0][2] == (*corner).face3)//第一大种
    {
        (*corner).face1_pos[0][0][2] = 1;
        (*corner).face2_pos[4][0][0] = 1;
        (*corner).face3_pos[3][0][2] = 1;
    }
    else if (cube[0][0][2] == (*corner).face1 && cube[3][0][2] == (*corner).face2 && cube[4][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[0][0][2] = 1;
        (*corner).face2_pos[3][0][2] = 1;
        (*corner).face3_pos[4][0][0] = 1;
    }
    else if (cube[4][0][0] == (*corner).face1 && cube[0][0][2] == (*corner).face2 && cube[3][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[4][0][0] = 1;
        (*corner).face2_pos[0][0][2] = 1;
        (*corner).face3_pos[3][0][2] = 1;
    }
    else if (cube[4][0][0] == (*corner).face1 && cube[3][0][2] == (*corner).face2 && cube[0][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[4][0][0] = 1;
        (*corner).face2_pos[3][0][2] = 1;
        (*corner).face3_pos[0][0][2] = 1;
    }
    else if (cube[3][0][2] == (*corner).face1 && cube[0][0][2] == (*corner).face2 && cube[4][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[3][0][2] = 1;
        (*corner).face2_pos[0][0][2] = 1;
        (*corner).face3_pos[4][0][0] = 1;
    }
    else if (cube[3][0][2] == (*corner).face1 && cube[4][0][0] == (*corner).face2 && cube[0][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[3][0][2] = 1;
        (*corner).face2_pos[4][0][0] = 1;
        (*corner).face3_pos[0][0][2] = 1;
    }
    else if (cube[0][0][0] == (*corner).face1 && cube[4][0][2] == (*corner).face2 && cube[1][0][0] == (*corner).face3)//第二大种
    {
        (*corner).face1_pos[0][0][0] = 1;
        (*corner).face2_pos[4][0][2] = 1;
        (*corner).face3_pos[1][0][0] = 1;
    }
    else if (cube[0][0][0] == (*corner).face1 && cube[1][0][0] == (*corner).face2 && cube[4][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[0][0][0] = 1;
        (*corner).face2_pos[1][0][0] = 1;
        (*corner).face3_pos[4][0][2] = 1;
    }
    else if (cube[4][0][2] == (*corner).face1 && cube[0][0][0] == (*corner).face2 && cube[1][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[4][0][2] = 1;
        (*corner).face2_pos[0][0][0] = 1;
        (*corner).face3_pos[1][0][0] = 1;
    }
    else if (cube[4][0][2] == (*corner).face1 && cube[1][0][0] == (*corner).face2 && cube[0][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[4][0][2] = 1;
        (*corner).face2_pos[1][0][0] = 1;
        (*corner).face3_pos[0][0][0] = 1;
    }
    else if (cube[1][0][0] == (*corner).face1 && cube[0][0][0] == (*corner).face2 && cube[4][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[1][0][0] = 1;
        (*corner).face2_pos[0][0][0] = 1;
        (*corner).face3_pos[4][0][2] = 1;
    }
    else if (cube[1][0][0] == (*corner).face1 && cube[4][0][2] == (*corner).face2 && cube[0][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[1][0][0] = 1;
        (*corner).face2_pos[4][0][2] = 1;
        (*corner).face3_pos[0][0][0] = 1;
    }
    else if (cube[0][2][0] == (*corner).face1 && cube[1][0][2] == (*corner).face2 && cube[2][0][0] == (*corner).face3)//第三大种002、100、402
    {
        (*corner).face1_pos[0][2][0] = 1;
        (*corner).face2_pos[1][0][2] = 1;
        (*corner).face3_pos[2][0][0] = 1;
    }
    else if (cube[0][2][0] == (*corner).face1 && cube[2][0][0] == (*corner).face2 && cube[1][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[0][2][0] = 1;
        (*corner).face2_pos[2][0][0] = 1;
        (*corner).face3_pos[1][0][2] = 1;
    }
    else if (cube[1][0][2] == (*corner).face1 && cube[0][2][0] == (*corner).face2 && cube[2][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[1][0][2] = 1;
        (*corner).face2_pos[0][2][0] = 1;
        (*corner).face3_pos[2][0][0] = 1;
    }
    else if (cube[1][0][2] == (*corner).face1 && cube[2][0][0] == (*corner).face2 && cube[0][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[1][0][2] = 1;
        (*corner).face2_pos[2][0][0] = 1;
        (*corner).face3_pos[0][2][0] = 1;
    }
    else if (cube[2][0][0] == (*corner).face1 && cube[0][2][0] == (*corner).face2 && cube[1][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[2][0][0] = 1;
        (*corner).face2_pos[0][2][0] = 1;
        (*corner).face3_pos[1][0][2] = 1;
    }
    else if (cube[2][0][0] == (*corner).face1 && cube[1][0][2] == (*corner).face2 && cube[0][2][0] == (*corner).face3)
    {
    (*corner).face1_pos[2][0][0] = 1;
        (*corner).face2_pos[1][0][2] = 1;
        (*corner).face3_pos[0][2][0] = 1;
    }
    else if (cube[0][2][2] == (*corner).face1 && cube[2][0][2] == (*corner).face2 && cube[3][0][0] == (*corner).face3)//第四大种
    {
    (*corner).face1_pos[0][2][2] = 1;
        (*corner).face2_pos[2][0][2] = 1;
        (*corner).face3_pos[3][0][0] = 1;
    }
    else if (cube[0][2][2] == (*corner).face1 && cube[3][0][0] == (*corner).face2 && cube[2][0][2] == (*corner).face3)
    {
    (*corner).face1_pos[0][2][2] = 1;
    (*corner).face2_pos[3][0][0] = 1;
    (*corner).face3_pos[2][0][2] = 1;
    }
    else if (cube[3][0][0] == (*corner).face1 && cube[0][2][2] == (*corner).face2 && cube[2][0][2] == (*corner).face3)
    {
    (*corner).face1_pos[3][0][0] = 1;
    (*corner).face2_pos[0][2][2] = 1;
    (*corner).face3_pos[2][0][2] = 1;
    }
    else if (cube[3][0][0] == (*corner).face1 && cube[2][0][2] == (*corner).face2 && cube[0][2][2] == (*corner).face3)
    {
    (*corner).face1_pos[3][0][0] = 1;
    (*corner).face2_pos[2][0][2] = 1;
        (*corner).face3_pos[0][2][2] = 1;
    }
    else if (cube[2][0][2] == (*corner).face1 && cube[0][2][2] == (*corner).face2 && cube[3][0][0] == (*corner).face3)
    {
    (*corner).face1_pos[2][0][2] = 1;
    (*corner).face2_pos[0][2][2] = 1;
    (*corner).face3_pos[3][0][0] = 1;
    }
    else if (cube[2][0][2] == (*corner).face1 && cube[3][0][0] == (*corner).face2 && cube[0][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[2][0][2] = 1;
        (*corner).face2_pos[3][0][0] = 1;
        (*corner).face3_pos[0][2][2] = 1;
    }
    else if (cube[1][2][0] == (*corner).face1 && cube[4][2][2] == (*corner).face2 && cube[5][2][0] == (*corner).face3)//第五大种
    {
        (*corner).face1_pos[1][2][0] = 1;
        (*corner).face2_pos[4][2][2] = 1;
        (*corner).face3_pos[5][2][0] = 1;
    }
    else if (cube[1][2][0] == (*corner).face1 && cube[5][2][0] == (*corner).face2 && cube[4][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[1][2][0] = 1;
        (*corner).face2_pos[5][2][0] = 1;
        (*corner).face3_pos[4][2][2] = 1;
    }
    else if (cube[4][2][2] == (*corner).face1 && cube[1][2][0] == (*corner).face2 && cube[5][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[4][2][2] = 1;
        (*corner).face2_pos[1][2][0] = 1;
        (*corner).face3_pos[5][2][0] = 1;
    }
    else if (cube[4][2][2] == (*corner).face1 && cube[5][2][0] == (*corner).face2 && cube[1][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[4][2][2] = 1;
        (*corner).face2_pos[5][2][0] = 1;
        (*corner).face3_pos[1][2][0] = 1;
    }
    else if (cube[5][2][0] == (*corner).face1 && cube[1][2][0] == (*corner).face2 && cube[4][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[5][2][0] = 1;
        (*corner).face2_pos[1][2][0] = 1;
        (*corner).face3_pos[4][2][2] = 1;
    }
    else if (cube[5][2][0] == (*corner).face1 && cube[4][2][2] == (*corner).face2 && cube[1][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[5][2][0] = 1;
        (*corner).face2_pos[4][2][2] = 1;
        (*corner).face3_pos[1][2][0] = 1;
    }
    else if (cube[1][2][2] == (*corner).face1 && cube[2][2][0] == (*corner).face2 && cube[5][0][0] == (*corner).face3)//第六大种
    {
        (*corner).face1_pos[1][2][2] = 1;
        (*corner).face2_pos[2][2][0] = 1;
        (*corner).face3_pos[5][0][0] = 1;
    }
    else if (cube[1][2][2] = (*corner).face1 && cube[5][0][0] == (*corner).face2 && cube[2][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[1][2][2] = 1;
        (*corner).face2_pos[5][0][0] = 1;
        (*corner).face3_pos[2][2][0] = 1;
    }
    else if (cube[2][2][0] == (*corner).face1 && cube[1][2][2] == (*corner).face2 && cube[5][0][0] == (*corner).face3)
    {
        (*corner).face1_pos[2][2][0] = 1;
        (*corner).face2_pos[1][2][2] = 1;
        (*corner).face3_pos[5][0][0] = 1;
    }
    else if (cube[2][2][0] == (*corner).face1 && cube[5][0][0] == (*corner).face2 && cube[1][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[2][2][0] = 1;
        (*corner).face2_pos[5][0][0] = 1;
        (*corner).face3_pos[1][2][2] = 1;
    }
    else if (cube[5][0][0] == (*corner).face1 && cube[1][2][2] == (*corner).face2 && cube[2][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[5][0][0] = 1;
        (*corner).face2_pos[1][2][2] = 1;
        (*corner).face3_pos[2][2][0] = 1;
    }
    else if (cube[5][0][0] == (*corner).face1 && cube[2][2][0] == (*corner).face2 && cube[1][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[5][0][0] = 1;
        (*corner).face2_pos[2][2][0] = 1;
        (*corner).face3_pos[1][2][2] = 1;
    }
    else if (cube[2][2][2] == (*corner).face1 && cube[3][2][0] == (*corner).face2 && cube[5][0][2] == (*corner).face3)//第七大种002、100、402
    {
        (*corner).face1_pos[2][2][2] = 1;
        (*corner).face2_pos[3][2][0] = 1;
        (*corner).face3_pos[5][0][2] = 1;
    }
    else if (cube[2][2][2] == (*corner).face1 && cube[5][0][2] == (*corner).face2 && cube[3][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[2][2][2] = 1;
        (*corner).face2_pos[5][0][2] = 1;
        (*corner).face3_pos[3][2][0] = 1;
    }
    else if (cube[3][2][0] == (*corner).face1 && cube[2][2][2] == (*corner).face2 && cube[5][0][2] == (*corner).face3)
    {
        (*corner).face1_pos[3][2][0] = 1;
        (*corner).face2_pos[2][2][2] = 1;
        (*corner).face3_pos[5][0][2] = 1;
    }
    else if (cube[3][2][0] == (*corner).face1 && cube[5][0][2] == (*corner).face2 && cube[2][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[3][2][0] = 1;
        (*corner).face2_pos[5][0][2] = 1;
        (*corner).face3_pos[2][2][2] = 1;
    }
    else if (cube[5][0][2] == (*corner).face1 && cube[2][2][2] == (*corner).face2 && cube[3][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[5][0][2] = 1;
        (*corner).face2_pos[2][2][2] = 1;
        (*corner).face3_pos[3][2][0] = 1;
    }
    else if (cube[5][0][2] == (*corner).face1 && cube[3][2][0] == (*corner).face2 && cube[2][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[5][0][2] = 1;
        (*corner).face2_pos[3][2][0] = 1;
        (*corner).face3_pos[2][2][2] = 1;
    }
    else if (cube[3][2][2] == (*corner).face1 && cube[5][2][2] == (*corner).face2 && cube[4][2][0] == (*corner).face3)//第八大种
    {
        (*corner).face1_pos[3][2][2] = 1;
        (*corner).face2_pos[5][2][2] = 1;
        (*corner).face3_pos[4][2][0] = 1;
    }
    else if (cube[3][2][2] == (*corner).face1 && cube[4][2][0] == (*corner).face2 && cube[5][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[3][2][2] = 1;
        (*corner).face2_pos[4][2][0] = 1;
        (*corner).face3_pos[5][2][2] = 1;
    }
    else if (cube[4][2][0] == (*corner).face1 && cube[3][2][2] == (*corner).face2 && cube[5][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[4][2][0] = 1;
        (*corner).face2_pos[3][2][2] = 1;
        (*corner).face3_pos[5][2][2] = 1;
    }
    else if (cube[4][2][0] == (*corner).face1 && cube[5][2][2] == (*corner).face2 && cube[3][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[4][2][0] = 1;
        (*corner).face2_pos[5][2][2] = 1;
        (*corner).face3_pos[3][2][2] = 1;
    }
    else if (cube[5][2][2] == (*corner).face1 && cube[3][2][2] == (*corner).face2 && cube[4][2][0] == (*corner).face3)
    {
        (*corner).face1_pos[5][2][2] = 1;
        (*corner).face2_pos[3][2][2] = 1;
        (*corner).face3_pos[4][2][0] = 1;
    }
    else if (cube[5][2][2] == (*corner).face1 && cube[4][2][0] == (*corner).face2 && cube[3][2][2] == (*corner).face3)
    {
        (*corner).face1_pos[5][2][2] = 1;
        (*corner).face2_pos[4][2][0] = 1;
        (*corner).face3_pos[3][2][2] = 1;
    }
}

void search_edges(edge_pieces* edge)
{//寻找特定棱块
    if (cube[0][0][1] == (*edge).face1 && cube[4][0][1] == (*edge).face2)//第一种
    {
        (*edge).face1_pos[0][0][1] = 1;
        (*edge).face2_pos[4][0][1] = 1;
    }
    else if (cube[4][0][1] == (*edge).face1 && cube[0][0][1] == (*edge).face2)
    {
        (*edge).face1_pos[4][0][1] = 1;
        (*edge).face2_pos[0][0][1] = 1;
    }
    else if (cube[0][1][0] == (*edge).face1 && cube[1][0][1] == (*edge).face2)//第二种
    {
        (*edge).face1_pos[0][1][0] = 1;
        (*edge).face2_pos[1][0][1] = 1;
    }
    else if (cube[1][0][1] == (*edge).face1 && cube[0][1][0] == (*edge).face2)
    {
        (*edge).face1_pos[1][0][1] = 1;
        (*edge).face2_pos[0][1][0] = 1;
    }
    else if (cube[0][2][1] == (*edge).face1 && cube[2][0][1] == (*edge).face2)//第三种
    {
        (*edge).face1_pos[0][2][1] = 1;
        (*edge).face2_pos[2][0][1] = 1;
    }
    else if (cube[2][0][1] == (*edge).face1 && cube[0][2][1] == (*edge).face2)
    {
        (*edge).face1_pos[2][0][1] = 1;
        (*edge).face2_pos[0][2][1] = 1;
    }
    else if (cube[0][1][2] == (*edge).face1 && cube[3][0][1] == (*edge).face2)//第四种
    {
        (*edge).face1_pos[0][1][2] = 1;
        (*edge).face2_pos[3][0][1] = 1;
    }
    else if (cube[3][0][1] == (*edge).face1 && cube[0][1][2] == (*edge).face2)
    {
        (*edge).face1_pos[3][0][1] = 1;
        (*edge).face2_pos[0][1][2] = 1;
    }
    else if (cube[1][1][0] == (*edge).face1 && cube[4][1][2] == (*edge).face2)//第五种
    {
        (*edge).face1_pos[1][1][0] = 1;
        (*edge).face2_pos[4][1][2] = 1;
    }
    else if (cube[4][1][2] == (*edge).face1 && cube[1][1][0] == (*edge).face2)
    {
        (*edge).face1_pos[4][1][2] = 1;
        (*edge).face2_pos[1][1][0] = 1;
    }
    else if (cube[1][1][2] == (*edge).face1 && cube[2][1][0] == (*edge).face2)//第六种
    {
        (*edge).face1_pos[1][1][2] = 1;
        (*edge).face2_pos[2][1][0] = 1;
    }
    else if (cube[2][1][0] == (*edge).face1 && cube[1][1][2] == (*edge).face2)
    {
        (*edge).face1_pos[2][1][0] = 1;
        (*edge).face2_pos[1][1][2] = 1;
    }//检查至此
    else if (cube[2][1][2] == (*edge).face1 && cube[3][1][0] == (*edge).face2)//第七种
    {
        (*edge).face1_pos[2][1][2] = 1;
        (*edge).face2_pos[3][1][0] = 1;
    }
    else if (cube[3][1][0] == (*edge).face1 && cube[2][1][2] == (*edge).face2)
    {
        (*edge).face1_pos[3][1][0] = 1;
        (*edge).face2_pos[2][1][2] = 1;
    }
    else if (cube[3][1][2] == (*edge).face1 && cube[4][1][0] == (*edge).face2)//第八种
    {
        (*edge).face1_pos[3][1][2] = 1;
        (*edge).face2_pos[4][1][0] = 1;
    }
    else if (cube[4][1][0] == (*edge).face1 && cube[3][1][2] == (*edge).face2)
    {
        (*edge).face1_pos[4][1][0] = 1;
        (*edge).face2_pos[3][1][2] = 1;
    }
    else if (cube[1][2][1] == (*edge).face1 && cube[5][1][0] == (*edge).face2)//第九种
    {
        (*edge).face1_pos[1][2][1] = 1;
        (*edge).face2_pos[5][1][0] = 1;
    }
    else if (cube[5][1][0] == (*edge).face1 && cube[1][2][1] == (*edge).face2)
    {
        (*edge).face1_pos[5][1][0] = 1;
        (*edge).face2_pos[1][2][1] = 1;
    }
    else if (cube[2][2][1] == (*edge).face1 && cube[5][0][1] == (*edge).face2)//第十种
    {
        (*edge).face1_pos[2][2][1] = 1;
        (*edge).face2_pos[5][0][1] = 1;
    }
    else if (cube[5][0][1] == (*edge).face1 && cube[2][2][1] == (*edge).face2)
    {
        (*edge).face1_pos[5][0][1] = 1;
        (*edge).face2_pos[2][2][1] = 1;
    }
    else if (cube[3][2][1] == (*edge).face1 && cube[5][1][2] == (*edge).face2)//第十一种
    {
    (*edge).face1_pos[3][2][1] = 1;
    (*edge).face2_pos[5][1][2] = 1;
    }
    else if (cube[5][1][2] == (*edge).face1 && cube[3][2][1] == (*edge).face2)
    {
    (*edge).face1_pos[5][1][2] = 1;
    (*edge).face2_pos[3][2][1] = 1;
    }
    else if (cube[4][2][1] == (*edge).face1 && cube[5][2][1] == (*edge).face2)//第十二种
    {
        (*edge).face1_pos[4][2][1] = 1;
        (*edge).face2_pos[5][2][1] = 1;
    }
    else if (cube[5][2][1] == (*edge).face1 && cube[4][2][1] == (*edge).face2)
    {
    (*edge).face1_pos[5][2][1] = 1;
    (*edge).face2_pos[4][2][1] = 1;
    }
}


void face_ckw(int face) //简化旋转函数的两个函数
{
    int tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = cube[face][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[face][i][j] = tmp[2 - j][i];
}
void face_ccw(int face)
{
    int tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[i][j] = cube[face][i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[face][i][j] = tmp[j][2 - i];
}

void up_ckw() //顺时针,下同
{
    face_ckw(0);
    char f[3] = {0};
    for (int i = 0; i < 3; i++)
        f[i] = cube[2][0][i];
    for (int i = 0; i < 3; i++)
    {
        cube[2][0][i] = cube[3][0][i];
        cube[3][0][i] = cube[4][0][i];
        cube[4][0][i] = cube[1][0][i];
        cube[1][0][i] = f[i];
    }
}
void up_ccw() //逆时针,下同
{
    face_ccw(0);
    char f[3] = {0};
    for (int i = 0; i < 3; i++)
        f[i] = cube[2][0][i];
    for (int i = 0; i < 3; i++)
    {
        cube[2][0][i] = cube[1][0][i];
        cube[1][0][i] = cube[4][0][i];
        cube[4][0][i] = cube[3][0][i];
        cube[3][0][i] = f[i];
    }
}
void left_ckw()
{
    face_ckw(1);
    char u[3] = {0};
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][i][0];
    for (int i = 0; i < 3; i++)
    {
        cube[0][i][0] = cube[4][2 - i][2];
        cube[4][2 - i][2] = cube[5][i][0];
        cube[5][i][0] = cube[2][i][0];
        cube[2][i][0] = u[i];
    }
}
void left_ccw()
{
    face_ccw(1);
    char u[3] = {0};
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][i][0];
    for (int i = 0; i < 3; i++)
    {
        cube[0][i][0] = cube[2][i][0];
        cube[2][i][0] = cube[5][i][0];
        cube[5][i][0] = cube[4][2 - i][2];
        cube[4][2 - i][2] = u[i];
    }
    
}
void front_ckw()
{
    face_ckw(2);
    char u[3];
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][2][i];
    for (int i = 0; i < 3; i++)
    {
        cube[0][2][i] = cube[1][2 - i][2];
        cube[1][2 - i][2] = cube[5][0][2 - i];
        cube[5][0][2 - i] = cube[3][i][0];
        cube[3][i][0] = u[i];
    }
}
void front_ccw()
{
    face_ccw(2);
    char u[3];
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][2][i];
    for (int i = 0; i < 3; i++)
    {
        cube[0][2][i] = cube[3][i][0];
        cube[3][i][0] = cube[5][0][2 - i];
        cube[5][0][2 - i] = cube[1][2 - i][2];
        cube[1][2 - i][2] = u[i];
    }
}
void right_ckw()
{
    char u[3] = {0};
    face_ckw(3);
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][i][2];
    for (int i = 0; i < 3; i++)
    {
        cube[0][i][2] = cube[2][i][2];
        cube[2][i][2] = cube[5][i][2];
        cube[5][i][2] = cube[4][2 - i][0];
        cube[4][2 - i][0] = u[i];
    }
}
void right_ccw()
{
    char u[3] = {0};
    face_ccw(3);
    for (int i = 0; i < 3; i++)
        u[i] = cube[0][i][2];
    for (int i = 0; i < 3; i++)
    {
        cube[0][i][2] = cube[4][2 - i][0];
        cube[4][2 - i][0] = cube[5][i][2];
        cube[5][i][2] = cube[2][i][2];
        cube[2][i][2] = u[i];
    }
}
void back_ckw()
{
    char r[3] = {0};
    face_ckw(4);
    for (int i = 0; i < 3; i++)
        r[i] = cube[3][i][2];
    for (int i = 0; i < 3; i++)
    {
        cube[3][i][2] = cube[5][2][2 - i];
        cube[5][2][2 - i] = cube[1][2 - i][0];
        cube[1][2 - i][0] = cube[0][0][i];
        cube[0][0][i] = r[i];
    }
}
void back_ccw()
{
    char r[3] = {0};
    face_ccw(4);
    for (int i = 0; i < 3; i++)
        r[i] = cube[3][i][2];
    for (int i = 0; i < 3; i++)
    {
        cube[3][i][2] = cube[0][0][i];
        cube[0][0][i] = cube[1][2 - i][0];
        cube[1][2 - i][0] = cube[5][2][2 - i];
        cube[5][2][2 - i] = r[i]; //TODO
    }
}
void down_ckw()
{
    char f[3] = {0};
    face_ckw(5);
    for (int i = 0; i < 3; i++)
        f[i] = cube[2][2][i];
    for (int i = 0; i < 3; i++)
    {
        cube[2][2][i] = cube[1][2][i];
        cube[1][2][i] = cube[4][2][i];
        cube[4][2][i] = cube[3][2][i];
        cube[3][2][i] = f[i];
    }
}
void down_ccw()
{
    char f[3] = {0};
    face_ccw(5);
    for (int i = 0; i < 3; i++)
        f[i] = cube[2][2][i];
    for (int i = 0; i < 3; i++)
    {
        cube[2][2][i] = cube[3][2][i];
        cube[3][2][i] = cube[4][2][i];
        cube[4][2][i] = cube[1][2][i];
        cube[1][2][i] = f[i];
    }
}

void dbg_show() //展示魔方当前状态,debug用
{
    cout << "        =========" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "        | ";
        for (int j = 0; j < 3; j++)
            cout << cube[0][i][j] << " ";
        cout << '|' << endl;
    }
    cout << "=================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int k = 1; k <= 4; k++)
        {
            for (int j = 0; j < 3; j++)
                cout << cube[k][i][j] << " ";
            cout << "| ";
        }
        cout << endl;
    }
    cout << "=================================" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "        | ";
        for (int j = 0; j < 3; j++)
            cout << cube[5][i][j] << " ";
        cout << '|' << endl;
    }
    cout << "        =========" << endl;
}

void (*op[12])() = {up_ckw, left_ckw, front_ckw, right_ckw, back_ckw, down_ckw,
                    up_ccw, left_ccw, front_ccw, right_ccw, back_ccw, down_ccw}; //op[i], 0<=i<=5顺时针, 6<=i<=11逆时针, 按照上左前右后下顺序

/*
1.还原底部十字
2.还原底部角块
3.解决中间层
4.还原顶部十字
5.还原顶部角块
6 让顶部全是相同颜色
7 让顶部角块正确
8 让顶部棱块正确

12一个人 3，找角块，找棱块一个人 5678一个人

*/

void function_1()   //一个用于还原顶面十字的函数
{
    front_ckw();
    right_ckw();
    up_ckw();
    right_ccw();
    up_ccw();
    front_ccw();
}

void function_2()   //一个用于还原顶面角的函数
{
    right_ckw();
    up_ckw();
    right_ccw();
    up_ckw();
    right_ckw();
    up_ckw();
    up_ckw();
    right_ccw();
}

void function_3_1()//see from left(公式2)//ok
{
    front_ckw(); up_ckw(); up_ckw(); front_ccw(); up_ckw(); front_ckw(); up_ckw(); up_ckw();
    front_ccw(); up_ckw(); left_ccw(); up_ccw(); left_ckw();
}
void function_3_2()//see from front//ok
{
    right_ckw(); up_ckw(); up_ckw(); right_ccw(); up_ckw(); right_ckw(); up_ckw(); up_ckw();
    right_ccw(); up_ckw(); front_ccw(); up_ccw(); front_ckw();
}
void function_3_3()//see from right\\ok
{
    back_ckw(); up_ckw(); up_ckw(); back_ccw(); up_ckw(); back_ckw(); up_ckw(); up_ckw();
    back_ccw(); up_ckw(); right_ccw(); up_ccw(); right_ckw();
}
void function_3_4()//see from back//ok
{
    left_ckw(); up_ckw(); up_ckw(); left_ccw(); up_ckw(); left_ckw(); up_ckw(); up_ckw();
    left_ccw(); up_ckw(); back_ccw(); up_ccw(); back_ckw();
}
void function_4_1()//see from left(公式3)//ok
{
    up_ckw(); front_ckw(); up_ccw(); front_ccw();
    up_ccw(); left_ccw(); up_ckw(); left_ckw();
}
void function_4_2()//see from front//ok
{
    up_ckw(); right_ckw(); up_ccw(); right_ccw();
    up_ccw(); front_ccw(); up_ckw(); front_ckw();
}
void function_4_3()//see from right\\ok
{
    up_ckw(); back_ckw(); up_ccw(); back_ccw();
    up_ccw(); right_ccw(); up_ckw(); right_ckw();
}
void function_4_4()//see from back//ok
{
    up_ckw(); left_ckw(); up_ccw(); left_ccw();
    up_ccw(); back_ccw(); up_ckw(); back_ckw();
}
void function_5_1()//see from left(公式4)//其余函数ccw与ckw均需修改
{
    front_ccw();   up_ccw();   front_ccw();   up_ccw();    front_ccw();  
    up_ckw();   front_ckw();   up_ckw();   front_ckw();
}
void function_5_2()//see from front\\ok
{
    right_ccw(); up_ccw(); right_ccw(); up_ccw(); right_ccw();
    up_ckw(); right_ckw(); up_ckw(); right_ckw();
}
void function_5_3()//see from right//ok
{
    back_ccw(); up_ccw(); back_ccw(); up_ccw(); back_ccw();
    up_ckw(); back_ckw(); up_ckw(); back_ckw();
}
void function_5_4()//see from back\\ok
{
    left_ccw(); up_ccw(); left_ccw(); up_ccw(); left_ccw();
    up_ckw(); left_ckw(); up_ckw(); left_ckw();
}


void step1(){
    char colorOftheBottom;
    colorOftheBottom =cube[5][2][2];
    while(cube[5][0][1]!=colorOftheBottom && cube[5][2][1]!=colorOftheBottom
    && cube[5][1][1]!=colorOftheBottom && cube[5][2][1]!=colorOftheBottom
    && cube[1][2][1]!=cube[1][1][1] && cube[2][2][1]!=cube[2][1][1]
    && cube[3][2][1]!=cube[3][1][1] && cube[4][2][1]!=cube[4][1][1]){
        if(cube[2][2][1]!=cube[2][1][1] || cube[5][0][1]!=colorOftheBottom){
            edge_pieces front= {colorOftheBottom,cube[2][1][1],-1,-1};
            search_edges(&front);
        }
        else if(cube[4][2][1]!=cube[4][1][1] || cube[5][2][1]!=colorOftheBottom){
            edge_pieces back= {colorOftheBottom,cube[2][1][1],-1,-1};
            search_edges(&back);
        }
        else if(cube[3][2][1]!=cube[3][1][1] || cube[5][2][0]!=colorOftheBottom){
            edge_pieces right= {colorOftheBottom,cube[2][1][1],-1,-1};
            search_edges(&right);
        }
        else if(cube[1][2][1]!=cube[1][1][1] || cube[5][1][0]!=colorOftheBottom){
            edge_pieces left= {colorOftheBottom,cube[2][1][1],-1,-1};
            search_edges(&left);
        }
    }
}


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

void step3(char a, char b, char c, char d, char e, char f)//  还原中间棱块 ,将6个面中心块具体颜色输入                                                   
{
    edge_pieces A = { b,c,{{{0}}},{{{0}}} };//先写一种，其余同理
    edge_pieces B = { c,d,{{{0}}},{{{0}}} };
    edge_pieces C = { d,e,{{{0}}},{{{0}}} };
    edge_pieces D = { e,b,{{{0}}},{{{0}}} };
    search_edges(&A);
    if (A.face1_pos[2][1][0] == 1 && A.face2_pos[1][1][2] == 1)
        function_3_1();
    else if(!(A.face2_pos[2][1][0] == 1 && A.face1_pos[1][1][2] == 1))
    {
        while (!((A.face1_pos[1][0][1] == 1 && A.face2_pos[0][1][0] == 1) || (A.face1_pos[0][2][1] == 1 && A.face2_pos[2][0][1] == 1)))
        {
            up_ckw();
            search_edges(&A);
        }
        if (A.face1_pos[1][0][1] == 1 && A.face2_pos[0][1][0] == 1)
            function_4_1();
        else if (A.face1_pos[0][2][1] == 1 && A.face2_pos[2][0][1] == 1)
            function_5_1();
    }
    dbg_show();
    search_edges(&B);
    if (B.face1_pos[3][1][0] == 1 && B.face2_pos[2][1][2] == 1)
        function_3_2();
    else if(!(B.face2_pos[3][1][0] == 1 && B.face1_pos[2][1][2] == 1))
    {
        while (!((B.face1_pos[2][0][1] == 1 && B.face2_pos[0][2][1] == 1) || (B.face1_pos[0][1][2] == 1 && B.face2_pos[3][0][1] == 1)))
        {
            up_ckw();
            search_edges(&B);
        }
        if (B.face1_pos[2][0][1] == 1 && B.face2_pos[0][2][1] == 1)
            function_4_2();
        else if (B.face1_pos[0][1][2] == 1 && B.face2_pos[3][0][1] == 1)
            function_5_2();
    }
    dbg_show();
    search_edges(&C);
    if (C.face1_pos[4][1][0] == 1 && C.face2_pos[3][1][2] == 1)
        function_3_3();
    else if(!(C.face2_pos[4][1][0] == 1 && C.face1_pos[3][1][2] == 1))
    {
        while (!((C.face1_pos[3][0][1] == 1 && C.face2_pos[0][1][2] == 1) || (C.face1_pos[0][0][1] == 1 && C.face2_pos[4][0][1] == 1)))
        {
            up_ckw();
            search_edges(&C);
        }
        if (C.face1_pos[3][0][1] == 1 && C.face2_pos[0][1][2] == 1)
            function_4_3();
        else if (C.face1_pos[0][0][1] == 1 && C.face2_pos[4][0][1] == 1)
            function_5_3();
    }
    dbg_show();
    search_edges(&D);
    if (D.face1_pos[1][1][0] == 1 && D.face2_pos[4][1][2] == 1)
        function_3_4();
    else if(!(D.face2_pos[1][1][0] == 1 && D.face1_pos[4][1][2] == 1))
    {
        while (!((D.face1_pos[4][0][1] == 1 && D.face2_pos[0][0][1] == 1) || (D.face1_pos[0][1][0] == 1 && D.face2_pos[1][0][1] == 1)))
        {
            up_ckw();
            search_edges(&D);
        }
        if (D.face1_pos[4][0][1] == 1 && D.face2_pos[0][0][1] == 1)
            function_4_4();
        else if (D.face1_pos[0][1][0] == 1 && D.face2_pos[1][0][1] == 1)
            function_5_4();
    }
    dbg_show();
}

void step4() //顶部十字
{
    while (!(cube[0][0][1] == cube[0][1][1] && cube[0][1][0] == cube[0][1][1] && cube[0][2][1] == cube[0][1][1] && cube[0][1][2] == cube[0][1][1]))
    {
        if (cube[0][1][1] == cube[0][2][1])
            up_ckw();
        else
            function_1();
    }
}

void step5()  //顶面角
{
    while (cube[0][0][0] != cube[0][1][1] || cube[0][2][0] != cube[0][1][1] || cube[0][2][0] != cube[0][1][1] || cube[0][2][2] != cube[0][1][1])
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (cube[0][i][j] == cube[0][1][1])
                    cnt++;
        if (cnt == 6)
        {
            while (cube[0][2][0] != cube[0][1][1])
            {
                up_ckw();
            }
            function_2();
        }
        if (cnt == 7)
        {
            while (cube[2][0][0] != cube[0][1][1])
            {
                up_ckw();
            }
            function_2();
        }
        if (cnt == 5)
        {
            while (cube[1][0][0] != cube[0][1][1] || cube[1][0][2] != cube[0][1][1])
            {
                up_ckw();
            }
            function_2();
        }
    }
}

void step6(){

}

void step7(){

}
void step8(){

}
//== Main Function ==//
int main()
{
    int corres[] = {2, 4, 1, 3, 0, 5}; //按照前后左右上下来读入
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cin >> cube[corres[i]][j][k];
    char A=cube[0][1][1],B=cube[1][1][1],C=cube[2][1][1],D=cube[3][1][1],E=cube[4][1][1],F=cube[5][1][1];//指示6个面中心面块颜色
    dbg_show();
    step4();
    step5();
    dbg_show();
    return 0;
}