/**
 * file:    main.c
 * author:  wallying@foxmail.com
 * date:    2019-12-16
 **/


#include <stdio.h>
#include "lib_list.h"


void print_list(void);
void print_node(void *node);


/*******************************************************************************
list单向链表使用方法：
1.定义用户节点结构体；
    例如： struct item_t {...};
    1).节点结构体的第一项必须为本结构体的指针变量，即struct item_t *next;
    2).节点结构体的其他项可以为节点所携带的信息变量，例如void *data;
2.定义用户节点变量：
    例如：struct item_t item;
3.定义用户链表变量；
    例如：list_t link_list;
    1).链表的类型必须为list_t;
4.使用链表。
    1).所有的操作，均需要使用链表的地址、节点的地址作为函数形参；
        例如向链表link_list的表头插入item节点：
        list_insert_head(&link_list, &item)
*******************************************************************************/

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

list_t link_list = NULL;


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


