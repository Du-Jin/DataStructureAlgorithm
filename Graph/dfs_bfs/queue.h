#ifndef QUEUE_H_
#define QUEUE_H_

template<typename ElementType>
class QueueNode {
 public:
   ElementType data_;
   QueueNode<ElementType>* last_;
   QueueNode<ElementType>* next_;
 public:
   QueueNode() {
     last_ = nullptr;
     next_ = nullptr;
   }
   QueueNode(ElementType data) {
     data_ = data;
     last_ = nullptr;
     next_ = nullptr;
   }
};

template<typename ElementType>
class Queue {
 public:
   QueueNode<ElementType>* front_;
   QueueNode<ElementType>* rear_;
 public:
   Queue() {
     front_ = nullptr;
     rear_ = nullptr;
   }
 public:
   bool IsEmpty() { return ( front_ == nullptr && rear_ == nullptr ); }
   void In(ElementType data);
   ElementType Out();
   bool IsElementExisted(ElementType element);
};

template<typename ElementType>
void Queue<ElementType>::In(ElementType data) {
  QueueNode<ElementType>* node_ptr = new QueueNode<ElementType>(data);

  if(IsEmpty()) {
    rear_ = node_ptr;
    front_ = node_ptr;
    return;
  }

  rear_->next_ = node_ptr;
  node_ptr->last_ = rear_;
  node_ptr->next_ = nullptr;
  rear_ = node_ptr;
}

template <typename ElementType>
ElementType Queue<ElementType>::Out() {
  if(IsEmpty()) {
    ElementType* ptr = new ElementType();
    return *ptr;
  }

  ElementType result = front_->data_;
  if(front_ == rear_) {
    front_ = nullptr;
    rear_ = nullptr;
    return result;
  }

  front_ = front_->next_;
  (front_->last_) = nullptr;
  return result;
}

template <typename ElementType>
bool Queue<ElementType>::IsElementExisted(ElementType element) {
  if(IsEmpty())
    return false;
  for(QueueNode<ElementType>* ptr = front_; ptr; ptr=ptr->next_) {
    if(ptr->data_ == element)
      return true;
  }
  return false;
}

#endif // QUEUE_H_