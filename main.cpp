#include <iostream>
#include "Containers.hpp"
#include "MonkeyTimer.hpp"
#include <numeric>


int main() {
    using namespace Objects;
    using namespace Sequences;
    using MonkeyTimer::print;
    using Value = int;

    std::vector<Value> list(10);
    std::iota(list.begin(), list.end(), 0);

    Map<std::string, int> map;
    map.add({"Alpha", 1});
    map.add({"Beta", 2});
    map.add({"Gamma", 3});
    print("\nKeys: ");
    for (const auto& key : map.keys()) {
        print(key, ", ");
    }
    print("\nValues: ");
    for (const auto& val : map.values()) {
        print(val, ", ");
    }
    print('\n');
    print("\nPairs:\n");
    for (const auto& pair : map.pairs()) {
        print(pair.key, ": ", pair.value, "\n");
    }
    print("\nLookups:\n");
    print("Alpha: ", map.lookup("Alpha"), '\n');
    print("Beta: ", map.lookup("Beta"), '\n');
    print("Gamma: ", map.lookup("Gamma"), '\n');

    print("Deque<Chainable<Integer>>\n");
    Deque<Chainable<int>> deque(list.begin(), list.end());

    for (auto _ : deque) {
        print(deque.pop().get(), ", ");
    }
    print('\n');

    for (auto val : list) {
        deque.queue(Chainable<Value>(val));
    }

    for (auto _ : deque) {
        print(deque.pop().get(), ", ");
    }
    print('\n');

    for (auto val : list) {
        deque.stack(Chainable<Value>(val));
    }

    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

    print("Adding 1 to each with apply(lambda)\n");
    deque.apply([](Chainable<Value> o){ return o.set(o.get() + 1); });

    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

    print("Pruning: ",deque.prune(0).get(), '\n');
    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

    print("Planting: 0", '\n');
    deque.plant(10, Chainable<Value>(0));

    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

    print("Shuffling\n");
    deque.shuffle();

    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

    print("Random Draw: ", deque.random().get(), '\n');

    for (const auto& val : deque) {
        print(val.get(), ", ");
    }
    print('\n');

}