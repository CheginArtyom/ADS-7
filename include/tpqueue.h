// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct DATA {
  char ch;
  int prior;
};

template<typename T>
class TPQueue {
 private:
 ITEM* head;
  struct ITEM {
    T data;
    ITEM* next;
  };
  TPQueue::ITEM* create(const T& znach) {
    ITEM* uk = new ITEM;
    uk->data = znach;
    uk->next = nullptr;
    return uk;
  }
  
 public:
  TPQueue() :head(nullptr) {}
  T pop() {
    ITEM* temp = head;
    head = head->next;
    return temp->data;
  }
  void push(T znach) {
    if (head) {
      ITEM* th = create(znach);
      if (znach.prior > head->data.prior) {
        th->next = head;
        head = th;
        return;
      }
      ITEM* temp = head;
      while (temp->next) {
      if (znach.prior > temp->next->data.prior) {
        th = create(znach);
        th->next = temp->next;
        temp->next = th;
        return;
      }
        temp = temp->next;
    }
    temp->next = create(znach);
    } else {
      head = create(znach);
      return;
    }
  }
};
