#include <iostream>
#include <limits.h>

using namespace std;

int main() {
	unsigned short n;

	cout << "0 ���� 65535 ������ ���ڸ� �Է��ϼ���.\n���ڸ� �Է��ϸ� �ݴ�� ��µ˴ϴ�.\n";
	cin >> n;
	
	if (n >= 65535) {
		cout << "���ڸ� �߸� �Է��Ͽ����ϴ�.";
	}
	else {
		while (n > 0) {
			printf("%d", n % 10);
			n = n / 10;
		}
	}

	return 0;
}