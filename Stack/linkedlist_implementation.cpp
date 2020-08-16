/*
 * 堆栈的链式存储实现（链表）
 */

#include <iostream>

using std::cout;
using std::endl;

namespace StackLinkedList{
// 链表节点
template <typename ElementType>
class LinkNode {
public:
  ElementType data_;       // 数据
  LinkNode* next_;         // 指针域，指向下一个节点
public:
  LinkNode() {
    next_ = nullptr;
  }
  LinkNode(ElementType data) {
    data_ = data;
    next_ = nullptr;
  }
  ~LinkNode() { }
};

template<typename ElementType>
class Stack{
private:
  LinkNode<ElementType>* top_;    // 指向链表第一个节点（作为栈顶）
  LinkNode<ElementType>* end_;    // 指向链表最后一个节点
public:
  Stack() {
    top_ = nullptr;
    end_ = nullptr;
  }
  ~Stack() {}
public:
  bool IsEmpty() {
    return (top_ == nullptr);
  }
  void Push(ElementType data);
  ElementType Pop();
};

// 入栈
template<typename ElementType>
void Stack<ElementType>::Push(ElementType data) {
  LinkNode<ElementType> node(data);
  if(IsEmpty()) {
    top_ = &node;
    end_ = &node;
  }
  else {
    end_->next_ = &node;
    end_ = &node;
  }
}

// 出栈
// NOTE:栈空时作出栈操作本应进行异常处理等操作。
//      由于本源码主要是学习堆栈的使用，因此暂未进行多余的处理。
template<typename ElementType>
ElementType Stack<ElementType>::Pop() {
  if(!(IsEmpty())) {
    ElementType data = top_->data_;
    top_ = top_->next_;
    return data;
  }
  else {
    ElementType elementtype_default_value;
    return elementtype_default_value;
  }
}

}


int main() {
  StackLinkedList::LinkNode<int> node(10);
  StackLinkedList::Stack<int> stack;
  stack.Push(18);

  auto data = stack.Pop();
  cout << "data popped:" << data << endl;

  cout << (stack.IsEmpty() ? "堆栈空" : "堆栈非空") << endl;

  return 0;
}