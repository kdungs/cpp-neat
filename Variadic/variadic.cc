/**
 * Implement a simple variadic function that takes an arbitrary number of
 * arguments.
 */
#include <iostream>
#include <utility>

/**
 * Base case: Do nothing.
 *
 * <TechnicalDetail>
 * The variadic function below is defined recursively. In order for this to
 * work we need to define a base case where the function is called without any
 * parameters.
 * </TechnicalDetail>
 */
void printIds() {}

/**
 * Function that takes an arbitrary number of objects of arbitrary types that
 * define a method id() as an input and prints all the ids to the screen in
 * separate lines.
 *
 * <TechnicalDetail>
 * Another constraint is that id() has to return a type that can be used with
 * a basic_istream.
 *
 * A big advantage of this system is that all those constraints are checked at
 * compile time.
 * </TechnicalDetail>
 */
template <typename T, typename... Ts>
void printIds(const T& t, const Ts& ...ts) {
  std::cout << t.id() << std::endl;
  printIds(ts...);
}

// Implement two simple structs that fulfil the requirements to be used with
// printIds().
struct SomethingInt {
  int id() const { return 42; }
};

struct SomethingString {
  const std::string _id;
  SomethingString(std::string s) : _id(std::move(s)) {}
  const std::string& id() const { return _id; }
};


int main(int argc, char *argv[]) {
  SomethingInt i;
  SomethingString s("Such string. Much dynamic.");

  printIds(i, s);
}
