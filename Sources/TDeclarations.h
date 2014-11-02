//
//  TDeclarations.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;



typedef id _TObject;
#define _TProtocols     NSObject, NSFastEnumeration, NSCopying, NSMutableCopying, NSSecureCoding



#pragma mark Generating

#define TArrayGenerate(Element) \
_TArrayCreateProtocol(Element) \
_TMutableArrayCreateProtocol(Element) \



#pragma mark - TArray

typedef _TObject TArray;
#define TArray(Element)                 TArray<TArray_##Element>
#define TArrayClass(Element, method)    ((TArray(Element))[NSArray method])
#define TArrayMake(Element, ...) \
(TArray(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    TArrayClass(Element, arrayWithObjects:objects count:sizeof(objects) / sizeof(Element *));\
})

#define _TArrayForward(Element)         @protocol TArray_##Element;



#pragma mark TMutableArray

typedef TArray TMutableArray;
#define TMutableArray(Element)                  TMutableArray<TMutableArray_##Element>
#define TMutableArrayClass(Element, method)     ((TMutableArray(Element))[NSMutableArray method])
#define TMutableArrayMake(Element, ...) \
(TMutableArray(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    TMutableArrayClass(Element, arrayWithObjects:objects count:sizeof(objects) / sizeof(Element *));\
})

#define _TMutableArrayForward(Element)          @protocol TMutableArray_##Element;



#pragma mark - TSet

typedef _TObject TSet;
#define TSet(Element)               TSet<TSet_##Element>
#define TSetClass(Element, method)  ((TMutableArray(Element))[NSMutableArray method])
#define TSetMake(Element, ...)      ( (TSet(Element)) TSetClass(Element, setWithArray:TArray(Element, __VA_ARGS__)) )

#define _TSetForward(Element)       @protocol TSet_##Element;


