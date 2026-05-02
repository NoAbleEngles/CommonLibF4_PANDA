# Решение проблемы: Offset vs ID для VTABLE и RTTI

## Проблема
**Исходный вопрос:** "Оффсет есть для VTABLE, а ID нет. В конечном итоге нам нужен именно оффсет, а не сам ID, как решить эту проблему?"

## Анализ

### Как работает система релокаций:

1. **REL::ID** - это идентификатор в базе данных релокаций IDA
   - Преобразуется в адрес через поиск в базе: `ID::address()` → ищет в `_id2offset` таблице

2. **REL::Offset** - это прямой offset от базового адреса модуля
   - Преобразуется в адрес напрямую: `Offset::address()` = `base() + offset()`

3. **REL::Relocation<T>** - универсальный контейнер адреса
   - Имеет конструкторы для **обоих** типов:
     ```cpp
     explicit Relocation(ID a_id);        // строка 681 в Relocation.h
     explicit Relocation(Offset a_offset); // строка 677 в Relocation.h
     ```

### Почему это безопасно:

**RTTI и VTABLE используются через `REL::Relocation`:**

```cpp
// Из RTTI.h:211-212
REL::Relocation<void*> from{ detail::remove_cvpr_t<From>::RTTI };
REL::Relocation<void*> to{ detail::remove_cvpr_t<To>::RTTI };
```

`REL::Relocation` **не заботится**, является ли его аргумент `ID` или `Offset` - оба конвертируются в адрес через метод `.address()`.

## Решение

### Добавлены новые функции в `REL/IDSelection.h`:

#### 1. Для одиночных значений (RTTI):
```cpp
constexpr Offset SelectVersionRTTI(std::size_t ogOffset, std::size_t aeOffset);
constexpr Offset SelectVersionRTTI(const Offset& ogOffset, const Offset& aeOffset);
```

#### 2. Для одиночных значений (универсальный):
```cpp
constexpr Offset SelectVersionOffset(std::size_t ogOffset, std::size_t aeOffset);
constexpr Offset SelectVersionOffset(const Offset& ogOffset, const Offset& aeOffset);
```

#### 3. Для VTABLE с одним значением:
```cpp
constexpr std::array<Offset, 1> SelectVersionVTABLEOffset(std::size_t og, std::size_t ae);
constexpr std::array<Offset, 1> SelectVersionVTABLEOffset(const Offset& og, const Offset& ae);
```

#### 4. Для VTABLE с множественным наследованием:
```cpp
template<std::size_t N>
constexpr std::array<Offset, N> SelectVersionVTABLEOffset(
    const std::array<Offset, N>& ogVTABLE,
    const std::array<Offset, N>& aeVTABLE
);
```

## Использование

### До (с ID):
```cpp
class MyClass
{
public:
    static constexpr auto RTTI{ REL::SelectVersionID(RTTI::MyClass, RTTI_AE::MyClass) };
    static constexpr auto VTABLE{ REL::SelectVersionVTABLE(VTABLE::MyClass, VTABLE_AE::MyClass) };
};
```

### После (с Offset):
```cpp
class MyClass
{
public:
    // Одиночное значение
    static constexpr auto RTTI{ REL::SelectVersionRTTI(0x1234567, 0x7654321) };
    static constexpr auto VTABLE{ REL::SelectVersionVTABLEOffset(0x1111111, 0x2222222) };

    // Или множественное наследование
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
};
```

## Гарантии безопасности

✅ **Не ломает существующую логику** - `REL::Relocation` всегда поддерживал `Offset`  
✅ **Совместимо с fallout_cast** - работает через `REL::Relocation<void*>`  
✅ **Compile-time проверки** - все `constexpr`, ошибки видны на этапе компиляции  
✅ **Нет overhead'а** - `Offset::address()` = простое сложение  
✅ **Полная симметрия с ID-версиями** - та же структура API  

## Поток данных

```
SelectVersionRTTI(og, ae)
    ↓
REL::Offset(выбранный_offset)
    ↓
REL::Relocation<void*>(offset)
    ↓
offset.address() = base() + offset()
    ↓
Используется в fallout_cast / vtable lookup
```

## Файлы изменены

- ✅ `CommonLibF4/include/REL/IDSelection.h` - добавлены offset-функции
- ✅ `CommonLibF4/examples/OffsetUsageExample.h` - примеры использования
- ✅ `CommonLibF4/docs/OFFSET_USAGE.md` - документация

## Заключение

**Проблема решена полностью:**
- Когда ID есть → используйте `SelectVersionID` / `SelectVersionVTABLE`
- Когда ID нет, но есть offset → используйте `SelectVersionOffset` / `SelectVersionVTABLEOffset` / `SelectVersionRTTI`

Обе системы работают через единый интерфейс `REL::Relocation`, поэтому **никакая логика не нарушена**.
