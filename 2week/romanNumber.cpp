#include <iostream>
#include <map>
#include <conio.h>

using namespace std;

int toNumber(string roman) { //�θ��� ���ڿ��� �μ��� �޾� �ش��ϴ� ������ ��ȯ
	map<char, int> romanMap; 
	romanMap['I'] = 1; //I�� 1�� (III�� 3)
	romanMap['V'] = 5; //V�� 5��
	romanMap['X'] = 10; //X�� 10����
	romanMap['L'] = 50; //L�� 50����
	romanMap['C'] = 100; //C�� 100����
	romanMap['D'] = 500; //D�� 500����
	romanMap['M'] = 1000; //M�� 1000���� ����

	int num = 0; //int�� num�� 0 ����
	int prev = 0; //int�� prev�� 0 ����

	for (int i = roman.length() - 1; i >= 0; i--) { //i(roman�� ����-1)�� 0�� �ǰų� Ŭ������ ���� �ݺ�, -1�� ���ִ� ������ ���ڿ��� ������ ������ �������� �о���� ���ؼ�
		int curr = romanMap[roman[i]]; //curr�� romanMap���� ������ ��
		if (curr < prev) { //���� ����(curr)���� ���� ����(prev)�� ū ���
			num -= curr; //curr ���ֱ�
		}
		else {
			num += curr; //curr �����ֱ�
		}
		prev = curr; //prev�� curr�� �� ������
	}
	return num; //num ��ȯ
}

int main() {
	string roman = ""; //roman�� string���� ����
	char input; //input�� char������ ����
	
	while (true) {
		cout << "�θ� ���ڸ� �Է��ϼ���.(�����Ϸ��� ESC)\n"; //�� ���
		input = getchar(); //Ű �Է� �ޱ�

		if (input == 27) { //27�� esc�� �ƽ�Ű �ڵ�
			break; //������ ���� ��
		}
		else {
			cin >> roman; //�θ��� �Է�

			if (!toNumber(roman)) { //�θ��ڰ� �ƴϸ�
				cout << "�߸��� ������ �Է��Ͽ����ϴ�.\n";
			}
			else {
				int num = toNumber(roman); //���� ���(toNumber ȣ��)
				cout << num << endl; //���� ���
			}
		}
	}

	return 0; //0���� ��ȯ
}

