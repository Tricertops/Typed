Type inferrence in Objective-C
=============================

This project includes several macros and class categories that provide hints for compiler type inferrence. From simple `let` and `var` that are inspired by Swift, to `foreach () {}` construct that replaces `for (in) {}` loops.


**Without type inferrence, the types are error-prone:**

```objc
NSString *name = @"Martin";
NSMutableString *mutableName = [name mutableCopy];

NSArray<NSString *> *letters = @[@"A", @"B", @"C"];
NSMutableArray<NSString *> *mutableLetters = [letters mutableCopy];

for (NSString *letter in letters) {
    //...
}
```

- Types of almost all variables are *not* checked by compiler.
- Methods `-mutableCopy` discard types, because they return `id`.
- Array literal doesn’t check for mixed types and doesn’t propagate element type.
- Loop `for (in) {}` ignores element type of enumerated collection.


**With type inferrence, this is still pure Objective-C:**

```objc
let name = @"Martin";
var mutableName = [name mutableCopy];

let letters = NSArray(@"A", @"B", @"C");
var mutableLetters = [letters mutableCopy];

foreach (letter, letters) {
    //...
}
```

- Types of *all* variables are inferred from context.
- Methods `-mutableCopy` are redeclared with proper return type.
- Macro `NSArray(…)` doesnt’t accept mixed types as arguments and returns `NSArray` with proper element type.
- Macro `foreach () {}` infers type of the variable from the enumerated collection.

