# c_samples

Язык `С++` добавляет к языку `С` инструментальные средства объектно-ориентированного программирования.

[gnu](http://www.gnu.org/) - GNU's not Unix

[make](http://www.gnu.org/software/make/) - GNU Make is a tool which controls the generation of executables

[gdb](https://www.gnu.org/software/gdb/) - The GNU Project Debugger

# Samples

[fsm](https://www.codeproject.com/Articles/1275479/State-Machine-Design-in-C) - finite state machine

# Libraries:

[ut hash](http://troydhanson.github.io/uthash/) hash table for c structures.

[protobuf c](https://github.com/protobuf-c/protobuf-c) C implementation of protocol buffers.

[pthread](http://man7.org/linux/man-pages/man0/pthread.h.0p.html#top_of_page) POSIX Programmer's Manual 

# Этапы построения програмы на С/С++ (От исходного кода до испоняемого файла):

- Препроцессор

Разрешает директивы препроцессора, такие как:
```
#include
#define
#ifndef, #ifdef, #endif
```

- Компиляция

Создает объектные файлы `*.obj, *.o`, проверяет ошибки.

- Компоновка

Сбор в месте - объектного кода, стандартного кода запуска для установленной операционной системы и библиотечного кода - последующее их помещением в отдельный файл, который называется `исполняемый`

---

## char
Тип `char` обычно определяется как 8ми битная `единица памяти`. В общем случае язык `C` гарантирует, что тип `char` достаточно велик, чтобы представлять `базовый набор символов` в системах, для которых реализованы компиляторы `C`. Язык `C` определяет байт как несколько битов, используемых типом `char`, поэтому может быть система с 16- или 32-битным байтом и типом `char`. В языке `C` размер одного байта определяется в терминах `char`. Таким образом, в системе с 16-битным типом `char` и 64-битным типом `double` операция `sizeof` сообщит, что тип `double` имеет размер 4байта.

## size_t
Размер `size_t` типа выбирается таким образом, чтобы в него можно было записать максимальный размер теоретически возможного массива любого типа.

???
```
printf("%zd", sizeof(int))
printf("%zu", sizeof(int))
```

## sizeof

Используете вы круглые скобки или нет, зависит от того, хотите вы получить размер типа:`sizeof(char)` или конкретной величины: `int i; sizeof i`. Круглые скобки `обязательны для типов`, но `необязательны для отдельный величин`.

## macro and preprocessor

Marco pattern: `#define <NAME> <VALUE>`

Numeric constant: `#define PI 3.4`

Char constant: `#define BEEP '\a'`, `#define MYCHAR 'a'`

String constant: `#define MYSTRING "string"`

## valgrind

Check memory leaks at exit:

`valgrind --leak-check=full ./c_valgrind_app`

Check where uninitialized variables is used:

`valgrind --track-origins=yes ./c_valgrind_app`

