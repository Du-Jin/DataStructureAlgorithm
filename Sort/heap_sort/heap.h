#ifndef HEAP_H
#define HEAP_H

template <typename ElementType>
class Heap {
public:
  bool MinHeapInsert(ElementType data);
  ElementType MinHeapDelete();

public:
  ElementType* head_;
  int size_;

public:
  Heap() {
    head_ = nullptr;
    size_ = 0;
  }
  Heap(int size) {
    head_ = new ElementType(size);
    size_ = size;
  }
  ~Heap() {
    head_ = nullptr;
  }
};

template <typename ElementType>
bool Heap<ElementType>::MinHeapInsert(ElementType data) {
  // 将元素插入到堆最后位置
  head_[size_] = data;
  size_++;
  if(size_ == 1)    // 原来堆为空堆，元素已插入到根节点位置，不需要调整
    return true;
  // 从下到上比较元素值并调整，使满足堆的结构要求
  for(int child_index = size_ - 1, parent_index = (child_index - 1) / 2;
      parent_index >= 0;
      child_index = parent_index, parent_index = (child_index - 1) / 2) {
    if(head_[parent_index] < head_[child_index])  // 已满足堆结构要求，不需要继续调整
      return true;
    else {
      // 交换父节点和子节点的值
      ElementType tmp = head_[parent_index];
      head_[parent_index] = head_[child_index];
      head_[child_index] = tmp;
    }
  }
  return true;
}

template <typename ElementType>
ElementType Heap<ElementType>::MinHeapDelete() {
  if(size_ == 0)
    return ElementType();

  ElementType root_element = head_[0];
  // 用最后一个结点替代根节点
  head_[0] = head_[size_ -1];
  size_--;
  if(size_ == 0)    // 删除结点后只有一个结点，则不需要调整
    return root_element;
  // 从上到下依次比较父节点和左右节点中最小的那个，迭代调整使满足堆结构要求
  for(int parent_index = 0, child_index = 1;
      child_index < size_;  // 至少左子节点存在（才能且需要与子节点比较大小判断是否要调整）
      parent_index = child_index, child_index = 2 * child_index + 1) {
    // 选出左右子节点中小的那个，以进行比较，判断是否需要调整以满足堆的结构特性
    if ((child_index + 1 < size_) &&                    // 右子节点存在，且
        (head_[child_index+1] < head_[child_index]))    // 右字节点比左节点小
      child_index++;
    if(head_[parent_index] < head_[child_index])  // 已满足堆结构要求，不需要继续调整
      break;
    else {
      // 交换父节点和子节点的值
      ElementType tmp = head_[parent_index];
      head_[parent_index] = head_[child_index];
      head_[child_index] = tmp;
    }
  }
  return root_element;
}

template <typename ElementType>
Heap<ElementType>* MinHeapBuild(ElementType *data, int size) {
  // 首先构造完全二叉树
  Heap<ElementType>* heap = new Heap<ElementType>(size);
  for(int i = 0; i < size; i++)
    heap->head_[i] = *(data+i);

  if(size <= 1)    // 空堆或只有根节点，则必然满足堆的结构要求，不需要调整,直接结束
    return heap;

  // 从最后一个子树开始，从右到左，从下到上，依次调整各层子树使满足堆的结构特性
  for(int parent = (size-2)/2, child = 2*parent+1;
      parent >= 0; parent--, child = 2 * parent + 1) {
    // 从上到下依次比较当前子树中父节点和左右子结点中最小的那个，迭代调整使满足堆要求
    for (int parent_index = parent, child_index = child;
         child_index < size; // 左子节点至少存在（才需要与子节点比较大小判断是否要调整）
         parent_index = child_index, child_index = 2 * parent_index + 1) {
      // 选出左右子节点中小的那个
      if((child_index + 1 < size) &&      // 右子节点存在且右子节点比左子节点小
         (heap->head_[child_index + 1] < heap->head_[child_index]))
        child_index++;
      if(heap->head_[parent_index] < heap->head_[child_index])  // 已满足堆要求
        break;
      else {
        ElementType tmp = heap->head_[child_index];
        heap->head_[child_index] = heap->head_[parent_index];
        heap->head_[parent_index] = tmp;
      }
    }
  }
  return heap;
}

#endif