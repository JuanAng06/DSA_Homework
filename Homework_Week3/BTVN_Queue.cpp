#include "BTVN_Array.cpp"
#include "BTVN_LinkedList.cpp"

struct QueueArray {
    
    List list;

    /**
     * Constructor.
     */
    QueueArray(int cap) : list(cap) {}

    /**
     * Kiểm tra xem Queue có rỗng không.
     * 
     * @return true nếu rỗng, false nếu không rỗng
     */
    bool isEmpty() {
        return list.isEmpty();
    }

    /**
     * Thêm giá trị vào cuối queue. (Độ phức tạp: O(1))
     * 
     * @param item giá trị cần thêm
     */
    void enqueue(int item) {
        cout << "enqueue(" << item << "): ";
        if (list.isFull()) {
            cout << "FAILED - The queue is full!" << endl;
        } else {
            list.addLast(item);
        }
    }

    /**
     * Xóa giá trị ở đầu queue. (Độ phức tạp: O(1))
     * 
     * @return giá trị vừa xóa
     */
    int dequeue() {
        cout << "dequeue(): ";
        if (list.isEmpty()) {
            cout << "FAILED - The queue is empty!" << endl;
            return -1;
        }
        cout << list.data[0] << " - OK" << endl;
        return list.deleteFirst();
    }

    /**
     * Kiểm tra kích cỡ của queue.
     * 
     * @return kích cỡ của queue
     */
    int size() {
        cout << "Current size: " << list.getCount() << endl;
        return list.getCount();
    }

    /**
     * Xuất ra giá trị đang ở đầu queue.
     * 
     * @return giá trị đầu queue
     */
    int peek() {
        cout << "peek(): ";
        if (list.isEmpty()) {
            cout << "FAILED - The queue is empty!" << endl;
            return -1;
        }
        cout << list.data[0] << " - OK" << endl;
        return list.getFirst();
    }
};





struct QueueLinkedList {
    
    LinkedList list;

    /**
     * Constructor.
     */
    QueueLinkedList() : list() {};

    /**
     * Kiểm tra xem Queue có rỗng không.
     * 
     * @return true nếu rỗng, false nếu không rỗng
     */
    bool isEmpty() {
        return list.isEmpty();
    }

    /**
     * Thêm giá trị vào cuối queue. (Độ phức tạp: O(1))
     * 
     * @param item giá trị cần thêm
     */
    void enqueue(int item) {
        list.addLast(item);
        cout << "enqueue(" << item << "): OK" << endl;
    }

    /**
     * Xóa giá trị ở đầu queue. (Độ phức tạp: O(1))
     * 
     * @return giá trị vừa xóa
     */
    int dequeue() {
        cout << "dequeue(): ";
        if (list.isEmpty()) {
            cout << "FAILED - The queue is empty!" << endl;
            return -1;
        }
        cout << list.getHead() << " - OK" << endl;
        return list.deleteFirst();
    }

    /**
     * Kiểm tra kích cỡ của queue.
     * 
     * @return kích cỡ của queue
     */
    int size() {
        cout << "Current size: " << list.getSize() << endl;
        return list.getSize();
    }

    /**
     * Xuất ra giá trị đang ở đầu queue.
     * 
     * @return giá trị đầu queue
     */
    int peek() {
        cout << "peek(): " << list.getHead() << " - OK" << endl;
        return list.getHead();
    }

};





// ===== TEST FUNCTION (AI gen) =====
int main() {
    cout << "=== Test QueueArray ===" << endl;
    QueueArray qa(5);
    qa.enqueue(10);
    qa.enqueue(20);
    qa.enqueue(30);
    qa.peek();
    qa.dequeue();
    qa.dequeue();
    qa.size();
    qa.dequeue();
    qa.dequeue(); // empty case

    cout << "\n=== Test QueueLinkedList ===" << endl;
    QueueLinkedList ql;
    ql.enqueue(100);
    ql.enqueue(200);
    ql.enqueue(300);
    ql.peek();
    ql.dequeue();
    ql.dequeue();
    ql.size();
    ql.dequeue();
    ql.dequeue(); // empty case

    return 0;
}