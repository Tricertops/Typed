//
//  Typed.h
//  Typed
//
//  Created by Martin Kiss on 30.10.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

@import Foundation;



typedef id TArray;



#define TArray(Element)                 TArray<TArray_##Element>
#define TArrayClass(Element, method)    ((TArray(Element))[NSArray method])
#define TArrayMake(Element, ...) \
(TArray(Element))({ \
    Element * __autoreleasing objects[] = { __VA_ARGS__ }; \
    TArrayClass(Element, arrayWithObjects:objects count:sizeof(objects) / sizeof(Element *));\
})


#define TArrayGenerate(Element) \
/*! TArray<Element> */ \
@class Element; \
@protocol TArray_##Element <NSObject> \
/*! Creating an Array */ \
+ (TArray(Element))array; \
+ (TArray(Element))arrayWithArray:(TArray(Element))array; \
+ (TArray(Element))arrayWithContentsOfFile:(NSString *)path; \
+ (TArray(Element))arrayWithContentsOfURL:(NSURL *)url; \
+ (TArray(Element))arrayWithObject:(Element *)object; \
+ (TArray(Element))arrayWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)cnt; \
+ (TArray(Element))arrayWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
/*! Initializing an Array */ \
- (TArray(Element))init; \
- (TArray(Element))initWithArray:(TArray(Element))array; \
- (TArray(Element))initWithArray:(TArray(Element))array copyItems:(BOOL)flag; \
- (TArray(Element))initWithContentsOfFile:(NSString *)path; \
- (TArray(Element))initWithContentsOfURL:(NSURL *)url; \
- (TArray(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TArray(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)cnt; \
/*! Querying an Array */ \
- (BOOL)containsObject:(Element *)object; \
@property (readonly) NSUInteger count; \
- (void)getObjects:(Element * __unsafe_unretained [])objects range:(NSRange)range; \
@property (nonatomic, readonly) Element *firstObject; \
@property (nonatomic, readonly) Element *lastObject; \
- (Element *)objectAtIndex:(NSUInteger)index; \
- (Element *)objectAtIndexedSubscript:(NSUInteger)index; \
/*!  */ \
- (Element *)firstObjectCommonWithArray:(TArray(Element))otherArray; \
- (NSUInteger)indexOfObject:(Element *)object; \
- (NSUInteger)indexOfObject:(Element *)object inRange:(NSRange)range; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element *)object; \
- (NSUInteger)indexOfObjectIdenticalTo:(Element *)object inRange:(NSRange)range; \
/* Typed array */ \
- (TArray(Element))arrayByAddingObject:(Element *)object; \
- (TArray(Element))arrayByAddingObjectsFromArray:(TArray(Element))otherArray; \
- (BOOL)isEqualToArray:(TArray(Element))otherArray; \
/* Not typed */ \
- (NSString *)componentsJoinedByString:(NSString *)separator; \
@property (readonly, copy) NSString *description; \
- (NSString *)descriptionWithLocale:(id)locale; \
- (NSString *)descriptionWithLocale:(id)locale indent:(NSUInteger)level; \
@end \


