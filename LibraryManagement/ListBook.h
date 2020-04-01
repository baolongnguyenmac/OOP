#ifndef LIST_BOOK_H_
#define LIST_BOOK_H_

#include "pre.h"
#include "Book.h"

#define BOOK_NOT_FOUND 1
#define DUPLICATED_BOOK 2

#define BOOK_DATA "Book.bin"
#define LIST_BOOK_CAPACITY 20

class CNode {
    public:
        CNode (CBook book) {
            _book = book;
        }

        CNode* getNext() {
            return _pNext;
        }

        CBook getBook() {
            return _book;
        }

        void setBook(CBook book) {
            _book = book;
        }

        void setNext(CNode *p) {
            _pNext = p;
        }

        ~CNode() {
            if (_pNext != NULL) {
                delete _pNext;
            }
            _book = CBook();
            _pNext = NULL;
        }

    private:
        CBook _book;
        CNode *_pNext = NULL;
        friend class CList;
};

class CList {
    public:
    #pragma region Giao diện 

        void push(CBook book) {
            if (isEmpty()) {
                _pHead = _pTail = new CNode(book);
            }
            else {
                _pTail->_pNext = new CNode(book);
                _pTail = _pTail->_pNext;
            }
        }

        // vector<CNode*> getVectorDel(string bookName) {
        //     vector<CNode*> listDel;
        //     for (CNode *p = _pHead; p != NULL; p = p->_pNext) {
        //         if (p->_book.getBookName() == bookName) {
        //             listDel.push_back(p);
        //         }
        //     }
        //     return listDel;
        // }

        // void erase(string bookName) {
        //     // trong th tên sách trùng nhau nhiều
        //     // chúng ta cần 1 listDel chứa các node có sách trùng tên
        //     vector<CNode*> listDel = getVectorDel(bookName);

        //     if (listDel.size() == 0) {
        //         cout << "Khong tim thay sach\n";
        //     }
        //     // nếu chỉ có 1 sách có tên bookName
        //     else if (listDel.size() == 1) {
        //         erase(listDel[0]);
        //     }
        //     // nếu phát hiện nhiều sách trùng tên nhau 
        //     else {
        //         cout << "Nhap ten tac gia: ";
        //         string tacGia;
        //         getline(cin, tacGia);
        //         for (int i = 0; i < listDel.size(); i++) {
        //             if (bookName == listDel[i]->_book.getBookName() && tacGia == listDel[i]->_book.getTacGia()) {
        //                 erase(listDel[i]);
        //                 return;
        //             }
        //         }
        //     }
        // }

    #pragma endregion Giao diện

        CNode* erase(CNode *del) {
            CNode *oldNode = new CNode(del->getBook());
            if (del == _pHead) {
                _pHead = _pHead->_pNext;
                delete del;
            }
            else {
                for (CNode *q = _pHead; q != NULL; q = q->_pNext) {
                    if (q->_pNext == del) {
                        q->_pNext = q->_pNext->_pNext;
                        delete del;
                    }
                }
            }
            return oldNode;
        }

        bool isEmpty() {
            return _pHead == NULL;
        }

        CNode* searchNode(CBook b) {
            for (CNode *p = _pHead; p != NULL; p = p->_pNext) {
                if (p->_book == b) {
                    return p;
                }
            }
            return NULL;
        }

        bool isDuplicated(CBook b) {
            for (CNode *p = _pHead; p != NULL; p = p->_pNext) {
                if (b == p->_book) {
                    return true;
                }
            }
            return false;
        }

        ~CList() {
            if (!isEmpty()) {
                CNode *current = _pHead;
                CNode *next;
                while (current != NULL) {
                    next = current->_pNext;
                    delete current;
                    current = next;
                }
                _pHead = _pTail = NULL;
            }
        }

    private:
        CNode *_pHead = NULL;
        CNode *_pTail = NULL;
        friend class CListBook;
};

class CListBook {
    public: 
    #pragma region Giao diện 

        void printListBook() {
            int count = 0;
            for (int i = 0; i < _listBook.size(); i++) {
                if (!_listBook[i].isEmpty()) {
                    for (CNode *p = _listBook[i]._pHead; p != NULL; p = p->getNext()) {
                        cout << count << ".  " << p->getBook() << endl;
                        count++;
                    }
                }
            }
        }

        void push() {
            cout << "Nhap sach can add:\n";
            CBook book;
            cin >> book;
            try {
                push(book);
                cout << "Them sach thanh cong\n";
            }
            catch (int n) {
                if (n == DUPLICATED_BOOK) {
                    cout << "Sach da ton tai trong he thong\n";
                }
            }
        }

        void erase() {
            cout << "Nhap ten sach can xoa: ";
            string bookName;
            getline(cin, bookName);
            try {
                erase(bookName);
                cout << "Xoa thanh cong\n";
            }
            catch (int n) {
                if (n == BOOK_NOT_FOUND) {
                    cout << "Khong tim thay sach can xoa\n";
                }
            }
        }

