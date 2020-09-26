/*
 * 表排序
*/

#include <iostream>
#include <string>

using namespace std;

#define N 9

void Swap(int& a, int& b) {
  int tmp = a;
  a = b;
  b = tmp;
}

class Student {
public:
  void Print() {
    cout << num_ << '\t' << name_ << '\t' << endl;
  }
  void Swap(const Student& stu) {
    num_ = stu.num_;
    name_ = stu.name_;
  }
public:
  Student() {
    num_ = 0;
    name_ = "null";
  }
  Student(int num, string name) {
    num_ = num;
    name_ = name;
  }
public:
  int num_;
  string name_;
};

// 生成N个Student元素
Student* Init() {
  Student* stu = new Student[N];
  stu[0] = Student(5, "jack");
  stu[1] = Student(9, "isaac");
  stu[2] = Student(3, "emy");
  stu[3] = Student(1, "bob");
  stu[4] = Student(2, "Rachel");
  stu[5] = Student(10, "monica");
  stu[6] = Student(4, "phebe");
  stu[7] = Student(7, "ross");
  stu[8] = Student(6, "joey");
  return stu;
}

  int table[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

// 表排序
void TableSort(Student* stu) {
  for (int i = 1; i < N; i++) {
    int tmp = table[i];
    int j = i;
    for (; j >0 && stu[tmp].num_ < stu[table[j-1]].num_; j--) {
        table[j] = table[j-1];
    }
    table[j] = tmp;
  }
}

// 物理排序
void PhysicalSort() {
  Student* stu = Init();
  TableSort(stu);
  for (int i = 0; i < N; i++) {
    if (table[i] != i) {
      // 开始调整环内元素位置
      Student tmp = stu[i];    // 暂存首个元素
      int ptr = i;
      while (1) {
        stu[ptr].Swap(stu[table[ptr]]);
        int next = table[ptr];
        table[ptr] = ptr;
        ptr = next;
        if(table[ptr] == i) {
          stu[ptr].Swap(tmp);
          table[ptr] = ptr;
          break;
        }
      }
    }
  }
  for(int i = 0; i < N; i++)
    stu[i].Print();
}

int main() {
  PhysicalSort();
  return 0;
}