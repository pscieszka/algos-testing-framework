#include <vector>
#include <algorithm> 

template <typename T>
bool validate_sorted(const std::vector<T>& data) {
    return std::is_sorted(data.begin(), data.end());
}