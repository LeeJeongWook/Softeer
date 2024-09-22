#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if a part of an IP address is valid (no leading zeros unless it's "0")
bool is_valid_part(const char* part) {
    if (part[0] == '0' && strlen(part) > 1) {
        return false;
    }

    int num = atoi(part);
    if (num < 0 || num > 255) {
        return false;
    }

    return true;
}

// Helper function to check if the IP is in the correct format (IPv4)
bool is_valid_ipv4(const char* ip) {
    int dots = 0;
    char ip_copy[16];
    strcpy(ip_copy, ip);
    
    char* part = strtok(ip_copy, ".");
    while (part) {
        if (!is_valid_part(part)) {
            return false;  // Invalid part found
        }
        dots++;
        part = strtok(NULL, ".");
    }

    return dots == 4;  // Valid if there are exactly 4 parts (3 dots)
}

// Function to check if the IP is in the banned list
bool is_banned(const char* ip, const char* banned_list[], size_t banned_list_len) {
    for (size_t i = 0; i < banned_list_len; i++) {
        if (strcmp(ip, banned_list[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Function to check if the IP is in the registered list
bool is_registered(const char* ip, const char* registered_list[], size_t registered_list_len) {
    for (size_t i = 0; i < registered_list_len; i++) {
        if (strcmp(ip, registered_list[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Solution function
int* solution(const char* ip_addresses[], size_t ip_addresses_len, const char* registered_list[], size_t registered_list_len, const char* banned_list[], size_t banned_list_len) {
    // 동적으로 IP 주소 수만큼 메모리 할당
    int* answer = (int*)malloc(ip_addresses_len * sizeof(int));

    for (size_t i = 0; i < ip_addresses_len; i++) {
        const char* ip = ip_addresses[i];
        
        if (!is_valid_ipv4(ip)) {
            answer[i] = 1;  // 규격에 맞지 않는 IP 주소
        } else if (is_banned(ip, banned_list, banned_list_len)) {
            answer[i] = 3;  // 차단된 IP 주소
        } else if (is_registered(ip, registered_list, registered_list_len)) {
            answer[i] = 0;  // 서버에 등록된 IP 주소
        } else {
            answer[i] = 2;  // 해당 IP에 대한 정보 없음 (등록 또는 차단된 IP가 아님)
        }
    }
    
    return answer;
}

// Test the solution function
int main() {
    const char* ip_addresses[] = { "123.023.123.123", "1.1.1.12", "119.123.45.39", "127.0.0.1" };
    const char* registered_list[] = { "119.123.45.39" };
    const char* banned_list[] = { "1.1.1.12" };

    size_t ip_addresses_len = 4;
    size_t registered_list_len = 1;
    size_t banned_list_len = 1;

    int* result = solution(ip_addresses, ip_addresses_len, registered_list, registered_list_len, banned_list, banned_list_len);

    for (size_t i = 0; i < ip_addresses_len; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
