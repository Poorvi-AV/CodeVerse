int compare(const void* a, const void* b) {
    int* intA = *(int**)a;
    int* intB = *(int**)b;
    return intA[0] - intB[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int idx = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (idx == 0 || result[idx - 1][1] < start) {
            result[idx] = (int*)malloc(sizeof(int) * 2);
            result[idx][0] = start;
            result[idx][1] = end;
            (*returnColumnSizes)[idx] = 2;
            idx++;
        } else {
            if (result[idx - 1][1] < end)
                result[idx - 1][1] = end;
        }
    }

    *returnSize = idx;
    return result;
}
