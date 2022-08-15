/*
* 线性表的顺序存储实现
*/

typedef int ElemType;

#define MaxSize 50
typedef struct {
	int length;
	ElemType data[MaxSize];
}SqList;

bool InsertList(SqList &L,int a, ElemType e){
	if (1 > a && a > L.length)
		return false;
	for (int i = L.length; i >= a; i--) {
		L.data[i] = L.data[i - 1];
	}
	L.data[a-1] = e;
	L.length++;
	return true;
}

bool DeleteList(SqList& L, int a, ElemType &e) {
	if (a<1 || a>L.length)
		return false;
	e = L.data[a - 1];
	for (int i = a; i < L.length; i++)
		L.data[i] = L.data[i + 1];
	L.length--;
	return true;
}

int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e)
			return i + 1;
	}
	return 0;
}