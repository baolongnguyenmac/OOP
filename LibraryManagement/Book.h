#ifndef BOOK_H_
#define BOOK_H_

#include "pre.h"

class CBook {
    public:
        friend ostream& operator<< (ostream &os, CBook book) {
            os << "Ten sach: " << book._bookName << " || Tac gia: " << book._tacGia << " || NXB: " << book._nxb << " || ISBN: " << book._isbn << " || Don gia: " << book._donGia;
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
        // string getPermission() {
        //     return _permission;
        // }

        // void setPermission(string permission) {
        //     _permission = permission;
        // }
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

        CBook(string name, string isbn, string nxb, string tacGia, int donGia) {
            _bookName =name;
            _isbn     =isbn;
            _nxb      =nxb;
            _tacGia   =tacGia;
            _donGia = donGia;
        }
        CBook(){
            _bookName = "";
            _isbn = "";
            _nxb = "";
            _tacGia = "";
            _donGia = 0;
            // _permission = "";
        }

        void readFile(istream &file) {
            size_t size;
            char *data;

            file.read((char*) &size, sizeof(size));
            data = new char[size+1];
            file.read(data, size);
            data[size]='\0';
            _bookName = data;
            delete data;

            file.read((char*) &size, sizeof(size));
            data = new char[size+1];
            file.read(data, size);
            data[size]='\0';
            _isbn = data;
            delete data;

            file.read((char*) &size, sizeof(size));
            data = new char[size+1];
            file.read(data, size);
            data[size]='\0';
            _nxb = data;
            delete data;

            file.read((char*) &size, sizeof(size));
            data = new char[size+1];
            file.read(data, size);
            data[size]='\0';
            _tacGia = data;
            delete data;

            // file.read((char*) &size, sizeof(size));
            // data = new char[size+1];
            // file.read(data, size);
            // data[size]='\0';
            // _donGia = atoi(data);
            // delete data;
            file.read((char*) &_donGia, sizeof(int));
        }

        void writeFile(ostream &file) {
            size_t size;

            size = _bookName.size();
            file.write((char*) &size, sizeof(size_t));
            file.write( (char*)_bookName.c_str(), size);

            size = _isbn.size();
            file.write((char*) &size, sizeof(size_t));
            file.write( (char*)_isbn.c_str(), size);

            size = _nxb.size();
            file.write((char*) &size, sizeof(size_t));
            file.write( (char*)_nxb.c_str(), size);

            size = _tacGia.size();
            file.write((char*) &size, sizeof(size_t));
            file.write( (char*)_tacGia.c_str(), size);

            file.write((char*) &_donGia, sizeof(int));
        }

    private:
        string _bookName;
        string _isbn;
        string _nxb;
        string _tacGia;
        int    _donGia;
        // string _permission;
};

#endif