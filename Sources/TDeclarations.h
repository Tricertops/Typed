//
//  TDeclarations.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//


#pragma mark - _TCollection

#define _TCollection id
#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding

#define _TCollectionMake(Type, Element, ...) \
(Type(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    NSUInteger count = sizeof(objects) / sizeof(Element *); \
    [Type##Alloc(Element) initWithObjects:objects count:count]; \
})



#pragma mark - Generating

#define TGenerate(Element) \
_TArrayCreateProtocol(Element) \
_TMutableArrayCreateProtocol(Element) \
_TSetCreateProtocol(Element) \
_TMutableSetCreateProtocol(Element) \
_TOrderedSetCreateProtocol(Element) \



#pragma mark - TArray

#define TArray(Element)                 _TCollection<TArray_##Element>
#define TArrayAlloc(Element)            ( (TArray(Element)) [NSArray alloc] )
#define TArrayMake(Element, ...)        _TCollectionMake(TArray, Element, __VA_ARGS__)
#define _TArrayForward(Element)         @protocol TArray_##Element;



#pragma mark TMutableArray

#define TMutableArray(Element)          _TCollection<TMutableArray_##Element>
#define TMutableArrayAlloc(Element)     ( (TMutableArray(Element)) [NSMutableArray alloc] )
#define TMutableArrayMake(Element, ...) _TCollectionMake(TMutableArray, Element, __VA_ARGS__)
#define _TMutableArrayForward(Element)  @protocol TMutableArray_##Element;



#pragma mark - TSet

#define TSet(Element)                   _TCollection<TSet_##Element>
#define TSetAlloc(Element)              ( (TSet(Element)) [NSSet alloc] )
#define TSetMake(Element, ...)          _TCollectionMake(TSet, Element, __VA_ARGS__)
#define _TSetForward(Element)           @protocol TSet_##Element;



#pragma mark - TMutableSet

#define TMutableSet(Element)            _TCollection<TMutableSet_##Element>
#define TMutableSetAlloc(Element)       ( (TMutableSet(Element)) [NSMutableSet alloc] )
#define TMutableSetMake(Element, ...)   _TCollectionMake(TMutableSet, Element, __VA_ARGS__)
#define _TMutableSetForward(Element)    @protocol TMutableSet_##Element;



#pragma mark - TOrderedSet

#define TOrderedSet(Element)            _TCollection<TOrderedSet_##Element>
#define TOrderedSetAlloc(Element)       ( (TOrderedSet(Element)) [NSOrderedSet alloc] )
#define TOrderedSetMake(Element, ...)   _TCollectionMake(TOrderedSet, Element, __VA_ARGS__)
#define _TOrderedSetForward(Element)    @protocol TOrderedSet_##Element;


