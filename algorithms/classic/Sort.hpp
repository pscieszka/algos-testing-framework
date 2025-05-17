#pragma once
#include "itf/Algorithm.hpp"

class Sort : public Algorithm<int>
{
public:
    std::string name() const override { return "BubbleSort"; }
    void run(std::vector<int>& data) override;
};
