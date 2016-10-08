#include <stdio.h>
#include "ptrptr.h"


void c_lib_function(int **ptr) { *ptr = (int *)(malloc(sizeof(int) * 3)); fprintf(stdout, "Allocating\n"); }
void c_lib_free(int *ptr) { free(ptr); fprintf(stdout, "Freeing\n"); }


struct CLibFreeWrapper {
   void operator()(int *ptr) const {
      c_lib_free(ptr);
   }
};


int main(int argc, char *argv[]) {
   std::unique_ptr<int, decltype(&c_lib_free)> option1{nullptr, c_lib_free};
   std::unique_ptr<int, CLibFreeWrapper> option2;

   c_lib_function(ptrptr(option1));
   c_lib_function(ptrptr(option2));
   return 0;
}
