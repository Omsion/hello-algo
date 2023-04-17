/**
 * File: binary_search.c
 * Created Time: 2023-03-18
 * Author: Guanngxu (446678850@qq.com)
 */

#include "../include/include.h"

/* 二分查找（双闭区间） */
int binarySearch(int *nums, int len, int target) {
    // 初始化双闭区间 [0, n-1] ，即 left, right 分别指向数组首元素、尾元素
    int left = 0, right = len - 1;
    // 循环，当搜索区间为空时跳出（当 left > right 时为空）
    while (left <= right) {
        int mid = (left + right) / 2; // 计算中点索引 mid
        if (nums[mid] < target)       // 此情况说明 target 在区间 [mid+1, right] 中
            left = mid + 1;
        else if (nums[mid] > target) // 此情况说明 target 在区间 [left, mid-1] 中
            right = mid - 1;
        else // 找到目标元素，返回其索引
            return mid;
    }
    // 未找到目标元素，返回 -1
    return -1;
}

/* 二分查找（左闭右开） */
int binarySearch1(int *nums, int len, int target) {
    // 初始化左闭右开 [0, n) ，即 left, right 分别指向数组首元素、尾元素+1
    int left = 0, right = len;
    // 循环，当搜索区间为空时跳出（当 left = right 时为空）
    while (left < right) {
        int mid = (left + right) / 2; // 计算中点索引 mid
        if (nums[mid] < target)       // 此情况说明 target 在区间 [mid+1, right) 中
            left = mid + 1;
        else if (nums[mid] > target) // 此情况说明 target 在区间 [left, mid) 中
            right = mid;
        else // 找到目标元素，返回其索引
            return mid;
    }
    // 未找到目标元素，返回 -1
    return -1;
}

/* Driver Code */
int main() {
    int target = 6;
    int nums[10] = {1, 3, 6, 8, 12, 15, 23, 67, 70, 92};

    /* 二分查找（双闭区间） */
    int index = binarySearch(nums, 10, target);
    printf("目标元素 6 的索引 = %d\n", index);

    /* 二分查找（左闭右开） */
    index = binarySearch1(nums, 10, target);
    printf("目标元素 6 的索引 = %d\n", index);

    return 0;
}