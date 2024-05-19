#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstring>
  
// ��������  
int count_chars(FILE *fp);  
int count_words(FILE *fp);  
  
int main(int argc, char *argv[]) {  
    // ����������  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // ���ļ�  
    FILE *fp = fopen(argv[2], "r");  
    if (!fp) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    // ���ݲ���ͳ���ַ����򵥴���  
    int count = 0;  
    if (strcmp(argv[1], "-c") == 0) {  
        count = count_chars(fp);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        count = count_words(fp);  
    } else {  
        printf("Invalid parameter: %s\n", argv[1]);  
        fclose(fp);  
        return 1;  
    }  
  
    // ������  
    if (strcmp(argv[1], "-c") == 0) {  
        printf("�ַ�����%d\n", count);  
    } else {  
        printf("��������%d\n", count);  
    }  
  
    // �ر��ļ�  
    fclose(fp);  
    return 0;  
}  
  
// ͳ���ַ���  
int count_chars(FILE *fp) {  
    int ch, count = 0;  
    while ((ch = fgetc(fp)) != EOF) {  
        count++;  
    }  
    rewind(fp); // �����ļ�ָ�뵽�ļ���ʼ  
    return count;  
}  
  
// ͳ�Ƶ�����  
int count_words(FILE *fp) {  
    int ch, in_word = 0, count = 0;  
    while ((ch = fgetc(fp)) != EOF) {  
        // ���Է���ĸ���ֵ��ַ�����������λ�ڵ����ڲ�  
        if (isalpha(ch)) {  
            if (!in_word) {  
                in_word = 1;  
                count++;  
            }  
        } else {  
            in_word = 0;  
        }  
    }  
    rewind(fp); // �����ļ�ָ�뵽�ļ���ʼ  
    return count;  
}
