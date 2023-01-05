//https://www.acmicpc.net/problem/2517

/*달리기 (Platinum 4)

장거리 달리기 대회에서 모든 선수가 반환점을 넘었다. 각 선수의 입장에서 지금 자기보다 앞에 달리고 있는 선수들 중
평소 실력이 자기보다 좋은 선수는 남은 거리 동안 앞지를 수 없다. 그러나 그 반대의 경우엔 추월할 수 있다.
이러한 가정 하에서 각 선수는 자신이 앞으로 얻을 수 있는 최선의 등수를 알 수 있다.

각 선수의 평소 실력은 정수로 주어지는데, 클 수록 실력이 더 좋다는 의미이다.
현재 달리고 있는 선수를 앞에서 부터 표시했을 때 평소 실력이 각각
2 8 10 7 1 9 4 15
라고 할 때 각 선수가 얻을 수 있는 최선의 등수는 각각
1 1 1 3 5 2 5 1 이 된다.

선수들의 평소 실력을 현재 달리고 있는 순서대로 입력 받아서 각 선수의 최선의 등수를 계산하시오.
선수는 최대 50만명이며, 실력은 정수로 최대 10억으로 표현된다. 그리고 선수들의 실력은 모두 다르다.
*/

//Solution : Red-black Tree에 Rank(greaterCount) 변수를 추가하고, lazy 갱신하는 방식으로 등수 구하기!
#include <iostream>
using namespace std;

struct Node {
    bool isRed;
    int value;
    int greaterCount;
    int lazy;
    Node* parent, * left, * right;
};

class RBTree {
private:
    Node* root, *recentlyInsertedNodePointer;
    int size;
    void insertReconstruction(Node* parent, bool isLeftChild);

public:
    RBTree() : root(nullptr), recentlyInsertedNodePointer(nullptr), size(0) {};
    void insertNode(int value);
    int getRankOfInsertedNode();
};




int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    RBTree tree;

    int nodeCount;
    cin >> nodeCount;

    while (nodeCount--)
    {
        int input;
        cin >> input;
        tree.insertNode(input);
        cout << tree.getRankOfInsertedNode() << "\n";
    }


    return 0;
}





void RBTree::insertReconstruction(Node* parent, bool isLeftChild)
{
    this->size++;
    Node* addedNode = isLeftChild ? parent->left : parent->right;

    if (!parent->isRed || !addedNode->isRed)
        return;

    Node* uncleNode;
    bool parentIsLeftChild;

    if (parent == parent->parent->left)
    {
        uncleNode = parent->parent->right;
        parentIsLeftChild = true;
    }
    else {
        uncleNode = parent->parent->left;
        parentIsLeftChild = false;
    }

    if (uncleNode == nullptr || uncleNode->isRed == false)
    {
        //if uncleNode is Black Color : Restructuring

        if (isLeftChild != parentIsLeftChild)
        { //if Node constructure is LR or RL, rotation once more
            addedNode->parent = parent->parent;
            parent->parent = addedNode;

            if (parentIsLeftChild)
            {   //LR case -> LL
                addedNode->parent->left = addedNode;
                parent->right = addedNode->left;
                if (parent->right)
                    parent->right->parent = parent;
                addedNode->left = parent;
                if (addedNode->left)
                    addedNode->left->parent = addedNode;
            }
            else {
                //RL case -> RR
                addedNode->parent->right = addedNode;
                parent->left = addedNode->right;
                if (parent->left)
                    parent->left->parent = parent;
                addedNode->right = parent;
                if (addedNode->right)
                    addedNode->right->parent = addedNode;
            }

            swap<Node*>(parent, addedNode);
        }


        Node* grandParent = parent->parent;
        parent->isRed = false;
        grandParent->isRed = true;

        if (grandParent->parent)
        {
            if (grandParent == grandParent->parent->left)
                grandParent->parent->left = parent;
            else
                grandParent->parent->right = parent;
        }
        else {
            //at this branch, grandParent == root then root must be changed
            this->root = parent;
        }

        parent->parent = grandParent->parent;
        grandParent->parent = parent;

        if (parentIsLeftChild) //LL Case
        {
            grandParent->left = parent->right;
            if (grandParent->left)
                grandParent->left->parent = grandParent;
            parent->right = grandParent;
        }
        else { //RR Case
            grandParent->right = parent->left;
            if (grandParent->right)
                grandParent->right->parent = grandParent;
            parent->left = grandParent;
        }

    }
    else {
        //if uncleNode is Red Color : Recoloring
        uncleNode->isRed = false;
        parent->isRed = false;

        Node* grandParent = parent->parent;
        if (grandParent == this->root)
            return;
        else {
            grandParent->isRed = true;
            insertReconstruction(grandParent->parent, grandParent == grandParent->parent->left);
        }
    }



}


void RBTree::insertNode(int value)
{
    Node* node = new Node;
    node->isRed = true;
    node->value = value;
    node->greaterCount = node->lazy = 0;
    node->left = node->right = node->parent = nullptr;
    this->recentlyInsertedNodePointer = node;

    if (this->root == nullptr)
    {
        node->isRed = false;
        this->root = node;
        return;
    }

    Node* nowPosition = this->root;
    bool addedChildisLeft;

    //add node at proper position
    while (true)
    {
        //add Lazy and spread
        if (nowPosition->lazy)
        {
            nowPosition->greaterCount += nowPosition->lazy;
            if (nowPosition->left)
                nowPosition->left->lazy += nowPosition->lazy;
            if (nowPosition->right)
                nowPosition->right->lazy += nowPosition->lazy;

            nowPosition->lazy = 0;
        }

        if (value < nowPosition->value)
            //select Left subTree
        {
            if (nowPosition->left)
                nowPosition = nowPosition->left;
            else
            {
                nowPosition->left = node;
                node->greaterCount = nowPosition->greaterCount + 1;
                node->parent = nowPosition;
                addedChildisLeft = true;
                break;
            }
        }
        else {
            //select Right subTree
            nowPosition->greaterCount++;
            if (nowPosition->left)
                nowPosition->left->lazy++;

            if (nowPosition->right)
                nowPosition = nowPosition->right;
            else
            {
                nowPosition->right = node;
                node->greaterCount = nowPosition->greaterCount - 1;
                node->parent = nowPosition;
                addedChildisLeft = false;
                break;
            }

        }


    }

    //Double Red Check
    //Note : nowPosition == node->parent
    insertReconstruction(nowPosition, addedChildisLeft);
}


int RBTree::getRankOfInsertedNode()
{
    return this->recentlyInsertedNodePointer->greaterCount + 1;
}