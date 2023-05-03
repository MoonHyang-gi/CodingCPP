#include <stdio.h>
#include <string.h>

int m_scanf(const char* format, int* var) {
    char buffer[256];
    int result = 0;
    int value = 0;
    int index = 0;
    float value_float = 0.0;

    //문자열 입력 받기
    gets(buffer, sizeof(buffer), stdin);

    //입력 문자열을 형식 문자열에 따라 변환
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            switch (format[++i]) {
            //정수 변환
            case 'd':
                while (buffer[result] >= '0' && buffer[result] <= '9') {
                    value = value * 10 + (buffer[result++] - '0');
                }

                if (buffer[result] != '\0') {
                    //숫자가 아닌 문자가 남아 있으면 오류 출력
                    return -1;
                }

                *var = value;
                break;

            //실수 변환
            case 'f':
                while (buffer[result] >= '0' && buffer[result] <= '9') {
                    value_float = value_float * 10.0 + (buffer[result++] - '0');
                }
                if (buffer[result] == '.') {
                    int decimal_count = 0;
                    while (buffer[++result] >= '0' && buffer[result] <= '9') {
                        value_float = value_float * 10.0 + (buffer[result] - '0');
                        decimal_count++;
                    }
                    while (decimal_count--) {
                        value_float /= 10.0;
                    }
                }
                *(float*)var = value_float;
                break;

            //문자 변환
            case 'c':
                *(char*)var = buffer[result++];
                break;

            //문자열 변환
            case 's':
                while (buffer[result] != '\0' && buffer[result] != ' ') {
                    *((char*)var + index++) = buffer[result++];
                }
                *((char*)var + index) = '\0';
                break;

            default:
                //지원하지 않는 형식 문자열일 경우
                return -1;
            }
        }
        else {
            //일치하지 않는 문자일 경우
            if (format[i] != buffer[result++]) {
                return -1;
            }
        }
    }

    //반환값은 변환된 변수의 개수 (한 개일 경우 1, 없을 경우 0)
    return 1;
}

int main() {
    int num;
    float fnum;
    char ch;
    char str[256];
    
    printf("정수값을 입력하세요: ");
    if (m_scanf("%d", &num) == 1)
        printf("입력한 정수값은 %d\n", num);
    else
        printf("Error\n");
        

    printf("실수값을 입력하세요(00.000000): ");
    if(m_scanf("%f", &fnum) == 1)
        printf("입력한 실수값은 %f\n", fnum);
    else
        printf("Error\n");

    printf("문자값을 입력하세요: ");
    if(m_scanf("%c", &ch) == 1)
        printf("입력한 문자값은 %c\n", ch);
    else
        printf("Error\n");

    printf("문자열을 입력하세요: ");
    if(m_scanf("%s", &str) == 1)
        printf("입력한 문자열은 %s\n", str);
    else
        printf("Error\n");



    return 0;
}

