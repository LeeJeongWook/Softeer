#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �������� Ŀ���ϴ� ���� �ȿ� ���� �ִ��� ���θ� �Ǵ��ϴ� �Լ�
int is_inside_circle(double x, double y, double cx, double cy, double r) {
    double distance_squared = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    return distance_squared <= r * r;
}

// �迭���� �־��� ������ ���� ���� ���Ե� ������ ���� ����ϴ� �Լ�
int calculate_sum_inside_circle(double cx, double cy, double r, int v[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (is_inside_circle(v[i] % 10, v[i] / 10, cx, cy, r)) {
            sum += v[i];
        }
    }
    return sum;
}

int main() {
    // �Է� ������: ������ ��ǥ (x, y)�� ������ (r), �迭 v
    double x_values[2][2] = {{5}, {3, 4}};
    double y_values[2][2] = {{5}, {3, 5}};
    double r_values[2][2] = {{5}, {2, 3}};
    int v_values[2][10] = {{92, 83, 14, 45, 66, 37, 28, 9, 10, 81},
                           {12, 83, 54, 35, 686, 337, 258, 95, 170, 831}};
    int lengths[2] = {10, 10};  // �迭 v�� ����

    // ��� ��� �� ���
    for (int i = 0; i < 2; i++) {
        int result_sum = 0;
        for (int j = 0; j < 2; j++) {
            result_sum += calculate_sum_inside_circle(x_values[i][j], y_values[i][j], r_values[i][j], v_values[i], lengths[i]);
        }
        printf("result: %d\n", result_sum);
    }

    return 0;
}
