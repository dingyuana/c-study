#include <iostream>

// 定义链表节点类
class Node {
public:
    int data; // 存储的数据
    Node* next; // 指向下一个节点的指针

    // 构造函数
    // Node();
    Node(int val) : data(val), next(nullptr) {}
};

// 链表类
class LinkedList {
public:
    Node* head; // 链表头指针

    // 构造函数
    LinkedList() : head(nullptr) {}

    // 初始化链表的函数
    void init() {
        if (head != nullptr) {
            // 如果链表已经初始化，则释放已有的内存
            delete head;
        }
        head = new Node(0); // 创建新的头节点，这里假设数据初始化为0
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
    LinkedList list;//类的实例化，声明定义了一个对象
    // LinkedList *list1;
    // list1 = new LinkedList();

    list.init(); // 初始化链表

    // 链表初始化后可以进行其他操作，例如添加节点、遍历等

    return 0;
}