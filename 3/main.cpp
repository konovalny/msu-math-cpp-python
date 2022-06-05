#include <iostream>
#include <stdexcept>

template<typename ItemType, unsigned int min_capacity>
class MyVector {
  unsigned int capacity;
  unsigned int size;
  ItemType minimum_storage[min_capacity];
  ItemType *storage = nullptr;

 public:

  class MyVectorIterator {
    unsigned int i = 0;
    MyVector *vector;

   public:
    MyVectorIterator(MyVector *v, int i) {
      vector = v;
      this->i = i;
    }
    MyVectorIterator(MyVector *v) {
      vector = v;
      this->i = 0;
    }

    ItemType &operator*() const { return (*vector)[i]; }
    ItemType *operator->() { return &(*vector)[i]; }
    // ++it
    MyVectorIterator &operator++() {
      i++;
      return *this;
    }
    // it++
    MyVectorIterator operator++(int) {
      MyVectorIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    friend bool operator==(const MyVectorIterator &a, const
    MyVectorIterator &b) {
      return (a.vector == b.vector) && (a.i == b.i);
    };
    friend bool operator!=(const MyVectorIterator &a, const
    MyVectorIterator &b) {
      return !(a == b);
    };
  };

  MyVector() {
    capacity = min_capacity;
    size = 0;
    storage = nullptr;
    minimum_storage[0] = 0;
  }

  MyVector(MyVectorIterator begin, MyVectorIterator end) {
    capacity = min_capacity;
    size = 0;
    storage = nullptr;
    for (auto it = begin; it != end; ++it) {
      this->push_back(*it);
    }
    minimum_storage[0] = 0;
  }


  ~MyVector() {
    delete[] storage;
  }

  unsigned int getSize() {
    return size;
  }
  unsigned int getCapacity() {
    return capacity;
  }

  void push_back(ItemType const &obj) {
    if (++size > capacity) {
      capacity = 1.5 * capacity;
      if (capacity - min_capacity > 0) {
        ItemType *new_storage = new ItemType[capacity - min_capacity];
        if (storage) {
          for (unsigned int i = 0; i < size - 1 - min_capacity; ++i) {
            new_storage[i] = storage[i];
          }
          delete[] storage;
        }
        storage = new_storage;
      }
    }
    if (size <= min_capacity) {
      minimum_storage[size - 1] = obj;
    } else {
      storage[size - 1 - min_capacity] = obj;
    }
  }

  ItemType &operator[](unsigned i) {
    if (i >= size) {
      throw std::runtime_error("Out of range!");
    }
    if (i < min_capacity) {
      return minimum_storage[i];
    } else {
      return storage[i - min_capacity];
    }
  }

  void popBack() {
    --size;
    if (capacity > 2 * size) {
      capacity = size;
      ItemType *new_storage;
      if (capacity > min_capacity) {
        new_storage = new ItemType[capacity - min_capacity];
        for (unsigned int i = 0; i < size - min_capacity; ++i) {
          new_storage[i] = storage[i];
        }
      } else {
        new_storage = nullptr;
      }
      if (storage) {
        delete[] storage;
      }
      storage = new_storage;
    }
  }

  MyVectorIterator begin() {
    return MyVectorIterator(this, 0);
  }

  MyVectorIterator end() {
    return MyVectorIterator(this, size);
  }

};

int main(void) {
  MyVector<int, 2> v;
  std::cout << "push" << std::endl;
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(1);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(2);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(3);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(4);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(5);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(6);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  v.push_back(7);
  std::cout << v.getCapacity() << " " << v.getSize() << std::endl;

  std::cout << "iterating through vector" << std::endl;

  MyVector<int, 2>::MyVectorIterator it1(&v);
  MyVector<int, 2>::MyVectorIterator it2(&v);
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;

    if (*it == 2) {
      it1 = it;
    }

    if (*it == 5) {
      it2 = it;
    }

  }

  std::cout << "constructor from iterators: " << std::endl;

  MyVector<int, 2> v_cut(it1, it2);

  std::cout << "iterating through obtained vector" << std::endl;

  for (auto it = v_cut.begin(); it != v_cut.end(); ++it) {
    std::cout << *it << std::endl;
  }

  std::cout << "pop" << std::endl;
  while (v.getSize() > 0) {
    v.popBack();
    std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  }

  return 0;
}
