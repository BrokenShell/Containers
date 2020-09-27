#include <iostream>
#include "Containers.hpp"
#include "MonkeyTimer.hpp"
#include <numeric>


int main() {
    using namespace Objects;
    using namespace Sequences;

    using Value = int;
    using Object = Monoid<Value>;

    std::vector<Value> list(10);
    std::iota(list.begin(), list.end(), 0);

    MonkeyTimer::print("Deque<Monoid<Integer>>\n");
    Deque<Monoid<int>> deque(list.begin(), list.end());

    for (auto _ : deque) {
        MonkeyTimer::print(deque.pop().get(), ", ");
    }
    MonkeyTimer::print('\n');

    for (auto val : list) {
        deque.queue(Object(val));
    }

    for (auto _ : deque) {
        MonkeyTimer::print(deque.pop().get(), ", ");
    }
    MonkeyTimer::print('\n');

    for (auto val : list) {
        deque.stack(Object(val));
    }

    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

    MonkeyTimer::print("Adding 1 to each with apply(lambda)\n");
    deque.apply([](Object o){ return o.set(o.get() + 1); });

    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

    MonkeyTimer::print("Pruning: ",deque.prune(0).get(), '\n');
    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

    MonkeyTimer::print("Planting: 0", '\n');
    deque.plant(10, Object(0));

    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

    MonkeyTimer::print("Shuffling\n");
    deque.shuffle();

    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

    MonkeyTimer::print("Random Draw: ", deque.random().get(), '\n');

    for (auto val : deque) {
        MonkeyTimer::print(val.get(), ", ");
    }
    MonkeyTimer::print('\n');

}