# Bitching about C++ Examples

Example classes that I refer to a lot in
[my C++ notes](https://bishan.app).

---

This repository contains fully expanded examples of how 
I would write examples I used in my notes with full C++ features & safety conventions.

All parts of this project are annotated with a link to a note on https://bishan.app that describes the relevant feature.

## Source Files

**[Header File](https://github.com/bishan-batel/CString/blob/main/examples/c_string/c_string.hpp)** |
**[Source File](https://github.com/bishan-batel/CString/blob/main/examples/c_string/c_string.cpp)**

> [!note]
**[Type Naming Convention](https://github.com/bishan-batel/CString/blob/main/utils.hpp)**
>
> I use a common naming convention for C++ & C that aliases a lot of standard types such as
> `int`, `long`, `long` `int`, `size_t`, etc, with variants such as
> `i32`, `i64`, `usize`, `f32`, etc. I find hungarian notation very unappealing, and the default types in C++ to be
> unclear at a glance
> what their type is, so I always use this notation. If you are confused what a certain type is, look inside
> the [utils.hpp](https://github.com/bishan-batel/CString/blob/main/utils.hpp) file
> to see descriptions of each of the type aliases.
>
> If this convention is good enough for the Linux Kernel, it's good enough for mine or any other projects.
