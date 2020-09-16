#ifndef __STACK_H
#define __STACK_H

template<typename ElementType>
class StackNode {
public:
  ElementType data_;
  StackNode* next_;
public:
  StackNode() {
    next_ = nullptr;
  }
  StackNode(ElementType data) {
    data_ = data;
    next_ = nullptr;
  }
};

template<typename ElementType>
class Stack {
public:
  StackNode<ElementType>* top_;
public:
  Stack() {
    top_ = nullptr;   // 这里一定要将top_设为nullptr
  }
public:
  bool IsEmpty();
  void Push(ElementType data);
  ElementType Pop();

};

template<typename ElementType>
bool Stack<ElementType>::IsEmpty() {
  return top_ == nullptr;
}

template<typename ElementType>
void Stack<ElementType>::Push(ElementType data) {
  StackNode<ElementType>* stack_node_ptr = new StackNode<ElementType>(data);
  if(IsEmpty()) {
    top_ = stack_node_ptr;
  }
  else {
    stack_node_ptr->next_ = top_;
    top_ = stack_node_ptr;
  }
}

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


#endif