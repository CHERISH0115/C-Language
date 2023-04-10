#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;              // ���ݸ���
    double conf;        // ���Ÿ���
    int precision;      // ����λ��
    double k_factor;    // ����ϵ��
    char unit[20];      // ���ݵĵ�λ

    // ��ȡ�û�����
    printf("���������ݸ���: ");
    scanf("%d", &n);

    printf("���������Ÿ���(0~1֮��): ");
    scanf("%lf", &conf);

    printf("������Ҫ������λ��: ");
    scanf("%d", &precision);

    printf("����������ϵ��(Ĭ��Ϊ1): ");
    scanf("%lf", &k_factor);

    printf("���������ݵĵ�λ: ");
    scanf("%s", unit);

    double data[n];     // ��������
    printf("����������: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }

    // ����ƽ��ֵ
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    double mean = sum / n;

    // ����A�಻ȷ����
    double a = 0;
    for (int i = 0; i < n; i++) {
        a += pow(data[i] - mean, 2);
    }
    a = sqrt(a / (n * (n - 1)));

    // ����B�಻ȷ����
    double b = k_factor * 1.96 * sqrt(a * a / n);

    // ���㲻ȷ����
    double u = sqrt(a * a + b * b);

    // �����׼ƫ��
    double std = sqrt(a * a);

    // ����ƽ��ֵ�ı�׼ƫ��
    double mean_std = std / sqrt(n);

    // ��������ƽ��ƫ��
    double mad = 0;
    for (int i = 0; i < n; i++) {
        mad += fabs(data[i] - mean);
    }
    mad /= n;

    // ����ϳɲ�ȷ����
    double k = sqrt(pow((1 - conf) / 2, 2) + pow((1 - conf) / 2, 2));
    double uc = k * u;

    // ������Բ�ȷ����
    double ruc = uc / mean * 100;

    // ������
    printf("ƽ��ֵ: %.*lf\n", precision, mean);
    printf("��׼ƫ��: %.*lf\n", precision, std);
    printf("ƽ��ֵ�ı�׼ƫ��: %.*lf\n", precision, mean_std);
    printf("A�಻ȷ����: %.*lf\n", precision, a);
    printf("B�಻ȷ����: %.*lf\n", precision, b);
    printf("�ϳɲ�ȷ����: %.*lf\n", precision, uc);
    printf("��Բ�ȷ����: %.*lf%%\n", precision, ruc);
    printf("----------------------------------------\n");
    printf("��׼��������\n");
	printf("���Ÿ���P=%.3lf\n", conf);
	printf("x=(%.3lf��%.3lf)%s\n", mean, uc, unit);
	printf("��Բ�ȷ����ED=%.2lf%%\n", ruc);

	return 0;
}
