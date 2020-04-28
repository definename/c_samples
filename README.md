# c_samples

> Язык `С++` добавляет к языку `С` инструментальные средства объектно-ориентированного программирования.

> Проектная философия языка `C` предусматривает использование функций в качестве строительных блоков.

[gnu](http://www.gnu.org/) - GNU's not Unix

# Manual

[make](http://www.gnu.org/software/make/) - GNU Make is a tool which controls the generation of executables

[gdb](https://www.gnu.org/software/gdb/) - The GNU Project Debugger

[gcc](https://www.gnu.org/software/gcc/) - The GNU Compiler Collection

# Samples

[fsm](https://www.codeproject.com/Articles/1275479/State-Machine-Design-in-C) - finite state machine

# Libraries:

[ut hash](http://troydhanson.github.io/uthash/) hash table for c structures.

[protobuf c](https://github.com/protobuf-c/protobuf-c) C implementation of protocol buffers.

[pthread](http://man7.org/linux/man-pages/man0/pthread.h.0p.html#top_of_page) POSIX Programmer's Manual 

---

## macro and preprocessor

Marco pattern: `#define <NAME> <VALUE>`

Numeric constant: `#define PI 3.4`

Char constant: `#define BEEP '\a'`, `#define MYCHAR 'a'`

String constant: `#define MYSTRING "string"`

## array

Назначенные инициализаторы(C99) `int arr[6] = {[5] = 100}`, инициализирует 6й элемент массива значением 100.

Массивы переменной длины(C99) `int s = 10; int arr[s]`, здесь переменная `s` не является константным целочисленным выражением.

В языке `C` гарантируется, что при выделении пространства памяти под массив указатель на первую ячейку после конца массива `будет допустимым`. Однако несмотря на доспустимость указателя, ссылающегося на позицию после конца массива возможность его разыменования `не гарантируется`

## malloc/free

`double *d = (double*)malloc(n * sizeof(double))` - приведение к `double *` не обязательно в `c`, но требуется в `c++`, поэтому использование приведения типа упрощает перенос программы из `c` в `c++`
