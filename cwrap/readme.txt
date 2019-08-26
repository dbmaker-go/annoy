C wrapper for annoy
===================

1. build:
```
  g++ -shared -fPIC -o libcannoy.so cannoy.cpp
```

2. usage in C:

test.c
```
// build c program:
//   cc -o test test.c -L. -lcannoy
//

#include "cannoy.h"

// call c wrapper functions
```

3. build dll with MSC
```
cl /c cannoy.cpp
link /DLL /OUT:cannoy.dll /DEF:cannoy.def cannoy.obj
cl test.c cannoy.lib
```

