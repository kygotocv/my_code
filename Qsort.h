#pragma once

#include <vector>
using namespace std;
int Partition(vector<int>& nums, int low, int high);
//
//void Qsort(vector<int>& nums , int low, int high)
//{
//	if (low < high)
//	{
//		int pivot = Partition(nums, low, high);
//		Qsort(nums, low, pivot - 1);
//		Qsort(nums, pivot + 1, high);
//	}
//}
//
//int Partition(vector<int>& nums, int low, int high)
//{
//	nums[0] = nums[low];
//	int pivot_val = nums[low];
//	while (low < high)
//	{
//		while (low < high && nums[high] >= pivot_val) --high; //如果不加等于的话可能会导致死循环，因为没法判断==的情况
//		nums[low] = nums[high];
//		while (low < high && nums[low] <= pivot_val) ++low;
//		nums[high] = nums[low];
//	}
//	nums[low] = pivot_val;
//	return low;
//}



//
//int ans = -1;
//
//int Partition(vector<int>& nums, int low, int high)
//{
//    nums[0] = nums[low];
//    int pivot_val = nums[low];
//    while (low < high)
//    {
//        while (low < high && nums[high] >= pivot_val) --high; //如果不加等于的话可能会导致死循环，因为没法判断==的情况
//        nums[low] = nums[high];
//        while (low < high && nums[low] <= pivot_val) ++low;
//        nums[high] = nums[low];
//    }
//    nums[low] = pivot_val;
//    return low;
//}
//void Qsort(vector<int>& nums, int l, int r, int k)
//{
//    if (l < r)
//    {
//        int pivot = Partition(nums, l, r);
//        if (pivot == nums.size() - k ) ans = nums[pivot];
//        if (pivot < nums.size() -k) Qsort(nums, pivot + 1, r, k);
//        else Qsort(nums, l, pivot - 1, k);
//    }
//}
//
//int findKthLargest(vector<int>& nums, int k)
//{
//    nums.insert(nums.begin(), 0);
//    int n = nums.size();
//    Qsort(nums, 1, n - 1, k);
//    if (ans == -1)return nums[n - k];
//    return ans;
//}



int Qsort(vector<int>& nums, int l, int r, int k)
{
    if (l == r)
        return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (nums[i] < partition);
        do j--; while (nums[j] > partition);
        if (i < j)
            swap(nums[i], nums[j]);
    }
    Qsort(nums, l, j, k);
    Qsort(nums, j + 1, r, k);
}

int findKthLargest(vector<int>& nums, int k)
{
    int n = nums.size();
    return Qsort(nums, 0, n - 1, n - k);
}