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
1. You should clone this repository and [this]() to the same directory
2. Install ```gcc``` compiler and ```make``` utility
3. Check that your PATH environment variable contains path to ```gcc``` compiler and ```make```
4. Just run ```make release``` in the root of this repository
5. Now you should create a IL-code file ```hello.il``` nearby to ```interpreter.bin``` file (or ```interpreter.bin.exe``` if you used windows's ```mingw``` to compile it)
6. Write some code to ```hello.il```
7. Run interpreter via command ```./interpreter.bin```
