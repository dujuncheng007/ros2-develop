#pragma once
#include <vector>

//Ω·ππ‘™∫À
struct Kernel
{
    int width;
    int height;
    std::vector<std::vector<int>> data;
};

class Morphology
{
public:
    //≈Ú’Õ
    std::vector<std::vector<int>> dilate(const std::vector<std::vector<int>>& src, const Kernel& kernel);
    //∏Ø ¥
    std::vector<std::vector<int>> erode(const std::vector<std::vector<int>>& src, const Kernel& kernel);
}; 
