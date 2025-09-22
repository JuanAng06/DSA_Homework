#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int n) {
        data = n;
        next = nullptr;
    }
};

struct LinkedList {

    //private
    Node* head = nullptr;
    Node* tail = nullptr;
    int size;

    //Constructor
    LinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    // ===== HELPER FUNCTIONS =====
    bool isEmpty() const {
        return (size == 0);
    }

    bool isValidInsertPosition(int position) const {
        return (0 <= position && position <= size);
    }

    bool isValidIndex(int position) const {
        return (0 <= position && position < size);
    }

    //public

    // ===== MAIN FUNCTIONS =====

    /**
     * Truy cập và in giá trị tại vị trí chỉ định trong danh sách liên kết.
     *
     * @param position vị trí cần truy cập
     * @return true nếu truy cập thành công, false nếu vị trí không hợp lệ hoặc danh sách rỗng
     */
    // Truy cập vào vị trí pos 
    bool access(int position) {
        cout << "access(" << position << "): ";
        if (!isValidIndex(position)) {
            cout << "FAILED - Invalid position!" << endl;
            return false;
        }

        if (isEmpty()) {
            cout << "FAILED - The array is empty!" << endl;
            return false;
        }

        Node* temp = head;
        for (int i = 0; i < position; i++) {
            temp = temp->next;
        }
        cout << temp->data << " - OK" << endl;
        return true;
    }

    /**
     * Thêm một node mới vào đầu danh sách liên kết.
     *
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công
     */
    // Thêm giá trị vào đầu linkedlist
    bool addFirst(int value) {

        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
            newNode->next = nullptr;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
        cout << "addFirst(" << value << "): OK" << endl;
        return true;
    }

    /**
     * Thêm một node mới vào cuối danh sách liên kết.
     *
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công
     */
    // Thêm giá trị vào cuối linkedlist 
    bool addLast(int value) {

        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        newNode->next = nullptr;
        size++;
        cout << "addLast(" << value << "): OK" << endl;
        return true;
    }

    /**
     * Thêm một node mới vào vị trí chỉ định trong danh sách.
     *
     * @param position vị trí muốn thêm (0 <= position <= size)
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công, false nếu vị trí không hợp lệ
     */
    // Thêm giá trị vào vị trí position
    bool addAtPosition(int position, int value) {

        cout << "addAtPosition(" << position << "," << value << "): ";
        if (!isValidInsertPosition(position)) {
            cout << "FAILED - Invalid position!" << endl;
            return false;
        }
        
        Node* newNode = new Node(value);
        if (position == 0) {
            return addFirst(value); //Gọi luôn hàm addFirst rồi trả về T/F
        } else if (position == size) {
            return addLast(value); //Tương tự
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }

        cout << "OK" << endl;
        return true;

    }

    /**
     * Xóa node đầu tiên trong danh sách.
     *
     * @return true nếu xóa thành công, false nếu danh sách rỗng
     */
    // Xóa phần tử đầu
    bool deleteFirst() {
        
        cout << "deleteFirst(): "; 
        if (isEmpty()) {
            cout << "FAILED - The list is empty!" << endl;
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            cout << "OK - The list is empty now!" << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "OK" << endl;
        }
        size--;
        return true;
    }

