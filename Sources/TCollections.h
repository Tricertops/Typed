//
//  TCollections.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark Private

#define _TConcat2(A, B)         A##B
#define _TConcat4(A, B, C, D)   A##B##C##D
#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding
#define _TWeakProtocols NSObject, NSFastEnumeration, NSCopying, NSCoding

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [_TConcat2(Type, Alloc)(Element) initWithObjects:objects count:count]; \
})

#define _TCollectionMakeByAdding(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    Type(Element) collection = _TConcat2(Type, Create)(Element); \
    for (NSUInteger index = 0; index < count; index++) { \
        [collection addObject:objects[index]];\
    } \
    collection; \
})

#define _TCollectionFromVariadic(MutableType, Element, First) \
(MutableType(Element))({ \
    va_list list; \
    va_start(list, First); \
    MutableType(Element) collection = [_TConcat2(MutableType, Alloc)(Element) init];\
    id object = First;\
    while (object) {\
        [collection addObject:object];\
        object = va_arg(list, id);\
    }\
    va_end(list);\
    collection; \
})


#define _TAssociativeCollectionMake(MutableType, Key, Value, Pairs...) \
(MutableType(Key, Value))({ \
    MutableType(Key, Value) _associative = [_TConcat2(MutableType,Alloc)(Key, Value) init];\
    Pairs; \
    _associative; \
})



#pragma mark -
#pragma mark Generating

#define TGenerate(Type, Ptr) \
_TArrayCreateProtocol(Type, Ptr) \
_TMutableArrayCreateProtocol(Type, Ptr) \
_TWeakArrayCreateProtocol(Type, Ptr) \
_TSetCreateProtocol(Type, Ptr) \
_TMutableSetCreateProtocol(Type, Ptr) \
_TCountedSetCreateProtocol(Type, Ptr) \
_TOrderedSetCreateProtocol(Type, Ptr) \
_TMutableOrderedSetCreateProtocol(Type, Ptr) \
_TWeakSetCreateProtocol(Type, Ptr) \

#define TAssociativeGenerate(Key,KeyPtr, Value,ValuePtr) \
_TDictionaryCreateProtocol(Key,KeyPtr, Value,ValuePtr) \
_TMutableDictionaryCreateProtocol(Key,KeyPtr, Value,ValuePtr) \
_TWeakDictionaryCreateProtocol(Key,KeyPtr, Value,ValuePtr) \
_TCacheCreateProtocol(Key,KeyPtr, Value,ValuePtr) \

#pragma mark Helpers

#define TPair(Key, Value)               [_associative setObject:(Value) forKey:(Key)]
#define TForIn(variable, TCollection)   for (typeof(TCollection.T_Enumeration) variable in TCollection)
#define TMap(source, destination, variable, expression) \
(typeof(destination))({ \
    NSMutableArray *__T_builder = [[source.class new] mutableCopy]; \
    TForIn(variable, source) { \
         [__T_builder addObject: (typeof(destination.T_Element))(expression) ]; \
    } \
    __T_builder; \
})




#pragma mark -
#pragma mark TArray

#define TArray(Type)                        _TConcat2(Type, Array)
#define TArrayAlloc(Type)                   ( (TArray(Type)) [NSArray alloc] )
#define TArrayCreate(Type)                  ( (TArray(Type)) [NSArray new] )
#define TArrayMake(Type, Objects...)        _TCollectionMake(TArray, Type, Objects)
#define TArrayFromVariadic(Type, First)     _TCollectionFromVariadic(TMutableArray, Type, First)
#define _TArrayForward(Type) \
    @protocol _TConcat2(TArray_, Type); \
    typedef id<_TConcat2(TArray_, Type)> _TConcat2(Type, Array); \



#pragma mark TMutableArray

#define TMutableArray(Type)                     _TConcat2(Type, MutableArray)
#define TMutableArrayAlloc(Type)                ( (TMutableArray(Type)) [NSMutableArray alloc] )
#define TMutableArrayCreate(Type)               ( (TMutableArray(Type)) [NSMutableArray new] )
#define TMutableArrayMake(Type, Objects...)     _TCollectionMake(TMutableArray, Type, Objects)
#define TMutableArrayFromVariadic(Type, First)  _TCollectionFromVariadic(TMutableArray, Type, First)
#define _TMutableArrayForward(Type) \
    @protocol _TConcat2(TMutableArray_, Type); \
    typedef id<_TConcat2(TMutableArray_, Type)> _TConcat2(Type, MutableArray); \



