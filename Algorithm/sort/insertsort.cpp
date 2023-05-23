// #include <iostream>
// using namespace std;

/***********插入排序***************/
int InsertSort(int a[], int n) {
	//int Total = 0;
	for (int i = 0; i < n-1; i++) {
		int end = i; //有序序列最后一个元素
		int temp = a[end + 1]; //待插入元素

		while (end >= 0) {
			if (temp < a[end]) {
				a[end + 1] = a[end];
				end--;
				//Total++;
			}
			else {
				//Total++;
				break;
			}
		}
		a[end + 1] = temp;
	}
	return 0;
}