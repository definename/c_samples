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

## Этапы построения програмы на С/С++ (От исходного кода до испоняемого файла):

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

## function

`Фактический аргумент` - это выражения, указанное в круглых скобках при вызове функции

`Формальный параметр` - это перменная, объявленная в заголовке определения функции

---

При следующем объявлении функции `void print_name();` компилятор `ANSI C` предположит, что вы решили воспользоваться стилем объявления, предшествующим прототипированию, и не будет проверять аргументы

Для отражения того, что функция не принимает аргументов, укажите ключевое слово `void` в круглых скобках `void print_name(void);`

---

Цикл либо рекурсия?

Обычно цикл является более удачным выбором.
Во-первых, из-за того, что каждый рекурсивный вызов создает собственный набор переменных, вариант с рекурсией использует больше памяти; каждый рекурсивный вызов помещает в стек новый набор переменных. При этом ограниценный оюъем стека может устанавливать предел количества рекурсивных вызовов.

Во-вторых, рекурси выполяется медленнее, т.к. каждый вызов функции занимает определенное время.

## pointer

Указатель - это переменная, значением коротой является адрес в памяти.

Пользователи `С++` узнают переменные указатели и заинтересуются, не имеет ли `С` также и ссылочные переменные. Ответ на этот воспрос отрицательный.

## array

Назначенные инициализаторы(C99) `int arr[6] = {[5] = 100}`, инициализирует 6й элемент массива значением 100.

Массивы переменной длины(C99) `int s = 10; int arr[s]`, здесь переменная `s` не является константным целочисленным выражением.

В языке `C` гарантируется, что при выделении пространства памяти под массив указатель на первую ячейку после конца массива `будет допустимым`. Однако несмотря на доспустимость указателя, ссылающегося на позицию после конца массива возможность его разыменования `не гарантируется`

## malloc/free

`double *d = (double*)malloc(n * sizeof(double))` - приведение к `double *` не обязательно в `c`, но требуется в `c++`, поэтому использование приведения типа упрощает перенос программы из `c` в `c++`

## storage classes

 `auto` - автоматическая переменная характеризуется автоматической продолжительность хранения, областью видимости в пределах блока и отсутствием связывание.
```
int main(void) {
 auto int var = 1;
}
```
