#pragma once 

#include "tree.h"
//inorder right to left

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
// TODO: your code here
	if(root == NULL) return;
	while(root != NULL){
		s.push(root);
		root = root->right_;
	}
	if(s.top()->data_ == NULL){
		++(*this);
	}
}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here
	if(s.empty()) return *this;

	do{
		Node* c = s.top();
		s.pop();
		if(c->left_ != NULL){
			s.push(c->left_);
			c = c->left_;
			while(c->right_ != NULL){
				s.push(c->right_);
				c = c->right_;
			}
		}
		if(s.empty()){
			curr_ = NULL;
		}
	}while(curr_ && s.top()->data_ == NULL);

	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
// TODO: your code here
	if(s.empty()) return T();
	return s.top()->data_;
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




template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
	if(hasAChild(currentIdx)){
		size_t min=0;
		min=maxPriorityChild(currentIdx);
		if(higherPriority(_elems[min],_elems[currentIdx])){
			std::swap(_elems[currentIdx],_elems[min]);
			heapifyDown(min);
		}
	}

	if(hasAChild(currentIdx)){
		size_t min=0;
		min=maxPriorityChild(currentind);
		if(current>min){
			std::swap(current, min);
			heapifyDown(min);
		}
	}
}
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{ 
	if(currentIdx==root())
		return;
	size_t parentIdx=parent(curr);
	if(higherPriority(current, parent)){
		swap(current, parent);
		heapifyUp(parent)
	}


heapifyDown{
	if(curr*2+1<elem.size()){
		size_t min=maxPriorityChild(curr);
		if(higherPriority(min, curr)){
			std::swap(min, curr);
			heapifydown(min);
		}
	}
}

heapifyUp{
	if(curr==0){
		return;
	}
	size_t parent=parent(curr);
	if(higherPriority(curr,parent)){
		std::swap(cur, parent);
		heapifyUp(parent);
	}
}

heapifyDown(curr){
	if(curr*2+1<elem.size()){
		size_t min=maxPriorityChild(curr);
		if(min<curr){
			std::swap(curr min);
			hd(min)
		}
	}
}

heapup(curr){
	if(curr==0){
		return;
	}
	size_t parent=(curr-1)/2;
	if(parent>curr){
		std:swap(curr,parn);
		hu(parent)
	}
}