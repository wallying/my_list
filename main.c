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
list��������ʹ�÷�����
1.�����û��ڵ�ṹ�壻
    ���磺 struct item_t {...};
    1).�ڵ�ṹ��ĵ�һ�����Ϊ���ṹ���ָ���������struct item_t *next;
    2).�ڵ�ṹ������������Ϊ�ڵ���Я������Ϣ����������void *data;
2.�����û��ڵ������
    ���磺struct item_t item;
3.�����û����������
    ���磺list_t link_list;
    1).��������ͱ���Ϊlist_t;
4.ʹ������
    1).���еĲ���������Ҫʹ������ĵ�ַ���ڵ�ĵ�ַ��Ϊ�����βΣ�
        ����������link_list�ı�ͷ����item�ڵ㣺
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


