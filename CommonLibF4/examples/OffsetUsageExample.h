#pragma once

#include "REL/IDSelection.h"

// Пример использования offset'ов вместо ID для RTTI и VTABLE

namespace ExampleUsage
{
    // Пример 1: Класс с одним VTABLE (offset)
    class __declspec(novtable) SimpleClass
    {
    public:
        // Используем offset вместо ID когда ID недоступен
        static constexpr auto RTTI{ REL::SelectVersionRTTI(0x1234567, 0x7654321) };
        static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(0x1111111, 0x2222222) };

        virtual ~SimpleClass() = default;
    };

    // Пример 2: Класс с множественным наследованием (несколько VTABLE)
    class __declspec(novtable) MultiInheritanceClass
    {
    public:
        static constexpr auto RTTI{ REL::SelectVersionRTTI(0x3333333, 0x4444444) };

        // Для множественного наследования - массив offset'ов
        static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(
            std::array<REL::Offset, 3>{
                REL::Offset(0x5555555),
                REL::Offset(0x6666666),
                REL::Offset(0x7777777)
            },
            std::array<REL::Offset, 3>{
                REL::Offset(0x8888888),
                REL::Offset(0x9999999),
                REL::Offset(0xAAAAAAA)
            }
        ) };

        virtual ~MultiInheritanceClass() = default;
    };

    // Пример 3: Смешанное использование - ID для одной версии, Offset для другой
    class __declspec(novtable) MixedClass
    {
    public:
        // RTTI может использовать ID для OG и offset для AE (или наоборот)
        static constexpr auto RTTI{ REL::SelectVersionOffset(0xBBBBBBB, 0xCCCCCCC) };

        // VTABLE аналогично
        static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(
            REL::Offset(0xDDDDDDD),
            REL::Offset(0xEEEEEEE)
        ) };

        virtual ~MixedClass() = default;
    };

    // Демонстрация использования в fallout_cast
    inline void DemonstrateCast()
    {
        SimpleClass* simple = nullptr;

        // fallout_cast работает с offset'ами точно так же, как с ID
        // потому что REL::Relocation принимает и ID, и Offset
        auto* casted = RE::fallout_cast<MultiInheritanceClass*>(simple);
    }
}

/* 
 * ВАЖНЫЕ ЗАМЕЧАНИЯ:
 * 
 * 1. REL::Offset конвертируется в адрес через: base() + offset()
 * 2. REL::ID конвертируется в адрес через: поиск в базе данных релокаций
 * 3. REL::Relocation может работать с обоими типами (см. Relocation.h:677-683)
 * 4. fallout_cast создает REL::Relocation<void*> из RTTI, который может быть как ID, так и Offset
 * 5. Для VTABLE используется массив, если есть множественное наследование
 * 
 * КОГДА ИСПОЛЬЗОВАТЬ OFFSET:
 * - Когда ID недоступен в базе данных релокаций
 * - Когда у вас есть прямой offset от базового адреса модуля
 * - Когда вы работаете с динамически найденными адресами
 * 
 * КОГДА ИСПОЛЬЗОВАТЬ ID:
 * - Когда ID есть в базе данных (RTTI_IDs.h, VTABLE_IDs.h)
 * - Когда нужна кроссплатформенность между разными версиями
 * - Это предпочтительный вариант, если ID доступен
 */
