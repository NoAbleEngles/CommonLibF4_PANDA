# CommonLibF4

## General Requirements

### Build Dependencies
* [Visual Studio Community 2019 16.10.0 Preview 3.0](https://visualstudio.microsoft.com/vs/preview/)
	* Desktop development with C++

### Development
* [clang-format 12.0.0](https://github.com/llvm/llvm-project/releases)
* [CMake](https://cmake.org/)
* [vcpkg](https://github.com/microsoft/vcpkg)

## F4SE Plugin Requirements

### End User Dependencies
* [Address Library for F4SE Plugins](https://www.nexusmods.com/fallout4/mods/47327)
* [F4SE](https://f4se.silverlock.org/)

### Development
* [Address Library for F4SE Plugins](https://www.nexusmods.com/fallout4/mods/47327)

My attempt to port CommonLibF4 to AE. I've put this project on hold for now, but I might return to it in the future. I only looked for new addresses for RTTI, virtual tables, singletons, and functions. I didn't check the compatibility of class fields across different versions. 
List of completed files:
MemoryManager.h
Actor.h
TESForms.h
AITimeStamp.h
Archive2.h
Atomic.h
BGSBaseAliases.h
BGSBodyPartDefs.h
BGSCharacterMorph.h
BGSCharacterTint.h
BGSCreatedObjectManager.h
BGSDefaultObjectManager.h
BGSHeadPart.h
BGSInventoryInterface.h
BGSInventoryItem.h
BGSMod.h
BGSPrimitive.h
BGSSaveLoad.h
BGSStoryManagerTreeForm.h
BGSTextureSet.h
bhkCharacterController.h
BSBound.h
BSExtraData.h
BSGraphics.h
BSHavok.h
BSInputDeviceManager.h
BSInputEventReceiver.h
BSInputEventSingleUser.h
BSInputEventUser.h
BSLock.h
BSMTAManager.h
BSPointerHandle.h
BSPreCulledObjects.h
BSScaleformManager.h
BSShader.h
BSStringPool.h
BSSystemFileStreamer.h
BSSystemUtility.h
BSTEvent.h
BSTextureSet.h
BSTSmartPointer.h
Calendar.h
ControlMap.h
Events.h
FavoritesManager.h
FormComponents.h
FormFactory.h
GameScript.h
