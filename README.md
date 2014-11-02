Statically typed Objective-C collections
=============================
Do you like typed arrays in Swift (or other languages)? Would you like to have them in Objective-C? Now you can.

This project provides a way to declare `NSArray` typed for one specific class, so all methods you call will be type-checked by the compiler.

![Image](Image.png)

**Project Status: In development.** _TArray_ is implemented and _TMutableArray_, _TDictionary_, _TSet_, and more are on the roadmap. Stay tuned.

> Symbol ⚠️ in the following code examples marks the point, where Xcode emits warning about incompatible types. These warning can be turned into errors for better safety.

TArray
------
_TArray_ and _TMutableArray_ are **drop-in replacements** for `NSArray` and `NSMutableArray` classes, but they are **parametrized** with element class. This declares an array of strings:

```objc
TArray(NSString) strings = nil;
TMutableArray(NSString) mutableStrings = nil;
```

However, for every element class you plan to use, you’ll need to generate the typed version of _TArray_:

```objc
// Typically in .h file
TArrayGenerate(NSString)
```
This will also generate _TMutableArray_ interface. Typed version fo the basic foundation classes are already provided.

### Creating
Objects stored as _TArrays_ at runtime are in fact `NSArray` instances (`NSMutableArray` for _TMutableArray_). The type-checking trick is made at **compile-time** using customized protocol interface.

You can store any `NSArray` in variable of this type, but you have to **cast** it:

```objc
TArray(NSString) strings = (TArray(NSString))objects;
TArray(NSString) strings = (TArray(NSString))@[ @"Apple", @"Orange", @"Pear" ];
TArray(NSString) strings = ⚠️objects;
TArray(NSString) strings = ⚠️@[ @"Apple", @"Orange" ];
TArray(NSString) strings = ⚠️(TArray(NSNumber))objects;
```

Such casting makes **no** static (nor dynamic) type-checking, so you have to be sure the array contains only instances of given class.

_TArray_ provides a convenience constructor with static type-checking:

```objc
TArray(NSString) strings = TArrayMake(NSString, @"Apple", @"Orange", @"Pear");
TArray(NSString) strings = TArrayMake(NSString, @"Apple", ⚠️@42);
```objc

To use a typed array as `NSArray`, cast it again:

```objc
NSArray *objects = (NSArray *)strings;
NSArray *objects = ⚠️strings;
```

### Methods
_TArray_ has **exact** the same interface as `NSArray` class, but all occurences of `id` are replaced with the class of the elements and `NSArray` types are replaced with a _TArray_ of the same type:

```objc
- (NSString *)objectAtIndex:(NSUInteger)index;
- (BOOL)containsObject:(NSString *)object;
- (TArray(NSString))arrayByAddingObjectsFromArray:(TArray(NSString))otherArray;
```

Accessing objects from a typed array:

```objc
NSString *apple = strings.firstObject;
NSString *orange = strings[1];
NSURL *websiteURL = ⚠️strings.firstObject;
NSNumber *ultimateAnswer = ⚠️strings[1];
```

Finding objects in a typed array:

```objc
BOOL containsApple = [strings containsObject:@"Apple"];
NSUInteger orangeIndex = [strings indexOfObject:@"Orange"];
BOOL containsUltimateAnswer = [strings containsObject:⚠️@42];
NSUInteger websiteURLIndex = [strings indexOfObject:⚠️websiteURL];
```

Deriving new typed arrays:

```objc
strings = [strings copy];
strings = [strings arrayByAddingObject:@"Peach"];
strings = [strings subarrayWithRange:NSMakeRange(0, 3)];
TArray(NSURL) URLs = ⚠️[strings copy];
TArray(NSDate) dates = ⚠️[strings arrayByAddingObject:@"Peach"];
TArray(NSNumber) answers = ⚠️[strings subarrayWithRange:NSMakeRange(0, 3)];
```

Mutating typed array:

```objc
TMutableArray(NSString) mutableStrings = [strings mutableCopy];        
[mutableStrings addObject:@"Pineapple"];
[mutableStrings replaceObjectAtIndex:2 withObject:@"Lemon"];
TMutableArray(NSDate) mutableDates = ⚠️[strings mutableCopy];        
[mutableStrings addObject:⚠️@42];
[mutableStrings replaceObjectAtIndex:2 withObject:⚠️websiteURL];
```

---

> More typed collection classes will be implemented in near future.

---
The MIT License (MIT)  
Copyright © 2014 Martin Kiss
