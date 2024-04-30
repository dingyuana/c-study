#include <iostream>  // ���������������
#include <cstring>   // �����ַ��������
#include <algorithm> // �����㷨�⣬����find����
#include <vector>    // ���������⣬���ڶ�̬����
using namespace std;

// ͼ����
class Book {
private:
    int id;                // ͼ���Ψһ��ʶ��
    std::string title;     // ͼ��ı���
    std::string author;    // ͼ�������
    int quantity;          // ͼ�������

public:
    // ���캯������ʼ��ͼ�������
    Book(int id, const std::string& title, const std::string& author, int quantity) 
        : id(id), title(title), author(author), quantity(quantity) {}

    // ��ȡͼ�� ID
    int getId() const { return id; }

    // ��ȡͼ�����
    std::string getTitle() const { return title; }

    // ��ȡͼ������
    std::string getAuthor() const { return author; }

    // ��ȡͼ������
    int getQuantity() const { return quantity; }

    // ����ͼ�� ID
    void setId(int id) { this->id = id; }

    // ����ͼ�����
    void setTitle(const std::string& title) { this->title = title; }

    // ����ͼ������
    void setAuthor(const std::string& author) { this->author = author; }

    // ����ͼ������
    void setQuantity(int quantity) { this->quantity = quantity; }
};

// ֽ��ͼ���࣬�̳���Book��
class PaperBook : public Book {
public:
    // ���캯��
    PaperBook(int id, const std::string& title, const std::string& author, int quantity)
        : Book(id, title, author, quantity) {}

    // �������ֽ��ͼ�����еķ���
};

// ����ͼ���࣬�̳���Book��
class EBook : public Book {
public:
    // ���캯��
    EBook(int id, const std::string& title, const std::string& author, int quantity)
        : Book(id, title, author, quantity) {}

    // ������ӵ���ͼ�����еķ���
};

// ������
class Reader {
private:
    std::string name;      // ���ߵ�����
    std::string email;     // ���ߵĵ�������
    std::vector<int> borrowedBooks; // ���߽��ĵ�ͼ��ID�б�

public:
    // ���캯������ʼ�����ߵ�����
    Reader(const std::string& name, const std::string& email) : name(name), email(email) {}

    // ��ȡ��������
    std::string getName() const { return name; }

    // ��ȡ���ߵ����ʼ�
    std::string getEmail() const { return email; }

    // ��ȡ���߽��ĵ�ͼ�� ID �б�
    const std::vector<int>& getBorrowedBooks() const { return borrowedBooks; }

    // ��ӽ��ĵ�ͼ�� ID ���б���
    void addBorrowedBook(int bookId) { borrowedBooks.push_back(bookId); }

    // ���б����Ƴ����ĵ�ͼ�� ID
    void removeBorrowedBook(int bookId) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }
};

// ��ʦ�࣬�̳���Reader��
class Teacher : public Reader {
public:
    // ���캯��
    Teacher(const std::string& name, const std::string& email)
        : Reader(name, email) {}

    // ��ʦ���Խ�������ͼ�飬���Բ���Ҫ��д�κη���
};

// ѧ���࣬�̳���Reader��
class Student : public Reader {
public:
    // ���캯��
    Student(const std::string& name, const std::string& email)
        : Reader(name, email) {}

    // ��д��ӽ���ͼ��ķ�������ֹ���ĵ���ͼ��
    void addBorrowedBook(int bookId) {
        // ���������з��������ж�ͼ���Ƿ�Ϊ����ͼ��
        // ����������Ǳ�׼���һ���֣���Ҫ�Զ���ʵ��
        if (!isEBook(bookId)) {
            Reader::addBorrowedBook(bookId);  // ���û������ӷ���
        } else {
            std::cout << "ѧ�����ܽ��ĵ���ͼ�顣" << std::endl;
        }
    }

private:
    // ���������ж�ͼ���Ƿ�Ϊ����ͼ��ķ���
    // ���������Ҫ����ʵ�����ʵ��
    bool isEBook(int bookId) {
        // ����Ӧ���Ǽ��bookId��Ӧ��ͼ���Ƿ�ΪEBook���͵��߼�
        // Ϊ��ʾ�������Ǽ򵥵ط���false
        return false;
    }
};


