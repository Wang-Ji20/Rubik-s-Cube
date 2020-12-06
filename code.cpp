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

//== Global Variables ==//
char cube[6][3][3] = {0}; //表示魔方状态

//== Functions ==//
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

//== Main Function ==//
int main()
{
    int corres[] = {2, 4, 1, 3, 0, 5}; //按照前后左右上下来读入
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cin >> cube[corres[i]][j][k];
    dbg_show();
    front_ccw();
    dbg_show();
    return 0;
}