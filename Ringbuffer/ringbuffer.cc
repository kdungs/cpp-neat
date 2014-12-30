#include <array>
#include <cassert>
#include <iostream>

/** A simple ringbuffer that can be used to implement a queue.
 * Optimisation could include move semantics or even pointers since flat memory
 * is not really a requirement here.
 * The buffer supports two operations: push and pop.
 * No error handling is done here. Simple assertions are used to state what
 * would be wrong use.
 */
template <typename T, std::size_t Capacity>
class Ringbuffer {
 public:
  auto capacity() const -> std::size_t { return Capacity; }
  auto pop() -> const T & {
    assert(n_ > 0);
    auto index = head_;
    head_ = (head_ + 1) % Capacity;
    n_--;
    return buffer_[index];
  }
  auto push(const T& elem) -> void {
    assert(n_ < Capacity);  // or return false or do something else
    auto index = (head_ + n_) % Capacity;
    n_++;
    buffer_[index] = elem;
  }
  auto size() const -> std::size_t { return n_; }

 private:
  std::size_t head_ = 0, n_ = 0;
  std::array<T, Capacity> buffer_;
};

auto main() -> int {
  Ringbuffer<double, 4> buf;
  buf.push(1.0);
  buf.push(2.0);
  std::cout << buf.pop() << ',' << buf.pop() << '\n';
}
