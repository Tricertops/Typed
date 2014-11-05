Statically typed Objective-C collections
=============================
Do you like typed arrays in Swift (or other languages)? Would you like to have them in Objective-C? Now you can.

![Image](Image.png)

**Project Status: In development.** _TArray_, _TSet_, _TOrderedSet_, and _TDictionary_ are implemented, _TCache_ and more are on the roadmap. Stay tuned.


Typed Collections
-----------------
_TArray_, _TSet_, _TOrderedSet_, and _TDictionary_ (with their mutable counterparts) are **parametrized drop-in replacements** for Foundation classes: `NSArray`, `NSSet`, `NSOrderedSet`, and `NSDictionary` respectively. Their parameter is the element class you wish to store, for example `TArray(NSString)`. Associative collections take two parameters, one for keys and one for values, for example `TDictionary(NSString, NSURL)`.

However, for **every element class** or association class pair you plan to use, you’ll need to generate the appropriate interfaces using a macro:

```objc
// Typically in .h file
TGenerate(NSString)
TAssociativeGenerate(NSString, NSURL)
```

Typed version fo the basic foundation classes are already provided.

### Casting
Objects stored as typed collections type are in fact Foundation collections (`NSArray`, `NSSet`, `NSDictionary`, …). The type-checking trick is made at **compile-time** using customized protocol interface.

You can store any `NSArray` in variable of _TArray_ type, but you have to **cast** it:

```objc
TArray(NSString) strings = (TArray(NSString))objects;
TArray(NSString) strings = (TArray(NSString))@[ @"Apple", @"Orange", @"Pear" ];
```

When not doing so, the compiler will **emit a warning**:

```objc
// Warning: Incompatible pointer types 3×:
TArray(NSString) strings = objects;
TArray(NSString) strings = @[ @"Apple", @"Orange" ];
TArray(NSString) strings = (TArray(NSNumber))objects;
```

Such casting makes **no** static (nor dynamic) type-checking, so you have to be sure the array contains only instances of given class.

You can use the typed collections in place of Foundation collections **without any casting**:

```objc
TSet(NSString) strings = ...
NSSet *objects = strings;
```

### Creating
Every typed collection has an allocation macro, that returns a new instance, but you **need to call `-init...`** method just like when allocating manually. Initialization methods are already type-checked against the element class:

```objc
TArray(NSString) strings = [TArrayAlloc(NSString) initWithObjects:@"Apple", nil];
```

In addition, every typed collection provides a convenience constructor with static type-checking of every element:

```objc
TSet(NSString) strings = TSetMake(NSString, @"Apple", @"Orange", @"Pear");
```

```objc
// Warning: Incompatible pointer types:
TArray(NSString) strings = TArrayMake(NSString, @"Apple", @42);
```

For _TDictionary_, the constructor is a bit more complicated, since it needs two types. You specify the pairs using _TPair_ macro, which should be used **only in this case**:

```objc
TDictionaryMake(NSString, NSNumber,
                TPair(@"Apple", @5),
                TPair(@"Orange", @2),
                TPair(@"Pear", @4));
```

```objc
// Warning: Incompatible pointer types 3×:
TDictionaryMake(NSString, NSNumber,
                TPair(@"Apple", @"5"),
                TPair(@2, @"Orange"),
                TPair(@"Pear", [NSDate new]));
```

### Methods
Typed collections have **exact** the same interface as their Foundation counterparts, but all occurences of `id` are **replaced with the class** of the elements (or associative keys and values). Also, all collection parameters (or return values) are **converted to typed** collections.

```objc
- (NSString *)objectAtIndex:(NSUInteger)index;
- (BOOL)containsObject:(NSString *)object;
- (TArray(NSString))arrayByAddingObjectsFromArray:(TArray(NSString))otherArray;
```

```objc
- (NSURL *)objectForKey:(NSString *)key;
@property (readonly, copy) TArray(NSURL) allValues;
- (TArray(NSString))allKeysForObject:(NSURL *)object;
```

**There is no implementation.** The method calls will be dispatched to their untyped variants at runtime.


Typed Examples
--------------
> You can find these code examples in `Test/main.m`.

**Accessing** objects in a typed array:

```objc
NSString *apple = strings.firstObject;
NSString *orange = strings[1];
```

```objc
// Warning: Incompatible pointer types 2×:
NSURL *websiteURL = strings.firstObject;
NSNumber *ultimateAnswer = strings[1];
```

**Finding** objects in a typed array:

```objc
BOOL containsApple = [strings containsObject:@"Apple"];
NSUInteger orangeIndex = [strings indexOfObject:@"Orange"];
```

```objc
// Warning: Incompatible pointer types 2×:
BOOL containsUltimateAnswer = [strings containsObject:@42];
NSUInteger websiteURLIndex = [strings indexOfObject:websiteURL];
```

**Deriving** new typed arrays:

```objc
strings = [strings copy];
strings = [strings arrayByAddingObject:@"Peach"];
strings = [strings subarrayWithRange:NSMakeRange(0, 3)];
```

```objc
// Warning: Incompatible pointer types 3×:
TArray(NSURL) URLs = [strings copy];
TArray(NSDate) dates = [strings arrayByAddingObject:@"Peach"];
TArray(NSNumber) answers = [strings subarrayWithRange:NSMakeRange(0, 3)];
```

**Mutating** typed array:

```objc
TMutableArray(NSString) mutableStrings = [strings mutableCopy];        
[mutableStrings addObject:@"Pineapple"];
[mutableStrings replaceObjectAtIndex:2 withObject:@"Lemon"];
```

```objc
// Warning: Incompatible pointer types 3×:
TMutableArray(NSDate) mutableDates = [strings mutableCopy];        
[mutableStrings addObject:@42];
[mutableStrings replaceObjectAtIndex:2 withObject:websiteURL];
```

**Sorting** typed set into typed array:

```objc
NSSortDescriptor *descriptor = [NSSortDescriptor sortDescriptorWithKey:@"self" ascending:YES];
TArray(NSSortDescriptor) descriptors = TArrayMake(NSSortDescriptor, descriptor);
TArray(NSString) sorted = [strings sortedArrayUsingDescriptors:descriptors];
```

```objc
// Warning: Incompatible pointer types:
TArray(NSNumber) sorted = [strings sortedArrayUsingDescriptors:descriptors];
```

**Lookup** in a typed dictionary:

```objc
NSInteger apples = fruitCounts[@"Apple"].integerValue;
```

```objc
// Warning: Incompatible pointer types 2×:
NSURL *website = fruitCounts[@"Apple"];
NSNumber *answer = fruitCounts[@42];
```

---
The MIT License (MIT)  
Copyright © 2014 Martin Kiss
