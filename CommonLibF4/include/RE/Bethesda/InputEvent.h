#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/InputDevice.h"

namespace RE
{
	enum class DIRECTION_VAL : std::int32_t
	{
		kNone,
		kUp,
		kRight,
		kDown,
		kLeft
	};

	enum class INPUT_EVENT_TYPE : std::int32_t
	{
		kButton,
		kMouseMove,
		kCursorMove,
		kChar,
		kThumbstick,
		kDeviceConnect,
		kKinect,
		kNone
	};

	enum class BS_BUTTON_CODE : std::int32_t
	{
		kBackspace = 0x08,
		kTab = 0x09,
		kEnter = 0x0D,
		kCapsLock = 0x14,
		kEscape = 0x1B,
		kSpace = 0x20,
		kPageUp = 0x21,
		kPageDown = 0x22,
		kEnd = 0x23,
		kHome = 0x24,
		kLeft = 0x25,
		kUp = 0x26,
		kRight = 0x27,
		kDown = 0x28,
		kInsert = 0x2D,
		kDelete = 0x2E,
		k0 = 0x30,
		k1 = 0x31,
		k2 = 0x32,
		k3 = 0x33,
		k4 = 0x34,
		k5 = 0x35,
		k6 = 0x36,
		k7 = 0x37,
		k8 = 0x38,
		k9 = 0x39,
		kA = 0x41,
		kB = 0x42,
		kC = 0x43,
		kD = 0x44,
		kE = 0x45,
		kF = 0x46,
		kG = 0x47,
		kH = 0x48,
		kI = 0x49,
		kJ = 0x4A,
		kK = 0x4B,
		kL = 0x4C,
		kM = 0x4D,
		kN = 0x4E,
		kO = 0x4F,
		kP = 0x50,
		kQ = 0x51,
		kR = 0x52,
		kS = 0x53,
		kT = 0x54,
		kU = 0x55,
		kV = 0x56,
		kW = 0x57,
		kX = 0x58,
		kY = 0x59,
		kZ = 0x5A,
		kNumpad_0 = 0x60,
		kNumpad_1 = 0x61,
		kNumpad_2 = 0x62,
		kNumpad_3 = 0x63,
		kNumpad_4 = 0x64,
		kNumpad_5 = 0x65,
		kNumpad_6 = 0x66,
		kNumpad_7 = 0x67,
		kNumpad_8 = 0x68,
		kNumpad_9 = 0x69,
		kNumpad_Multiply = 0x6A,
		kNumpad_Plus = 0x6B,
		kNumpad_Minus = 0x6D,
		kNumpad_Period = 0x6E,
		kNumpad_Divide = 0x6F,
		kF1 = 0x70,
		kF2 = 0x71,
		kF3 = 0x72,
		kF4 = 0x73,
		kF5 = 0x74,
		kF6 = 0x75,
		kF7 = 0x76,
		kF8 = 0x77,
		kF9 = 0x78,
		kF10 = 0x79,
		kF11 = 0x7A,
		kF12 = 0x7B,
		kSemicolon = 0xBA,
		kComma = 0xBC,
		kEquals = 0xBB,
		kMinus = 0xBD,
		kPeriod = 0xBE,
		kDivide = 0xBF,
		kLBracket = 0xDB,
		kBackslash = 0xDC,
		kRBracket = 0xDD,
		kApostrophe = 0xDE,
		kLShift = 0xA0,
		kRShift = 0xA1,
		kLControl = 0xA2,
		kRControl = 0xA3,
		kLAlt = 0xA4,
		kRAlt = 0xA5,

		kGamepad = 0x10000,
		kDPAD_Up = 0x10001,
		kDPAD_Down = 0x10002,
		kDPAD_Left = 0x10004,
		kDPAD_Right = 0x10008,
		kLTrigger = 0x10009,
		kRTrigger = 0x1000A,
		kSelect = 0x10020,
		kLStick = 0x10040,
		kRStick = 0x10080,
		kLShoulder = 0x10100,
		kRShoulder = 0x10200,
		kAButton = 0x11000,
		kBButton = 0x12000,
		kXButton = 0x14000,
		kYButton = 0x18000,
	};

