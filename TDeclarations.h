//
//  TDeclarations.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;



typedef id _TObject;



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

//TODO: TMutableArray

