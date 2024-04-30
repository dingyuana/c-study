#include <iostream>  // 引入输入输出流库
#include <cstring>   // 引入字符串处理库
#include <algorithm> // 引入算法库，用于find函数
#include <vector>    // 引入向量库，用于动态数组
using namespace std;

// 图书类
class Book {
private:
    int id;                // 图书的唯一标识符
    std::string title;     // 图书的标题
    std::string author;    // 图书的作者
    int quantity;          // 图书的数量

public:
    // 构造函数，初始化图书的属性
    Book(int id, const std::string& title, const std::string& author, int quantity) 
        : id(id), title(title), author(author), quantity(quantity) {}

    // 获取图书 ID
    int getId() const { return id; }

    // 获取图书标题
    std::string getTitle() const { return title; }

    // 获取图书作者
    std::string getAuthor() const { return author; }

    // 获取图书数量
    int getQuantity() const { return quantity; }

    // 设置图书 ID
    void setId(int id) { this->id = id; }

    // 设置图书标题
    void setTitle(const std::string& title) { this->title = title; }

    // 设置图书作者
    void setAuthor(const std::string& author) { this->author = author; }

    // 设置图书数量
    void setQuantity(int quantity) { this->quantity = quantity; }
};

// 纸质图书类，继承自Book类
class PaperBook : public Book {
public:
    // 构造函数
    PaperBook(int id, const std::string& title, const std::string& author, int quantity)
        : Book(id, title, author, quantity) {}

    // 可以添加纸质图书特有的方法
};

// 电子图书类，继承自Book类
class EBook : public Book {
public:
    // 构造函数
    EBook(int id, const std::string& title, const std::string& author, int quantity)
        : Book(id, title, author, quantity) {}

    // 可以添加电子图书特有的方法
};

// 读者类
class Reader {
private:
    std::string name;      // 读者的名字
    std::string email;     // 读者的电子邮箱
    std::vector<int> borrowedBooks; // 读者借阅的图书ID列表

public:
    // 构造函数，初始化读者的属性
    Reader(const std::string& name, const std::string& email) : name(name), email(email) {}

    // 获取读者姓名
    std::string getName() const { return name; }

    // 获取读者电子邮件
    std::string getEmail() const { return email; }

    // 获取读者借阅的图书 ID 列表
    const std::vector<int>& getBorrowedBooks() const { return borrowedBooks; }

    // 添加借阅的图书 ID 到列表中
    void addBorrowedBook(int bookId) { borrowedBooks.push_back(bookId); }

    // 从列表中移除借阅的图书 ID
    void removeBorrowedBook(int bookId) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }
};

// 教师类，继承自Reader类
class Teacher : public Reader {
public:
    // 构造函数
    Teacher(const std::string& name, const std::string& email)
        : Reader(name, email) {}

    // 教师可以借阅任意图书，所以不需要重写任何方法
};

// 学生类，继承自Reader类
class Student : public Reader {
public:
    // 构造函数
    Student(const std::string& name, const std::string& email)
        : Reader(name, email) {}

    // 重写添加借阅图书的方法，防止借阅电子图书
    void addBorrowedBook(int bookId) {
        // 假设我们有方法可以判断图书是否为电子图书
        // 这个方法不是标准库的一部分，需要自定义实现
        if (!isEBook(bookId)) {
            Reader::addBorrowedBook(bookId);  // 调用基类的添加方法
        } else {
            std::cout << "学生不能借阅电子图书。" << std::endl;
        }
    }

private:
    // 假设这是判断图书是否为电子图书的方法
    // 这个方法需要根据实际情况实现
    bool isEBook(int bookId) {
        // 这里应该是检查bookId对应的图书是否为EBook类型的逻辑
        // 为了示例，我们简单地返回false
        return false;
    }
};


// 图书馆类
class Library {
private:
    std::vector<Book> books;      // 图书列表
    std::vector<Reader> readers;  // 读者列表

public:
    // 添加一本图书到图书列表中
    void addBook(const Book& book) { books.push_back(book); }

    // 获取图书列表
    const std::vector<Book>& getBooks() const { return books; }

    // 添加一个读者到读者列表中
    void addReader(const Reader& reader) { readers.push_back(reader); }

    // 获取读者列表
    const std::vector<Reader>& getReaders() const { return readers; }

    // 借阅图书，通过图书ID和读者姓名
    void borrowBook(int bookId, const std::string& readerName) {
        for (auto& reader : readers) {  // 遍历读者列表
            if (reader.getName() == readerName) {  // 找到指定的读者
                std::cout<<readerName;
                reader.addBorrowedBook(bookId);  // 将图书ID添加到读者的借阅列表
                break;
            }else{
                std::cout<<"没有找到该读者";
            }
        }
    }

    // 归还图书，通过图书ID和读者姓名
    void returnBook(int bookId, const std::string& readerName) {
        for (auto& reader : readers) {  // 遍历读者列表
            if (reader.getName() == readerName) {  // 找到指定的读者
                reader.removeBorrowedBook(bookId);  // 从读者的借阅列表移除图书ID
                break;
            }
        }
    }

        // 打印菜单选项
    void printMenu() const {
        std::cout << "1. 添加图书\n";
        std::cout << "2. 添加读者\n";
        std::cout << "3. 借阅图书\n";
        std::cout << "4. 归还图书\n";
        std::cout << "5. 显示读者借阅的图书\n";
        std::cout << "6. 退出\n";
    }
};

int main() {
        Library library;
    bool exit = false;
    int choice;

    while (!exit) {
        library.printMenu();  // 打印菜单
        std::cout << "请选择一个操作: ";
        std::cin >> choice;   // 读取用户的选择

        switch (choice) {
            case 1: {
                int id;
                std::cout << "输入图书ID: ";
                std::cin >> id;

                std::cout << "输入图书标题: ";
                std::string title;
                std::cin.ignore();
                std::getline(std::cin, title);

                std::string author;
                std::cout << "输入图书作者: ";
                std::cin.ignore();
                std::getline(std::cin, author);

                
                int quantity;
                std::cout << "输入图书数量: ";
                std::cin >> quantity;

                Book book(id, title, author, quantity);
                library.addBook(book);
                std::cout << "新增加图书1完成";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 2: {
                std::string name, email;
                std::cout << "输入读者姓名: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "输入读者邮箱: ";
                std::cin.ignore();
                std::getline(std::cin, email);

                Reader reader(name, email);
                library.addReader(reader);
                std::cout << "新增加读者完成";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 3: {
                int bookId;
                std::string readerName;
                std::cout << "输入要借阅的图书ID: ";
                std::cin >> bookId;
                std::cout << "输入借阅者姓名: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                library.borrowBook(bookId, readerName);
                std::cout << "借阅完成";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 4: {
                int bookId;
                std::string readerName;
                std::cout << "输入要归还的图书ID: ";
                std::cin >> bookId;
                std::cout << "输入归还者姓名: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                library.returnBook(bookId, readerName);
                std::cout << "归还完成";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 5: {
                std::string readerName;
                std::cout << "输入要查询的读者姓名: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                for (const auto& reader : library.getReaders()) {
                    if (reader.getName() == readerName) {
                        std::cout << reader.getName() << "借阅的图书ID列表: ";
                        for (int bookId : reader.getBorrowedBooks()) {
                            std::cout << bookId << " ";
                        }
                        std::cout << std::endl;
                        std::cout<<"============================================================";
                        std::cout << std::endl;
                        break;
                    }
                }
                break;
            }
            case 6:
                exit = true;
                break;
            default:
                std::cout << "无效的选项，请重新选择。\n";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
        }
    }

    return 0;
}
