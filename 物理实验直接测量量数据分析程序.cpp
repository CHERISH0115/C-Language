#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;              // 数据个数
    double conf;        // 置信概率
    int precision;      // 保留位数
    double k_factor;    // 修正系数
    char unit[20];      // 数据的单位

    // 获取用户输入
    printf("请输入数据个数: ");
    scanf("%d", &n);

    printf("请输入置信概率(0~1之间): ");
    scanf("%lf", &conf);

    printf("请输入要保留的位数: ");
    scanf("%d", &precision);

    printf("请输入修正系数(默认为1): ");
    scanf("%lf", &k_factor);

    printf("请输入数据的单位: ");
    scanf("%s", unit);

    double data[n];     // 数据数组
    printf("请输入数据: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    // 计算平均值
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    double mean = sum / n;

    // 计算A类不确定度
    double a = 0;
    for (int i = 0; i < n; i++) {
        a += pow(data[i] - mean, 2);
    }
    a = sqrt(a / (n * (n - 1)));

    // 计算B类不确定度
    double b = k_factor * 1.96 * sqrt(a * a / n);

    // 计算不确定度
    double u = sqrt(a * a + b * b);

    // 计算标准偏差
    double std = sqrt(a * a);

    // 计算平均值的标准偏差
    double mean_std = std / sqrt(n);

    // 计算算数平均偏差
    double mad = 0;
    for (int i = 0; i < n; i++) {
        mad += fabs(data[i] - mean);
    }
    mad /= n;

    // 计算合成不确定度
    double k = sqrt(pow((1 - conf) / 2, 2) + pow((1 - conf) / 2, 2));
    double uc = k * u;

    // 计算相对不确定度
    double ruc = uc / mean * 100;

    // 输出结果
    printf("平均值: %.*lf\n", precision, mean);
    printf("标准偏差: %.*lf\n", precision, std);
    printf("平均值的标准偏差: %.*lf\n", precision, mean_std);
    printf("A类不确定度: %.*lf\n", precision, a);
    printf("B类不确定度: %.*lf\n", precision, b);
    printf("合成不确定度: %.*lf\n", precision, uc);
    printf("相对不确定度: %.*lf%%\n", precision, ruc);
    printf("----------------------------------------\n");
    printf("标准输出结果：\n");
	printf("置信概率P=%.3lf\n", conf);
	printf("x=(%.3lf±%.3lf)%s\n", mean, uc, unit);
	printf("相对不确定度ED=%.2lf%%\n", ruc);

	return 0;
}
