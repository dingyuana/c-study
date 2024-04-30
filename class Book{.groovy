class Book{
private:
    Book();   //构造函数 1.与类名完全一样，2，系统会自动创造，3. 实例化时，这是第一函数
    private String title;
    private String author;
    private int pages;
    private String isbn;
}

int main(){
    Book book1;
}