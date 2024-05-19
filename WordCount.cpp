#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstring>
  
// 函数声明  
int count_chars(FILE *fp);  
int count_words(FILE *fp);  
  
int main(int argc, char *argv[]) {  
    // 检查参数数量  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] [input_file_name]\n", argv[0]);  
        return 1;  
    }  
  
    // 打开文件  
    FILE *fp = fopen(argv[2], "r");  
    if (!fp) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    // 根据参数统计字符数或单词数  
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
  
    // 输出结果  
    if (strcmp(argv[1], "-c") == 0) {  
        printf("字符数：%d\n", count);  
    } else {  
        printf("单词数：%d\n", count);  
    }  
  
    // 关闭文件  
    fclose(fp);  
    return 0;  
}  
  
// 统计字符数  
int count_chars(FILE *fp) {  
    int ch, count = 0;  
    while ((ch = fgetc(fp)) != EOF) {  
        count++;  
    }  
    rewind(fp); // 重置文件指针到文件开始  
    return count;  
}  
  
// 统计单词数  
int count_words(FILE *fp) {  
    int ch, in_word = 0, count = 0;  
    while ((ch = fgetc(fp)) != EOF) {  
        // 忽略非字母数字的字符，除非它们位于单词内部  
        if (isalpha(ch)) {  
            if (!in_word) {  
                in_word = 1;  
                count++;  
            }  
        } else {  
            in_word = 0;  
        }  
    }  
    rewind(fp); // 重置文件指针到文件开始  
    return count;  
}