#pragma mark TWeakArray

#define TWeakArray(Type)                     _TConcat2(Type, WeakArray)
#define TWeakArrayCreate(Type)               ( (TWeakArray(Type)) [NSPointerArray weakObjectsPointerArray] )
#define TWeakArrayMake(Type, Objects...)     _TCollectionMakeByAdding(TWeakArray, Type, Objects)
#define TWeakArrayFromVariadic(Type, First)  _TCollectionFromVariadic(TWeakArray, Type, First)
#define _TWeakArrayForward(Type) \
    @protocol _TConcat2(TWeakArray_, Type); \
    typedef id<_TConcat2(TWeakArray_, Type)> _TConcat2(Type, WeakArray); \



#pragma mark -
#pragma mark TSet

#define TSet(Type)                      _TConcat2(Type, Set)
#define TSetAlloc(Type)                 ( (TSet(Type)) [NSSet alloc] )
#define TSetCreate(Type)                ( (TSet(Type)) [NSSet new] )
#define TSetMake(Type, Objects...)      _TCollectionMake(TSet, Type, Objects)
#define TSetFromVariadic(Type, First)   _TCollectionFromVariadic(TMutableSet, Type, First)
#define _TSetForward(Type) \
    @protocol _TConcat2(TSet_, Type); \
    typedef id<_TConcat2(TSet_, Type)> _TConcat2(Type, Set); \



#pragma mark TMutableSet

#define TMutableSet(Type)                       _TConcat2(Type, MutableSet)
#define TMutableSetAlloc(Type)                  ( (TMutableSet(Type)) [NSMutableSet alloc] )
#define TMutableSetCreate(Type)                 ( (TMutableSet(Type)) [NSMutableSet new] )
#define TMutableSetMake(Type, Objects...)       _TCollectionMake(TMutableSet, Type, Objects)
#define TMutableSetFromVariadic(Type, First)    _TCollectionFromVariadic(TMutableSet, Type, First)
#define _TMutableSetForward(Type) \
    @protocol _TConcat2(TMutableSet_, Type); \
    typedef id<_TConcat2(TMutableSet_, Type)> _TConcat2(Type, MutableSet); \



#pragma mark TCountedSet

#define TCountedSet(Type)                       _TConcat2(Type, CountedSet)
#define TCountedSetAlloc(Type)                  ( (TCountedSet(Type)) [NSCountedSet alloc] )
#define TCountedSetCreate(Type)                 ( (TCountedSet(Type)) [NSCountedSet new] )
#define TCountedSetMake(Type, Objects...)       _TCollectionMake(TCountedSet, Type, Objects)
#define TCountedSetFromVariadic(Type, First)    _TCollectionFromVariadic(TCountedSet, Type, First)
#define _TCountedSetForward(Type) \
    @protocol _TConcat2(TCountedSet_, Type); \
    typedef id<_TConcat2(TCountedSet_, Type)> _TConcat2(Type, CountedSet); \



#pragma mark -
#pragma mark TOrderedSet

#define TOrderedSet(Type)                       _TConcat2(Type, OrderedSet)
#define TOrderedSetAlloc(Type)                  ( (TOrderedSet(Type)) [NSOrderedSet alloc] )
#define TOrderedSetCreate(Type)                 ( (TOrderedSet(Type)) [NSOrderedSet new] )
#define TOrderedSetMake(Type, Objects...)       _TCollectionMake(TOrderedSet, Type, Objects)
#define TOrderedSetFromVariadic(Type, First)    _TCollectionFromVariadic(TMutableOrderedSet, Type, First)
#define _TOrderedSetForward(Type) \
    @protocol _TConcat2(TOrderedSet_, Type); \
    typedef id<_TConcat2(TOrderedSet_, Type)> _TConcat2(Type, OrderedSet); \



