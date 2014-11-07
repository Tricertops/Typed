//
//  TMutableSet.h
//  Typed
//
//  Created by Martin Kiss on 2.11.14.
//  Copyright (c) 2014 Triceratops. All rights reserved.
//

#import "TSet.h"



#define _TMutableSetCreateProtocol(Element, Ptr) \
/*! NSMutableSet Interface */ \
_TMutableSetForward(Element) \
@protocol TMutableSet_##Element <TSet_##Element> \
- (TMutableSet(Element))self; \
/*! Initializing a Set */ \
- (TMutableSet(Element))initWithArray:(TArray(Element))array; \
- (TMutableSet(Element))initWithObjects:(Element Ptr )firstObject, ... NS_REQUIRES_NIL_TERMINATION; \
- (TMutableSet(Element))initWithObjects:(const Element Ptr  __autoreleasing [])objects count:(NSUInteger)count; \
- (TMutableSet(Element))initWithSet:(TSet(Element))set; \
- (TMutableSet(Element))initWithSet:(TSet(Element))set copyItems:(BOOL)flag; \
- (TMutableSet(Element))init; \
- (TMutableSet(Element))initWithCoder:(NSCoder *)decoder; \
- (TMutableSet(Element))initWithCapacity:(NSUInteger)capacity; \
/*! Adding Objects */ \
- (void)addObject:(Element Ptr )object; \
- (void)addObjectsFromArray:(TArray(Element))array; \
- (void)unionSet:(TSet(Element))other; \
/*! Removing Objects */ \
- (void)removeAllObjects; \
- (void)removeObject:(Element Ptr )object; \
- (void)filterUsingPredicate:(NSPredicate *)predicate; \
- (void)minusSet:(TSet(Element))other; \
- (void)intersectSet:(TSet(Element))other; \
/*! Replacing Objects */ \
- (void)setSet:(TSet(Element))other; \
@end


