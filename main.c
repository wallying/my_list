/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-17
 **/


#include <stdio.h>
#include "lib_list.h"


void print_list(void);
void print_node(void *node);


/*******************************************************************************
lib_list单向链表使用方法:
1.定义链表变量(类型必须为list_t)
    例如：list_t link_list;
2.定义节点结构体(结构体首项必须为本结构体指针)
    结构体余项可以为数据信息携带指针,如void *data;
    例如：struct item_t {struct item_t *next; void *data; ...};
3.定义节点结构体变量
    例如：struct item_t item;
4.使用链表API函数(函数形参必须为链表地址、节点地址)
    list_init(&link_list);
    list_insert_head(&link_list, &item)
    list_insert_tail(&link_list, &item);
*******************************************************************************/

list_t link_list = NULL;

typedef struct _item_t {
    struct _item_t *next;
    void *data;
} myItem_t;

myItem_t item1 = {NULL, "01"};
myItem_t item2 = {NULL, "02"};
myItem_t item3 = {NULL, "03"};
myItem_t item4 = {NULL, "04"};
myItem_t item5 = {NULL, "05"};
myItem_t item6 = {NULL, "06"};



int main(int argc, char *argv[])
{
    list_init(&link_list);print_list();

    list_insert_head(&link_list, &item1);print_list();
    printf("\r\n");




    list_insert_tail(&link_list, &item2);print_list();

    list_insert_prev(&link_list, &item2, &item5);print_list();
    list_insert_prev(&link_list, &item2, &item6);print_list();
    list_insert_prev(&link_list, &item2, &item5);print_list();
    list_insert_prev(&link_list, &item2, NULL);print_list();
    list_insert_prev(&link_list, NULL, &item3);print_list();
    printf("\r\n");


    list_init(&link_list);print_list();
    print_node(list_tail(&link_list));printf("\r\n");



    getchar();
    return 0;
}


void print_list(void)
{
    printf("%02d: ", list_length(&link_list));

    printf("[");
    print_node(list_head(&link_list));
    printf(",");
    print_node(list_tail(&link_list));
    printf("] ");

    myItem_t *p;
    for (p = list_head(&link_list); p != NULL; p = p->next) {
        print_node(p);
        printf(" -> ");
    }
    printf("NULL");
    printf("\r\n");
}

void print_node(void *node)
{
    if (node == NULL) {
        printf("NULL");
    } else {
        printf("(%s)", (char *)((myItem_t *)node)->data);
    }
}


