#include <iostream>
#include <fmt/format.h>

int main()
{
    std::cout << fmt::format("Value: {}", 10) << std::endl;
    return 1;
}