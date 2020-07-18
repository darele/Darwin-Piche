//sum segment tree with segment update
//and segment query
//a few modifications to get min or max;

#include <bits/stdc++.h>
#define tam 300005
//first significant bit
//is the height of the tree
using namespace std;

int h;
int n;
int t[2 * tam];
int d[tam];//delayed changes to be made

void apply(int p, int val) {
	t[p] += val;
	if (p < n) d[p] += val; //if not leaf, apply
}

void build(int p) {
	//for max or min type
	//t[p] = max or min(t[p << 1] + t[p << 1 | 1] + d[p])
	while (p > 1) p >>= 1, t[p] = t[p << 1] + t[p << 1 | 1] + d[p];
}

//push changes from a leaf to all its parents
void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

//increase from [l, r)
void inc(int l, int r, int val) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, val);
		if (r & 1) apply(--r, val);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r) {
	l += n;
	r += n;
	push(l);
	push(r - 1);
	//adjust ans accordingly
	int ans = 0;
	for (; l < r; l >>= 1, r >>= 1) {
		//ans = max or min(ans, t[l++])
		if (l & 1) ans += t[l++];
		if (r & 1) ans += t[--r];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> n;
	//first significant bit
	//is the height of the tree
	h = sizeof(n) * 8 - __builtin_clz(n);
	//single elements are leaves from
	//n to 2 * n
	int in;
	for (int i = 0; i < n; i++) {
		cin >> in;
		inc(i, i + 1, in);
	}
	cout << endl;
	cout << query(4, 10);
	cout << endl;
	return 0;
}
