#include"Header.h"
void init(tree& bst) {
	bst = NULL;
}
void duyetNodeLeftRight(tree bst) {
	if (bst != NULL) {
		cout << bst->data << "\t";
		duyetNodeLeftRight(bst->left);
		duyetNodeLeftRight(bst->right);
	}
	
}
void duyetLeftNodeRight(tree bst) {
	if (bst != NULL) {
		duyetLeftNodeRight(bst->left);
		cout << bst->data << "\t";
		duyetLeftNodeRight(bst->right);
	}
	
}
void duyetLeftRightNode(tree bst) {
	if (bst != NULL) {
		duyetLeftRightNode(bst->left);
		duyetLeftRightNode(bst->right);
		cout << bst->data << "\t";
	}
	
}
tree createNode(TYPEINFO x) {
	tree p = new node();
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
int insertNode(tree& bst, TYPEINFO x) {
	if (bst == NULL) {
		bst = createNode(x);
		return 1;
	}
	else if (bst->data > x) insertNode(bst->left, x);
	else if (bst->data < x) insertNode(bst->right, x);
	else return 0;
}
tree search(tree bst, TYPEINFO x) {
	if (bst->data == x) return bst;
	else if (bst->data > x)search(bst->left, x);
	else if (bst->data < x)search(bst->right, x);
	else return NULL;
}
void infoNode(tree bst) {
	if (bst == NULL)return;
	else {
		cout << "\nNode : " << bst->data << "\t";
		if (bst->left != NULL)
			cout << "\nLeft-Node: " << bst->left->data;
		if (bst->right != NULL)
			cout << "\nRight-Node: " << bst->right->data;
	}
}
int remove(tree& bst, TYPEINFO x) {
	
	tree p,// node can xoa 
		 q,//node thay the 
		 f;// node cha node thay the
	p = bst;
	f = NULL;
	while (p != NULL) {
		
		if (p->data == x)break;
		else {
			f = p;
			if (p->data < x)p = p->right;
			else  p = p->left;
		}
	}
	// p la node can xoa 
	// f la node cha cua p
	if (p == NULL)return 0;
	else {
		                                        // truong hop p co hai node con 
		if (p->left != NULL && p->right != NULL) {
			q = p->left;                        // du dinh :q la node thay the 
			f = p;                              // du dinh :f la node cha node thay the
			while (q->right != NULL) {
				f = q;
				q = q->right;
			}
			// q la con phai cung nhanh trai cua node p
			p->data = q->data;
			p = q;   // node can xoa bay h la node the mang 
		}
		if (p->left != NULL)q = p->left;   
		else q = p->right;
		if (p == bst) bst = q;
		else {
			if (p == f->left)f->left = q;
			else f->right = q;
		}
		delete p;
		return 1;
	}
}