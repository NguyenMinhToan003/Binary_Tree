#include "Header.h"
void main() {
	tree bst;
	bst = NULL;
	int option = 0;
	int a;
	while (1) {
		cout << "\n1.Them.";
		cout << "\n2.Tim Kiem";
		cout << "\n3.Xoa";
		cout << "\n4.Duyet";
		cout << "\nLua chon : ";
		
		cin >> option;
		if (option == 1) {
			cout << "\nNhap so : ";
			cin >> a;
			if (insertNode(bst, a))
				cout << "\nXong!";
			else cout << "\nThat Bai!";
			
		}
		else if (option == 2) {
			cout << "\nNhap so : ";
			cin >> a;
			infoNode(search(bst,a));
		}
		else if (option == 3) {
			cout << "\nNhap so : ";
			cin >> a;
			if (remove(bst, a))
				cout << "\nXoa thanh cong.";
			else cout << "\Xoa khong thanh cong.";
		}
		else if (option == 4) {
			cout << "\nduyet Node Left Right : ";
			duyetNodeLeftRight(bst);
			cout << "\nduyet Left Node Right : ";
			duyetLeftNodeRight(bst);
			cout << "\nduyet Left Right Node : ";
			duyetLeftRightNode(bst);

		}
		
	}
	
}