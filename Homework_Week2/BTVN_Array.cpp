#include <iostream>

using namespace std;

struct List{
    //private
    int size;
    int count;
    int* data;

    /**Constructor*/
    List(){
        data = nullptr;
        size = 0;
        count = 0;
    }

    List(int cap){
        data = new int[cap];
        size = cap;
        count = 0;
    }

    /** Destructor */
    ~List(){
        delete[] data;
    }
    //public

                                                        // ===== HELPER FUNCTIONS =====
    bool isFull() const {
        return count == size;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isValidIndex(int position) const {
        return (position >= 0 && position < count);
    }

    bool isValidInsertPosition(int position) const {
        return (position >= 0 && position <= count);
    }

    // ===== MAIN FUNCTIONS =====

    /**
     * Truy cập phần tử tại vị trí chỉ định trong danh sách.
     *
     * @param position vị trí muốn truy cập (0 <= position < count)
     * @return true nếu truy cập thành công, false nếu vị trí không hợp lệ
     */
    // Truy cập vào data[position]
    bool access(int position) {

        if (!isValidIndex(position)) {
            cout << "FAILED - position = " << position << " is invalid!" << endl;
            return false;
        }

        cout << "data[" << position << "] = " << data[position] << endl;
        return true;
    }

    /**
     * Thêm phần tử mới vào đầu danh sách.
     *
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công, false nếu danh sách đã đầy
     */
    // Thêm data vào đầu danh sách
    bool addFirst(int value) {
        cout << "addFirst(" << value << "): ";
        if (isFull()) {
            cout << "FAILED - The List is full!" << endl;
            return false;
        }

        for (int i = count; i > 0; i--){
            data[i] = data[i - 1];
        }
        data[0] = value;
        count++;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Thêm phần tử mới vào cuối danh sách.
     *
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công, false nếu danh sách đã đầy
     */
    // Thêm data vào cuối danh sách
    bool addLast(int value) {
        cout << "addLast(" << value << "): ";
        if (isFull()) {
            cout << "FAILED - The List is full!" << endl;
            return false;
        }

        data[count] = value;
        count++;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Thêm phần tử mới vào vị trí chỉ định trong danh sách.
     *
     * @param position vị trí muốn thêm (0 <= position <= count)
     * @param value giá trị cần thêm
     * @return true nếu thêm thành công, false nếu danh sách đầy hoặc vị trí không hợp lệ
     */
    // Thêm data vào vị trí position
    bool addAtPosition(int position, int value) {
        cout << "addAtPosition(" << position << "," << value << "): ";
        if (isFull() || !isValidInsertPosition(position)) {
            cout << "FAILED - ";
            if (count == size) {
                cout << "The List is full!" << endl;
            }
            if (position > count + 1) {
                cout << "The position is invalid!" << endl;
            }
            return false;
        }

        for (int i = count; i > position; i--){
            data[i] = data[i - 1];
        }

        data[position] = value;
        count++;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Xóa phần tử đầu tiên trong danh sách.
     *
     * @return true nếu xóa thành công, false nếu danh sách rỗng
     */
    // Xóa data đầu danh sách
    bool deleteFirst() {
        cout << "deleteFirst(): ";
        if (isEmpty()) {
            cout << "FAILED - The List is empty!" << endl;
            return false;
        }

        for (int i = 0; i < count - 1; i++) {
            data[i] = data[i + 1];
        }
        count--;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Xóa phần tử cuối cùng trong danh sách.
     *
     * @return true nếu xóa thành công, false nếu danh sách rỗng
     */
    // Xóa data vào cuối danh sách
    bool deleteLast() {
        cout << "deleteLast(): ";
        if (isEmpty()) {
            cout << "FAILED - The List is empty!" << endl;
            return false;
        }

        count--;
        cout << "OK" << endl;
        return true;
    }

    /**
     * Xóa phần tử tại vị trí chỉ định trong danh sách.
     *
     * @param position vị trí cần xóa (0 <= position < count)
     * @return true nếu xóa thành công, false nếu vị trí không hợp lệ hoặc danh sách rỗng
     */
    // Xóa data ở vị trí position
    bool deleteAtPosition(int position) {
        cout << "deleteAtPosition(" << position << "): ";
        if (isFull() || !isValidIndex(position)) {
            cout << "FAILED - ";
            if (count == size) {
                cout << "The List is full!" << endl;
            }
            if (position < 0 || position > count + 1) {
                cout << "The position is invalid!" << endl;
            }
            return false;
        }

        for (int i = position; i < count; i++) {
            data[i] = data[i + 1];
        }
        count--;
        cout << "OK" << endl;
        return true;

    }

    /**
     * In toàn bộ danh sách theo chiều xuôi (từ đầu đến cuối).
     */
    void print() {
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    /**
     * In toàn bộ danh sách theo chiều ngược (từ cuối đến đầu).
     */
    void printReverse() {
        for (int i = count - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// ===== vvv TEST HERE (AI gen down here sorry) vvv =====
int main() {
    List arr(5); // capacity = 5

    cout << "=== Test addFirst ===" << endl;
    arr.addFirst(10);
    arr.addFirst(20);
    arr.addFirst(30);
    arr.print(); // 30 20 10

    cout << "\n=== Test addLast ===" << endl;
    arr.addLast(40);
    arr.print(); // 30 20 10 40

    cout << "\n=== Test addAtPosition ===" << endl;
    arr.addAtPosition(2, 99); // chèn 99 vào pos = 2
    arr.print(); // 30 20 99 10 40

    cout << "\n=== Test addAtPosition when full ===" << endl;
    arr.addAtPosition(1, 77); // thất bại vì full

    cout << "\n=== Test access ===" << endl;
    arr.access(0);
    arr.access(4);
    arr.access(10); // invalid

    cout << "\n=== Test deleteFirst ===" << endl;
    arr.deleteFirst();
    arr.print();

    cout << "\n=== Test deleteLast ===" << endl;
    arr.deleteLast();
    arr.print();

    cout << "\n=== Test deleteAtPosition ===" << endl;
    arr.deleteAtPosition(1); // xóa tại pos = 1
    arr.print();

    cout << "\n=== Test printReverse ===" << endl;
    arr.printReverse();

    return 0;
}