	constexpr std::string_view ToString(BS_BUTTON_CODE code) noexcept
	{
		switch (code) {
		case BS_BUTTON_CODE::kBackspace:
			return "Backspace";
		case BS_BUTTON_CODE::kTab:
			return "Tab";
		case BS_BUTTON_CODE::kEnter:
			return "Enter";
		case BS_BUTTON_CODE::kCapsLock:
			return "CapsLock";
		case BS_BUTTON_CODE::kEscape:
			return "Escape";
		case BS_BUTTON_CODE::kSpace:
			return "Space";
		case BS_BUTTON_CODE::kPageUp:
			return "PageUp";
		case BS_BUTTON_CODE::kPageDown:
			return "PageDown";
		case BS_BUTTON_CODE::kEnd:
			return "End";
		case BS_BUTTON_CODE::kHome:
			return "Home";
		case BS_BUTTON_CODE::kLeft:
			return "Left";
		case BS_BUTTON_CODE::kUp:
			return "Up";
		case BS_BUTTON_CODE::kRight:
			return "Right";
		case BS_BUTTON_CODE::kDown:
			return "Down";
		case BS_BUTTON_CODE::kInsert:
			return "Insert";
		case BS_BUTTON_CODE::kDelete:
			return "Delete";
		case BS_BUTTON_CODE::k0:
			return "0";
		case BS_BUTTON_CODE::k1:
			return "1";
		case BS_BUTTON_CODE::k2:
			return "2";
		case BS_BUTTON_CODE::k3:
			return "3";
		case BS_BUTTON_CODE::k4:
			return "4";
		case BS_BUTTON_CODE::k5:
			return "5";
		case BS_BUTTON_CODE::k6:
			return "6";
		case BS_BUTTON_CODE::k7:
			return "7";
		case BS_BUTTON_CODE::k8:
			return "8";
		case BS_BUTTON_CODE::k9:
			return "9";
		case BS_BUTTON_CODE::kA:
			return "A";
		case BS_BUTTON_CODE::kB:
			return "B";
		case BS_BUTTON_CODE::kC:
			return "C";
		case BS_BUTTON_CODE::kD:
			return "D";
		case BS_BUTTON_CODE::kE:
			return "E";
		case BS_BUTTON_CODE::kF:
			return "F";
		case BS_BUTTON_CODE::kG:
			return "G";
		case BS_BUTTON_CODE::kH:
			return "H";
		case BS_BUTTON_CODE::kI:
			return "I";
		case BS_BUTTON_CODE::kJ:
			return "J";
		case BS_BUTTON_CODE::kK:
			return "K";
		case BS_BUTTON_CODE::kL:
			return "L";
		case BS_BUTTON_CODE::kM:
			return "M";
		case BS_BUTTON_CODE::kN:
			return "N";
		case BS_BUTTON_CODE::kO:
			return "O";
		case BS_BUTTON_CODE::kP:
			return "P";
		case BS_BUTTON_CODE::kQ:
			return "Q";
		case BS_BUTTON_CODE::kR:
			return "R";
		case BS_BUTTON_CODE::kS:
			return "S";
		case BS_BUTTON_CODE::kT:
			return "T";
		case BS_BUTTON_CODE::kU:
			return "U";
		case BS_BUTTON_CODE::kV:
			return "V";
		case BS_BUTTON_CODE::kW:
			return "W";
		case BS_BUTTON_CODE::kX:
			return "X";
		case BS_BUTTON_CODE::kY:
			return "Y";
		case BS_BUTTON_CODE::kZ:
			return "Z";
		case BS_BUTTON_CODE::kNumpad_0:
			return "Numpad_0";
		case BS_BUTTON_CODE::kNumpad_1:
			return "Numpad_1";
		case BS_BUTTON_CODE::kNumpad_2:
			return "Numpad_2";
		case BS_BUTTON_CODE::kNumpad_3:
			return "Numpad_3";
		case BS_BUTTON_CODE::kNumpad_4:
			return "Numpad_4";
		case BS_BUTTON_CODE::kNumpad_5:
			return "Numpad_5";
		case BS_BUTTON_CODE::kNumpad_6:
			return "Numpad_6";
		case BS_BUTTON_CODE::kNumpad_7:
			return "Numpad_7";
		case BS_BUTTON_CODE::kNumpad_8:
			return "Numpad_8";
		case BS_BUTTON_CODE::kNumpad_9:
			return "Numpad_9";
		case BS_BUTTON_CODE::kNumpad_Multiply:
			return "Numpad_Multiply";
		case BS_BUTTON_CODE::kNumpad_Plus:
			return "Numpad_Plus";
		case BS_BUTTON_CODE::kNumpad_Minus:
			return "Numpad_Minus";
		case BS_BUTTON_CODE::kNumpad_Period:
			return "Numpad_Period";
		case BS_BUTTON_CODE::kNumpad_Divide:
			return "Numpad_Divide";
		case BS_BUTTON_CODE::kF1:
			return "F1";
		case BS_BUTTON_CODE::kF2:
			return "F2";
		case BS_BUTTON_CODE::kF3:
			return "F3";
		case BS_BUTTON_CODE::kF4:
			return "F4";
		case BS_BUTTON_CODE::kF5:
			return "F5";
		case BS_BUTTON_CODE::kF6:
			return "F6";
		case BS_BUTTON_CODE::kF7:
			return "F7";
		case BS_BUTTON_CODE::kF8:
			return "F8";
		case BS_BUTTON_CODE::kF9:
			return "F9";
		case BS_BUTTON_CODE::kF10:
			return "F10";
		case BS_BUTTON_CODE::kF11:
			return "F11";
		case BS_BUTTON_CODE::kF12:
			return "F12";
		case BS_BUTTON_CODE::kSemicolon:
			return "Semicolon";
		case BS_BUTTON_CODE::kComma:
			return "Comma";
		case BS_BUTTON_CODE::kEquals:
			return "Equals";
		case BS_BUTTON_CODE::kMinus:
			return "Minus";
		case BS_BUTTON_CODE::kPeriod:
			return "Period";
		case BS_BUTTON_CODE::kDivide:
			return "Divide";
		case BS_BUTTON_CODE::kLBracket:
			return "LBracket";
		case BS_BUTTON_CODE::kBackslash:
			return "Backslash";
		case BS_BUTTON_CODE::kRBracket:
			return "RBracket";
		case BS_BUTTON_CODE::kApostrophe:
			return "Apostrophe";
		case BS_BUTTON_CODE::kLShift:
			return "LShift";
		case BS_BUTTON_CODE::kRShift:
			return "RShift";
		case BS_BUTTON_CODE::kLControl:
			return "LControl";
		case BS_BUTTON_CODE::kRControl:
			return "RControl";
		case BS_BUTTON_CODE::kLAlt:
			return "LAlt";
		case BS_BUTTON_CODE::kRAlt:
			return "RAlt";
		case BS_BUTTON_CODE::kGamepad:
			return "Gamepad";
		case BS_BUTTON_CODE::kDPAD_Up:
			return "DPAD_Up";
		case BS_BUTTON_CODE::kDPAD_Down:
			return "DPAD_Down";
		case BS_BUTTON_CODE::kDPAD_Left:
			return "DPAD_Left";
		case BS_BUTTON_CODE::kDPAD_Right:
			return "DPAD_Right";
		case BS_BUTTON_CODE::kLTrigger:
			return "LTrigger";
		case BS_BUTTON_CODE::kRTrigger:
			return "RTrigger";
		case BS_BUTTON_CODE::kSelect:
			return "Select";
		case BS_BUTTON_CODE::kLStick:
			return "LStick";
		case BS_BUTTON_CODE::kRStick:
			return "RStick";
		case BS_BUTTON_CODE::kLShoulder:
			return "LShoulder";
		case BS_BUTTON_CODE::kRShoulder:
			return "RShoulder";
		case BS_BUTTON_CODE::kAButton:
			return "AButton";
		case BS_BUTTON_CODE::kBButton:
			return "BButton";
		case BS_BUTTON_CODE::kXButton:
			return "XButton";
		case BS_BUTTON_CODE::kYButton:
			return "YButton";
		default:
			return "Unknown";
		}
	}

