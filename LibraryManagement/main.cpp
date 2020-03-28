#include "ListBook.h"
#include "pre.h"

int main(int argc, char const *argv[]) {
    CListBook *listBook = CListBook::getInstance();

    listBook->push(CBook("meo", "meo", "meo", "meo", 12));

    listBook->printListBook();

    return 0;
}
