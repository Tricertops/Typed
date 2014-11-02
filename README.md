Statically typed Objective-C collections
=============================
Do you like typed arrays in Swift (or other languages)? Would you like to have them in Objective-C? Now you can.

This project provides a way to declare `NSArray` typed for one specific class, so all methods you call will be type-checked by the compiler.

![Image](Image.png)

**Project Status: In development.** _TArray_ is implemented and _TMutableArray_, _TDictionary_, _TSet_, and more are on the roadmap. Stay tuned.

> Symbol ⚠️ in the following code examples marks the point, where Xcode emits warning about incompatible types. These warning can be turned into errors for better safety.

TArray
------
_TArray_ is **drop-in replacement** for `NSArray` type, but it’s **parametrized** with element class. This declares an array of strings:

```
TArray(NSString) strings = nil;
```

However, for every element class you plan to use, you’ll need to generate the typed version of _TArray_:

```
// Typically in .h file
TArrayGenerate(NSString)
```

Typed version fo the basic foundation classes are already provided.

### Creating
Objects stored as _TArrays_ at runtime are in fact `NSArray` instances. The type-checking trick is made at **compile-time** using customized protocol interface.

You can store any `NSArray` in variable of this type, but you have to **cast** it:

```
TArray(NSString) strings = (TArray(NSString))objects;
TArray(NSString) strings = (TArray(NSString))@[ @"Apple", @"Orange", @"Pear" ];
TArray(NSString) strings = ⚠️objects;
TArray(NSString) strings = ⚠️@[ @"Apple", @"Orange" ];
TArray(NSString) strings = ⚠️(TArray(NSNumber))objects;
```

Such casting makes **no** static (nor dynamic) type-checking, so you have to be sure the array contains only instances of given class.

_TArray_ provides a convenience constructor that with static type-checking:

```
TArray(NSString) strings = TArrayMake(NSString, @"Apple", @"Orange", @"Pear");
TArray(NSString) strings = TArrayMake(NSString, @"Apple", ⚠️@42);
```

To use a typed array as `NSArray`, cast it again:

```
NSArray *objects = (NSArray *)strings;
NSArray *objects = ⚠️strings;
```

### Methods
_TArray_ has **exact** the same interface as `NSArray` class, but all occurences of `id` are replaced with the class of the elements and `NSArray` types are replaced with a _TArray_ of the same type:

```
- (NSString *)objectAtIndex:(NSUInteger)index;
- (BOOL)containsObject:(NSString *)object;
- (TArray(NSString))arrayByAddingObjectsFromArray:(TArray(NSString))otherArray;
```

Accessing objects from a typed array:

```
NSString *apple = strings.firstObject;
NSString *orange = strings[1];
NSURL *websiteURL = ⚠️strings.firstObject;
NSNumber *ultimateAnswer = ⚠️strings[1];
```

Finding objects in a typed array:

```
BOOL containsApple = [strings containsObject:@"Apple"];
NSUInteger orangeIndex = [strings indexOfObject:@"Orange"];
BOOL containsUltimateAnswer = [strings containsObject:⚠️@42];
NSUInteger websiteURLIndex = [strings indexOfObject:⚠️websiteURL];
```

Deriving new typed arrays:

```
strings = [strings copy];
strings = [strings arrayByAddingObject:@"Peach"];
strings = [strings subarrayWithRange:NSMakeRange(0, 3)];
TArray(NSURL) URLs = ⚠️[strings copy];
TArray(NSDate) dates = ⚠️[strings arrayByAddingObject:@"Peach"];
TArray(NSNumber) answers = ⚠️[strings subarrayWithRange:NSMakeRange(0, 3)];
```
---

> More typed collection classes will be implemented in near future.

---
The MIT License (MIT)  
Copyright © 2014 Martin Kiss
