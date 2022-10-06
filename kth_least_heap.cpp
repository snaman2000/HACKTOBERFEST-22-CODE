#include <bits/stdc++.h> 
using namespace std; 
struct Heap { 
	vector<int> v; 
	int n; 
	Heap(int i = 0) 
		: n(i) 
	{ 
		v = vector<int>(n); 
	} 
}; 

void swap(int& a, int& b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
}
int parent(int i) 
{ 
	return (i - 1) / 2; 
} 
int left(int i) 
{ 
	return 2 * i + 1; 
} 

inline int right(int i) 
{ 
	return 2 * i + 2; 
} 
void heapify(Heap& h, int i) 
{ 
	int l = left(i), r = right(i), m = i; 
	if (l < h.n && h.v[i] > h.v[l]) 
		m = l; 
	if (r < h.n && h.v[m] > h.v[r]) 
		m = r; 
	if (m != i) { 
		swap(h.v[m], h.v[i]); 
		heapify(h, m); 
	} 
}
int extractMin(Heap& h) 
{ 
	if (!h.n) 
		return -1; 
	int m = h.v[0]; 
	h.v[0] = h.v[h.n-- - 1]; 
	heapify(h, 0); 
	return m; 
} 
int findKthSmalles(Heap &h, int k) { 
	for (int i = 1; i < k; ++i) 
		extractMin(h); 
	return extractMin(h); 
} 

int main() 
{ 
	Heap h1(7),h2(7); 
	h1.v = vector<int>{ 10, 50, 40, 75, 60, 65, 45 }; 
    h2.v = vector<int>{ 10, 50, 40, 75, 60, 65, 45 }; 
	int k ;
    cout<<"Enter the value of k ";
    cin>>k;
	cout << "kth least element is "<<findKthSmalles(h1, k); 
    cout << "\nkth largest element is "<<findKthSmalles(h2,7-k); 
	return 0; 
} 
