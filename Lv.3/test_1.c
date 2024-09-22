#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 기지국이 커버하는 영역 안에 점이 있는지 여부를 판단하는 함수
int is_inside_circle(double x, double y, double cx, double cy, double r) {
    double distance_squared = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    return distance_squared <= r * r;
}

// 배열에서 주어진 기지국 영역 내에 포함된 값들의 합을 계산하는 함수
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
    // 입력 데이터: 기지국 좌표 (x, y)와 반지름 (r), 배열 v
    double x_values[2][2] = {{5}, {3, 4}};
    double y_values[2][2] = {{5}, {3, 5}};
    double r_values[2][2] = {{5}, {2, 3}};
    int v_values[2][10] = {{92, 83, 14, 45, 66, 37, 28, 9, 10, 81},
                           {12, 83, 54, 35, 686, 337, 258, 95, 170, 831}};
    int lengths[2] = {10, 10};  // 배열 v의 길이

    // 결과 계산 및 출력
    for (int i = 0; i < 2; i++) {
        int result_sum = 0;
        for (int j = 0; j < 2; j++) {
            result_sum += calculate_sum_inside_circle(x_values[i][j], y_values[i][j], r_values[i][j], v_values[i], lengths[i]);
        }
        printf("result: %d\n", result_sum);
    }

    return 0;
}
