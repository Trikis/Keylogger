#include "Keys.h"
#include <iostream>

LRESULT CALLBACK KeyProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode == HC_ACTION) {
		KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
		DWORD VKcode = p->vkCode;

		if (wParam == WM_KEYUP && (VKcode == VK_SHIFT || VKcode == VK_RSHIFT || VKcode == VK_LSHIFT)) {
			Keys::bShift = FALSE;
		}

		if (wParam == WM_KEYDOWN) {
			if (VKcode == VK_SHIFT || VKcode == VK_LSHIFT || VKcode == VK_RSHIFT) {
				Keys::bShift = TRUE;
			}

			std::wstring res = Keys::CodeToString(VKcode);
			std::wcout << res;
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
	setlocale(LC_ALL, "Russian");

	HHOOK KeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyProc, NULL, NULL);
	if (KeyHook == NULL) return -1;

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(KeyHook);
}