// Copyright 2021 NNTU-CS

#include "algorithm"

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

int firstEnter(int *arr, int l, int r, int x) {
  if (l <= r) {
    int mid = l + (r - l) / 2;
    if ((x > arr[mid - 1] || mid == 0) && arr[mid] == x) {
      return mid;
    } else if (x > arr[mid]) {
      return firstEnter(arr, mid + 1, r, x);
    }
    return firstEnter(arr, l, mid - 1, x);
  }
  return -1;
}

int lastEnter(int *arr, int l, int r, int x, int size) {
  if (l <= r) {
    int mid = l + (r - l) / 2;
    if ((x < arr[mid + 1] || mid == size - 1) && arr[mid] == x) {
      return mid;
    } else if (x < arr[mid]) {
      return lastEnter(arr, l, mid - 1, x, size);
    }
    return lastEnter(arr, mid + 1, r, x, size);
  }
  return -1;
}

int cbinsearch(int *arr, int l, int r, int value, int size) {
  int first = firstEnter(arr, l, r, value);

  if (first == -1) {
    return 0;
  }

  int last = lastEnter(arr, l, r, value, size);
  return last - first + 1;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    int find = value - arr[i];
    counter += cbinsearch(arr, i + 1, len - 1, find, len);
  }
  return counter;
}
