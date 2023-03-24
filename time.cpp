#include <stdio.h>
#include <time.h>
#include<windows.h>
int main()
{
    time_t now; // time_t类型是定义在time.h头文件中的数据类型，它存储了当前时间的秒数
    struct tm *local_time; // struct tm结构体类型用于存储当前时间的年、月、日、小时、分钟和秒等信息

    while(1) // 无限循环，使计时器一直运行
    {
        now = time(NULL); // 获取当前时间的秒数
        local_time = localtime(&now); // 将当前时间的秒数转换为本地时间

        // 输出当前时间的小时、分钟和秒，并以指定格式显示
        printf("%02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

        // 延迟1秒，以达到显示数的变化效果
        Sleep(1);
    }

    return 0;
}

