// #include <iostream>
// using namespace std;

/***********合并排序***************/
//合并两个有序数组
void Merge(int a[], int low, int high) {
	int *new_a = new int[high - low + 1];
	int mid = (low + high) / 2;
	int left = low, right = mid + 1;
	int i = 0, k = 0;

	while (left<=mid && right<=high) {
		if (a[left] <= a[right]) {
			new_a[i++] = a[left++];
		}
		else {
			new_a[i++] = a[right++];
		}
		//Total++;
	}
	//a[low-->mid]有剩余
	while (left <= mid) {
		new_a[i++] = a[left++];
	}
	while (right <= high) {
		new_a[i++] = a[right++];
	}
	
	for (i = low; i <= high; i++) {
		a[i] = new_a[k++];
	}

	delete []new_a;
}
//拆分序列直至子序列长度为1
void MergeSort(int a[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high);
	}
}