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

                                                    // ===== GETTER ======
    int getSize() {
        return size;
    }

    int getHead() {
        return head->data;
    }

    int getTail() {
        return tail->data;
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
     * @return giá trị head vừa xóa
     */
    // Xóa phần tử đầu
    int deleteFirst() {
        
        if (isEmpty()) {
            return -1;
        }

        int dataRemove = head->data;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
        return dataRemove;
    }

    /**
     * Xóa node cuối cùng trong danh sách.
     *
     * @return giá trị tail vừa xóa
     */
    // Xóa phần tử cuối
    int deleteLast() {

        if (isEmpty()) {
            return -1;
        }

        int dataDel = tail->data;
        if (head == tail) {
            delete head;
            head = tail = nullptr; //Tránh dangling pointer
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
        return dataDel;
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