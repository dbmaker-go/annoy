C wrapper for annoy
===================

1. build:
```
  g++ -shared -fPIC -o libcannoy.so cannoy.c
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

