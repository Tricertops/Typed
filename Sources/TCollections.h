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

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [_TConcat2(Type, Alloc)(Element) initWithObjects:objects count:count]; \
})

#define _TAssociativeCollectionMake(MutableType, Key, Value, Pairs...) \
(MutableType(Key, Value))({ \
    MutableType(Key, Value) _associative = [_TConcat2(MutableType,Alloc)(Key, Value) init];\
    Pairs; \
    _associative; \
})



#pragma mark -
#pragma mark Generating

#define TGenerate(Element, Ptr) \
_TArrayCreateProtocol(Element, Ptr) \
_TMutableArrayCreateProtocol(Element, Ptr) \
_TSetCreateProtocol(Element, Ptr) \
_TMutableSetCreateProtocol(Element, Ptr) \
_TCountedSetCreateProtocol(Element, Ptr) \
_TOrderedSetCreateProtocol(Element, Ptr) \
_TMutableOrderedSetCreateProtocol(Element, Ptr) \

#define TAssociativeGenerate(Key,KeyPtr, Value,ValuePtr) \
_TDictionaryCreateProtocol(Key,KeyPtr, Value,ValuePtr) \
_TMutableDictionaryCreateProtocol(Key,KeyPtr, Value,ValuePtr) \
_TCacheCreateProtocol(Key,KeyPtr, Value,ValuePtr) \



#pragma mark - 
#pragma mark Helpers

#define TPair(Key, Value)               [_associative setObject:(Value) forKey:(Key)]



#pragma mark -
#pragma mark TArray

#define TArray(Element)                 _TConcat2(Element, Array)
#define TArrayAlloc(Element)            ( (TArray(Element)) [NSArray alloc] )
#define TArrayMake(Element, ...)        _TCollectionMake(TArray, Element, __VA_ARGS__)
#define _TArrayForward(Element) \
    @protocol _TConcat2(TArray_, Element); \
    typedef id<_TConcat2(TArray_, Element)> _TConcat2(Element, Array); \



#pragma mark TMutableArray

#define TMutableArray(Element)          _TConcat2(Element, MutableArray)
#define TMutableArrayAlloc(Element)     ( (TMutableArray(Element)) [NSMutableArray alloc] )
#define TMutableArrayMake(Element, ...) _TCollectionMake(TMutableArray, Element, __VA_ARGS__)
#define _TMutableArrayForward(Element) \
    @protocol _TConcat2(TMutableArray_, Element); \
    typedef id<_TConcat2(TMutableArray_, Element)> _TConcat2(Element, MutableArray); \



#pragma mark -
#pragma mark TSet

#define TSet(Element)                   _TConcat2(Element, Set)
#define TSetAlloc(Element)              ( (TSet(Element)) [NSSet alloc] )
#define TSetMake(Element, ...)          _TCollectionMake(TSet, Element, __VA_ARGS__)
#define _TSetForward(Element) \
    @protocol _TConcat2(TSet_, Element); \
    typedef id<_TConcat2(TSet_, Element)> _TConcat2(Element, Set); \



#pragma mark TMutableSet

#define TMutableSet(Element)            _TConcat2(Element, MutableSet)
#define TMutableSetAlloc(Element)       ( (TMutableSet(Element)) [NSMutableSet alloc] )
#define TMutableSetMake(Element, ...)   _TCollectionMake(TMutableSet, Element, __VA_ARGS__)
#define _TMutableSetForward(Element) \
    @protocol _TConcat2(TMutableSet_, Element); \
    typedef id<_TConcat2(TMutableSet_, Element)> _TConcat2(Element, MutableSet); \



#pragma mark TCountedSet

#define TCountedSet(Element)            _TConcat2(Element, CountedSet)
#define TCountedSetAlloc(Element)       ( (TCountedSet(Element)) [NSCountedSet alloc] )
#define TCountedSetMake(Element, ...)   _TCollectionMake(TCountedSet, Element, __VA_ARGS__)
#define _TCountedSetForward(Element) \
    @protocol _TConcat2(TCountedSet_, Element); \
    typedef id<_TConcat2(TCountedSet_, Element)> _TConcat2(Element, CountedSet); \



#pragma mark -
#pragma mark TOrderedSet

#define TOrderedSet(Element)            _TConcat2(Element, OrderedSet)
#define TOrderedSetAlloc(Element)       ( (TOrderedSet(Element)) [NSOrderedSet alloc] )
#define TOrderedSetMake(Element, ...)   _TCollectionMake(TOrderedSet, Element, __VA_ARGS__)
#define _TOrderedSetForward(Element) \
    @protocol _TConcat2(TOrderedSet_, Element); \
    typedef id<_TConcat2(TOrderedSet_, Element)> _TConcat2(Element, OrderedSet); \



#pragma mark TMutableOrderedSet

#define TMutableOrderedSet(Element)             _TConcat2(Element, MutableOrderedSet)
#define TMutableOrderedSetAlloc(Element)        ( (TMutableOrderedSet(Element)) [NSMutableOrderedSet alloc] )
#define TMutableOrderedSetMake(Element, ...)    _TCollectionMake(TMutableOrderedSet, Element, __VA_ARGS__)
#define _TMutableOrderedSetForward(Element) \
    @protocol _TConcat2(TMutableOrderedSet_, Element); \
    typedef id<_TConcat2(TMutableOrderedSet_, Element)> _TConcat2(Element, MutableOrderedSet); \



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)                 _TConcat4(Key, To, Value, Dictionary)
#define TDictionaryAlloc(Key, Value)            ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define TDictionaryMake(Key, Value, TPairs...)  ( (TDictionary(Key, Value)) _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs) )
#define _TDictionaryForward(Key, Value) \
    @protocol _TConcat4(TDictionary_, Key, _, Value); \
    typedef id<_TConcat4(TDictionary_, Key, _, Value)> _TConcat4(Key, To, Value, Dictionary); \



#pragma mark TMutableDictionary

#define TMutableDictionary(Key, Value)                  _TConcat4(Key, To, Value, MutableDictionary)
#define TMutableDictionaryAlloc(Key, Value)             ( (TMutableDictionary(Key, Value)) [NSMutableDictionary alloc] )
#define TMutableDictionaryMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs)
#define _TMutableDictionaryForward(Key, Value) \
    @protocol _TConcat4(TMutableDictionary_, Key, _, Value); \
    typedef id<_TConcat4(TMutableDictionary_, Key, _, Value)> _TConcat4(Key, To, Value, MutableDictionary); \



#pragma mark - TCache

#define TCache(Key, Value)                  _TConcat4(Key, To, Value, Cache)
#define TCacheAlloc(Key, Value)             ( (TCache(Key, Value)) [NSCache alloc] )
#define TCacheMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TCache, Key, Value, TPairs)
#define _TCacheForward(Key, Value) \
    @protocol _TConcat4(TCache_, Key, _, Value); \
    typedef id<_TConcat4(TCache_, Key, _, Value)> _TConcat4(Key, To, Value, Cache); \


