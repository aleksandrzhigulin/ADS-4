#include "algorithm"
using namespace std;
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) counter++;
    }
  }
  return counter;
}

int countPairs2(int *arr, int len, int value) {
  sort(arr, arr + len);
  int end = len - 1;
  while (arr[end] > value) {
    end--;
  }

  int counter = 0;
  for (int i = 0; i < end - 1; i++) {
    for (int j = i + 1; j < end; j++) {
      if (arr[i] + arr[j] == value) counter++;
    }
  }
  return counter;
}

bool binarySearch(const int *arr, int left, int right, int value) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      return true;
    } else if (arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return false;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  sort(arr, arr + len);
  for (int i = 0; i < len; i++) {
    if (binarySearch(arr, i, len - 1, value - arr[i])) {
      counter = counter + 1;
    }
  }
  return counter;
}
