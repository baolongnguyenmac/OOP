
#include "ListBook.h"
#include "pre.h"

int main(int argc, char const *argv[]) {
    CListBook *listBook = CListBook::getInstance();

    try {
        listBook->push(CBook("Lap trinh huong doi tuonng", "1", "Khoa hoc va Ky thuat", "Doan Van Ban", (rand()%20 + 1)*1000));
        listBook->push(CBook("Lap trinh huong doi tuong voi Java", "2", "Khoa hoc va Ky thuat", "Tran Dan Thu", (rand()%20 + 1)*1000));
        listBook->push(CBook("Ngu van 12"  , "3",  "Nha xuat ban Giao duc", "Nguyen Van Meo", (rand()%20 + 1)*1000));
        listBook->push(CBook("Ngu van 11"  , "4",  "Nha xuat ban Giao duc", "Nguyen Van Meo", (rand()%20 + 1)*1000));
        listBook->push(CBook("Ngu van 10"  , "5",  "Nha xuat ban Giao duc", "Nguyen Van Meo", (rand()%20 + 1)*1000));
        listBook->push(CBook("Giai tich 10", "6",  "Nha xuat ban Giao duc", "Nguyen Van Cho", (rand()%20 + 1)*1000));
        listBook->push(CBook("Giai tich 11", "7",  "Nha xuat ban Giao duc", "Nguyen Van Cho", (rand()%20 + 1)*1000));
        listBook->push(CBook("Giai tich 12", "8",  "Nha xuat ban Giao duc", "Nguyen Van Cho", (rand()%20 + 1)*1000));
        listBook->push(CBook("Hinh hoc 10" , "9",  "Nha xuat ban Giao duc", "Nguyen Van Ga", (rand()%20 + 1)*1000));
        listBook->push(CBook("Hinh hoc 11" , "10", "Nha xuat ban Giao duc", "Nguyen Van Ga", (rand()%20 + 1)*1000));
        listBook->push(CBook("Hinh hoc 12" , "11", "Nha xuat ban Giao duc", "Nguyen Van Ga", (rand()%20 + 1)*1000));
        listBook->push(CBook("Hinh hoc 12" , "12", "Nha xuat ban Giao duc", "Nguyen Bao Long", (rand()%20 + 1)*1000));
    }
    catch (int n) {
        cout << "i'm fucked\n";
    }

    // listBook->update();
    // string a = "Ngu van 12";
    listBook->erase();

    listBook->update();

    listBook->writeFile();

    listBook->printListBook();

    return 0;
}