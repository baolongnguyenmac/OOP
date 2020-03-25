#ifndef LIST_BOOK_H_
#define LIST_BOOK_H_

#include "pre.h"
#include "Book.h"

#define BOOK_NOT_FOUND 1
#define DUPLICATED_BOOK 2

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

    private:
        CBook _book;
        CNode *_pNext = NULL;
        friend class CList;
};

class CList {
    public:
        void push(CBook book) {
            if (_pHead == NULL) {
                _pHead = _pTail = new CNode(book);
            }
            else {
                _pTail->_pNext = new CNode(book);
                _pTail = _pTail->_pNext;
            }
        }

        CNode* searchNode(string name) {
            for (CNode *p = _pHead; p != NULL; p = p->_pNext) {
                if (p->_book.getBookName() == name) {
                    return p;
                }
            }
            return NULL;
        }

        void deleteNode(string name) {
            CNode *del = searchNode(name);
            if (del == NULL) {
                throw BOOK_NOT_FOUND;
            }

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
        }

    private:
        CNode *_pHead = NULL;
        CNode *_pTail = NULL;
        friend class CListBook;
};

class CListBook {
    public: 
        CListBook() {
            _listBook.resize(1000, new CList());
        }

        void addBook() {
            cout << "Nhap sach can add: ";
            CBook book;
            cin >> book;
            try {
                addBook(book, *this);
            }
            catch (int n) {
                if (n == DUPLICATED_BOOK) {
                    cout << "Sach da ton tai trong he thong\n";
                }
            }
        }

        void delBook() {
            cout << "Nhap ten sach can xoa: ";
            string name;
            getline(cin, name);
            try {
                delBook(name, *this);
            }
            catch (int n) {
                if (n == BOOK_NOT_FOUND) {
                    cout << "Khong tim thay sach can xoa\n";
                }
            }
        }

        void updateBook() {
            cout << "Nhap ten sach can update: ";
            string name;
            getline(cin, name);

            int h = HashString(name) % 1000;
            CNode *p = _listBook[h]->searchNode(name);
            if (p == NULL) {
                cout << "Khong tim thay sach can update\n";
                return;
            }

            cout << "Update sach: \n";
            cout << p->getBook() << endl;
            cout << "=================\n";
            CBook newBook;
            cin >> newBook;
            try {
                updateBook(name, *this, newBook);
            }
            catch (int n) {
                if (n == DUPLICATED_BOOK) {
                    cout << "Sach da ton tai trong he thong\n";
                }
            }
        }

    private:
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

        void addBook(CBook b, CListBook &l) {
            int h = HashString(b.getBookName()) % 1000;
            for (CNode *p = l._listBook[h]->_pHead; p != NULL; p = p->getNext()) {
                if (p->getBook() == b) {
                    throw DUPLICATED_BOOK;
                }
            }
            l._listBook[h]->push(b);
        }

        void delBook(string name, CListBook &l) {
            int h = HashString(name) % 1000;

            // có thể sẽ throw BOOK_NOT_FOUND
            return l._listBook[h]->deleteNode(name);
        }

        void updateBook(string name, CListBook &l, CBook newBook) {
            int h = HashString(name) % 1000;

            // có thể sẽ throw BOOK_NOT_FOUND
            l._listBook[h]->deleteNode(name);
            // có thể throw DUPLICATED_BOOK
            l.addBook(newBook, l);
        }

        vector<CList*> _listBook;
};

#endif