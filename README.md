# my_list
my list library

https://github.com/wallying/my_list.git

## lib_list单向链表使用方法:
### 1.定义链表变量(类型必须为list_t)
    list_t link_list;
### 2.定义节点结构体(结构体首项必须为本结构体指针)
    结构体余项可以为数据信息携带指针,如void *data;
    struct item_t {struct item_t *next; void *data; ...};
### 3.定义节点结构体变量
    struct item_t item;
### 4.使用链表API函数(函数形参必须为链表地址、节点地址)
    list_init(&link_list);
    list_insert_head(&link_list, &item)
    list_insert_tail(&link_list, &item);
