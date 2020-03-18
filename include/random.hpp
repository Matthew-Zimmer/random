#pragma once
#include <algorithm>
#include <random>

namespace Slate::Random
{
    extern std::random_device rd;
    extern std::mt19937 gen;

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

    template <typename Dis>
    auto number(Dis& dis)
    {
        return dis(gen);
    }

    template <typename T>
    auto bounded_number(T const& bounds)
    {
        return number(-bounds, bounds);
    }

    template <typename ... Tuples>
    bool choice(Tuples&& ... f)
    {
        double p{ number(0.0, 1.0) }, q{ 0 };
        return ((p < (q += std::get<0>(f)) ? std::get<1>(f)(), true : false) || ...);
    }

    bool probability(double prob);

    template <typename Type>
    auto& element(Type&& container)
    {
        auto iter{ std::begin(container) };
        std::advance(iter, number<std::size_t>(0, container.size() - 1));
        return *iter;
    }

    template <typename Type, typename Dis>
    auto& element(Type&& container, Dis&& dis)
    {
        auto iter{ std::begin(container) };
        std::advance(iter, number(dis));
        return *iter;
    }
}
