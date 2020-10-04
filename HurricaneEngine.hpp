#pragma once

#include <random>

namespace Engine {
    using MT_Engine = std::mt19937_64;
    using DB_Engine = std::discard_block_engine<MT_Engine, 20, 16>;
    using RNG_Engine = std::shuffle_order_engine<DB_Engine, 64>;
    thread_local std::random_device RandomDevice{std::random_device()}; // NOLINT(cert-err58-cpp)
    thread_local Engine::RNG_Engine Hurricane{RandomDevice()}; // NOLINT(cert-err58-cpp)
}

template<typename Integer>
auto random_below(Integer number) -> Integer {
    std::uniform_int_distribution<Integer> distribution {0, number - 1};
    return distribution(Engine::Hurricane);
}

template<typename Integer>
auto random_int(Integer lo, Integer hi) -> Integer {
    std::uniform_int_distribution<Integer> distribution {lo, hi};
    return distribution(Engine::Hurricane);
}

template<typename Integer>
auto random_range(Integer start, Integer stop, Integer step) -> Integer {
    if (start == stop or step == 0) return start;
    const auto width{std::abs(start - stop) - 1};
    const auto pivot{step > 0 ? std::min(start, stop) : std::max(start, stop)};
    const auto step_size{std::abs(step)};
    return pivot + step_size * random_below((width + step_size) / step);
}