// ͼ�����
class Library {
private:
    std::vector<Book> books;      // ͼ���б�
    std::vector<Reader> readers;  // �����б�

public:
    // ���һ��ͼ�鵽ͼ���б���
    void addBook(const Book& book) { books.push_back(book); }

    // ��ȡͼ���б�
    const std::vector<Book>& getBooks() const { return books; }

    // ���һ�����ߵ������б���
    void addReader(const Reader& reader) { readers.push_back(reader); }

    // ��ȡ�����б�
    const std::vector<Reader>& getReaders() const { return readers; }

    // ����ͼ�飬ͨ��ͼ��ID�Ͷ�������
    void borrowBook(int bookId, const std::string& readerName) {
        for (auto& reader : readers) {  // ���������б�
            if (reader.getName() == readerName) {  // �ҵ�ָ���Ķ���
                std::cout<<readerName;
                reader.addBorrowedBook(bookId);  // ��ͼ��ID��ӵ����ߵĽ����б�
                break;
            }else{
                std::cout<<"û���ҵ��ö���";
            }
        }
    }

    // �黹ͼ�飬ͨ��ͼ��ID�Ͷ�������
    void returnBook(int bookId, const std::string& readerName) {
        for (auto& reader : readers) {  // ���������б�
            if (reader.getName() == readerName) {  // �ҵ�ָ���Ķ���
                reader.removeBorrowedBook(bookId);  // �Ӷ��ߵĽ����б��Ƴ�ͼ��ID
                break;
            }
        }
    }

        // ��ӡ�˵�ѡ��
    void printMenu() const {
        std::cout << "1. ���ͼ��\n";
        std::cout << "2. ��Ӷ���\n";
        std::cout << "3. ����ͼ��\n";
        std::cout << "4. �黹ͼ��\n";
        std::cout << "5. ��ʾ���߽��ĵ�ͼ��\n";
        std::cout << "6. �˳�\n";
    }
};

int main() {
        Library library;
    bool exit = false;
    int choice;

    while (!exit) {
        library.printMenu();  // ��ӡ�˵�
        std::cout << "��ѡ��һ������: ";
        std::cin >> choice;   // ��ȡ�û���ѡ��

        switch (choice) {
            case 1: {
                int id;
                std::cout << "����ͼ��ID: ";
                std::cin >> id;

                std::cout << "����ͼ�����: ";
                std::string title;
                std::cin.ignore();
                std::getline(std::cin, title);

                std::string author;
                std::cout << "����ͼ������: ";
                std::cin.ignore();
                std::getline(std::cin, author);

                
                int quantity;
                std::cout << "����ͼ������: ";
                std::cin >> quantity;

                Book book(id, title, author, quantity);
                library.addBook(book);
                std::cout << "������ͼ��1���";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 2: {
                std::string name, email;
                std::cout << "�����������: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "�����������: ";
                std::cin.ignore();
                std::getline(std::cin, email);

                Reader reader(name, email);
                library.addReader(reader);
                std::cout << "�����Ӷ������";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 3: {
                int bookId;
                std::string readerName;
                std::cout << "����Ҫ���ĵ�ͼ��ID: ";
                std::cin >> bookId;
                std::cout << "�������������: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                library.borrowBook(bookId, readerName);
                std::cout << "�������";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 4: {
                int bookId;
                std::string readerName;
                std::cout << "����Ҫ�黹��ͼ��ID: ";
                std::cin >> bookId;
                std::cout << "����黹������: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                library.returnBook(bookId, readerName);
                std::cout << "�黹���";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
            }
            case 5: {
                std::string readerName;
                std::cout << "����Ҫ��ѯ�Ķ�������: ";
                std::cin.ignore();
                std::getline(std::cin, readerName);
                for (const auto& reader : library.getReaders()) {
                    if (reader.getName() == readerName) {
                        std::cout << reader.getName() << "���ĵ�ͼ��ID�б�: ";
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
                std::cout << "��Ч��ѡ�������ѡ��\n";
                std::cout << std::endl;
                std::cout<<"============================================================";
                std::cout << std::endl;
                break;
        }
    }

    return 0;
}
