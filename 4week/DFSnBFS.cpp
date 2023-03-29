#include <iostream>

class Node {
public:
    int value; //노드 저장 값
    Node* firstChild; //첫 번째 자식 노드 포인터
    Node* nextSibling; //다음 자식 노드 포인터
    Node* parent; //부모 노드 포인터

    Node(int v) { //생성자
        value = v;
        firstChild = nullptr; //첫 번째 자식 포인터형 변수에 대한 null (null 값 할당)
        nextSibling = nullptr; //다음 자식 "
        parent = nullptr; //부모 "
    }

    ~Node() { //소멸자
        if (firstChild != nullptr) { 
            delete firstChild; //첫 번째 자식 메모리 할당 취소
        }
        if (nextSibling != nullptr) {
            delete nextSibling; //다음 자식 메모리 할당 취소
        }
    }

    void addChild(Node* child) { //자식 노드 추가 함수
        child -> parent = this; 
        if (firstChild == nullptr) { //첫 번째 자식 비었으면 
            firstChild = child; //첫 번째 자식으로 추가
        }
        else {
            Node* sibling = firstChild;
            while (sibling -> nextSibling != nullptr) { //다음 자식이 비어있지 않을 때까지
                sibling = sibling -> nextSibling; //다음으로
            }
            sibling -> nextSibling = child; //다음 자식으로 추가
        }
    }
};

class Tree {
public:
    Node* root; //트리 루트 노드 포인터

    Tree() { //생성자
        root = nullptr;
    }

    ~Tree() { //소멸자
        delete root;
    }

    void insert(int value, int parentValue = 0) { //노드 추가 함수
        if (root == nullptr) { //루트가 비었으면
            root = new Node(value); //새 노드 추가
            return;
        }

        Node* parent = search(root, parentValue); //특정 값에 대한 노드 검색 함수
        if (parent == nullptr) { //부모가 비었으면
            std::cerr << "Parent not found" << std::endl; //출력
            return;
        }

        Node* child = new Node(value); //클래스 생성자 호출, 생성된 객체 주소 반환
        parent -> addChild(child); //부모 노드의 자식 노드로 추가
    }

    Node* search(Node* node, int value) { //노드 찾기 함수
        if (node -> value == value) { //현재 노드와 찾는 값이 일치하면
            return node; 
        }
        Node* result = nullptr; //초기화
        if (node -> firstChild != nullptr) { //node가 가리키는 노드의 첫번째 자식 노드가 null이 아니라면
            result = search(node -> firstChild, value); //search 함수 재귀 호출, node->firstChild를 루트로 하는 서브트리에서 value 찾기
        } 
        if (result == nullptr && node->nextSibling != nullptr) { //result가 null이고 node의 다음 형제가 null이 아닐 경우
            result = search(node -> nextSibling, value); //node의 다음 형제 노드 루트로 하는 서브트리에서 value 찾기
        } //search 함수는 찾은 노드 result에 할당하고 반환
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

    //std::cout << tree.root->value << std::endl;    // 출력값: 1
    //std::cout << tree.root->firstChild->value << std::endl;    // 출력값: 2
    //std::cout << tree.root->firstChild->nextSibling->value << std::endl;    // 출력값: 3
    //std::cout << tree.root->firstChild->firstChild->value << std::endl;    // 출력값: 4
    //std::cout << tree.root->firstChild->firstChild->nextSibling->value << std::endl;    // 출력값: 5

    return 0;
}
