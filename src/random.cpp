#include "random.hpp"

namespace Slate::Random
{
    std::random_device rd{};
    std::mt19937 gen(rd());

    bool probability(double prob)
    {
        return number(0.0, 1.0) < prob;
    }
}