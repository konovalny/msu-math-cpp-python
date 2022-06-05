#include <iostream>
#include <stdexcept>

template<typename ItemType, unsigned int min_capacity>
class MyVector {
  unsigned int capacity;
  unsigned int size;
  ItemType *storage = nullptr;

 public:

  MyVector() {
    capacity = min_capacity;
    size = 0;
    storage = new ItemType[min_capacity];
  }

  ~MyVector() {
    delete[] storage;
  }

  MyVector(MyVector const & other) {
    capacity = other.capacity;
    size = other.size;
    storage = new ItemType[capacity];
    for (int i = 0; i < size; ++i) {
      storage[i] = other.storage[i];
    }
  }

  MyVector & operator=(const MyVector & other) {
    if (&other != this) {
      capacity = other.capacity;
      size = other.size;
      if (other.storage != this->storage) {
        if (storage) {
          delete[] storage;
        }
        storage = new ItemType[capacity];
        for (int i = 0; i < size; ++i) {
          storage[i] = other.storage[i];
        }
      }
    }
    return *this;
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
      ItemType *new_storage = new ItemType[capacity];
      if (storage) {
        for (unsigned int i = 0; i < size - 1; ++i) {
          new_storage[i] = storage[i];
        }
        delete[] storage;
      }
      storage = new_storage;
    }
    storage[size - 1] = obj;

  }

  ItemType &operator[](unsigned i) {
    if (i >= size) {
      throw std::runtime_error("Out of range!");
    }
    return storage[i];
  }

  void popBack() {
    --size;
    if (capacity > 2 * size) {
      capacity = size;
      ItemType *new_storage;
      if (capacity > 0) {
        new_storage = new ItemType[capacity];
        for (unsigned int i = 0; i < size; ++i) {
          new_storage[i] = storage[i];
        }
      } else {
        new_storage = nullptr;
      }
      delete[] storage;
      storage = new_storage;
    }
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

  std::cout << "pop" << std::endl;
  while (v.getSize() > 0) {
    v.popBack();
    std::cout << v.getCapacity() << " " << v.getSize() << std::endl;
  }

  return 0;
}
