# Generic Containers

## Objects
### `Monoid<Integer>` Chainable Object
- `get() const -> Integer` getter
- `set(Integer val) -> Monoid<Integer>` chainable setter

### `Monad<Integer>` Pure Chainable Object
- `get() const -> Integer` getter
- `set(Integer val) const -> Monad<Integer>` chainable const setter

## Sequences
### `Deque<Integer>` Bidirectional Sequence
- `stack(Integer val) -> void` push a value to the top of the deque
- `queue(Integer val) -> void` push a value to the bottom of the deque
- `pop() -> Integer` remove and return the top value of the deque
- `plant(size_t idx, Integer val) -> void` emplace a value at a specific index
- `prune(size_t idx) -> Integer` remove and return a value from a specific index
- `shuffle() -> void` randomize the deque
- `random() -> Integer` remove and return a random value from the deque
- `apply(F function) -> void` applies the function `F(Integer) -> Integer` to each value in the deque 
- `size() -> size_t` returns the number of values in the deque

### `Stack<Integer>` FILO Sequence
- `pop() -> Integer` remove and return the top value
- `push(Integer val) -> void` push a value to the top
- `size() -> size_t` returns the number of values

### `Queue<Integer>` FIFO Sequence
- `pop() -> Integer` remove and return the top value
- `push(Integer val) -> void` push a value to the bottom
- `size() -> size_t` returns the number of values

### `Map<K, V>` Sequence of Key/Value Pairs
- `keys() -> Deque<K>`
- `values() -> Deque<V>`
- `pairs() -> Deque<Pair<K, V>>`
- `lookup(K) -> V`
- `remove(K) -> V`
- `add(Pair<K, V>)`
