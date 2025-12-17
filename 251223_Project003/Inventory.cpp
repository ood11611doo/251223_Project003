// Copyright 2025 ood11611doo

#include <algorithm>
#include "Inventory.h"

using namespace std;  // NOLINT

bool compareItemsByPrice(const Item& a, const Item& b) {
  return a.GetPrice() < b.GetPrice();
}

template <typename T>
Inventory<T>::Inventory(int capacity)
    : capacity_(capacity), size_(0) {
  if (capacity_ <= 0) {
    capacity_ = 1;
  }

  pItems_ = new T[capacity_];
}

template <typename T>
Inventory<T>::Inventory(const Inventory<T>& original)
    : capacity_(original.capacity_), size_(original.size_) {
  pItems_ = new T[capacity_];

  for (int i = 0; i < size_; i++) {
    pItems_[i] = original.pItems_[i];
  }
}

template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other) {
  if (this != &other) {
    delete[] pItems_;

    capacity_ = other.capacity_;
    size_ = other.size_;
    pItems_ = new T[capacity_];

    for (int i = 0; i < size_; i++) {
      pItems_[i] = other.pItems_[i];
    }
  }
}

template <typename T>
void Inventory<T>::AddItem(const T& item) {
  if (size_ >= capacity_) {
    int newCapacity = capacity_ * 2;
    T* pNewItems = new T[newCapacity];

    for (int i = 0; i < size_; ++i) {
      pNewItems[i] = pItems_[i];
    }

    delete[] pItems_;
    capacity_ = newCapacity;
    pItems_ = pNewItems;
  }

  pItems_[size_] = item;
  size_++;
}

template <typename T>
void Inventory<T>::SortItems() {
  if constexpr (is_base_of_v<Item, T>) {
    sort(pItems_, pItems_ + size_, compareItemsByPrice);
  } else {
    // Ways to sort even type is not an item kinda
  }
}

template <typename T>
void Inventory<T>::Resize(int newCapacity) {
  if (newCapacity <= 0) {
    newCapacity = 1;
  }

  T* pNewItems = new T[newCapacity];
  int itemsToCopy = (newCapacity < size_) ? newCapacity : size_;

  for (int i = 0; i < itemsToCopy; ++i) {
    pNewItems[i] = pItems_[i];
  }

  delete[] pItems_;
  capacity_ = newCapacity;
  size_ = itemsToCopy;
  pItems_ = pNewItems;
}

template <typename T>
void Inventory<T>::RemoveLastItem() {
  if (size_ > 0) {
    size_--;
  }
}

template <typename T>
void Inventory<T>::PrintAllItems() const {
  if constexpr (is_base_of_v<Item, T>) {
    for (int i = 0; i < size_; ++i) {
      pItems_[i].PrintInfo();
    }
  }
}

template class Inventory<Item>;
