#include "random.hpp"
#include <ordeal/ordeal.hpp>
#include <iostream>

using namespace Slate;
using namespace Ordeal;

class Seeded_Tests : public Unit_Test<Seeded_Tests>
{
public:
    Seeded_Tests() : Unit_Test{ "number tests" }
    {}

    auto run(Test<0>) 
    {
        std::vector<int> x(100);
        for (int i = 0; i < 100; i++)
            x.push_back(Random::number(0, 100));
        return "bounds check [a, b]"_name = Value{ x }.expects([](auto const& x){ return x >= 0 && x <= 100; });
    }

    auto run(Test<1>)
    {
        std::vector<int> x(100);
        for (int i = 0; i < 100; i++)
            x.push_back(Random::bounded_number(100));
        return "bounds check [-b, b]"_name = Value{ x }.expects([](auto const& x){ return x >= -100 && x <= 100; });
    }

    auto run(Test<2>)
    {
        std::discrete_distribution<int> dis{ { 40, 10, 10, 40 } };
        std::unordered_map<int, int> x(100);
        for (int i = 0; i < 100; i++)
            x[Random::number(dis)]++;
        return "discrete distribution manual"_name = Value{ x }.expects([](auto const& x){ 
            auto&& [k, v] = x;
            switch (k)
            {
            case 0:
                return v >= 30 && v <= 50;
            case 1:
                return v >= 0 && v <= 20;
            case 2:
                return v >= 0 && v <= 20;
            case 3:
                return v >= 30 && v <= 50;
            }
            return false;
        });
    }
};