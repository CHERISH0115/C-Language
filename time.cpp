#include <stdio.h>
#include <time.h>
#include<windows.h>
int main()
{
    time_t now; // time_t�����Ƕ�����time.hͷ�ļ��е��������ͣ����洢�˵�ǰʱ�������
    struct tm *local_time; // struct tm�ṹ���������ڴ洢��ǰʱ����ꡢ�¡��ա�Сʱ�����Ӻ������Ϣ

    while(1) // ����ѭ����ʹ��ʱ��һֱ����
    {
        now = time(NULL); // ��ȡ��ǰʱ�������
        local_time = localtime(&now); // ����ǰʱ�������ת��Ϊ����ʱ��

        // �����ǰʱ���Сʱ�����Ӻ��룬����ָ����ʽ��ʾ
        printf("%02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

        // �ӳ�1�룬�Դﵽ��ʾ���ı仯Ч��
        Sleep(1);
    }

    return 0;
}

