// #include <iostream>
// using namespace std;

/***********快速排序***************/
void QuickSort(int a[], int left, int right) {
	if (left < right) {
		int i = left, j = right;
		int temp = a[left];  //基准数
		while (i < j) {
			//从右往左
			while (i < j && a[j] >= temp) {
				j--;
				//Total++;
			}

			//Total++;
			if (i < j)
				a[i++] = a[j];

			while (i < j && a[i] <= temp) {
				i++;
				//Total++;
			}

			//Total++;
			if (i < j)
				a[j--] = a[i];
		}
		a[i] = temp;
		QuickSort(a, left, i-1);
		QuickSort(a, i + 1, right);
	}
}