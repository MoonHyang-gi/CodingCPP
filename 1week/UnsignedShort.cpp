#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	unsigned short n;

	cout << "0 부터 65535 사이의 숫자를 입력하세요.\n숫자를 입력하면 반대로 출력됩니다.\n";
	cin >> n;
	
	if (n >= 65535) {
		cout << "숫자를 잘못 입력하였습니다.";
	}
	else {
		while (n > 0) {
			printf("%d", n % 10);
			n = n / 10;
		}
	}

	return 0;
}