	constexpr bool IsButtonCodeValid(BS_BUTTON_CODE code) noexcept
	{
		switch (code) {
		case BS_BUTTON_CODE::kBackspace:
		case BS_BUTTON_CODE::kTab:
		case BS_BUTTON_CODE::kEnter:
		case BS_BUTTON_CODE::kCapsLock:
		case BS_BUTTON_CODE::kEscape:
		case BS_BUTTON_CODE::kSpace:
		case BS_BUTTON_CODE::kPageUp:
		case BS_BUTTON_CODE::kPageDown:
		case BS_BUTTON_CODE::kEnd:
		case BS_BUTTON_CODE::kHome:
		case BS_BUTTON_CODE::kLeft:
		case BS_BUTTON_CODE::kUp:
		case BS_BUTTON_CODE::kRight:
		case BS_BUTTON_CODE::kDown:
		case BS_BUTTON_CODE::kInsert:
		case BS_BUTTON_CODE::kDelete:
		case BS_BUTTON_CODE::k0:
		case BS_BUTTON_CODE::k1:
		case BS_BUTTON_CODE::k2:
		case BS_BUTTON_CODE::k3:
		case BS_BUTTON_CODE::k4:
		case BS_BUTTON_CODE::k5:
		case BS_BUTTON_CODE::k6:
		case BS_BUTTON_CODE::k7:
		case BS_BUTTON_CODE::k8:
		case BS_BUTTON_CODE::k9:
		case BS_BUTTON_CODE::kA:
		case BS_BUTTON_CODE::kB:
		case BS_BUTTON_CODE::kC:
		case BS_BUTTON_CODE::kD:
		case BS_BUTTON_CODE::kE:
		case BS_BUTTON_CODE::kF:
		case BS_BUTTON_CODE::kG:
		case BS_BUTTON_CODE::kH:
		case BS_BUTTON_CODE::kI:
		case BS_BUTTON_CODE::kJ:
		case BS_BUTTON_CODE::kK:
		case BS_BUTTON_CODE::kL:
		case BS_BUTTON_CODE::kM:
		case BS_BUTTON_CODE::kN:
		case BS_BUTTON_CODE::kO:
		case BS_BUTTON_CODE::kP:
		case BS_BUTTON_CODE::kQ:
		case BS_BUTTON_CODE::kR:
		case BS_BUTTON_CODE::kS:
		case BS_BUTTON_CODE::kT:
		case BS_BUTTON_CODE::kU:
		case BS_BUTTON_CODE::kV:
		case BS_BUTTON_CODE::kW:
		case BS_BUTTON_CODE::kX:
		case BS_BUTTON_CODE::kY:
		case BS_BUTTON_CODE::kZ:
		case BS_BUTTON_CODE::kNumpad_0:
		case BS_BUTTON_CODE::kNumpad_1:
		case BS_BUTTON_CODE::kNumpad_2:
		case BS_BUTTON_CODE::kNumpad_3:
		case BS_BUTTON_CODE::kNumpad_4:
		case BS_BUTTON_CODE::kNumpad_5:
		case BS_BUTTON_CODE::kNumpad_6:
		case BS_BUTTON_CODE::kNumpad_7:
		case BS_BUTTON_CODE::kNumpad_8:
		case BS_BUTTON_CODE::kNumpad_9:
		case BS_BUTTON_CODE::kNumpad_Multiply:
		case BS_BUTTON_CODE::kNumpad_Plus:
		case BS_BUTTON_CODE::kNumpad_Minus:
		case BS_BUTTON_CODE::kNumpad_Period:
		case BS_BUTTON_CODE::kNumpad_Divide:
		case BS_BUTTON_CODE::kF1:
		case BS_BUTTON_CODE::kF2:
		case BS_BUTTON_CODE::kF3:
		case BS_BUTTON_CODE::kF4:
		case BS_BUTTON_CODE::kF5:
		case BS_BUTTON_CODE::kF6:
		case BS_BUTTON_CODE::kF7:
		case BS_BUTTON_CODE::kF8:
		case BS_BUTTON_CODE::kF9:
		case BS_BUTTON_CODE::kF10:
		case BS_BUTTON_CODE::kF11:
		case BS_BUTTON_CODE::kF12:
		case BS_BUTTON_CODE::kSemicolon:
		case BS_BUTTON_CODE::kComma:
		case BS_BUTTON_CODE::kEquals:
		case BS_BUTTON_CODE::kMinus:
		case BS_BUTTON_CODE::kPeriod:
		case BS_BUTTON_CODE::kDivide:
		case BS_BUTTON_CODE::kLBracket:
		case BS_BUTTON_CODE::kBackslash:
		case BS_BUTTON_CODE::kRBracket:
		case BS_BUTTON_CODE::kApostrophe:
		case BS_BUTTON_CODE::kLShift:
		case BS_BUTTON_CODE::kRShift:
		case BS_BUTTON_CODE::kLControl:
		case BS_BUTTON_CODE::kRControl:
		case BS_BUTTON_CODE::kLAlt:
		case BS_BUTTON_CODE::kRAlt:
		case BS_BUTTON_CODE::kGamepad:
		case BS_BUTTON_CODE::kDPAD_Up:
		case BS_BUTTON_CODE::kDPAD_Down:
		case BS_BUTTON_CODE::kDPAD_Left:
		case BS_BUTTON_CODE::kDPAD_Right:
		case BS_BUTTON_CODE::kLTrigger:
		case BS_BUTTON_CODE::kRTrigger:
		case BS_BUTTON_CODE::kSelect:
		case BS_BUTTON_CODE::kLStick:
		case BS_BUTTON_CODE::kRStick:
		case BS_BUTTON_CODE::kLShoulder:
		case BS_BUTTON_CODE::kRShoulder:
		case BS_BUTTON_CODE::kAButton:
		case BS_BUTTON_CODE::kBButton:
		case BS_BUTTON_CODE::kXButton:
		case BS_BUTTON_CODE::kYButton:
			return true;
		default:
			return false;
		}
	}

