#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATION 1000000
#define MAX_LINES 1000

// BFS를 위한 Queue 구조체 정의
typedef struct {
    int station;
    int transfers;
} Node;

Node queue[MAX_STATION];
int front = 0, rear = 0;
int visited[MAX_STATION];

// 큐 함수 정의
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
    memset(visited, -1, sizeof(visited));  // 방문 배열 초기화
    front = rear = 0;  // 큐 초기화
    
    enqueue(start, 0);  // 시작 역 큐에 삽입
    visited[start] = 0;

    // BFS 탐색
    while (!isEmpty()) {
        Node current = dequeue();
        int curr_station = current.station;
        int curr_transfers = current.transfers;

        // 도착역에 도달하면 환승 횟수 반환
        if (curr_station == end) {
            printf("ans: %d\n", curr_station);
            return curr_transfers;
        }

        for (size_t line = 0; line < subway_len; line++) {
            // 노선 문자열에서 현재 역이 포함되어 있는지 확인
            char temp[100];
            strcpy(temp, subway[line]);
            char* token = strtok(temp, " ");
            int isInLine = 0;
            
            // 해당 노선에 현재 역이 포함되어 있는지 확인
            while (token != NULL) {
                if (atoi(token) == curr_station) {
                    isInLine = 1;
                    break;
                }
                token = strtok(NULL, " ");
            }
            
            // 현재 역이 해당 노선에 포함되어 있으면, 다음 역으로 이동
            if (isInLine) {
                strcpy(temp, subway[line]);
                token = strtok(temp, " ");
                while (token != NULL) {
                    int next_station = atoi(token);
                    // 아직 방문하지 않은 역이라면
                    if (visited[next_station] == -1) {
                        // 환승 여부 결정
                        if (curr_station == next_station || visited[curr_station] == visited[next_station]) {
                            visited[next_station] = curr_transfers;  // 같은 노선이면 환승 없음
                        } else {
                            visited[next_station] = curr_transfers + 1;  // 다른 노선으로 환승 시
                        }
                        enqueue(next_station, visited[next_station]);
                    }
                    token = strtok(NULL, " ");
                }
            }
        }
    }

    return -1;  // 도착할 수 없는 경우
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
        printf("최소 환승 횟수: %d\n", result);
    } else {
        printf("도착할 수 없습니다.\n");
    }

    return 0;
}
