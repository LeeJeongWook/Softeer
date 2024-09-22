#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATION 1000000
#define MAX_LINES 1000

// BFS�� ���� Queue ����ü ����
typedef struct {
    int station;
    int transfers;
} Node;

Node queue[MAX_STATION];
int front = 0, rear = 0;
int visited[MAX_STATION];

// ť �Լ� ����
void enqueue(int station, int transfers) {
    queue[rear].station = station;
    queue[rear].transfers = transfers;
    rear++;
}

Node dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int solution(const char* subway[], size_t subway_len, int start, int end) {
    memset(visited, -1, sizeof(visited));  // �湮 �迭 �ʱ�ȭ
    front = rear = 0;  // ť �ʱ�ȭ
    
    enqueue(start, 0);  // ���� �� ť�� ����
    visited[start] = 0;

    // BFS Ž��
    while (!isEmpty()) {
        Node current = dequeue();
        int curr_station = current.station;
        int curr_transfers = current.transfers;

        // �������� �����ϸ� ȯ�� Ƚ�� ��ȯ
        if (curr_station == end) {
            printf("ans: %d\n", curr_station);
            return curr_transfers;
        }

        for (size_t line = 0; line < subway_len; line++) {
            // �뼱 ���ڿ����� ���� ���� ���ԵǾ� �ִ��� Ȯ��
            char temp[100];
            strcpy(temp, subway[line]);
            char* token = strtok(temp, " ");
            int isInLine = 0;
            
            // �ش� �뼱�� ���� ���� ���ԵǾ� �ִ��� Ȯ��
            while (token != NULL) {
                if (atoi(token) == curr_station) {
                    isInLine = 1;
                    break;
                }
                token = strtok(NULL, " ");
            }
            
            // ���� ���� �ش� �뼱�� ���ԵǾ� ������, ���� ������ �̵�
            if (isInLine) {
                strcpy(temp, subway[line]);
                token = strtok(temp, " ");
                while (token != NULL) {
                    int next_station = atoi(token);
                    // ���� �湮���� ���� ���̶��
                    if (visited[next_station] == -1) {
                        // ȯ�� ���� ����
                        if (curr_station == next_station || visited[curr_station] == visited[next_station]) {
                            visited[next_station] = curr_transfers;  // ���� �뼱�̸� ȯ�� ����
                        } else {
                            visited[next_station] = curr_transfers + 1;  // �ٸ� �뼱���� ȯ�� ��
                        }
                        enqueue(next_station, visited[next_station]);
                    }
                    token = strtok(NULL, " ");
                }
            }
        }
    }

    return -1;  // ������ �� ���� ���
}

int main() {
    const char* subway[] = {
        "1 2 3 4 5 6 7 8",
        "2 11",
        "0 11 10",
        "3 17 19 12 13 9 14 15 10",
        "20 21"
    };
    int start = 1;
    int end = 9;
    int result = solution(subway, 5, start, end);

    if (result != -1) {
        printf("�ּ� ȯ�� Ƚ��: %d\n", result);
    } else {
        printf("������ �� �����ϴ�.\n");
    }

    return 0;
}
