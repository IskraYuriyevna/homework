#include <stdio.h>
#include <stdlib.h>

// 检查文件大小是否为整数字节数
int checkFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size % sizeof(int) == 0;
}

// 从文件中读取两个数字并返回较大的一个
// 同时将较小的数字写回原位置
int getAndWriteMax(FILE *file, long pos1, long pos2) {
    int num1, num2;
    
    fseek(file, pos1, SEEK_SET);
    fread(&num1, sizeof(int), 1, file);
    
    fseek(file, pos2, SEEK_SET);
    fread(&num2, sizeof(int), 1, file);
    
    if (num1 > num2) {
        fseek(file, pos2, SEEK_SET);
        fwrite(&num1, sizeof(int), 1, file);
        return num2;
    } else {
        fseek(file, pos1, SEEK_SET);
        fwrite(&num2, sizeof(int), 1, file);
        return num1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("使用方法: %s 源文件 目标文件\n", argv[0]);
        return 1;
    }

    // 打开源文件
    FILE *source = fopen(argv[1], "rb+");
    if (!source) {
        printf("无法打开源文件\n");
        return 1;
    }

    // 检查文件大小是否正确
    if (!checkFileSize(source)) {
        fclose(source);
        FILE *result = fopen(argv[2], "wb");
        fclose(result);
        return 0;
    }

    // 获取文件中整数的数量
    fseek(source, 0, SEEK_END);
    long fileSize = ftell(source);
    int numCount = fileSize / sizeof(int);

    // 打开目标文件
    FILE *result = fopen(argv[2], "wb");
    if (!result) {
        printf("无法打开目标文件\n");
        fclose(source);
        return 1;
    }

    // 冒泡排序思想，每次找出最大值写入目标文件
    for (int i = 0; i < numCount; i++) {
        int maxNum;
        
        // 第一次读取第一个数作为当前最大值
        fseek(source, 0, SEEK_SET);
        fread(&maxNum, sizeof(int), 1, source);

        // 遍历剩余的数，不断更新最大值
        for (long pos = sizeof(int); pos < fileSize; pos += sizeof(int)) {
            maxNum = getAndWriteMax(source, pos - sizeof(int), pos);
        }

        // 将最大值写入目标文件
        fwrite(&maxNum, sizeof(int), 1, result);
        fileSize -= sizeof(int);
    }

    fclose(source);
    fclose(result);
    return 0;
}