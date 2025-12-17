// Copyright 2025 ood11611doo

#pragma once
#include <iostream>
#include <string>

using namespace std;  // NOLINT

class Item {
 private:
  string name_;
  int price_;

 public:
  explicit Item(string name = "´õ¹Ì", int price = 0);
  ~Item() = default;

  void PrintInfo() const;

  string GetName() const { return name_; }
  int GetPrice() const { return price_; }
};
