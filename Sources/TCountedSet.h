//
//  TCountedSet.h
//  Typed
//
//  Created by Martin Kiss on 4.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TMutableSet.h"



#define _TCountedSetCreateProtocol(Element, Ptr) \
/*! NSCountedSet Interface */ \
_TCountedSetForward(Element) \
@protocol TCountedSet_##Element <TMutableSet_##Element> \
- (TCountedSet(Element))self; \
/*! Initializing a Set */ \
- (TCountedSet(Element))initWithArray:(TArray(Element))array; \
- (TCountedSet(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TCountedSet(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TCountedSet(Element))initWithSet:(TSet(Element))set; \
- (TCountedSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TCountedSet(Element))init; \
- (TCountedSet(Element))initWithCoder:(NSCoder *)decoder; \
- (TCountedSet(Element))initWithCapacity:(NSUInteger)capacity; \
/*! Examining a Counted Set */ \
- (NSUInteger)countForObject:(Element Ptr )object; \
@end

//TODO: What returns -copy and -mutableCopy?


