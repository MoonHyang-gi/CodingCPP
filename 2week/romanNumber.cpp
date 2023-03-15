#include <iostream>
#include <map>

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
			num += curr; //num�� �����ֱ�
		}
		prev = curr; //prev�� curr�� �� ������
	}
	return num; //num ��ȯ
}

int main() {
	string roman; //roman �� string���� ����

	cout << "�θ� ���ڸ� �Է��ϼ���.\n"; //�� ���
	cin >> roman; //�θ� ���ڸ� ����ڰ� �Է��ϵ���

	int num = toNumber(roman); //���� ���(toNumber ȣ��)

	cout << num << endl; //num ���

	return 0; //0���� ��ȯ
}
