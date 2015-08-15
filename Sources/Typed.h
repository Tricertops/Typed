//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 11.6.15.
//  Copyright © 2015 iMartin Kiss. All rights reserved.
//

#import <Foundation/Foundation.h>




//! Use to initialize new mutable variable with given value. Type will be inferred, add explicit `=` sign.
#define VAR(variable_equals, value)        typeof(value) variable_equals (value)

//! Use to initialize new immutable variable with given value. Type will be inferred, add explicit `=` sign.
#define LET(variable_equals, value)        typeof(value) const variable_equals (value)

//! Use directly after `for` declare enumation variable and the collection. Collection must conform to `TypedEnumerable` protocol. Type will be inferred, add explicit `in` keyword.
#define IN(variable_in, collection)    (typeof((collection).T_enumerableType) variable_in (collection))

//! Aahhh! Since Generic types include comma, they are hard to pass to macros. This fixes that problem…
#define PASS(...) __VA_ARGS__

//! Use to convert collection of one type to the same collection of different type. Collection’s mutable class must have addObject: (NSArray, NSSet, NSOrderedSet).
#define MAP(from, type, code...) \
(NSMutableArray<type> *)({ \
    NSMutableArray<type> *builder = [NSMutableArray new]; /*! Create mutable array. */ \
    for IN(x in, (from)) { /*! Enumerated variable is named `collectionObject`. */ \
        type mapped = (code); /*! Code may be single expression or {} block. */ \
        if (mapped == nil) continue; /*! Skip nils. */ \
        [builder addObject: mapped]; /*! Add. */ \
    } \
    builder; \
})


//! Pseudo-return to be used in compound expressions.
#define yield



#pragma mark -
//! These methods don’t need implementation. Method `T_enumerableType` is only for use in `typeof()` and copying is already implemented.


@interface NSArray<ObjectType> (Typed)
- (ObjectType)T_enumerableType;
- (NSArray<ObjectType> *)copy;
- (NSMutableArray<ObjectType> *)mutableCopy;
@end


@interface NSSet<ObjectType> (Typed)
- (ObjectType)T_enumerableType;
- (NSSet<ObjectType> *)copy;
- (NSMutableSet<ObjectType> *)mutableCopy;
@end


@interface NSCountedSet<ObjectType> (Typed)
- (NSCountedSet<ObjectType> *)mutableCopy;
@end


@interface NSOrderedSet<ObjectType> (Typed)
- (ObjectType)T_enumerableType;
- (NSOrderedSet<ObjectType> *)copy;
- (NSMutableOrderedSet<ObjectType> *)mutableCopy;
@end


@interface NSHashTable<ObjectType> (Typed)
- (ObjectType)T_enumerableType;
- (NSHashTable<ObjectType> *)copy;
@end


@interface NSDictionary<KeyType, ObjectType> (Typed)
- (KeyType)T_enumerableType;
- (NSDictionary<KeyType, ObjectType> *)copy;
- (NSMutableDictionary<KeyType, ObjectType> *)mutableCopy;
@end


@interface NSMapTable<KeyType, ObjectType> (Typed)
- (KeyType)T_enumerableType;
- (NSMapTable<KeyType, ObjectType> *)copy;
@end


@interface NSCache<KeyType, ObjectType> (Typed)
- (NSCache<KeyType, ObjectType> *)copy;
@end


