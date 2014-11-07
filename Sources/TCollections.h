//
//  TCollections.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#pragma mark -
#pragma mark TCollection

#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [Type##Alloc(Element) initWithObjects:objects count:count]; \
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

#define TArray(Element)                 Element##Array
#define TArrayAlloc(Element)            ( (TArray(Element)) [NSArray alloc] )
#define TArrayMake(Element, ...)        _TCollectionMake(TArray, Element, __VA_ARGS__)
#define _TArrayForward(Element) \
    @protocol TArray_##Element; \
    typedef id<TArray_##Element> Element##Array; \



#pragma mark TMutableArray

#define TMutableArray(Element)          Element##MutableArray
#define TMutableArrayAlloc(Element)     ( (TMutableArray(Element)) [NSMutableArray alloc] )
#define TMutableArrayMake(Element, ...) _TCollectionMake(TMutableArray, Element, __VA_ARGS__)
#define _TMutableArrayForward(Element) \
    @protocol TMutableArray_##Element; \
    typedef id<TMutableArray_##Element> Element##MutableArray; \



#pragma mark -
#pragma mark TSet

#define TSet(Element)                   Element##Set
#define TSetAlloc(Element)              ( (TSet(Element)) [NSSet alloc] )
#define TSetMake(Element, ...)          _TCollectionMake(TSet, Element, __VA_ARGS__)
#define _TSetForward(Element) \
    @protocol TSet_##Element; \
    typedef id<TSet_##Element> Element##Set; \



#pragma mark TMutableSet

#define TMutableSet(Element)            Element##MutableSet
#define TMutableSetAlloc(Element)       ( (TMutableSet(Element)) [NSMutableSet alloc] )
#define TMutableSetMake(Element, ...)   _TCollectionMake(TMutableSet, Element, __VA_ARGS__)
#define _TMutableSetForward(Element) \
    @protocol TMutableSet_##Element; \
    typedef id<TMutableSet_##Element> Element##MutableSet; \



#pragma mark TCountedSet

#define TCountedSet(Element)            Element##CountedSet
#define TCountedSetAlloc(Element)       ( (TCountedSet(Element)) [NSCountedSet alloc] )
#define TCountedSetMake(Element, ...)   _TCollectionMake(TCountedSet, Element, __VA_ARGS__)
#define _TCountedSetForward(Element) \
    @protocol TCountedSet_##Element; \
    typedef id<TCountedSet_##Element> Element##CountedSet; \



#pragma mark -
#pragma mark TOrderedSet

#define TOrderedSet(Element)            Element##OrderedSet
#define TOrderedSetAlloc(Element)       ( (TOrderedSet(Element)) [NSOrderedSet alloc] )
#define TOrderedSetMake(Element, ...)   _TCollectionMake(TOrderedSet, Element, __VA_ARGS__)
#define _TOrderedSetForward(Element) \
    @protocol TOrderedSet_##Element; \
    typedef id<TOrderedSet_##Element> Element##OrderedSet; \



#pragma mark TMutableOrderedSet

#define TMutableOrderedSet(Element)             Element##MutableOrderedSet
#define TMutableOrderedSetAlloc(Element)        ( (TMutableOrderedSet(Element)) [NSMutableOrderedSet alloc] )
#define TMutableOrderedSetMake(Element, ...)    _TCollectionMake(TMutableOrderedSet, Element, __VA_ARGS__)
#define _TMutableOrderedSetForward(Element) \
    @protocol TMutableOrderedSet_##Element; \
    typedef id<TMutableOrderedSet_##Element> Element##MutableOrderedSet; \


