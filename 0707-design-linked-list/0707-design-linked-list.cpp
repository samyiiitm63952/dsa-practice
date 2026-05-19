class MyLinkedList {
public:

    class node {
    public:
        int val;
        node* next;
        node* prev;

        node(int x) {
            val = x;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {

        if(index < 0 || index >= size) {
            return -1;
        }

        node* temp = head;

        while(index--) {
            temp = temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val) {

        node* adder = new node(val);

        adder->next = head;

        if(head != nullptr) {
            head->prev = adder;
        }

        head = adder;

        size++;
    }

    void addAtTail(int val) {

        node* adder = new node(val);

        if(head == nullptr) {
            head = adder;
            size++;
            return;
        }

        node* temp = head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = adder;
        adder->prev = temp;

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index < 0 || index > size) {
            return;
        }

        if(index == 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        node* adder = new node(val);

        adder->next = temp->next;
        adder->prev = temp;

        temp->next->prev = adder;
        temp->next = adder;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) {
            return;
        }

        if(index == 0) {

            node* deleter = head;

            head = head->next;

            if(head != nullptr) {
                head->prev = nullptr;
            }

            delete deleter;
            size--;

            return;
        }

        node* temp = head;

        for(int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        node* deleter = temp->next;

        temp->next = deleter->next;

        if(deleter->next != nullptr) {
            deleter->next->prev = temp;
        }

        delete deleter;

        size--;
    }
};