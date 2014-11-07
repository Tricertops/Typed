//
//  TCollections.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark Private

#define _TConcat(A, B)    A##B
#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [_TConcat(Type, Alloc)(Element) initWithObjects:objects count:count]; \
})

#define _TAssociativeCollectionMake(MutableType, Key, Value, Pairs...) \
(MutableType(Key, Value))({ \
    MutableType(Key, Value) _associative = [MutableType##Alloc(Key, Value) init];\
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

#define TAssociativeGenerate(Key, Value) \
_TDictionaryCreateProtocol(Key, Value) \
_TMutableDictionaryCreateProtocol(Key, Value) \
_TCacheCreateProtocol(Key, Value) \



#pragma mark - 
#pragma mark Helpers

#define TPair(Key, Value)               [_associative setObject:(Value) forKey:(Key)]



#pragma mark -
#pragma mark TArray

#define TArray(Element)                 _TConcat(Element, Array)
#define TArrayAlloc(Element)            ( (TArray(Element)) [NSArray alloc] )
#define TArrayMake(Element, ...)        _TCollectionMake(TArray, Element, __VA_ARGS__)
#define _TArrayForward(Element) \
    @protocol _TConcat(TArray_, Element); \
    typedef id<_TConcat(TArray_, Element)> _TConcat(Element, Array); \



#pragma mark TMutableArray

#define TMutableArray(Element)          _TConcat(Element, MutableArray)
#define TMutableArrayAlloc(Element)     ( (TMutableArray(Element)) [NSMutableArray alloc] )
#define TMutableArrayMake(Element, ...) _TCollectionMake(TMutableArray, Element, __VA_ARGS__)
#define _TMutableArrayForward(Element) \
    @protocol _TConcat(TMutableArray_, Element); \
    typedef id<_TConcat(TMutableArray_, Element)> _TConcat(Element, MutableArray); \



#pragma mark -
#pragma mark TSet

#define TSet(Element)                   _TConcat(Element, Set)
#define TSetAlloc(Element)              ( (TSet(Element)) [NSSet alloc] )
#define TSetMake(Element, ...)          _TCollectionMake(TSet, Element, __VA_ARGS__)
#define _TSetForward(Element) \
    @protocol _TConcat(TSet_, Element); \
    typedef id<_TConcat(TSet_, Element)> _TConcat(Element, Set); \



#pragma mark TMutableSet

#define TMutableSet(Element)            _TConcat(Element, MutableSet)
#define TMutableSetAlloc(Element)       ( (TMutableSet(Element)) [NSMutableSet alloc] )
#define TMutableSetMake(Element, ...)   _TCollectionMake(TMutableSet, Element, __VA_ARGS__)
#define _TMutableSetForward(Element) \
    @protocol _TConcat(TMutableSet_, Element); \
    typedef id<_TConcat(TMutableSet_, Element)> _TConcat(Element, MutableSet); \



#pragma mark TCountedSet

#define TCountedSet(Element)            _TConcat(Element, CountedSet)
#define TCountedSetAlloc(Element)       ( (TCountedSet(Element)) [NSCountedSet alloc] )
#define TCountedSetMake(Element, ...)   _TCollectionMake(TCountedSet, Element, __VA_ARGS__)
#define _TCountedSetForward(Element) \
    @protocol _TConcat(TCountedSet_, Element); \
    typedef id<_TConcat(TCountedSet_, Element)> _TConcat(Element, CountedSet); \



#pragma mark -
#pragma mark TOrderedSet

#define TOrderedSet(Element)            _TConcat(Element, OrderedSet)
#define TOrderedSetAlloc(Element)       ( (TOrderedSet(Element)) [NSOrderedSet alloc] )
#define TOrderedSetMake(Element, ...)   _TCollectionMake(TOrderedSet, Element, __VA_ARGS__)
#define _TOrderedSetForward(Element) \
    @protocol _TConcat(TOrderedSet_, Element); \
    typedef id<_TConcat(TOrderedSet_, Element)> _TConcat(Element, OrderedSet); \



#pragma mark TMutableOrderedSet

#define TMutableOrderedSet(Element)             _TConcat(Element, MutableOrderedSet)
#define TMutableOrderedSetAlloc(Element)        ( (TMutableOrderedSet(Element)) [NSMutableOrderedSet alloc] )
#define TMutableOrderedSetMake(Element, ...)    _TCollectionMake(TMutableOrderedSet, Element, __VA_ARGS__)
#define _TMutableOrderedSetForward(Element) \
    @protocol _TConcat(TMutableOrderedSet_, Element); \
    typedef id<_TConcat(TMutableOrderedSet_, Element)> _TConcat(Element, MutableOrderedSet); \



#pragma mark -
#pragma mark TDictionary

#define TDictionary(Key, Value)                 Key##To##Value##Dictionary
#define TDictionaryAlloc(Key, Value)            ( (TDictionary(Key, Value)) [NSDictionary alloc] )
#define TDictionaryMake(Key, Value, TPairs...)  ( (TDictionary(Key, Value)) _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs) )
#define _TDictionaryForward(Key, Value) \
@protocol TDictionary_##Key##_##Value; \
typedef id<TDictionary_##Key##_##Value> Key##To##Value##Dictionary; \



#pragma mark TMutableDictionary

#define TMutableDictionary(Key, Value)                  Key##To##Value##MutableDictionary
#define TMutableDictionaryAlloc(Key, Value)             ( (TMutableDictionary(Key, Value)) [NSMutableDictionary alloc] )
#define TMutableDictionaryMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TMutableDictionary, Key, Value, TPairs)
#define _TMutableDictionaryForward(Key, Value) \
@protocol TMutableDictionary_##Key##_##Value; \
typedef id<TMutableDictionary_##Key##_##Value> Key##To##Value##MutableDictionary; \



#pragma mark - TCache

#define TCache(Key, Value)                  Key##To##Value##Cache
#define TCacheAlloc(Key, Value)             ( (TCache(Key, Value)) [NSCache alloc] )
#define TCacheMake(Key, Value, TPairs...)   _TAssociativeCollectionMake(TCache, Key, Value, TPairs)
#define _TCacheForward(Key, Value) \
@protocol TCache_##Key##_##Value; \
typedef id<TCache_##Key##_##Value> Key##To##Value##Cache; \


