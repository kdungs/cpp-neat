#ifndef PTRPTR_H
#define PTRPTR_H

#pragma once

//
//  Taken from http://stackoverflow.com/questions/22095214/how-to-use-unique-ptr-with-data-allocated-within-a-c-library
//     (see response by Mooing Duck)
//
//  Adapated by me to include an array version.
//

#include <memory>

template <typename T, typename D>
struct ptrptr_type {
   ptrptr_type(std::unique_ptr<T,D> &ptr)
      : ptr_(ptr),
        t_(ptr_.get())
   {
   }


   ~ptrptr_type() {
      if (ptr_.get() != t_) {
         ptr_.reset(t_);
      }
   }

   operator T**() { return &t_; }
private:
   std::unique_ptr<T,D> &ptr_;
   T *t_;
};

template <typename T, typename D>
struct ptrptr_type<T[],D> {
   ptrptr_type(std::unique_ptr<T[],D> &ptr)
      : ptr_(ptr),
        tptr_(ptr.get())
   {
   }
   ~ptrptr_type() {
      if (ptr_.get() != tptr_) {
         ptr_.reset(tptr_);
      }
   }

   operator T**() { return &tptr_; }
private:
   std::unique_ptr<T[],D> &ptr_;
   T *tptr_;
};



template<class T, class D>
ptrptr_type<T,D> ptrptr(std::unique_ptr<T,D> &ptr) { return { ptr }; }

#endif
