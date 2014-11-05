//
//  TCountedSet.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TMutableSet.h"



#define _TCountedSetCreateProtocol(Element) \
@class Element; \
/*! NSCountedSet Interface */ \
@protocol TCountedSet_##Element <TMutableSet_##Element> \
- (TCountedSet(Element))self; \
/*! Initializing a Set */ \
- (TCountedSet(Element))initWithArray:(TArray(Element))array; \
- (TCountedSet(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TCountedSet(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TCountedSet(Element))initWithSet:(TSet(Element))set; \
- (TCountedSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TCountedSet(Element))init; \
- (TCountedSet(Element))initWithCoder:(NSCoder *)decoder; \
- (TCountedSet(Element))initWithCapacity:(NSUInteger)capacity; \
/*! Examining a Counted Set */ \
- (NSUInteger)countForObject:(Element *)object; \
@end

//TODO: What returns -copy and -mutableCopy?


