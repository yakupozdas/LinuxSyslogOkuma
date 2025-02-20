#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512  // Maksimum satir uzunlugu

// Bagli liste dugum yapisi
struct LogNode {
    char message[MAX_LINE];
    struct LogNode* next;
};

// Yeni dugum olusturma fonksiyonu
struct LogNode* createNode(char* logMessage) {
    struct LogNode* newNode = (struct LogNode*)malloc(sizeof(struct LogNode));
    if (!newNode) {
        printf("Bellek tahsis hatasi!\n");
        return NULL;
    }
    strncpy(newNode->message, logMessage, MAX_LINE);
    newNode->next = NULL;
    return newNode;
}

// Syslog verisini oku ve bagli listeye ekle
struct LogNode* readSyslog() {
    FILE* file = fopen("/var/log/syslog", "r");  // Syslog dosyasini ac
    if (!file) {
        printf("Syslog dosyasi acilamadi!\n");
        return NULL;
    }

    struct LogNode* head = NULL;
    struct LogNode* tail = NULL;
    char line[MAX_LINE];

    while (fgets(line, sizeof(line), file)) {
        struct LogNode* newNode = createNode(line);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}

// Bagli listeyi ekrana yazdir
void printLog(struct LogNode* head) {
    struct LogNode* temp = head;
    while (temp) {
        printf("%s", temp->message);
        temp = temp->next;
    }
}

// Bellegi temizle
void freeList(struct LogNode* head) {
    struct LogNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct LogNode* logList = readSyslog();
    if (logList) {
        printf("Syslog Kayitlari:\n");
        printLog(logList);
        freeList(logList);
    }
    return 0;
}

