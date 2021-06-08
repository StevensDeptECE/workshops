int f() {
	return 3;
}

int g(int a, int b) {
	return a + b;
}

// this symbol is not global, and not exported
static int h() {
	// this function is Private. Make sure it cannot be called from the outside
	return -3;
}

int x[10] = {9, 1, 3};
