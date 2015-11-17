Macros for Objective-C generics <a href="https://flattr.com/submit/auto?user_id=Tricertops&url=https%3A%2F%2Fgithub.com%2FiMartinKiss%2FTyped" target="_blank"><img src="https://api.flattr.com/button/flattr-badge-large.png" alt="Flattr this" title="Flattr this" border="0"></a>
=============================
So we got Objective-C generics for collections and the language got even more verbose. This little project provided a working implementation of generics before their inclusion in the language. See branch [`legacy`](https://github.com/iMartinKiss/Typed/tree/legacy) for more details.

The new purpose is to simplify working with existing generics system by introducing the missing type inferrence from Swift.

Instead of this:

```objc
NSMutableArray<NSArray<NSString *> *> *hostsByResource = [NSMutableArray new];
for (NSString *key in table.allKeys) {
    NSDictionary<NSString *, NSURL *> *resource = table[key];
    NSMutableArray<NSString *> *hosts = [NSMutableArray new];
    for (NSURL *URL in table.allValues)
        [hosts addObject: URL.host];
    [hostsByResource addObject:hosts];
}
```

Write this:

```objc
LET(hostsByResource =, MAP(table.allKeys, typeof(hosts), {
    LET(resource =, table[x]);
    LET(hosts =, MAP(resource.allValues, NSString *, x.host));
    yield hosts;
}));
```



LET & VAR
---------

Declare constant or mutable variable without specifying the type. `LET()` uses `const` to prevent re-assignation of another value. They both require typing explicit `=` sign, so the assignment is not obfuscated.

```objc
LET(string =, @"String"); // NSString*
VAR(integer =, 5); // int
integer += 2;
LET(resource =, table[@"users"]); // NSDictionary<NSString*,User*>*
```

FOR
---

Enumerate collections without specifying the type. `FOR()` works with `for-in` language statement to infer element type. The `in` keyword is required to improve readability.

```objc
NSArray<NSString *> *fruits = @[ @"Apple", @"Pear", @"Orange" ];
for IN(fruit in, fruits) {
    // fruit is NSString*
}
```


MAP
---

Map arrays to other arrays without specifying the type (almost). `MAP()` takes existing array and an expression that is applied to all elements. If the expression returns `nil` it is not added to the result array. The macro requires specifiying the type of the resulted array elements (`NSString *` in the examples below).

```objc
LET(URLs =, self.allURLs);
LET(hosts =, MAP(URLs, NSString *, x.host));
```

Compound statement is also supported. This is not a block, so calling `break` and `continue` applies to the internal enumeration loop (you can skip elements or interrupt the mapping). Calling `return` would terminate current function. Proper way to return a value from this expression, is to just write it as the last statement (GNU thing, don’t ask me why).
 
```objc
LET(descriptions =, MAP(URLs, NSString *, {
    NSMutableString *description = [NSMutableString new];
    [description appendString: @"GET "];
    [description appendString: x.path];
    description;
}));
```


NSCopying & NSMutableCopying
----------------------------

Foundation collections are really bad at declaring their copy types. All of them were given appropriate types instead of `id`.

```objc
- (NSArray *)copy;
- (NSMutableArray *)mutableCopy;
```


---
The MIT License (MIT)  
Copyright © 2015 Martin Kiss
