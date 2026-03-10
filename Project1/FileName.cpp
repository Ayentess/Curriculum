#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char name[20];
    char phone[20];
    struct Node* next;
} LinkNode;
// 创建通讯录链表
LinkNode* createList() {
    int n;
    printf("请输入通讯录中通讯者的数量：\n");
    scanf("%d", &n);
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->next = NULL;
    LinkNode* tail = head;
    for (int i = 0; i < n; i++) {
        LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
        printf("请输入第%d个通讯者的姓名和电话号码：\n", i + 1);
        scanf("%19s %19s", newNode->name, newNode->phone);
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}
// 插入通讯者结点
void insert_link(LinkNode* head, LinkNode* newNode) {
    LinkNode* current = head;
    while (current->next != NULL) {
        if (strcmp(current->next->name, newNode->name) == 0 && strcmp(current->next->phone, newNode->phone) == 0) {
            printf("通讯者已存在，插入失败！\n");
            free(newNode);
            return;
        }
        current = current->next;
    }
    current->next = newNode;
    newNode->next = NULL;

    printf("插入成功！\n");
}
// 查询通讯者结点
void search_link(LinkNode* head, char* name) {
    LinkNode* current = head->next;
    bool found = false;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0) {
            printf("姓名 %s，电话 %s\n", current->name, current->phone);
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        printf("未找到该联系人\n");
    }
}
// 删除通讯者结点
void delete_link(LinkNode* head, LinkNode* p) {
    LinkNode* current = head->next;
    LinkNode* p = head;
    if (head->next == NULL) {
        printf("通讯录为空，无法删除！\n");
        return;
    }

    while (current != NULL) {
        if (strcmp(current->name, p->name) == 0 && strcmp(current->phone, p->phone) == 0) {
            p->next = current->next;
            free(current);
            printf("删除成功！\n");
            return;
        }
        p = current;
        current = current->next;
    }
    printf("未找到该联系人，删除失败！\n");
}
// 输出通讯录链表
void print_List(LinkNode* head) {
    LinkNode* current = head->next;
    if (current == NULL) {
        printf("通讯录为空！\n");
        return;
    }
    while (current != NULL) {
        printf("姓名：%s，电话号码：%s\n", current->name, current->phone);
        current = current->next;
    }
}
void showMenu() {
    system("cls");
    printf("1、通讯录链表的建立\n");
    printf("2、通讯者结点的插入\n");
    printf("3、通讯者结点的查询\n");
    printf("4、通讯者结点的删除\n");
    printf("5、通讯录链表的输出\n");
    printf("0、退出管理系统\n");
    printf("请选择0~5：\n");
}
int main() {
    LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
    head->next = NULL;

    while (true) {
        showMenu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            head = createList();
            printf("通讯录链表建立成功！\n");
            system("pause");
            system("cls");
            break;
        case 2: {
            LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
            printf("请输入要插入的通讯者姓名和电话号码：\n");
            scanf("%19s %19s", newNode->name, newNode->phone);
            insert_link(head, newNode);
            system("pause");
            system("cls");
            break;
        }
        case 3: {
            char name[20];
            printf("请输入要查询的通讯者姓名：\n");
            scanf("%19s", name);
            search_link(head, name);
            system("pause");
            system("cls");
            break;
        }
        case 4: {
            LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
            printf("请输入要删除的通讯者姓名和电话号码：\n");
            scanf("%19s %19s", newNode->name, newNode->phone);
            delete_link(head, newNode);
            free(newNode);
            system("pause");
            system("cls");
            break;
        }
        case 5:
            print_List(head);
            system("pause");
            system("cls");
            break;
        case 0:
            return 0;
        default:
            printf("输入错误，请重新输入！\n");
            system("pause");
            showMenu();
            break;
        }
    }

    return 0;
}