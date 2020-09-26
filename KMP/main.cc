/*
* 串的模式匹配算法KMP
*/
#include <iostream>
#include <string>

using namespace std;

string str = "It wasn't all romantic. I didn't have a dorm room, so I slept on the floor in friends' rooms, I returned coke bottles for the 5￠ deposits to buy food with, and I would walk the 7 miles across town every Sunday night to get one good meal a week at the Hare Krishna temple. I loved it. And much of what I stumbled into by following my curiosity and intuition turned out to be priceless later on. Let me give you one example";

string pattern = "Krishna";

void BuildMatch(const string& pattern, int* match) {
  match[0] = -1;
  for (int i = 1; i < pattern.size(); i++) {
    int tmp = match[i-1];
    while((tmp >=0) && (pattern[tmp+1] != pattern[i]))
      tmp = match[tmp];
    if (pattern[tmp+1] == pattern[i])
      match[i] = tmp+1;
    else
      match[i] = -1;
  }
}

int KMP(const string& str, const string& pattern) {
  int n = str.size();
  int m = pattern.size();
  if (n < m)
    return -1;
  int *match = new int[m];
  BuildMatch(pattern, match);
  int s = 0, p = 0;
  while (s<n && p<m) {
    if(str[s] == pattern[p]) {
      s++;
      p++;
    }
    else if (p>0)
      p = match[p-1] + 1;
    else
      s++;
  }
  return (p == m) ? (s-m): -1;
}

int main() {
  int result = KMP(str, pattern);
  if (result == -1)
    cout << "Not Found." << endl;
  else {
    cout << "position: " << result << endl;
    for(int i = result; i < result + pattern.size(); i++)
      cout << str[i];
    cout << endl;
  }
  return 0;
}