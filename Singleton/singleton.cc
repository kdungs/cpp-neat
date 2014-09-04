/**
 */
#include <iostream>
#include <thread>

#include "../widget.h"

/**
 * Very simple implementation of a thread-safe singleton.
 * The idea is stolen from Herb Sutter.
 */
Widget& instance() {
  static Widget w;
  return w;
}


// A very simple example that makes use of the singleton.
// Should be replaced by something more sophisticated.
void doSomethingWithWidget(int id) {
  std::cout << id << ": " << &(instance()) << std::endl;
}

int main(int argc, char *argv[]) {
  std::thread t1(doSomethingWithWidget, 1),
              t2(doSomethingWithWidget, 2);
  t1.join();
  t2.join();
}
