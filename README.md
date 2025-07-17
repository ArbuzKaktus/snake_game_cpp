# 🐍 Snake Game | C++ & SFML


Классическая игра "Змейка" с современной реализацией на C++23 с использованием SFML для графики и CMake для сборки.

[![Snake](https://s.iimg.su/s/17/xcnV3hdmDQLVnG8xN7saSieX9XLcx5VD2q8FbLF2.png)](https://iimg.su/i/TlmVao)

## Запуск

### Сборка проекта
```bash
# Клонирование репозитория
git clonehttps://github.com/ArbuzKaktus/snake_game_сpp.git
cd snake_game_cpp

mkdir build && cd build
cmake .. && make

# Запуск
./snake
```

## Управление
| Клавиша  | Действие                         |
|----------|----------------------------------|
| W        | Движение вверх                   |
| S        | Движение вниз                    |
| A        | Движение влево                   |
| D        | Движение вправо                  |
| Enter    | Рестарт игры, при проигрыше      |

## Структура проекта
```text
snake_game_cpp/
├── bin/            # Исполняемые файлы
├── lib/            # Основные компоненты
│   ├── game/       # Игровая логика
│   ├── snake/      # Логика змейки
│   └── apple/      # Логика яблок
├── font/         # Ресурсы (шрифт)
└── CMakeLists.txt  # Конфигурация сборки
```

## ⚙️ Настройки игры
Все параметры можно изменить в `lib/constants.h`:

```cpp
namespace game {
    const size_t kScreenWidth = 800;     // Ширина окна
    const size_t kScreenHeight = 600;    // Высота окна
    const float  kTimeout = 0.2f;        // Скорость игры (сек/ход)
    const size_t kApllesCount = 5;       // Макс. яблок на экране
}
```

## Зависимости
- SFML 2.5+ (Graphics, Window, System)
- CMake 3.16+
- Компилятор с поддержкой C++23


<div align="center">
  <sub>Создано с ❤️ для изучения C++ и SFML</sub>
</div>