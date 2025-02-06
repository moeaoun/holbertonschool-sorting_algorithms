// Inside 3-quick_sort.c

void quick_sort(int *array, size_t size);
static void lomuto_partition(int *array, size_t low, size_t high, size_t size);

void quick_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    lomuto_partition(array, 0, size - 1, size);
}

static void lomuto_partition(int *array, size_t low, size_t high, size_t size) {
    int temp;
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);
}

