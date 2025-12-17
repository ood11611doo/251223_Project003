// Copyright 2025 ood11611doo

#pragma once
#include <algorithm>
#include <type_traits>
#include "Item.h"

template <typename T>
class Inventory {
 private:
  T* pItems_;
  int capacity_;
  int size_;

 public:
  explicit Inventory(int capacity = 10);
  Inventory(const Inventory<T>& original);
  ~Inventory() { delete[] pItems_; }

  void Assign(const Inventory<T>& other);
  void AddItem(const T& item);
  void SortItems();
  void Resize(int newCapacity);
  void RemoveLastItem();

  void PrintAllItems() const;

  int GetSize() const { return size_; }
  int GetCapacity() const { return capacity_; }
};
