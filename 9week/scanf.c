#include <stdio.h>
#include <string.h>

int m_scanf(const char* format, int* var) {
    char buffer[256];
    int result = 0;
    int value = 0;
    int index = 0;
    float value_float = 0.0;

    //���ڿ� �Է� �ޱ�
    gets(buffer, sizeof(buffer), stdin);

    //�Է� ���ڿ��� ���� ���ڿ��� ���� ��ȯ
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            switch (format[++i]) {
            //���� ��ȯ
            case 'd':
                while (buffer[result] >= '0' && buffer[result] <= '9') {
                    value = value * 10 + (buffer[result++] - '0');
                }

                if (buffer[result] != '\0') {
                    //���ڰ� �ƴ� ���ڰ� ���� ������ ���� ���
                    return -1;
                }

                *var = value;
                break;

            //�Ǽ� ��ȯ
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

            //���� ��ȯ
            case 'c':
                *(char*)var = buffer[result++];
                break;

            //���ڿ� ��ȯ
            case 's':
                while (buffer[result] != '\0' && buffer[result] != ' ') {
                    *((char*)var + index++) = buffer[result++];
                }
                *((char*)var + index) = '\0';
                break;

            default:
                //�������� �ʴ� ���� ���ڿ��� ���
                return -1;
            }
        }
        else {
            //��ġ���� �ʴ� ������ ���
            if (format[i] != buffer[result++]) {
                return -1;
            }
        }
    }

    //��ȯ���� ��ȯ�� ������ ���� (�� ���� ��� 1, ���� ��� 0)
    return 1;
}

int main() {
    int num;
    float fnum;
    char ch;
    char str[256];
    
    printf("�������� �Է��ϼ���: ");
    if (m_scanf("%d", &num) == 1)
        printf("�Է��� �������� %d\n", num);
    else
        printf("Error\n");
        

    printf("�Ǽ����� �Է��ϼ���(00.000000): ");
    if(m_scanf("%f", &fnum) == 1)
        printf("�Է��� �Ǽ����� %f\n", fnum);
    else
        printf("Error\n");

    printf("���ڰ��� �Է��ϼ���: ");
    if(m_scanf("%c", &ch) == 1)
        printf("�Է��� ���ڰ��� %c\n", ch);
    else
        printf("Error\n");

    printf("���ڿ��� �Է��ϼ���: ");
    if(m_scanf("%s", &str) == 1)
        printf("�Է��� ���ڿ��� %s\n", str);
    else
        printf("Error\n");



    return 0;
}

