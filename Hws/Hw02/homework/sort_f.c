/**
 * Copyright (c) 2012 MIT License by 6.172 Staff
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/


#include "./util.h"

// Function prototypes
static void merge_f(data_t* A, int p, int q, int r, data_t* tmp);
static void copy_f(data_t* source, data_t* dest, int n);
void isort(data_t* begin, data_t* end);

// A helper function for sort_f
void helper(data_t* A, int p, int r, data_t* tmp) {
  assert(A);
  // coarsening !
  if (r - p <= 15) {
    isort(A + p, A + r);
    return;
  }
  if (p < r) {
    int q = (p + r) / 2;
    helper(A, p, q, tmp);
    helper(A, q + 1, r, tmp);
    merge_f(A, p, q, r, tmp);
  }
}

// A basic merge sort routine that sorts the subarray A[p..r]
void sort_f(data_t* A, int p, int r) {
  data_t* tmp;
  mem_alloc(&tmp, r - p + 1);
  if (tmp == NULL) {
      mem_free(&tmp);
  }
  // let the helper() function do the right thing !
  helper(A, p, r, tmp);
  mem_free(&tmp);
}

// A merge routine. Merges the sub-arrays A [p..q] and A [q + 1..r].
// Uses one arrays 'tmp'
static inline void merge_f(data_t* A, int p, int q, int r, data_t* tmp) {
  assert(A);
  assert(p <= q);
  assert((q + 1) <= r);
  int n1 = q - p + 1;
  int n2 = r - q;

  copy_f(&(*(A + p)), tmp, n1);
  *(tmp + n1) = UINT_MAX;

  int i = 0;
  int j = 0;

  // note: we should make sure both i and j are within the boundary first
  // everytime we will compare the item in the tmp array and the item in latter half of array A
  for (int k = p; k <= r; k++) {
    if (i >= n1) {
      *(A + k) = *(A + q + 1 + j);
      j++;
    } else if (j >= n2) {
      *(A + k) = *(tmp + i);
      i++;
    } else if (*(tmp + i) <= *(A + q + 1 + j)) {
      *(A + k) = *(tmp + i);
      i++;
    } else {
      *(A + k) = *(A + q + 1 + j);
      j++;
    }
    //printf("===> %d\n", *(A + k));
  }
}

static inline void copy_f(data_t* source, data_t* dest, int n) {
  assert(dest);
  assert(source);

  for (int i = 0 ; i < n ; i++) {
    *(dest + i) = *(source + i);
  }
}
