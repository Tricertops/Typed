//
//  TCollections.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark TCollection

#define _TConcat(A, B)    A##B
#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [_TConcat(Type, Alloc)(Element) initWithObjects:objects count:count]; \
})

#define TGenerate(Element) \
_TArrayCreateProtocol(Element) \
_TMutableArrayCreateProtocol(Element) \
_TSetCreateProtocol(Element) \
_TMutableSetCreateProtocol(Element) \
_TCountedSetCreateProtocol(Element) \
_TOrderedSetCreateProtocol(Element) \
_TMutableOrderedSetCreateProtocol(Element) \



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


