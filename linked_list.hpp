#pragma once

namespace data_structures {
    template<typename T>
        class linked_list {
        public:
            struct node {
                T value;
                node* next;
                node* prev;

                node() = default;
                node(T value) : value(value) {}
                node(T value, node* next, node* prev) : value(value), next(next), prev(prev) {}
            };

            class iterator {
            private:
                node* pointer;
            public:
                iterator(node* pointer) : pointer(pointer) {}

                iterator& operator=(node* pointer) {
                    this->pointer = pointer;
                    return *this;
                }

                iterator& operator++() {
                    if (pointer) pointer = pointer->next;
                    return *this;
                }

                iterator operator++(int) {
                    iterator iter = *this;
                    ++*this;
                    return iter;
                }

                iterator& operator--() {
                    if (pointer) pointer = pointer->prev;
                    return *this;
                }

                iterator operator--(int) {
                    iterator iter = *this;
                    --*this;
                    return iter;
                }

                iterator operator+(int i) {
                    iterator iter = pointer;
                    while (i-- && pointer) iter.pointer = iter.pointer->next;
                    return iter;
                }

                iterator operator-(int i) {
                    iterator iter = pointer;
                    while (i-- && pointer) iter.pointer = iter.pointer->prev;
                    return iter;
                }

                bool operator!() {
                    return pointer == nullptr;
                }

                bool operator!=(const iterator& iter) {
                    return pointer != iter.pointer;
                }

                bool operator==(const iterator& iter) {
                    return pointer == iter.pointer;
                }

                T operator*() const {
                    return pointer->value;
                }

                T& operator*() {
                    return pointer->value;
                }
            };
        private:
            node* head;
            node* tail;
        public:
            linked_list() = default;
            ~linked_list() {
                node* ptr = head;
                while (ptr) {
                    ptr = ptr->next;
                    delete head;
                    head = ptr;
                }
                delete head;
            }
        public:
            bool is_empty() const {
                return head == nullptr;
            }
        public:
            void push_back(T value) {
                node* ptr = new node(value);
                if (is_empty()) {
                    head = tail = ptr;
                    return;
                }
                tail->next = ptr;
                ptr->prev = tail;
                tail = ptr;
            }
        public:
            iterator begin() {
                return iterator(head); 
            }

            iterator end() {
                return iterator(tail);
            }

            const iterator begin() const {
                return iterator(head);
            }

            const iterator end() const {
                return iterator(end);
            }
        };
}
