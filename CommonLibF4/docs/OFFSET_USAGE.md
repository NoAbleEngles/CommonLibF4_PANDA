# Использование Offset вместо ID для RTTI и VTABLE

## Проблема
Иногда в базе данных релокаций нет ID для VTABLE или RTTI, но есть прямой offset от базового адреса модуля.

## Решение
Используйте функции с суффиксом `Offset` или `RTTI` из `REL/IDSelection.h`:

### Для одиночных значений

```cpp
// RTTI
static constexpr auto RTTI{ REL::SelectVersionRTTI(0x1234567, 0x7654321) };
// или
static constexpr auto RTTI{ REL::SelectVersionOffset(0x1234567, 0x7654321) };

// VTABLE (одно значение)
static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(0x1111111, 0x2222222) };
```

### Для массивов VTABLE (множественное наследование)

```cpp
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
```

## Как это работает

1. **`REL::ID`** - поиск адреса через базу данных релокаций
2. **`REL::Offset`** - прямое вычисление: `base_address + offset`
3. **`REL::Relocation`** - принимает оба типа и конвертирует в адрес

```cpp
// Оба варианта работают одинаково:
REL::Relocation<void*> fromID{ REL::ID(12345) };       // поиск в базе
REL::Relocation<void*> fromOffset{ REL::Offset(0x1000) }; // base + 0x1000
```

## API функции

### SelectVersionRTTI
```cpp
constexpr Offset SelectVersionRTTI(std::size_t ogOffset, std::size_t aeOffset);
constexpr Offset SelectVersionRTTI(const Offset& ogOffset, const Offset& aeOffset);
```

### SelectVersionOffset
```cpp
constexpr Offset SelectVersionOffset(std::size_t ogOffset, std::size_t aeOffset);
constexpr Offset SelectVersionOffset(const Offset& ogOffset, const Offset& aeOffset);
```

### SelectVersionVTABLEOffset
```cpp
// Одно значение
constexpr std::array<Offset, 1> SelectVersionVTABLEOffset(std::size_t og, std::size_t ae);
constexpr std::array<Offset, 1> SelectVersionVTABLEOffset(const Offset& og, const Offset& ae);

// Массив (для множественного наследования)
template<std::size_t N>
constexpr std::array<Offset, N> SelectVersionVTABLEOffset(
    const std::array<Offset, N>& ogVTABLE,
    const std::array<Offset, N>& aeVTABLE
);
```

## Сравнение: ID vs Offset

| Аспект | REL::ID | REL::Offset |
|--------|---------|-------------|
| Источник данных | База данных релокаций | Прямой offset |
| Когда использовать | ID доступен в RTTI_IDs.h/VTABLE_IDs.h | ID отсутствует |
| Производительность | Требует поиска в базе | Прямое вычисление |
| Надежность | Зависит от базы данных | Зависит от версии игры |
| Совместимость | Работает с REL::Relocation | Работает с REL::Relocation |

## Полный пример

```cpp
class __declspec(novtable) MyClass
{
public:
    // RTTI: используем offset (ID недоступен)
    static constexpr auto RTTI{ REL::SelectVersionRTTI(0x1234567, 0x7654321) };

    // VTABLE: множественное наследование, 3 vtable
    static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(
        std::array<REL::Offset, 3>{
            REL::Offset(0x1000000),
            REL::Offset(0x2000000),
            REL::Offset(0x3000000)
        },
        std::array<REL::Offset, 3>{
            REL::Offset(0x4000000),
            REL::Offset(0x5000000),
            REL::Offset(0x6000000)
        }
    ) };

    virtual ~MyClass() = default;
};

// Использование в fallout_cast работает прозрачно
MyClass* ptr = nullptr;
auto* casted = RE::fallout_cast<OtherClass*>(ptr); // работает!
```

## Важно

- `SelectVersionRTTI` - это просто алиас для `SelectVersionOffset` с более понятным именем
- Обе функции возвращают `REL::Offset`
- `REL::Relocation` автоматически обрабатывает как `ID`, так и `Offset`
- Логика работы **не ломается** - это полностью совместимо с существующим кодом
