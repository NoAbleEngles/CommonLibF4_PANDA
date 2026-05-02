#include "REL/IDSelection.h"
#include "REL/Relocation.h"

// Тест 1: Проверка constexpr
static_assert(std::is_same_v<decltype(REL::SelectVersionOffset(0x1000, 0x2000)), REL::Offset>);
static_assert(std::is_same_v<decltype(REL::SelectVersionRTTI(0x1000, 0x2000)), REL::Offset>);

// Тест 2: Проверка что Offset работает с Relocation
namespace Test {
    constexpr REL::Offset testOffset = REL::SelectVersionOffset(0x1000, 0x2000);

    void TestRelocation() {
        // Это должно компилироваться - Relocation принимает Offset
        REL::Relocation<void*> rel1{ testOffset };
        REL::Relocation<void*> rel2{ REL::Offset(0x1234) };

        // Также должно работать с ID для сравнения
        REL::Relocation<void*> rel3{ REL::ID(12345) };
    }

    // Тест 3: Проверка VTABLE массивов
    constexpr auto vtable1 = REL::SelectVersionVTABLEOffset(0x1000, 0x2000);
    static_assert(vtable1.size() == 1);

    constexpr auto vtable3 = REL::SelectVersionVTABLEOffset(
        std::array<REL::Offset, 3>{
            REL::Offset(0x1000),
            REL::Offset(0x2000),
            REL::Offset(0x3000)
        },
        std::array<REL::Offset, 3>{
            REL::Offset(0x4000),
            REL::Offset(0x5000),
            REL::Offset(0x6000)
        }
    );
    static_assert(vtable3.size() == 3);

    // Тест 4: Проверка что можно использовать в классах
    class __declspec(novtable) TestClass {
    public:
        static constexpr auto RTTI{ REL::SelectVersionRTTI(0x100000, 0x200000) };
        static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(0x300000, 0x400000) };

        virtual ~TestClass() = default;
    };

    // Тест 5: Проверка что тип правильный
    static_assert(std::is_same_v<decltype(TestClass::RTTI), const REL::Offset>);
    static_assert(std::is_same_v<decltype(TestClass::VTABLE), const std::array<REL::Offset, 1>>);
}

// Все тесты успешны если этот файл компилируется