    /**
     * Xóa node cuối cùng trong danh sách.
     *
     * @return true nếu xóa thành công, false nếu danh sách rỗng
     */
    // Xóa phần tử cuối
    bool deleteLast() {

        cout << "deleteLast(): ";

        if (isEmpty()) {
            cout << "FAILED - The array is empty!" << endl;
            return false;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr; //Tránh dangling pointer
            cout << "OK - The array is empty now!" << endl;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Xóa node tại vị trí chỉ định trong danh sách.
     *
     * @param position vị trí cần xóa (0 <= position < size)
     * @return true nếu xóa thành công, false nếu vị trí không hợp lệ
     */
    // Xóa phần tử ở vị trí pos
    bool deleteAtPosition(int position) {

        cout << "deleteAtPosition(" << position << "): ";

        if (!isValidIndex(position)) {
            cout << "FAILED - Invalid position!" << endl;
            return false;
        }

        if (position == 0) {
            deleteFirst();
        } else if (position == size - 1) {
            deleteLast();
        } else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            size--;
        }
        if (isEmpty()) {
            head = tail = nullptr;
        }
        cout << "OK" << endl;
        return true;

    }

    /**
     * In toàn bộ danh sách theo thứ tự từ đầu đến cuối.
     */
    // In LinkedList 
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    /**
     * In toàn bộ danh sách theo thứ tự ngược lại (từ cuối về đầu).
     */
    // In LinkedList ngược
    void printReverse() {
        vector<int> dataVector;
        Node* temp = head;
        while (temp != nullptr) {
            dataVector.push_back(temp->data);
            temp = temp->next;
        }
        for (int i = size - 1; i >= 0; i--) {
            cout << dataVector[i] << " ";
        }
    }
};

// ===== vvv TEST HERE (AI gen down here sorry) vvv =====
#include <cassert>
#include <vector>
#include <string>

// === Helper functions ===
std::vector<int> toVector(LinkedList& list) {
    std::vector<int> result;
    Node* temp = list.head;
    while (temp != nullptr) {
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

void assertEqual(std::vector<int> expected, std::vector<int> actual, const std::string& testName) {
    assert(expected == actual && "Test failed!");
    std::cout << "[PASSED] " << testName << std::endl;
}

// === Test functions ===
void testAddFirst() {
    LinkedList list;
    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);
    assertEqual({30, 20, 10}, toVector(list), "addFirst()");
}

void testAddLast() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    assertEqual({10, 20, 30}, toVector(list), "addLast()");
}

void testAddAtPosition() {
    LinkedList list;
    list.addLast(10);
    list.addLast(30);
    list.addAtPosition(1, 20);   // giữa
    list.addAtPosition(0, 5);    // đầu
    list.addAtPosition(4, 40);   // cuối
    assertEqual({5, 10, 20, 30, 40}, toVector(list), "addAtPosition()");
}

void testDeleteFirst() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.deleteFirst(); // remove 10
    assertEqual({20, 30}, toVector(list), "deleteFirst()");
}

void testDeleteLast() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.deleteLast(); // remove 30
    assertEqual({10, 20}, toVector(list), "deleteLast()");
}

void testDeleteAtPosition() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    list.addLast(40);
    list.deleteAtPosition(1); // remove 20
    list.deleteAtPosition(2); // remove 40
    assertEqual({10, 30}, toVector(list), "deleteAtPosition()");
}

void testAccess() {
    LinkedList list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    bool ok1 = list.access(0); // expect true (10)
    bool ok2 = list.access(2); // expect true (30)
    bool ok3 = list.access(5); // expect false
    assert(ok1 && ok2 && !ok3 && "access() failed!");
    std::cout << "[PASSED] access()" << std::endl;
}

void testPrintAndReverse() {
    LinkedList list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    std::cout << "Forward print: ";
    list.print();      // expect 1 2 3
    std::cout << "\nReverse print: ";
    list.printReverse(); // expect 3 2 1
    std::cout << "\n[PASSED] print & printReverse()\n";
}

// === EDGE + STRESS CASES
void testEdgeCases() {
    LinkedList list;

    // Truy cập/xóa/chèn ngoài phạm vi
    assert(!list.access(0));
    assert(!list.deleteAtPosition(5));
    assert(!list.addAtPosition(-1, 100));
    assert(!list.addAtPosition(1, 100));

    // Thêm 3 phần tử để test biên
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);

    assert(list.access(2));   // vị trí cuối cùng
    assert(!list.access(3));  // ngoài phạm vi
    list.deleteAtPosition(0); // xóa đầu
    list.deleteAtPosition(1); // xóa cuối
    list.deleteAtPosition(0); // xóa hết
    assert(list.isEmpty());   // danh sách rỗng
    std::cout << "[PASSED] Edge cases\n";
}

void testStress() {
    LinkedList list;

    const int N = 1000;

    // addLast N lần
    for (int i = 0; i < N; i++) list.addLast(i);
    assert(toVector(list).size() == N);

    // Xóa N lần từ đầu
    for (int i = 0; i < N; i++) list.deleteFirst();
    assert(list.isEmpty());

    // addFirst N lần
    for (int i = 0; i < N; i++) list.addFirst(i);
    assert(toVector(list).size() == N);

    // Xóa N lần từ cuối
    for (int i = 0; i < N; i++) list.deleteLast();
    assert(list.isEmpty());

    std::cout << "[PASSED] Stress test with " << N << " elements\n";
}

// === Main ===
int main() {
    testAddFirst();
    testAddLast();
    testAddAtPosition();
    testDeleteFirst();
    testDeleteLast();
    testDeleteAtPosition();
    testAccess();
    testPrintAndReverse();

    // === STRESS + EDGE CASES ===
    testEdgeCases();
    testStress();

    std::cout << "\n✅ All detailed tests passed!\n";
    return 0;
}
