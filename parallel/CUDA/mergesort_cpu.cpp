// 8 7   6 5    4 3    2 1
// x y
//merge sort
// 7 8   5 6    3 4    1 2

// 5 6  7 8     1 2 3 4
// i                j


//     k
// 1 2
//n=8
//seg = 1
void merge2(const uint32_t* x, const uint32_t* y, uint32_t* z, int seg) {
    int i = 0, j = 0, k = 0; // i is location in x, j is location in y, k is location in z
    while(i < n && j < n) {
        if (x[i] < y[i])
            z[k++] = x[i];
        else  {
            z[k++] = y[i];
        }
    while (i < n)
        z[k++] = x[i++];
    while (j < n)
        z[k++] = y[j++]
}
// assuming an array a, and space in b same size
void merge_seg(const uint32_t *a, uint32_t *b, int n, int seg) {
  for (int i = 0; i < n; i += 2*seg) {
    //a[i] is the first array
    //a[i+seg] is the second array
    merge2(a, a+seg, b, seg);
  }
}

void merge(const uint32_t* a, int n) {
    uint32_t* temp = new uint32_t[n];
    for (int i = 1; i < n; i *= 2) {
        merge_seg(a, temp, n, i);
        swap(a, temp);
    }
}