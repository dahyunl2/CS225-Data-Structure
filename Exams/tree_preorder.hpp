#pragma once

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
// TODO: your code here
	if(root == NULL) return;
	//Node* node = root;
	/*while(root != NULL){
		s.push(root);
		root = root->right_;
	}
	if(s.top()->data_ == NULL){
		++(*this);
	} */
	while(root != NULL) {
		q.push(root);
		root = root -> left_;
	}
	if (q.front() -> data_ == NULL) {
		++(*this);
	}
	/*while (true) {
		if (node != NULL) {
			s.push(node);
			q.push(node);
			node = node->left_;
		} else {
			if (s.empty()) break;
			node = s.top();
			s.pop();
			node = node->right_;
		}
	} */
	//curr_ = q.front();
}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
// TODO: your code here

	if(q.empty()) return *this;

	do{
		Node* c = q.front();
		q.pop();
		if(c->right_ != NULL){
			q.push(c->right_);
			c = c->right_;
			while(c->left_ != NULL){
				q.push(c->left_);
				c = c->left_;
			}
		}
		if(q.empty()){
			curr_ = NULL;
		}
	}while(curr_ && q.front()->data_ == NULL);

	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
// TODO: your code here
	if(q.empty()) return T();
	return q.front()->data_;
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}