# Generic Containers in C++

## Chainable Objects
### `Chainable<T>` Chainable Object
- `id() const -> Chainable<T>`
- `pop() const -> T`
- `look() const -> T`
- `set(T val) -> Chainable<T>`

### `Monad<T>`
- `get() -> T`
- `set(T val) -> Monad<T>`


## Sequences
### `Deque<T>` Bidirectional Sequence
- `stack(T val) -> void` push a value to the top of the deque
- `queue(T val) -> void` push a value to the bottom of the deque
- `pop() -> T` remove and return the top value of the deque
- `plant(size_t idx, T val) -> void` emplace a value at a specific index
- `prune(size_t idx) -> T` remove and return a value from a specific index
- `shuffle() -> void` randomize the deque
- `random() -> T` remove and return a random value from the deque
- `apply(F function) -> void` applies the function `F(T) -> T` to each value in the deque 
- `size() -> size_t` returns the number of values in the deque

### `Pair<K, V>`
- `keys() -> Deque<K>`
- `values() -> Deque<V>`
- `pairs() -> Deque<Pair<K, V>>`
- `lookup(K key) -> V`
- `remove(K key) -> void` Work in progress
- `add(Pair<K, V> pair) -> void`
- `begin() -> Pair<K, V>`
- `end() -> Pair<K, V>`

### `Stack<T>` FILO Sequence
- `pop() -> T` remove and return the top value
- `push(T val) -> void` push a value to the top
- `size() -> size_t` returns the number of values

### `Queue<T>` FIFO Sequence
- `pop() -> T` remove and return the top value
- `push(T val) -> void` push a value to the bottom
- `size() -> size_t` returns the number of values

### `Map<K, V>` Sequence of Key/Value Pairs
- `keys() -> Deque<K>`
- `values() -> Deque<V>`
- `pairs() -> Deque<Pair<K, V>>`
- `lookup(K) -> V`
- `remove(K) -> V`
- `add(Pair<K, V>)`
