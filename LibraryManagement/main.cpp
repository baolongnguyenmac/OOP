// #include "ListBook.h"
#include "pre.h"

class CNode {
    public:
        CNode(int data) {
            d = data;
        }

    private:
        int d;
        CNode *pNext = NULL;
        friend class CList;
};

class CList {
    public:
        void push(int d) {
            if (head == nullptr) {
                head = tail = new CNode(d);
            }
            else {
                tail->pNext = new CNode(d);
                tail = tail->pNext;
            }
        }

        void del(int d) {
            CNode *del = searchNode(d);
            if (del == NULL) {
                return;
            }

            // node cần xoá là tail 
            if (del->pNext == NULL) {
                CNode *p = head;
                for (; p->pNext != tail; p = p->pNext);
                delete del;
                tail = p;
            }
            else {
                CNode *next = del->pNext;
                del->d = next->d;
                del->pNext = next->pNext;
                delete next;
            }
        }

        void print() {
            for (CNode *p = head; p != nullptr; p = p->pNext) {
                cout << p->d << " ";
            }
            cout << endl;
        }

        CNode* searchNode(int d) {
            for (CNode *p = head; p != nullptr; p = p->pNext) {
                if (p->d == d) {
                    return p;
                }
            }
            return nullptr;
        }

    private:
        CNode *head = nullptr;
        CNode *tail = nullptr;
};

int main(int argc, char const *argv[]) {
    CList l;
    l.push(1);
    l.push(2);
    l.push(223);
    l.push(2212313);
    l.push(3);

    l.del(3);
    l.del(1);
    l.del(223);

    l.print();

    return 0;
}
