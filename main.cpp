#include "ctrl.h"

int main() {
	int x;
	auto controller = Controller();
	cout << "1. admin\n2. client\n";
	cin >> x;
	if (x == 1) { controller.Run_Admin(); }
	else if (x == 2) { controller.Run_Client(); }
		else cout << "attempt failed";

	return 0;
}