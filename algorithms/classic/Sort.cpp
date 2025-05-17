#include "Sort.hpp"
#include <algorithm>
#include <vector>

void Sort::run(std::vector<int>& data)
{
    std::sort(data.begin(), data.end());
}
