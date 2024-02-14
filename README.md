# CString Example
Example CString Class that I refer to a lot in 
[my C++ notes](https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B). 

---

This repo contains how I would write a class that wraps around a normal C-Style String in a safe manner with all C++ conventions I would normally use.

All parts of this project are annotated with a link to a note on https://bishan.app that describes the relevant feature.

**[Header File](https://github.com/bishan-batel/CString/blob/main/c_string.hpp)**
**[Source File](https://github.com/bishan-batel/CString/blob/main/c_string.cpp)**

>[!note]
**[Type Naming Convention](https://github.com/bishan-batel/CString/blob/main/utils.hpp)**
> 
> I use a common naming convention for C++ & C that aliases a lot of standard types such as 
> `int`, `long`, `long` `int`, `size_t`, etc, with variants such as
> `i32`, `i64`, `usize`, `f32`, etc. I find hungarian notation very unappealing, and the default types in C++ to be unclear at a glance
> what their type is, so I always use this notation. If you are confused what a certain type is, look inside the [utils.hpp](https://github.com/bishan-batel/CString/blob/main/utils.hpp) file 
> to see descriptions of each of the type aliases.
> 
> If this convention is good enough for the Linux Kernel, it's good enough for mine or any other projects.