	constexpr BS_BUTTON_CODE FromStringToButtonCode(std::string_view str) noexcept
	{
		if constexpr (true) {
			if (str == "kBackspace")
				return BS_BUTTON_CODE::kBackspace;
			if (str == "kTab")
				return BS_BUTTON_CODE::kTab;
			if (str == "kEnter")
				return BS_BUTTON_CODE::kEnter;
			if (str == "kCapsLock")
				return BS_BUTTON_CODE::kCapsLock;
			if (str == "kEscape")
				return BS_BUTTON_CODE::kEscape;
			if (str == "kSpace")
				return BS_BUTTON_CODE::kSpace;
			if (str == "kPageUp")
				return BS_BUTTON_CODE::kPageUp;
			if (str == "kPageDown")
				return BS_BUTTON_CODE::kPageDown;
			if (str == "kEnd")
				return BS_BUTTON_CODE::kEnd;
			if (str == "kHome")
				return BS_BUTTON_CODE::kHome;
			if (str == "kLeft")
				return BS_BUTTON_CODE::kLeft;
			if (str == "kUp")
				return BS_BUTTON_CODE::kUp;
			if (str == "kRight")
				return BS_BUTTON_CODE::kRight;
			if (str == "kDown")
				return BS_BUTTON_CODE::kDown;
			if (str == "kInsert")
				return BS_BUTTON_CODE::kInsert;
			if (str == "kDelete")
				return BS_BUTTON_CODE::kDelete;
			if (str == "k0")
				return BS_BUTTON_CODE::k0;
			if (str == "k1")
				return BS_BUTTON_CODE::k1;
			if (str == "k2")
				return BS_BUTTON_CODE::k2;
			if (str == "k3")
				return BS_BUTTON_CODE::k3;
			if (str == "k4")
				return BS_BUTTON_CODE::k4;
			if (str == "k5")
				return BS_BUTTON_CODE::k5;
			if (str == "k6")
				return BS_BUTTON_CODE::k6;
			if (str == "k7")
				return BS_BUTTON_CODE::k7;
			if (str == "k8")
				return BS_BUTTON_CODE::k8;
			if (str == "k9")
				return BS_BUTTON_CODE::k9;
			if (str == "kA")
				return BS_BUTTON_CODE::kA;
			if (str == "kB")
				return BS_BUTTON_CODE::kB;
			if (str == "kC")
				return BS_BUTTON_CODE::kC;
			if (str == "kD")
				return BS_BUTTON_CODE::kD;
			if (str == "kE")
				return BS_BUTTON_CODE::kE;
			if (str == "kF")
				return BS_BUTTON_CODE::kF;
			if (str == "kG")
				return BS_BUTTON_CODE::kG;
			if (str == "kH")
				return BS_BUTTON_CODE::kH;
			if (str == "kI")
				return BS_BUTTON_CODE::kI;
			if (str == "kJ")
				return BS_BUTTON_CODE::kJ;
			if (str == "kK")
				return BS_BUTTON_CODE::kK;
			if (str == "kL")
				return BS_BUTTON_CODE::kL;
			if (str == "kM")
				return BS_BUTTON_CODE::kM;
			if (str == "kN")
				return BS_BUTTON_CODE::kN;
			if (str == "kO")
				return BS_BUTTON_CODE::kO;
			if (str == "kP")
				return BS_BUTTON_CODE::kP;
			if (str == "kQ")
				return BS_BUTTON_CODE::kQ;
			if (str == "kR")
				return BS_BUTTON_CODE::kR;
			if (str == "kS")
				return BS_BUTTON_CODE::kS;
			if (str == "kT")
				return BS_BUTTON_CODE::kT;
			if (str == "kU")
				return BS_BUTTON_CODE::kU;
			if (str == "kV")
				return BS_BUTTON_CODE::kV;
			if (str == "kW")
				return BS_BUTTON_CODE::kW;
			if (str == "kX")
				return BS_BUTTON_CODE::kX;
			if (str == "kY")
				return BS_BUTTON_CODE::kY;
			if (str == "kZ")
				return BS_BUTTON_CODE::kZ;
			if (str == "kNumpad_0")
				return BS_BUTTON_CODE::kNumpad_0;
			if (str == "kNumpad_1")
				return BS_BUTTON_CODE::kNumpad_1;
			if (str == "kNumpad_2")
				return BS_BUTTON_CODE::kNumpad_2;
			if (str == "kNumpad_3")
				return BS_BUTTON_CODE::kNumpad_3;
			if (str == "kNumpad_4")
				return BS_BUTTON_CODE::kNumpad_4;
			if (str == "kNumpad_5")
				return BS_BUTTON_CODE::kNumpad_5;
			if (str == "kNumpad_6")
				return BS_BUTTON_CODE::kNumpad_6;
			if (str == "kNumpad_7")
				return BS_BUTTON_CODE::kNumpad_7;
			if (str == "kNumpad_8")
				return BS_BUTTON_CODE::kNumpad_8;
			if (str == "kNumpad_9")
				return BS_BUTTON_CODE::kNumpad_9;
			if (str == "kNumpad_Multiply")
				return BS_BUTTON_CODE::kNumpad_Multiply;
			if (str == "kNumpad_Plus")
				return BS_BUTTON_CODE::kNumpad_Plus;
			if (str == "kNumpad_Minus")
				return BS_BUTTON_CODE::kNumpad_Minus;
			if (str == "kNumpad_Period")
				return BS_BUTTON_CODE::kNumpad_Period;
			if (str == "kNumpad_Divide")
				return BS_BUTTON_CODE::kNumpad_Divide;
			if (str == "kF1")
				return BS_BUTTON_CODE::kF1;
			if (str == "kF2")
				return BS_BUTTON_CODE::kF2;
			if (str == "kF3")
				return BS_BUTTON_CODE::kF3;
			if (str == "kF4")
				return BS_BUTTON_CODE::kF4;
			if (str == "kF5")
				return BS_BUTTON_CODE::kF5;
			if (str == "kF6")
				return BS_BUTTON_CODE::kF6;
			if (str == "kF7")
				return BS_BUTTON_CODE::kF7;
			if (str == "kF8")
				return BS_BUTTON_CODE::kF8;
			if (str == "kF9")
				return BS_BUTTON_CODE::kF9;
			if (str == "kF10")
				return BS_BUTTON_CODE::kF10;
			if (str == "kF11")
				return BS_BUTTON_CODE::kF11;
			if (str == "kF12")
				return BS_BUTTON_CODE::kF12;
			if (str == "kSemicolon")
				return BS_BUTTON_CODE::kSemicolon;
			if (str == "kComma")
				return BS_BUTTON_CODE::kComma;
			if (str == "kEquals")
				return BS_BUTTON_CODE::kEquals;
			if (str == "kMinus")
				return BS_BUTTON_CODE::kMinus;
			if (str == "kPeriod")
				return BS_BUTTON_CODE::kPeriod;
			if (str == "kDivide")
				return BS_BUTTON_CODE::kDivide;
			if (str == "kLBracket")
				return BS_BUTTON_CODE::kLBracket;
			if (str == "kBackslash")
				return BS_BUTTON_CODE::kBackslash;
			if (str == "kRBracket")
				return BS_BUTTON_CODE::kRBracket;
			if (str == "kApostrophe")
				return BS_BUTTON_CODE::kApostrophe;
			if (str == "kLShift")
				return BS_BUTTON_CODE::kLShift;
			if (str == "kRShift")
				return BS_BUTTON_CODE::kRShift;
			if (str == "kLControl")
				return BS_BUTTON_CODE::kLControl;
			if (str == "kRControl")
				return BS_BUTTON_CODE::kRControl;
			if (str == "kLAlt")
				return BS_BUTTON_CODE::kLAlt;
			if (str == "kRAlt")
				return BS_BUTTON_CODE::kRAlt;
			if (str == "kGamepad")
				return BS_BUTTON_CODE::kGamepad;
			if (str == "kDPAD_Up")
				return BS_BUTTON_CODE::kDPAD_Up;
			if (str == "kDPAD_Down")
				return BS_BUTTON_CODE::kDPAD_Down;
			if (str == "kDPAD_Left")
				return BS_BUTTON_CODE::kDPAD_Left;
			if (str == "kDPAD_Right")
				return BS_BUTTON_CODE::kDPAD_Right;
			if (str == "kLTrigger")
				return BS_BUTTON_CODE::kLTrigger;
			if (str == "kRTrigger")
				return BS_BUTTON_CODE::kRTrigger;
			if (str == "kSelect")
				return BS_BUTTON_CODE::kSelect;
			if (str == "kLStick")
				return BS_BUTTON_CODE::kLStick;
			if (str == "kRStick")
				return BS_BUTTON_CODE::kRStick;
			if (str == "kLShoulder")
				return BS_BUTTON_CODE::kLShoulder;
			if (str == "kRShoulder")
				return BS_BUTTON_CODE::kRShoulder;
			if (str == "kAButton")
				return BS_BUTTON_CODE::kAButton;
			if (str == "kBButton")
				return BS_BUTTON_CODE::kBButton;
			if (str == "kXButton")
				return BS_BUTTON_CODE::kXButton;
			if (str == "kYButton")
				return BS_BUTTON_CODE::kYButton;
		}
		return static_cast<BS_BUTTON_CODE>(-1);
	}

