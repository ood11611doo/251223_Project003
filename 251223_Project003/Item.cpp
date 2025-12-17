// Copyright 2025 ood11611doo

#include <iostream>
#include <string>
#include "Item.h"

Item::Item(string name, int price) : name_(name), price_(price) {}

void Item::PrintInfo() const {
  cout <<
    "[이름: " << name_ <<
    ", 가격: " << price_ <<
    "]" << endl;
}
