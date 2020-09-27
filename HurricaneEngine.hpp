#pragma once

#include <random>

namespace Engine {
    using MT_Engine = std::mt19937_64;
    using DB_Engine = std::discard_block_engine<MT_Engine, 20, 16>;
    using RNG_Engine = std::shuffle_order_engine<DB_Engine, 64>;
    thread_local std::random_device RandomDevice{std::random_device()}; // NOLINT(cert-err58-cpp)
    thread_local Engine::RNG_Engine Hurricane{RandomDevice()}; // NOLINT(cert-err58-cpp)
}

template<typename T>
auto random_below(T number) -> T {
    std::uniform_int_distribution<T> distribution {0, number-1};
    return distribution(Engine::Hurricane);
}