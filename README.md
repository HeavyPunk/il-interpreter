# il-interpreter
---
Current repository is represent interpreter for IL-code([documentation link](none))\
At the current moment it supports only folowing operators:
- LD
- LDN
- ST
- ADD
- MUL

But has implementation for many other operators (actual behavior will be added a bit later)
---
### Compilation and run guide:
1. You should clone this repository and [this](https://github.com/Mashpoe/c-hashmap) to the same directory
2. Install ```gcc``` compiler and ```make``` utility
3. Check that your PATH environment variable contains path to ```gcc``` compiler and ```make```
4. Just run ```make release``` in the root of this repository
5. Now you should create a IL-code file ```hello.il``` nearby to ```interpreter.bin``` file (or ```interpreter.bin.exe``` if you used windows's ```mingw``` to compile it)
6. Write some code to ```hello.il```
7. Run interpreter via command ```./interpreter.bin```
---
### IL-code example
```
LD in ;get a integer from stdin and write it to A register
ADD 3 ;add 3 to A register
MUL 2 ;multiply for 2 the A register
ST out ;write the A register's value to stdout

RET ;return on 1 level higher in callstack (interrupt execution at current situation)

LD 10 ;write a 10 to register A
MUL 5


ST out
```
