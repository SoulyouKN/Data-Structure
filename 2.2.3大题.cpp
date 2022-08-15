#define MaxSize 30
//数据结构定义
typedef int ElemType;
typedef struct{
	int length;
	ElemType data[MaxSize];
}SqList;

//第二题
//算法思路：设第一个元素最小，依次往后扫描，与更小则交换
bool DaleteMin(SqList &L,ElemType &min){
	if(L.length==0)return  false;
	min = L.data[0];
	int locate = 0;
	for(int i = 0;i<L.length;i++){
		if(L.data[i]<min){
			min = L.data[i];
			locate = i;
		}
	}
	L.data[locate] = L.data[L.length-1];
	L.length --;
	return true;
}

//第二题
//算法思路：讲前半部分元素与后半部分元素互换
bool Reverse(SqList &L){
	int temp;
	for(int i = 0;i<L.length/2;i++){
		temp = L.data[L.length-i-1];
		L.data[L.length-i-1] = L.data[i];
		L.data[i] = temp;
	}
	return true;
}

//第三题
//算法思路：从前开始扫描，若为x，k加一，若不为x，元素前移k个位置
bool DeleteX(SqList &L, ElemType x){
	int k = 0,i = 0;
	while(i<L.length){
		if(L.data[i]==x){
			k++;
		}else{
			L.data[i-k] = L.data[i];
		}
		i ++;
	}
	L.length -= k;
	return ture;
}

//第四题
//算法思路：找出有序顺序表中第一个大于s的元素位置i，
//并找到第一个大于等于t的位置j，从i起，元素前移j-i个单位
bool DeleteStoT(SqList &L, ElemType s,ElemType t){
	if(t>=s||L.length==0)return false;
	int i = 0,j = 0;
	while(L.data[i]<s&&i<L.length){
		i++;
	}
	if(i>L.length){
		return false;
	}
	while(L.data[j]<=t&&j<L.length){
		j++;
	}
	if(j>L.length){
		return false;
	}
	for(;j<L.lenth;i++,j++){
		L.data[i] = L.data[j];
	}
	L.length = i;
	return ture;
}

//第五题
//算法思路：从前开始扫描，若为范围内，k加一，若不为x，元素前移k个位置
bool DeleteStoT(SqList &L, ElemType s,ElemType t){
	int k = 0,i = 0;
	if(t>=s||L.length==0)return false;
	while(i<L.length){
		if(L.data>=s&&L.data<=t){
			k ++;
		}else{
			L.data[i-k] = L.data[i];
		}
		i ++;
	}
	L.lenth = L.length - k;
	return true;
}

//第六题
//算法思路1：依次往后扫描，若是与前一个元素相等（满足删除条件）,k加1，若不等，元素前移k各单位
bool Distinct1(SqList &L){
	if(L.length==0)return  false;
	int k = 0;
	for(int i = 1;i<L.length;i++){
		if(L.data[i] = L.data[i-1]){
			k ++;
		}else{
			L.data[i-k] = L.data[i];
		}
	}
	L.length = L.length - k;
	return true;
}
//算法思路2：设立ij两个指针，初始化是分别指向前两个元素，i记录无序表最后一个元素的位置
//j往后移动，若ij所指元素不等，把j所指元素插入无需表，i自增
bool Distinct2(SqList &L){
	if(L.length==0)return  false;
	int i, j;
	for(i = 0,j = 1;j<L.length;j++){
		if(L.data[i]!=L.data[j]){
			L.data[++i] = L.data[j];
		}
	}
	L.length = i + 1;
	return true;
}

/*小结：删除表中满足某条件的元素
定义变量temp计数，从前往后扫描，满足某条件，temp自增1，若不满足，元素前移temp个单位
!!!!!最后修改改表长为L.length-temp
*/

//第七题
//算法思路：使用二路归并排序合并两有序表(增序)
bool Merge(SqList M, SqList N,SqList &L){
	int i = 0,j = 0,k = 0;
	if(M.length+N.length>L.MaxSize)return false;
	while(i<M.length&&j<N.length){
		if(M.data[i]<=N.data[j]){
			L.data[k++] = M.data[i++];
		}else{
			L.data[k++] = N.data[j++];
		}
	}
	if(i>=M.length){
		for(;j < N.length;j++){
			L.data[k++] = N.data[j];
		}
	}
	if(j>=N.length){
		for(;i < M.length;i++){
			L.data[k++] = M.data[i];
		}
	}
	L.length = k;
	return true;
}

//第八题
//算法思路1(暴力解)：使用临时数组存储较短的数组，移动另一数组，最后进行赋值
bool Exchange(SqList &A,int m,int n){	
	ElemType temp[m];
	for(int i = 0;i< m;i++)
		temp[i] = A.data[m];
	for(int i = m;i<m+n；i++)
		A.data[i-m] = A.data[i];
	for(int i = n,i<m+n;i++)
		A.data[i] = temp[i-n];
	return true;
}
//算法思路2：①对数组A使用逆置算法；②对两个子数组使用逆置算法
void Reverse(SqList &L){
	ElemType temp;
	for(int i = 0;i<length/2;i++){
		temp = L.data[i];
		L.data[i] = L.data[length-i-1];
		L.data[length-i-1] = temp;
	}
}

bool Exchange(SqList &L){
	Reverse(L);
	
}


//第九题
//算法思路：使用折半查找，并对查找失败情况改写
bool BinaryFind(SqList &L,ElemType x){
	int low,high,mid;
	low = 0,high = L.length-1;
	
	while(high>low){
		mid = (low+high)/2;
		if(L.data[mid] = &&mid!=L.length-1){
			ElemType temp = L.data[mid+1];
			L.data[mid+1] = L.data[mid];
			L.data[mid] = L.data[mid+1];
			break;
		}
		if(l.data[mid]>x)
			high = mid-1;
		else
			low = mid+1;
	}
	if(low>high){
		for(int i = L.length;i>=low -1;i--){
			L.data[i] = L.data[i-1];
		}
		L.data[low-1] = x;
		L.length ++;
	}
}

//第十题
//算法思路：左移p个单位<=>①0~p-1倒置;②p~n倒置;③0~n倒置
void Reverse(SqList &L,ElemType begin,ElemType end){
	for(int i = 0;i<(begin+end)/2;i++){
		int temp = L.data[i];
		L.data[i] = L.data[end-i];
		L.data[end-i] = L.data[i];
	}
}

bool LeftMove(SqList &L){
	Reverse(L,0,p-1);
	Reverse(L,p,n-1);
	Reverse(L,0,n-1);
	return true;
}

//第十一题
//算法思路：设AB长均为n，由于AB为升序序列，使用归并排序，得到的新数组中第n个元素即为中位数
void Merge_Mid(SqList &C,SqList A,SqList B,int n,ElemType &mid){
	int C.length  = 0
	while(C.length<n){
		int i = 0,j =0;
		if(A.data[i]<B.data[j]){
			C.data[C.length++] = A.data[i++];
		}else{
			C.data[C.length++] = B.data[j++];
		}
	}
	mid = C.data[C.length-1];
}
//时间复杂度O（n）;空间复杂度O（1） 
