#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //구조체 생성
    int num;
    char ch;
    char str[256];
} MyStruct;

             // 파일 입력 읽기 , 입력 값 읽기 , 가변 인자
void myScanf(FILE* file, const char* format, ...)
{
    int* intValue;
    char* chValue;
    char* strValue;

    size_t formatLen = strlen(format);
    size_t argIndex = 0;

    for (size_t i = 0; i < formatLen; i++)
    {
        if (format[i] == '%')
        {
            switch (format[++i])
            {
            //%d 형식 지정
            case 'd':
                intValue = ((int**)&format)[++argIndex]; //참조하여 값 저장
                fscanf_s(stdin, "%d", intValue); //정수값 stdin으로 입력
                fprintf(file, "%d ", *intValue); //file에 출력
                break;

            //%c 형식 지정
            case 'c':
                chValue = ((char**)&format)[++argIndex];
                fscanf_s(stdin, " %c", chValue, 1);
                fprintf(file, "%c ", *chValue);
                break;

            //%s 형식 지정
            case 's':
                strValue = ((char**)&format)[++argIndex];
                                //최대 255개의 문자 입력
                fscanf_s(stdin, "%255s", strValue, (unsigned int)sizeof(strValue));
                fprintf(file, "%s ", strValue);
                break;

            default:
                //예외 처리(지원하지 않는 형식 지정자)
                printf("Error\n");
                break;
            }
        }
    }
}

int main()
{
    FILE* file = fopen("output.txt", "w"); //file open
    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    MyStruct myStruct; //구조체 인스턴스 생성

    printf("이름을 입력하세요: ");
    myScanf(file, "%s", myStruct.str);

    printf("점수를 입력하세요: ");
    myScanf(file, "%d", &myStruct.num);
    if (myStruct.num != "%d") {
        printf("Error 점수가 아닙니다.\n");
        return -1;
    }

    printf("성적을 입력하세요: ");
    myScanf(file, " %c", &myStruct.ch);

    printf("내 이름은 %s이고 이번학기 점수는 %d점이고 성적은 %c를 받았습니다.", myStruct.str, myStruct.num, myStruct.ch);

    fclose(file); //file close

    return 0;
}
