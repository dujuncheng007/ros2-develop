#include "morph2.h"
#include <vector>

std::vector<std::vector<int>> Morphology::dilate(const std::vector<std::vector<int>>& src, const Kernel& kernel)
{
    int rows = src.size();
    int cols = src[0].size();
    std::vector<std::vector<int>> dst(rows, std::vector<int>(cols, 0));

    int k_h = kernel.height;
    int k_w = kernel.width;
    int offset_y = k_h / 2;
    int offset_x = k_w / 2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool hit = false;
            for (int ki = 0; ki < k_h; ki++)
            {
                for (int kj = 0; kj < k_w; kj++)
                {
                    int y = i - offset_y + ki;
                    int x = j - offset_x + kj;
                    if (y >= 0 && y < rows && x >= 0 && x < cols)
                    {
                        if (src[y][x] == 1)
                        {
                            hit = true;
                            break;
                        }
                    }
                }
                if (hit) break;
            }
            dst[i][j] = hit ? 1 : 0;
        }
    }
    return dst;
}

std::vector<std::vector<int>> Morphology::erode(const std::vector<std::vector<int>>& src, const Kernel& kernel)
{
    int rows = src.size();
    int cols = src[0].size();
    std::vector<std::vector<int>> dst(rows, std::vector<int>(cols, 0));

    int k_h = kernel.height;
    int k_w = kernel.width;
    int offset_y = k_h / 2;
    int offset_x = k_w / 2;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            bool all_one = true;
            for (int ki = 0; ki < k_h; ki++)
            {
                for (int kj = 0; kj < k_w; kj++)
                {
                    int y = i - offset_y + ki;
                    int x = j - offset_x + kj;
                    if (y < 0 || y >= rows || x < 0 || x >= cols)
                    {
                        all_one = false;
                        break;
                    }
                    if (src[y][x] != 1)
                    {
                        all_one = false;
                        break;
                    }
                }
                if (!all_one) break;
            }
            dst[i][j] = all_one ? 1 : 0;
        }
    }
    return dst;
}