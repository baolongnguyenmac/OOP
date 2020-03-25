#ifndef BOOK_H_
#define BOOK_H_

#include "pre.h"

class CBook {
    public:
        friend ostream& operator<< (ostream &os, CBook book) {
            os << book._bookName << " || " << book._tacGia << " || " << book._nxb << " || " << book._isbn;
            return os;
        }

        string getBookName() {
            return _bookName;
        }
        string getIsbn() {
            return _isbn;
        }
        string getTacGia() {
            return _tacGia;
        }
        string getNxb() {
            return _nxb;
        }
        int getDonGia() {
            return _donGia;
        }

        void setBookName(string name) {
            _bookName = name;
        }
        void setIsbn(string isbn) {
            _isbn = isbn;
        }
        void setNxb(string nxb) {
            _nxb = nxb;
        }
        void setTacGia(string tacGia) {
            _tacGia = tacGia;
        }
        void setDonGia(int donGia) {
            _donGia = donGia;
        }

        bool operator==(CBook b) {
            if (_bookName == b._bookName && _tacGia == b._tacGia) {
                return true;
            }
            return false;
        }

        friend istream& operator>>(istream &is, CBook &book) {
            cout << "Nhap ten sach: ";
            getline(is, book._bookName);
            cout << "Nhap isbn: ";
            getline(is, book._isbn);
            cout << "Nhap tac gia: ";
            getline(is, book._tacGia);
            cout << "Nhap nxb: ";
            getline(is, book._nxb);
            cout << "Nhap don gia: ";
            is >> book._donGia;
            is.ignore();
            return is;
        }

    private:
        string _bookName = "";
        string _isbn = "";
        string _nxb = "";
        string _tacGia = "";
        int _donGia = 0;
};

#endif