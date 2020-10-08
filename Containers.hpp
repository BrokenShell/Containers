#pragma once

#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include "HurricaneEngine.hpp"


namespace Objects {

    template<typename T>
    class Chainable {
        bool _bool {false};
        T value {T()};
    public:
        Chainable() = default;

        Chainable(Chainable<T> const& m) : value(m.get()) {}

        explicit Chainable(T val) : value(val) {}

        explicit operator bool() const {
            return _bool;
        }

        auto id() const -> Chainable<T> {
            return *this;
        }

        auto get() const -> T {
            return value;
        }

        auto pop() -> T {
            auto result = value;
            value = T();
            _bool = false;
            return result;
        }

        template<typename F>
        auto apply(F&& func) -> Chainable<T> {
            value = func(value);
            _bool = true;
            return id();
        }

        auto set(T val) -> Chainable<T> {
            value = std::move(val);
            _bool = true;
            return id();
        }
    };

    template<typename T>
    class Monad {
        T value;
    public:
        explicit Monad(T val) : value(val) {}

        auto get() const -> T {
            return value;
        }

        auto set(T val) const -> Monad<T> {
            return Monad(std::move(val));
        }
    };
}

namespace Sequences {

    template<typename T>
    struct Deque {
        std::vector<T> data;

        Deque() = default;

        ~Deque() = default;

        template<typename Iter>
        Deque(Iter begin, Iter end) : data(begin, end) {}

        template<typename UT>
        void stack(UT&& value) {
            data.push_back(std::forward<UT>(value));
        }

        template<typename UT>
        void queue(UT&& value) {
            data.insert(data.begin(), std::forward<UT>(value));
        }

        auto pop() -> T {
            const auto result {data.back()};
            data.pop_back();
            return result;
        }

        template<typename UT>
        void plant(size_t idx, UT&& value) {
            data.insert(data.end() - idx, std::forward<UT>(value));
        }

        auto prune(size_t idx) -> T {
            const auto result {data[size() - idx - 1]};
            data.erase(data.end() - idx - 1);
            return result;
        }

        void shuffle() {
            std::shuffle(begin(), end(), Engine::Hurricane);
        }

        auto random() -> T {
            return prune(random_below(size()));
        }

        auto size() const {
            return data.size();
        }

        auto begin() {
            return data.rbegin();
        }

        auto end() {
            return data.rend();
        }

        template<typename F>
        void apply(F&& function) {
            std::transform(begin(), end(), begin(), function);
        }
    };

    template<typename K, typename V>
    struct Pair {
        K key;
        V value;

        Pair() = default;

        ~Pair() = default;

        Pair(K key, V val) : key(key), value(val) {};
    };

    template<typename K, typename V>
    struct Map {
        Deque<Pair<K, V>> data;

        Map() = default;

        ~Map() = default;

        auto keys() -> Deque<K> {
            Deque<K> result;
            for (Pair<K, V> pair : data) {
                result.stack(pair.key);
            }
            return result;
        }

        auto values() -> Deque<V> {
            Deque<V> result;
            for (Pair<K, V> pair : data) {
                result.stack(pair.value);
            }
            return result;
        }

        auto pairs() -> Deque<Pair<K, V>> {
            return {data.begin(), data.end()};
        }

        auto lookup(K key) -> V {
            // needs work
            auto p = std::find_if(data.begin(), data.end(), [key](Pair<K, V> pair) { return pair.key == key; });
            if (p >= data.begin() and p < data.end()) return (*p).value;
            else return V(); // default const V might not be best idea... Maybe<T>
        }

        auto remove(K key) -> V {
            // needs work
        }

        void add(Pair<K, V> pair) {
            data.stack(pair);
        }

        auto begin() {
            return data.data.begin();
        }

        auto end() {
            return data.data.end();
        }
    };

    template<typename T>
    class Stack {
        std::vector<T> data;
    public:
        Stack() = default;

        template<typename Iter>
        Stack(Iter begin, Iter end) : data(begin, end) {}

        template<typename UT>
        void push(UT&& value) {
            data.push_back(std::forward<UT>(value));
        }

        auto pop() -> T {
            assert(!data.empty());
            auto result {data.back()};
            data.pop_back();
            return result;
        }

        auto size() const {
            return data.size();
        }

        auto begin() const {
            return data.crbegin();
        }

        auto end() const {
            return data.crend();
        }
    };

    template<typename T>
    class Queue {
        std::vector<T> data;
    public:
        Queue() = default;

        template<typename Iter>
        Queue(Iter begin, Iter end) : data(begin, end) {}

        template<typename UT>
        void push(UT&& value) {
            data.insert(data.begin(), std::forward<UT>(value));
        }

        auto pop() -> T {
            assert(!data.empty());
            auto result {data.back()};
            data.pop_back();
            return result;
        }

        auto size() const {
            return data.size();
        }

        auto begin() const {
            return data.crbegin();
        }

        auto end() const {
            return data.crend();
        }
    };

} // end namespace
