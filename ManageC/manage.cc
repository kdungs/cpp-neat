#include <memory>

#include "object.h"

int main() {
  using uniqueObjectPtr = std::unique_ptr<object_t, decltype(&object_free)>;
  uniqueObjectPtr obj{object_new(1337), object_free};
}
