#pragma once
#include <vector>
#include <string>

template <class T>
class Algorithm 
{
public:
    virtual std::string name() const = 0;
    virtual void run(std::vector<T>& data) = 0;
    virtual ~Algorithm() = default;
};