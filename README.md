# Generic Containers

## Objects
### `Monoid<T>` Chainable Object
- `get() const -> T` getter
- `set(T val) -> Monoid<T>` chainable setter

### `Monad<T>` Pure Chainable Object
- `get() const -> T` getter
- `set(T val) const -> Monad<T>` chainable const setter

## Sequences
### `Deque<T>` Bidirectional Sequence
Replaces Stack and Queue.
- `stack(T val) -> void` push a value to the top of the deque
- `queue(T val) -> void` push a value to the bottom of the deque
- `pop() -> T` remove and return the top value of the deque
- `plant(size_t idx, T val) -> void` emplace a value at a specific index
- `prune(size_t idx) -> T` remove and return a value from a specific index
- `shuffle() -> void` randomize the deque
- `random() -> T` remove and return a random value from the deque
- `apply(F function) -> void` applies the function `F(T) -> T` to each value in the deque 
- `size() -> size_t` returns the number of values in the deque

### `Stack<T>` deprecated

### `Queue<T>` deprecated

### `Map<K, V>` Sequence of Key/Value Pairs
- `keys() -> Deque<K>`
- `values() -> Deque<V>`
- `pairs() -> Deque<Pair<K, V>>`
- `lookup(K) -> V`
- `remove(K) -> V`
- `add(Pair<K, V>)`