#pragma mark TMutableOrderedSet

#define TMutableOrderedSet(Type)                    _TConcat2(Type, MutableOrderedSet)
#define TMutableOrderedSetAlloc(Type)               ( (TMutableOrderedSet(Type)) [NSMutableOrderedSet alloc] )
#define TMutableOrderedSetCreate(Type)              ( (TMutableOrderedSet(Type)) [NSMutableOrderedSet new] )
#define TMutableOrderedSetMake(Type, Objects...)    _TCollectionMake(TMutableOrderedSet, Type, Objects)
#define TMutableOrderedSetFromVariadic(Type, First) _TCollectionFromVariadic(TMutableOrderedSet, Type, First)
#define _TMutableOrderedSetForward(Type) \
    @protocol _TConcat2(TMutableOrderedSet_, Type); \
    typedef id<_TConcat2(TMutableOrderedSet_, Type)> _TConcat2(Type, MutableOrderedSet); \



#pragma mark TWeakSet

#define TWeakSet(Type)                    _TConcat2(Type, WeakSet)
#define TWeakSetCreate(Type)              ( (TWeakSet(Type)) [NSHashTable weakObjectsHashTable] )
#define TWeakSetMake(Type, Objects...)    _TCollectionMakeByAdding(TWeakSet, Type, Objects)
#define TWeakSetFromVariadic(Type, First) _TCollectionFromVariadic(TWeakSet, Type, First)
#define _TWeakSetForward(Type) \
    @protocol _TConcat2(TWeakSet_, Type); \
    typedef id<_TConcat2(TWeakSet_, Type)> _TConcat2(Type, WeakSet); \



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)                 _TConcat4(Key, To, Value, Dictionary)
#define TDictionaryAlloc(Key, Value)            ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define TDictionaryCreate(Key, Value)           ( (TDictionary(Key, Value)) [NSDictionary new] )
#define TDictionaryMake(Key, Value, TPairs...)  ( (TDictionary(Key, Value)) _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs) )
#define _TDictionaryForward(Key, Value) \
    @protocol _TConcat4(TDictionary_, Key, _, Value); \
    typedef id<_TConcat4(TDictionary_, Key, _, Value)> _TConcat4(Key, To, Value, Dictionary); \



#pragma mark TMutableDictionary

#define TMutableDictionary(Key, Value)                  _TConcat4(Key, To, Value, MutableDictionary)
#define TMutableDictionaryAlloc(Key, Value)             ( (TMutableDictionary(Key, Value)) [NSMutableDictionary alloc] )
#define TMutableDictionaryCreate(Key, Value)            ( (TMutableDictionary(Key, Value)) [NSMutableDictionary new] )
#define TMutableDictionaryMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs)
#define _TMutableDictionaryForward(Key, Value) \
    @protocol _TConcat4(TMutableDictionary_, Key, _, Value); \
    typedef id<_TConcat4(TMutableDictionary_, Key, _, Value)> _TConcat4(Key, To, Value, MutableDictionary); \



#pragma mark TWeakDictionary

#define TWeakDictionary(Key, Value)                     _TConcat4(Key, To, Value, WeakDictionary)
#define TWeakDictionaryCreate(Key, Value, constructor)  ( (TWeakDictionary(Key, Value)) [NSMapTable constructor] )
#define _TWeakDictionaryForward(Key, Value) \
    @protocol _TConcat4(TWeakDictionary_, Key, _, Value); \
    typedef id<_TConcat4(TWeakDictionary_, Key, _, Value)> _TConcat4(Key, To, Value, WeakDictionary); \



#pragma mark - TCache

#define TCache(Key, Value)                  _TConcat4(Key, To, Value, Cache)
#define TCacheAlloc(Key, Value)             ( (TCache(Key, Value)) [NSCache alloc] )
#define TCacheCreate(Key, Value)            ( (TCache(Key, Value)) [NSCache new] )
#define TCacheMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TCache, Key, Value, TPairs)
#define _TCacheForward(Key, Value) \
    @protocol _TConcat4(TCache_, Key, _, Value); \
    typedef id<_TConcat4(TCache_, Key, _, Value)> _TConcat4(Key, To, Value, Cache); \


