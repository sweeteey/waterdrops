// #include <iostream>
// using namespace std;

/***********冒泡排序***************/
int BubbleSort(int a[], int n) {
	//int Total = 0;
	int end = n;
	while (end) {
		int flag = 0; //记录是否有交换
		for (int i = 1; i < end; i++) {
			if (a[i-1] > a[i]) {
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				flag = 1;
			}
			//Total++;
		}
		if (flag == 0) {
			break;
		}
		end--;
	}
	return 0;
}