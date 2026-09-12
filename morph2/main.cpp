#include <iostream>
#include <vector>
#include "morph2.h"

//打印矩阵
void printMat(const std::vector<std::vector<int>>& img)
{
    for (auto& row : img)
    {
        for (auto v : row)
        {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
    std::cout << "---------------------\n";
}

int main()
{
    //构造测试图，带孔洞方块
    std::vector<std::vector<int>> origin = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,0,0,0,0,0,1,0,0},
        {0,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    //5×5全1结构元
    Kernel se5;
    se5.width = 5;
    se5.height = 5;
    se5.data.assign(5, std::vector<int>(5, 1));

    Morphology mor;
    std::cout << "原始图像\n";
    printMat(origin);

    auto dilation1 = mor.dilate(origin, se5);
    std::cout << "dilation1：一次膨胀\n";
    printMat(dilation1);

    auto dilation2 = mor.dilate(dilation1, se5);
    std::cout << "dilation2：连续两次膨胀\n";
    printMat(dilation2);

    auto erode_img = mor.erode(dilation2, se5);
    std::cout << "腐蚀结果\n";
    printMat(erode_img);

    return 0;
}