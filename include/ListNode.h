//
// Created by cxq on 2023/3/2.
//

#ifndef CONAN_CMAKE_LISTNODE_H
#define CONAN_CMAKE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};


#endif //CONAN_CMAKE_LISTNODE_H