	class IDEvent;

	class __declspec(novtable) InputEvent
	{
	public:
		static constexpr auto RTTI{ RTTI::InputEvent };
		static constexpr auto VTABLE{ VTABLE::InputEvent };

		enum class HANDLED_RESULT : std::int32_t
		{
			kUnhandled,
			kContinue,
			kStop
		};

		virtual ~InputEvent() = default;  // 00

		// add
		virtual bool HasIDCode() const { return false; }  // 02
		virtual const BSFixedString& QUserEvent() const;  // 03

		template <class T>
		[[nodiscard]] T* As() noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const noexcept  //
			requires(std::derived_from<T, InputEvent> &&
					 !std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (*eventType == T::TYPE) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] T* As()  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<T*>(this);
			} else {
				return nullptr;
			}
		}

		template <class T>
		[[nodiscard]] const T* As() const  //
			requires(std::same_as<std::decay_t<T>, IDEvent>)
		{
			if (HasIDCode()) {
				return static_cast<const T*>(this);
			} else {
				return nullptr;
			}
		}

		// members
		stl::enumeration<INPUT_DEVICE, std::int32_t> device{ INPUT_DEVICE::kNone };             // 08
		std::int32_t deviceID{ 0 };                                                             // 0C
		stl::enumeration<INPUT_EVENT_TYPE, std::int32_t> eventType{ INPUT_EVENT_TYPE::kNone };  // 10
		InputEvent* next{ nullptr };                                                            // 18
		std::uint32_t timeCode{ static_cast<std::uint32_t>(-1) };                               // 20
		stl::enumeration<HANDLED_RESULT, std::int32_t> handled{ HANDLED_RESULT::kUnhandled };   // 24
	};
	static_assert(sizeof(InputEvent) == 0x28);

	class __declspec(novtable) CharacterEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CharacterEvent };
		static constexpr auto VTABLE{ VTABLE::CharacterEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kChar };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CharacterEvent() = default;  // 00

		// members
		std::uint32_t charCode{ 0 };  // 28
	};
	static_assert(sizeof(CharacterEvent) == 0x30);

	extern template CharacterEvent* InputEvent::As() noexcept;
	extern template const CharacterEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) DeviceConnectEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::DeviceConnectEvent };
		static constexpr auto VTABLE{ VTABLE::DeviceConnectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kDeviceConnect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~DeviceConnectEvent() = default;  // 00

		// members
		bool connected{ true };  // 28
	};
	static_assert(sizeof(DeviceConnectEvent) == 0x30);

	extern template DeviceConnectEvent* InputEvent::As() noexcept;
	extern template const DeviceConnectEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) IDEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IDEvent };
		static constexpr auto VTABLE{ VTABLE::IDEvent };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IDEvent() = default;  // 00

		// override (InputEvent)
		bool HasIDCode() const override { return true; }  // 02

		const BSFixedString& QUserEvent() const override  // 03
		{
			if (!disabled) {
				return strUserEvent;
			}

			return "DISABLED"sv;
		}

		[[nodiscard]] const bool QDisabled() const noexcept { return disabled; }
		[[nodiscard]] const std::uint32_t QIDCode() const noexcept { return idCode; }
		[[nodiscard]] const BSFixedString& QRawUserEvent() const noexcept { return strUserEvent; }

		// members
		BSFixedString strUserEvent;  // 28
		std::int32_t idCode{ -1 };   // 30
		bool disabled{ false };      // 34
	};
	static_assert(sizeof(IDEvent) == 0x38);

	extern template IDEvent* InputEvent::As();
	extern template const IDEvent* InputEvent::As() const;

	class __declspec(novtable) ButtonEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ButtonEvent };
		static constexpr auto VTABLE{ VTABLE::ButtonEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kButton };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ButtonEvent() = default;  // 00

		[[nodiscard]] BS_BUTTON_CODE GetBSButtonCode() const noexcept
		{
			stl::enumeration<BS_BUTTON_CODE> result{ static_cast<BS_BUTTON_CODE>(idCode) };
			switch (device.get()) {
			case INPUT_DEVICE::kGamepad:
				result.set(BS_BUTTON_CODE::kGamepad);
			default:
				return result.get();
			}
		}

		[[nodiscard]] float QAnalogValue() const noexcept { return value; }
		[[nodiscard]] bool QHeldDown(float a_heldDownSecs) const noexcept { return value != 0.0 && a_heldDownSecs <= heldDownSecs; }
		[[nodiscard]] float QHeldDownSecs() const noexcept { return heldDownSecs; }
		[[nodiscard]] bool QJustPressed() const noexcept { return value != 0.0F && heldDownSecs == 0.0F; }
		[[nodiscard]] bool QReleased(float a_heldDownSecs) const noexcept { return value == 0.0F && a_heldDownSecs <= heldDownSecs; }

		// members
		float value{ 0.0F };         // 38
		float heldDownSecs{ 0.0F };  // 3C
	};
	static_assert(sizeof(ButtonEvent) == 0x40);

	extern template ButtonEvent* InputEvent::As() noexcept;
	extern template const ButtonEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) CursorMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::CursorMoveEvent };
		static constexpr auto VTABLE{ VTABLE::CursorMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kCursorMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~CursorMoveEvent() = default;  // 00

		// members
		std::int32_t cursorPosX{ 0 };  // 38
		std::int32_t cursorPosY{ 0 };  // 3C
	};
	static_assert(sizeof(CursorMoveEvent) == 0x40);

	extern template CursorMoveEvent* InputEvent::As() noexcept;
	extern template const CursorMoveEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) KinectEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::KinectEvent };
		static constexpr auto VTABLE{ VTABLE::KinectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kKinect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~KinectEvent() = default;  // 00

		// members
		BSFixedString strHeard;  // 38
	};
	static_assert(sizeof(KinectEvent) == 0x40);

	extern template KinectEvent* InputEvent::As() noexcept;
	extern template const KinectEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) MouseMoveEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MouseMoveEvent };
		static constexpr auto VTABLE{ VTABLE::MouseMoveEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kMouseMove };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~MouseMoveEvent() = default;  // 00

		// members
		std::int32_t mouseInputX{ 0 };  // 38
		std::int32_t mouseInputY{ 0 };  // 3C
	};
	static_assert(sizeof(MouseMoveEvent) == 0x40);

	extern template MouseMoveEvent* InputEvent::As() noexcept;
	extern template const MouseMoveEvent* InputEvent::As() const noexcept;

	class __declspec(novtable) ThumbstickEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ThumbstickEvent };
		static constexpr auto VTABLE{ VTABLE::ThumbstickEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kThumbstick };

		enum THUMBSTICK_ID : std::int32_t
		{
			kLeft = 0xB,
			kRight = 0xC,
		};

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~ThumbstickEvent() = default;  // 00

		// members
		float xValue{ 0.0F };                           // 38
		float yValue{ 0.0F };                           // 3C
		DIRECTION_VAL prevDir{ DIRECTION_VAL::kNone };  // 40
		DIRECTION_VAL currDir{ DIRECTION_VAL::kNone };  // 44
	};
	static_assert(sizeof(ThumbstickEvent) == 0x48);

	extern template ThumbstickEvent* InputEvent::As() noexcept;
	extern template const ThumbstickEvent* InputEvent::As() const noexcept;
}
