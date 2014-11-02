//
//  TMutableSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TSet.h"



#define _TMutableSetCreateProtocol(Element) \
@class Element; \
/*! NSMutableSet Interface */ \
@protocol TMutableSet_##Element <TSet_##Element> \
/*! Initializing a Set */ \
- (TMutableSet(Element))initWithArray:(TArray(Element))array; \
- (TMutableSet(Element))initWithObjects:(Element *)firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableSet(Element))initWithObjects:(const Element * __autoreleasing [])objects count:(NSUInteger)count; \
- (TMutableSet(Element))initWithSet:(TSet(Element))set; \
- (TMutableSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TMutableSet(Element))init; \
- (TMutableSet(Element))initWithCoder:(NSCoder *)decoder; \
- (TMutableSet(Element))initWithCapacity:(NSUInteger)capacity; \
/*! Adding Objects */ \
- (void)addObject:(Element *)object; \
- (void)addObjectsFromArray:(TArray(Element))array; \
- (void)unionSet:(TSet(Element))otherSet; \
/*! Removing Objects */ \
- (void)removeAllObjects; \
- (void)removeObject:(Element *)object; \
- (void)filterUsingPredicate:(NSPredicate *)predicate; \
- (void)minusSet:(TSet(Element))otherSet; \
- (void)intersectSet:(TSet(Element))otherSet; \
/*! Replacing Objects */ \
- (void)setSet:(TSet(Element))otherSet; \
@end


