/*
* 堆栈的顺序存储实现（数组）
*/

#include <iostream>

using namespace std;

template<typename ElementType>
class Stack {
private:
  int max_size_;        // 堆栈容量
  ElementType* head_;   // 指向堆栈存储空间首元素
  ElementType* top_;    // 指向栈顶元素
public:
  Stack() {
    max_size_ = 0;
    top_ = nullptr;
    head_ = nullptr;
  }
  Stack(int max_size) {
    max_size_ = max_size;
    head_ = new ElementType[max_size];
    top_ = head_;
    cout << "成功构造一个容量为" << max_size << "的空堆栈" << endl;
  }
  ~Stack() {
    delete head_;
    top_ = nullptr;
  }
public:
  bool IsEmpty() {
    return (top_ == head_);
  }
  bool IsFull() {
    return (top_ - head_ >= max_size_);
  }
  void Push(ElementType item);
  ElementType Pop();
};

// 入栈
template<typename ElementType>
void Stack<ElementType>::Push(ElementType item) {
  if(!IsFull()) {
    top_++;
    (*top_) = item;
  }
}

// 出栈
// NOTE:栈空时作出栈操作本应进行异常处理等操作。
//      由于本源码主要是学习堆栈的使用，因此暂未进行多余的处理。
template<typename ElementType>
ElementType Stack<ElementType>::Pop() {
  if(!IsEmpty()) {
    auto item = *top_;
    top_--;
    return item;
  }
  else {
    ElementType elementtype_default_value;
    return elementtype_default_value;
  }
}

int main() {
  Stack<int> stack(3);
  stack.Push(6);
  stack.Push(128);
  auto item = stack.Pop();
  cout << item << endl;
  item = stack.Pop();
  cout << item << endl;
  cout << (stack.IsEmpty() ? "堆栈空" : "堆栈非空") << endl;

  stack.Push(6);
  stack.Push(128);
  stack.Push(64);
  cout << (stack.IsFull() ? "堆栈满" : "堆栈未满") << endl;

  return 0;
}