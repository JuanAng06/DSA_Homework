#include "BTVN_Array.cpp"
#include "BTVN_LinkedList.cpp"

struct StackArray {

    List list;

    StackArray(int cap) : list(cap) {} // Khởi tạo trực tiếp
    /** Cách 2:
     * StackArray(int cap) {
     *      list = List(cap);
     * }
     */

    /**
     * Kiểm tra xem list có rỗng không.
     *
     * @return true nếu list rỗng, false nếu vẫn còn phần tử
     *
     */
    bool isEmpty() {
        return list.isEmpty();
    }

    /**
     * Đẩy giá trị lên đầu Stack.
     * 
     * @param item giá trị cần đẩy
     * 
     */
    void push(int item) {
        cout << "push(" << item << "): ";
        if (!list.isFull()) {
            list.addLast(item);
        } else {
            cout << "FAILED - The Stack is full!" << endl;
        }
    }

    /**
     * Rút giá trị trên cùng ra ngoài Stack.
     * 
     * @return -1 nếu Stack rỗng, list.deleteLast() (Giá trị cần xóa) nếu Stack có phần tử
     * 
     */
    int pop() {
        cout << "pop(): ";
        if (isEmpty()) {
            cout << "FAILED - The Stack is empty!" << endl;
            return -1;
        }
        return list.deleteLast();
    }

    /**
     * Kiểm tra kích cỡ hiện tại của Stack.
     * 
     * @return list.count (Kích cỡ hiện tại của stack)
     */
    int size() {
        cout << "Current size: " << list.count << endl;
        return list.count;
    }

    /**
     * Lấy giá trị trên đầu của Stack.
     * 
     * @return -1 nếu stack rỗng, list.data[list.count - 1] (Giá trị top hiện tại) nếu Stack có phần tử
     */
    int top() {
        cout << "top(): ";
        if (list.isEmpty()) {
            cout << "FAILED - Stack is empty!" << endl;
            return -1;
        }
        list.access(list.count - 1);
        return list.data[list.count - 1];
    }
};

struct StackLinkedList {

    LinkedList list;

    /**
     * Constructor.
     */
    StackLinkedList() : list() {}

    /**
     * Kiểm tra xem list có rỗng không.
     *
     * @return true nếu list rỗng, false nếu vẫn còn phần tử
     */
    bool isEmpty() {
        return list.isEmpty();
    }

    /**
     * Đẩy giá trị lên đầu Stack.
     * 
     * @param item giá trị cần đẩy
     */
    void push(int item) {
        list.addFirst(item);
        cout << "push(" << item << "): OK" << endl;
    }

    /**
     * Rút giá trị trên cùng ra ngoài Stack.
     * 
     * @return -1 nếu Stack rỗng, list.deleteLast() (Giá trị cần xóa) nếu Stack có phần tử
     */
    int pop() {
        cout << "pop(): ";
        if (isEmpty()) {
            cout << "FAILED - The Stack is empty!" << endl;
            return -1;
        }
        cout << list.head->data << " - OK" << endl;
        return list.deleteFirst();
    }

    /**
     * Kiểm tra kích cỡ hiện tại của Stack.
     * 
     * @return list.count (Kích cỡ hiện tại của stack)
     */
    int size() {
        return list.size;
    }

    /**
     * Lấy giá trị trên đầu của Stack.
     * 
     * @return -1 nếu stack rỗng, list.data[list.count - 1] (Giá trị top hiện tại) nếu Stack có phần tử
     */
    int top() {
        cout << "top(): ";
        if (isEmpty()) {
            cout << "FAILED - The Stack is empty!" << endl;
            return -1;
        }
        cout << list.head->data << " - OK" << endl;
        return list.head->data;
    }

};

// ===== TEST FUNCION (AI gen) =====
int main() {
    StackArray st(5); // Stack dung lượng 5 phần tử

    cout << "=== Test push ===" << endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.size();
    st.top();

    cout << "\n=== Test pop ===" << endl;
    st.pop();
    st.size();
    st.top();

    cout << "\n=== Test push thêm cho đầy ===" << endl;
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70); // sẽ thất bại vì đầy

    cout << "\n=== Test pop toàn bộ ===" << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop(); // stack rỗng -> báo lỗi

    cout << "\n=== Test top khi rỗng ===" << endl;
    st.top(); // báo lỗi vì stack rỗng

    cout << "\n=== Test size khi rỗng ===" << endl;
    st.size();

    cout << " ======= /// LINKED LIST VERSION /// =======" << endl;




    // SỬ DỤNG LINKED LIST
     StackLinkedList stll;  // stack dùng linked list

    cout << "=== Test push ===" << endl;
    stll.push(10);
    stll.push(20);
    stll.push(30);
    cout << "Current size: " << stll.size() << endl;
    stll.top();

    cout << "\n=== Test pop ===" << endl;
    stll.pop();
    cout << "Current size: " << stll.size() << endl;
    stll.top();

    cout << "\n=== Test push thêm nhiều phần tử ===" << endl;
    stll.push(40);
    stll.push(50);
    stll.push(60);
    cout << "Current size: " << stll.size() << endl;
    stll.top();

    cout << "\n=== Test pop toàn bộ ===" << endl;
    stll.pop();
    stll.pop();
    stll.pop();
    stll.pop();
    stll.pop();
    cout << "Current size: " << stll.size() << endl;

    cout << "\n=== Test top khi rỗng ===" << endl;
    stll.top();
    stll.pop();

    return 0;
}
