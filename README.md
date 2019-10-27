# c_samples

Язык `С++` добавляет к языку `С` инструментальные средства объектно-ориентированного программирования.

[gnu](http://www.gnu.org/) - GNU's not Unix

# Libraries:

[ut hash](http://troydhanson.github.io/uthash/) hash table for c structures.

[protobuf c](https://github.com/protobuf-c/protobuf-c) C implementation of protocol buffers.

# Этапы построения програмы на С/С++ (От исходного кода до испоняемого файла):

- Препроцессор

Разрешает директивы препроцессора, такие как:
```
#include
#define
#ifdef, #enif
```
- Компиляция

Создает объектные файлы `*.obj, *.o`, проверяет ошибки.

- Компоновка

Сбор в месте - объектного кода, стандартного кода запуска для установленной операционной системы и библиотечного кода - последующее их помещением в отдельный файл, который называется `исполняемый`

# Install protobuf(protoc) on linux:

`sudo apt install protobuf-compiler`
