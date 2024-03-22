// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
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
  for (int i = 0; i < end; i++) {
    for (int j = end; i < j; j--) {
      if (arr[i] + arr[j] == value) counter++;
    }
  }
  return counter;
}

int binarySearch(int *arr, int size, int value) {
  int counter = 0, left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
      left = mid - 1;
      right = mid + 1;

      while (arr[left] == value && left >= 0) {
        left--;
        counter++;
      }
      while (arr[right] == value && right < size) {
        right++;
        counter++;
      }
      return ++counter;
    } else if (arr[mid] > value) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len - 1; i++) {
    int newSize = len - i - 1;
    counter += binarySearch(&arr[i + 1], newSize, value - arr[i]);
  }
  return counter;
}
