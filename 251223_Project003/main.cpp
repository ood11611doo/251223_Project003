// Copyright 2025 ood11611doo

#include <iostream>
#include "Inventory.h"
#include "Item.h"

using namespace std;  // NOLINT

int main() {
  Inventory<Item>* myInventory = new Inventory<Item>();
  myInventory->PrintAllItems();

  myInventory->AddItem(Item("빨간 포션", 50));
  myInventory->AddItem(Item("파란 포션", 30));
  myInventory->AddItem(Item("황금 검", 300));
  myInventory->PrintAllItems();

  myInventory->SortItems();
  myInventory->PrintAllItems();

  delete myInventory;
  return 0;
}
