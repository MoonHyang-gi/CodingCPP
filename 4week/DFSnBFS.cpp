#include <iostream>

class Node {
public:
    int value; //��� ���� ��
    Node* firstChild; //ù ��° �ڽ� ��� ������
    Node* nextSibling; //���� �ڽ� ��� ������
    Node* parent; //�θ� ��� ������

    Node(int v) { //������
        value = v;
        firstChild = nullptr; //ù ��° �ڽ� �������� ������ ���� null (null �� �Ҵ�)
        nextSibling = nullptr; //���� �ڽ� "
        parent = nullptr; //�θ� "
    }

    ~Node() { //�Ҹ���
        if (firstChild != nullptr) { 
            delete firstChild; //ù ��° �ڽ� �޸� �Ҵ� ���
        }
        if (nextSibling != nullptr) {
            delete nextSibling; //���� �ڽ� �޸� �Ҵ� ���
        }
    }

    void addChild(Node* child) { //�ڽ� ��� �߰� �Լ�
        child -> parent = this; 
        if (firstChild == nullptr) { //ù ��° �ڽ� ������� 
            firstChild = child; //ù ��° �ڽ����� �߰�
        }
        else {
            Node* sibling = firstChild;
            while (sibling -> nextSibling != nullptr) { //���� �ڽ��� ������� ���� ������
                sibling = sibling -> nextSibling; //��������
            }
            sibling -> nextSibling = child; //���� �ڽ����� �߰�
        }
    }
};

class Tree {
public:
    Node* root; //Ʈ�� ��Ʈ ��� ������

    Tree() { //������
        root = nullptr;
    }

    ~Tree() { //�Ҹ���
        delete root;
    }

    void insert(int value, int parentValue = 0) { //��� �߰� �Լ�
        if (root == nullptr) { //��Ʈ�� �������
            root = new Node(value); //�� ��� �߰�
            return;
        }

        Node* parent = search(root, parentValue); //Ư�� ���� ���� ��� �˻� �Լ�
        if (parent == nullptr) { //�θ� �������
            std::cerr << "Parent not found" << std::endl; //���
            return;
        }

        Node* child = new Node(value); //Ŭ���� ������ ȣ��, ������ ��ü �ּ� ��ȯ
        parent -> addChild(child); //�θ� ����� �ڽ� ���� �߰�
    }

    Node* search(Node* node, int value) { //��� ã�� �Լ�
        if (node -> value == value) { //���� ���� ã�� ���� ��ġ�ϸ�
            return node; 
        }
        Node* result = nullptr; //�ʱ�ȭ
        if (node -> firstChild != nullptr) { //node�� ����Ű�� ����� ù��° �ڽ� ��尡 null�� �ƴ϶��
            result = search(node -> firstChild, value); //search �Լ� ��� ȣ��, node->firstChild�� ��Ʈ�� �ϴ� ����Ʈ������ value ã��
        } 
        if (result == nullptr && node->nextSibling != nullptr) { //result�� null�̰� node�� ���� ������ null�� �ƴ� ���
            result = search(node -> nextSibling, value); //node�� ���� ���� ��� ��Ʈ�� �ϴ� ����Ʈ������ value ã��
        } //search �Լ��� ã�� ��� result�� �Ҵ��ϰ� ��ȯ
        return result;
    }
};

int main() {
    //Tree tree;
    //tree.insert(1);
    //tree.insert(2, 1);
    //tree.insert(3, 1);
    //tree.insert(4, 2);
    //tree.insert(5, 2);

    //std::cout << tree.root->value << std::endl;    // ��°�: 1
    //std::cout << tree.root->firstChild->value << std::endl;    // ��°�: 2
    //std::cout << tree.root->firstChild->nextSibling->value << std::endl;    // ��°�: 3
    //std::cout << tree.root->firstChild->firstChild->value << std::endl;    // ��°�: 4
    //std::cout << tree.root->firstChild->firstChild->nextSibling->value << std::endl;    // ��°�: 5

    return 0;
}
