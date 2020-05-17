#include <iostream>
#include <fmt/format.h>
#include "MoistureSensor.h"

int main()
{
    std::cout << fmt::format("Value: {}", test()) << std::endl;
    return 1;
}