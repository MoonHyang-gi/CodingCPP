#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct { //����ü ����
    int* num;
    char* ch;
    char* str;
} MyStruct;

             // ���� �Է� �б� , �Է� �� �б� , ���� ����
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
            //%d ���� ����
            case 'd':
                intValue = ((int**)&format)[++argIndex]; //�����Ͽ� �� ����
                fscanf_s(stdin, "%d", intValue); //������ stdin���� �Է�
                fprintf(file, "%d ", *intValue); //file�� ���
                break;

            //%c ���� ����
            case 'c':
                chValue = ((char**)&format)[++argIndex];
                fscanf_s(stdin, " %c", chValue, 1);
                fprintf(file, "%c ", *chValue);
                break;

            //%s ���� ����
            case 's':
                strValue = ((char**)&format)[++argIndex];
                                //�ִ� 255���� ���� �Է�
                fscanf_s(stdin, "%255s", strValue, (unsigned int)sizeof(strValue));
                fprintf(file, "%s ", strValue);
                break;

            default:
                //���� ó��(�������� �ʴ� ���� ������)
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
        printf("������ �� �� �����ϴ�.");
        return 1;
    }

    MyStruct myStruct; //����ü �ν��Ͻ� ����

    //���� �޸� �Ҵ�
    myStruct.num = (int*)malloc(sizeof(int));
    myStruct.ch = (char*)malloc(sizeof(char));
    myStruct.str = (char*)malloc(sizeof(char) * 256);

    printf("�̸��� �Է��ϼ���: ");
    myScanf(file, "%s", myStruct.str);

    printf("������ �Է��ϼ���: ");
    myScanf(file, "%d", myStruct.num);

    printf("������ �Է��ϼ���: ");
    myScanf(file, " %c", myStruct.ch);

    printf("�� �̸��� %s�̰� �̹��б� ������ %d���̰� ������ %c�� �޾ҽ��ϴ�.", myStruct.str, *myStruct.num, *myStruct.ch);

    //���� �޸� ����
    free(myStruct.num);
    free(myStruct.ch);
    free(myStruct.str);

    fclose(file); //file close

    return 0;
}
