#pragma once
#include <algorithm>
#include <random>

namespace Slate::Random
{
    std::random_device rd{};
    std::mt19937 gen(rd());

    template <typename Type>
    auto number(Type const& lower, Type const& upper) -> std::enable_if_t<std::is_integral_v<Type>, Type>
    {
        return std::uniform_int_distribution<Type>{ lower, upper }(gen);
    }

    template <typename Type>
    auto number(Type const& lower, Type const& upper) -> std::enable_if_t<std::is_floating_point_v<Type>, Type>
    {
        return std::uniform_real_distribution<Type>{ lower, upper }(gen);
    }

    template <typename T>
    auto number(T const& bounds)
    {
        return number(-bounds, bounds);
    }

    template <typename ... Tuples>
    bool choice(Tuples&& ... f)
    {
        double p{ number(0.0, 1.0) }, q{ 0 };
        return ((p < (q += std::get<0>(f)) ? std::get<1>(f)(), true : false) || ...);
    }

    bool probability(double prob)
    {
        return number(0.0, 1.0) < prob;
    }

    template <typename Type>
    auto& element(Type&& container)
    {
        auto iter{ std::begin(container) };
        std::advance(iter, number<std::size_t>(0, container.size() - 1));
        return *iter;
    }
}