        void update() {
            cout << "Nhap ten sach can update: ";
            string bookName;
            getline(cin, bookName);
            try {
                update(bookName);
                cout << "Update thanh cong\n";
            }
            catch (int n) {
                if (n == DUPLICATED_BOOK) {
                    cout << "Sach da ton tai trong he thong\n";
                }
                else if (n == BOOK_NOT_FOUND) {
                    cout << "Khong tim thay sach trong he thong\n";
                }
            }
        }

/*

        void erase() {
            cout << "Nhap ten sach can xoa: ";
            string bookName;
            getline(cin, bookName);
            int h = HashString(bookName) % LIST_BOOK_CAPACITY;
            _listBook[h].erase(bookName);
        }

        void update() {
            cout << "Nhap ten sach can update: ";
            string bookName;
            getline(cin, bookName);
            int h = HashString(bookName) % LIST_BOOK_CAPACITY;
            vector<CNode*> listDel =  _listBook[h].getVectorDel(bookName);
            if (listDel.size() == 0) {
                cout << "Khong tim thay sach " << bookName << endl;
            }
            else {
                cout << "Nhap lai thong tin sach: \n";
                CBook newBook;
                cin >> newBook;

                bool isSuccessful = false;
                if (listDel.size() == 1) {
                    if (update(listDel[0], h, newBook)) {
                        isSuccessful = true;
                    }
                }
                else {
                    cout << "Nhap ten tac gia cua sach can update: ";
                    string tacGia;
                    getline(cin, tacGia);
                    for (int i = 0; i < listDel.size(); i++) {
                        if (listDel[i]->getBook().getBookName() == bookName && listDel[i]->getBook().getTacGia() == tacGia) {
                            if (update(listDel[i], h, newBook)) {
                                isSuccessful = true;
                            }
                        }
                    }
                }

                if (isSuccessful) {
                    cout << "Update thanh cong\n";
                }
                else {
                    cout << "Update khong thanh cong\n";
                }
            }
        }

*/

    #pragma endregion   Giao diện 

        void update(string bookName) {
            // có thể throw BOOK_NOT_FOUND
            CBook oldBook = erase(bookName);
            cout << "Nhap lai thong tin sach: \n";
            CBook newBook;
            cin >> newBook;
            // có thể throw DUPLICATE_BOOK
            try {
                push(newBook);
            }
            catch (int n) {
                if (n == DUPLICATED_BOOK) {
                    push(oldBook);
                    throw DUPLICATED_BOOK;
                }
            }
        }

        CBook erase(string bookName) {
            int h = HashString(bookName) % LIST_BOOK_CAPACITY;
            vector<CNode*> del;

            for (CNode *p = _listBook[h]._pHead; p != NULL; p = p->getNext()) {
                if (p->getBook().getBookName() == bookName) {
                    del.push_back(p);
                }
            }

            if (del.size() == 0) {
                throw BOOK_NOT_FOUND;
            }
            else if (del.size() == 1) {
                return erase(del[0], h);
            }
            else {
                cout << "Tim thay nhieu sach co ten" << bookName << "\nNhap ten tac gia: ";
                string tacGia;
                getline(cin, tacGia);
                for (int i = 0; i < del.size(); i++) {
                    if (tacGia == del[i]->getBook().getTacGia()) {
                        return erase(del[i], h);
                    }
                }
                throw BOOK_NOT_FOUND;
            }
        }

        CBook erase(CNode *p, int hashIndex) {
            return _listBook[hashIndex].erase(p)->getBook();
        }

        void writeFile() {
            fstream file(BOOK_DATA, ios::binary | ios::out);
            if (file.is_open()) {
                for (int i = 0; i < _listBook.size(); i++) {
                    if (!_listBook[i].isEmpty()) {
                        for (CNode *p = _listBook[i]._pHead; p != NULL; p = p->getNext()) {
                            p->getBook().writeFile(file);
                        }
                    }
                }
            }
            else {
                cout << "Loi mo file\n";
            }
            file.close();
        }

        void readFile() {
            fstream file(BOOK_DATA, ios::binary | ios::in);
            if (file.is_open()) {
                CBook *temp;
                while (!file.eof()) {
                    temp = new CBook;
                    temp->readFile(file);
                    if (temp->getBookName() == "") {
                        break;
                    }
                    push(*temp);
                }
                delete temp;
            }
            else {
                cout << "Loi mo file\n";
            }
        }

        long long HashString(string name) {
            string s;
            if (name.length() >= 7) {
                s = name.substr(name.length() - 7);
            }
            else {
                s = name;
            }
            int p = 31;
            int m = pow(10, 9) + 9;

            long long h = 0;
            for (int i = 0; i < s.length(); i++) {
                h += fmod((int)s[i] * pow(p, i), m);
            }

            return h;
        }

        void push(CBook b) {
            int h = HashString(b.getBookName()) % LIST_BOOK_CAPACITY;
            if (_listBook[h].isDuplicated(b)) {
                throw DUPLICATED_BOOK;
            }
            _listBook[h].push(b);
        }

/*

        bool update(CNode *p, int hashIndex, CBook newBook) {
            // xoá sách cần update ra khỏi list nhưng lưu lại thông tin sách đó vào 1 biến phụ 
            CBook book = p->getBook();
            _listBook[hashIndex].erase(p);

            try {
                push(newBook);
            }
            catch (int n) {
                // nếu dính lỗi trùng sách thì trả lại sách đã xoá vào list
                if (n == DUPLICATED_BOOK) {
                    // không gọi push của CListBook bởi vì đoạn này chỉ cần push, không cần nghĩ
                    _listBook[hashIndex].push(book);  
                    return false;  
                }
            }
            return true;
        }

*/

        static CListBook* getInstance() {
            if (_instance == NULL) {
                _instance = new CListBook();
            }
            return _instance;
        }

    private:
        vector<CList> _listBook;
        static CListBook* _instance;

        CListBook(){
            _listBook.resize(LIST_BOOK_CAPACITY, CList());

            readFile();
        }
};

CListBook* CListBook::_instance = NULL;

#endif