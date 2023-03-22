#include <iostream>
#include <map>
#include <conio.h>

using namespace std;

int toNumber(string roman) { //로마자 문자열을 인수로 받아 해당하는 정수를 반환
	map<char, int> romanMap; 
	romanMap['I'] = 1; //I는 1로 (III면 3)
	romanMap['V'] = 5; //V는 5로
	romanMap['X'] = 10; //X는 10으로
	romanMap['L'] = 50; //L은 50으로
	romanMap['C'] = 100; //C는 100으로
	romanMap['D'] = 500; //D는 500으로
	romanMap['M'] = 1000; //M은 1000으로 저장

	int num = 0; //int형 num에 0 지정
	int prev = 0; //int형 prev에 0 지정

	for (int i = roman.length() - 1; i >= 0; i--) { //i(roman의 길이-1)가 0이 되거나 클때까지 빼기 반복, -1을 해주는 이유는 문자열의 오른쪽 끝에서 왼쪽으로 읽어나가기 위해서
		int curr = romanMap[roman[i]]; //curr에 romanMap으로 저장한 값
		if (curr < prev) { //이전 문자(curr)보다 현재 문자(prev)가 큰 경우
			num -= curr; //curr 빼주기
		}
		else {
			num += curr; //curr 더해주기
		}
		prev = curr; //prev가 curr이 될 때까지
	}
	return num; //num 반환
}

int main() {
	string roman = ""; //roman을 string으로 지정
	char input; //input을 char형으로 지정
	
	while (true) {
		cout << "로마 숫자를 입력하세요.(종료하려면 ESC)\n"; //글 출력
		input = getchar(); //키 입력 받기

		if (input == 27) { //27은 esc의 아스키 코드
			break; //누르면 실행 끝
		}
		else {
			cin >> roman; //로마자 입력

			if (!toNumber(roman)) { //로마자가 아니면
				cout << "잘못된 정보를 입력하였습니다.\n";
			}
			else {
				int num = toNumber(roman); //숫자 계산(toNumber 호출)
				cout << num << endl; //숫자 출력
			}
		}
	}

	return 0; //0으로 반환
}

