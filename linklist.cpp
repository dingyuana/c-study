#include <iostream>

// 定义链表节点类
class Node {
public:
    int data; // 存储的数据
    Node* next; // 指向下一个节点的指针

    // 构造函数
    Node(int val) : data(val), next(nullptr) {}
};

// 链表类
class LinkedList {
public:
    Node* head; // 链表头指针

    // 构造函数
    LinkedList() : head(nullptr) {}

    // 初始化链表的函数
    void init(int val) {
        if (head == nullptr) {
            head = new Node(val); // 创建新的头节点
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            // 到达链表尾部，添加新节点
            current->next = new Node(val);
        }
    }

    // 插入节点的方法
    void insert(int position, int val) {
        if (position <= 0) {
            // 插入到链表头部
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        } else {
            // 查找插入位置的前一个节点
            int index = 1;
            Node* current = head;
            while (current != nullptr && index < position) {
                current = current->next;
                index++;
            }
            if (current != nullptr) {
                // 在指定位置插入新节点
                Node* newNode = new Node(val);
                newNode->next = current->next;
                current->next = newNode;
            } else {
                // 插入位置超出链表长度，添加到链表尾部
                Node* newNode = new Node(val);
                current->next = newNode;
            }
        }
    }

    // 析构函数，用于释放链表占用的内存
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    list.init(1); // 初始化链表，头节点值为1

    // 插入节点到链表头部
    list.insert(1, 0);

    // 插入节点到链表尾部
    list.insert(2, 2);

    // 插入节点到链表中间
    list.insert(2, 1);

    // 遍历链表输出节点值
    Node* current = list.head;
    // while (current != nullptr) {
    //     std::cout << current->data << " -> ";
    //     current = current->next;
    // }
    // std::cout << "nullptr" << std::endl;

    LinkedList list1, list2;
    list1.init(1); // 初始化链表，头节点值为1
    list1.insert(1, 2);
    list1.insert(2, 3);

    Node* current1 = list1.head;
    // current1 = list1.head;
    while (current1 != nullptr) {
        std::cout << current1->data << " -> ";
        current1 = current1->next;
    }
    std::cout << "nullptr" << std::endl;
    
    list2.init(1); // 初始化链表，头节点值为1
    list2.insert(1, 3);
    list2.insert(2, 4);

    Node* current2 = list2.head;
    while (current2 != nullptr) {
        std::cout << current2->data << " -> ";
        current2 = current2->next;
    }
    std::cout << "nullptr" << std::endl;



    LinkedList list3;
    list3.init(0); 
    current1= list1.head;
    current2=list2.head;
    int pos=1;
    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data < current2->data) {
            list3.insert(pos, current1->data);
            current1 = current1->next;
        } else {
            list3.insert(pos, current2->data);
            current2 = current2->next;
        }
        pos++;
    }

    
    Node* current3 = list3.head;
    while (current3 != nullptr) {
        std::cout << current3->data << " -> ";
        current3 = current3->next;
    }
    std::cout << "nullptr" << std::endl;
    // while (current1 != nullptr) {
    //     list3.insert(pos, current1->data);
    // if (current1->data >current2->data)
    // {
    //     list3.insert(pos, current2->data);
    // }
    // 释放链表占用的内存

    return 0;
}