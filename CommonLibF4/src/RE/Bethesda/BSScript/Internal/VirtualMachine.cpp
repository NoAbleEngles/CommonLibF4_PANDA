#include "C:/cpp/CommonLibF4/build/CommonLibF4/CMakeFiles/CommonLibF4.dir/Release/cmake_pch.hxx"
#include "RE/Bethesda/BSScript/Internal/VirtualMachine.h"
#include "RE/Bethesda/GameScript.h"
namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				auto vm = GameVM::GetSingleton();
				return vm ? static_cast<VirtualMachine*>(vm->impl.get()) : nullptr;
			}
		}
	}
}
